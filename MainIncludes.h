static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static void xShutdown();
#include "Cheat.h"
#include "Print.hpp"
#include "d3d9_x.h"
#include "xor.hpp"
#include <tchar.h>
#include <dwmapi.h>
#include <vector>
#include "Keybind.h"
#include "Threads.h"
#include "FN_Sdk_Offsets.h"
#include "xstring"
#include "BoneIndex.h"
#include "Aimbot.cpp"
#include "WindowStreamProof.h"
#include "DrawEsp.h"
#include "W2S_ Camera.h"
#include "icons1.h"
#include "definitions.h"
#include "FN Sdk Includes.h"
#define color1 (WORD)(0x0001 | 0x0000)
#define color2 (WORD)(0x0002 | 0x0000)
#define color3 (WORD)(0x0003 | 0x0000)
#define color4 (WORD)(0x0004 | 0x0000)
#define color5 (WORD)(0x0005 | 0x0000)
#define color6 (WORD)(0x0006 | 0x0000)
#define color7 (WORD)(0x0007 | 0x0000)
#define color8 (WORD)(0x0008 | 0x0000)
#define color9 (WORD)(0x0008 | 0x0000)
#define COLOR(h, c) SetConsoleTextAttribute(h, c);
ImFont* m_pFont;
Vector3 localactorpos;
uint64_t TargetPawn;
HWND MyWnd = NULL;
HWND GameWnd = NULL;
int localplayerID;
RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;
uintptr_t GamePid;
uintptr_t GameBaseAddress;
DWORD ScreenCenterX;
static ImColor Color;
DWORD ScreenCenterY;
DWORD_PTR closestPawn = NULL;
Vector3 Location;
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;
inline static int menu_animation = 0;
inline static int border_animation = 0;
inline static int menu_slide = 0;
inline static bool small_tab = false;
inline static int do_tab_anim = 0;


template<class T>
struct TArray {
	friend struct FString;

public:
	inline TArray() {
		Data = nullptr;
		Count = Max = 0;
	};

	inline INT Num() const {
		return Count;
	};

	inline T& operator[](INT i) {
		return Data[i];
	};

	inline BOOLEAN IsValidIndex(INT i) {
		return i < Num();
	}

private:
	T* Data;
	INT Count;
	INT Max;
};

typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t CurrentActorMesh;
	DWORD_PTR rootcomp;
	std::string name;
}FNlEntity;
std::vector<FNlEntity> entityList;

void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}

namespace Process {
	DWORD ID;
	HANDLE Handle;
	HWND Hwnd;
	WNDPROC WndProc;
	int WindowWidth;
	int WindowHeight;
	int WindowLeft;
	int WindowRight;
	int WindowTop;
	int WindowBottom;
	LPCSTR Title;
	LPCSTR ClassName;
	LPCSTR Path;
}

namespace DirectX9Interface {
	IDirect3D9Ex* Direct3D9 = NULL;
	IDirect3DDevice9Ex* pDevice = NULL;
	D3DPRESENT_PARAMETERS pParams = { NULL };
	MARGINS Margin = { -1 };
	MSG Message = { NULL };
}


namespace OverlayWindow {
	WNDCLASSEX WindowClass;
	HWND Hwnd;
	LPCSTR Name;
}

void xShutdown()
{
	TriBuf->Release();
	D3dDevice->Release();
	p_Object->Release();

	DestroyWindow(Window);
	UnregisterClass((L"AMD"), NULL);
}
HWND game_wnd;
int screen_width;
int screen_height;
const MARGINS Margin = { -1 };


void setup_window()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX win_class = {
		sizeof(WNDCLASSEX),
		0,
		WinProc,
		0,
		0,
		nullptr,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		nullptr,
		nullptr,
		TEXT("AMD"),
		LoadIcon(nullptr, IDI_APPLICATION)
	};

	if (!RegisterClassEx(&win_class))
		exit(1);

	game_wnd = FindWindowW(NULL, TEXT("Fortnite  "));

	if (game_wnd) {
		screen_width = 1900;
		screen_height = 1070;
	}
	else
		exit(2);

	Window = CreateWindowExA(NULL, "AMD", "AMD", WS_POPUP | WS_VISIBLE, Width + 10, Height + 5, screen_width, screen_height, NULL, NULL, 0, NULL);
	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, (int)GetWindowLong(Window, GWL_EXSTYLE) | WS_EX_LAYERED | WS_EX_TRANSPARENT);
	SetLayeredWindowAttributes(Window, RGB(0, 0, 0), 0, ULW_COLORKEY);
	SetLayeredWindowAttributes(Window, 0, 255, LWA_ALPHA);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}

bool CheckDriverStatus() {
	int icheck = 29;
	NTSTATUS status = 0;
	Unprotect(Driver::GetBaseAddress);
	uintptr_t BaseAddr = Driver::GetBaseAddress(Driver::currentProcessId);
	if (BaseAddr == 0) {
		return false;
	}
	Protect(Driver::GetBaseAddress);

	int checked = Driver::read<int>(Driver::currentProcessId, (uintptr_t)&icheck, &status);
	if (checked != icheck) {
		return false;
	}

	return true;
}

DWORD Menuthread(LPVOID in)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_F1) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(2);
	}
}

DWORD GetProcessIdByName(wchar_t* name) {
	Protect(_ReturnAddress());

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE) {
		while (Process32Next(snapshot, &entry) == TRUE) {
			if (_wcsicmp(entry.szExeFile, name) == 0) {
				Unprotect(_ReturnAddress());
				return entry.th32ProcessID;
			}
		}
	}

	CloseHandle(snapshot);
	Unprotect(_ReturnAddress());
	return 0;
}

uintptr_t milliseconds_now() {
	static LARGE_INTEGER s_frequency;
	static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
	if (s_use_qpc) {
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		return (1000LL * now.QuadPart) / s_frequency.QuadPart;
	}
	else {
		return GetTickCount();
	}
}

void LoadProtectedFunctions() {

	uintptr_t t = milliseconds_now();
	BYTE xorkey = 0x0;
	for (DWORD i = 0; i < 8; i++) {
		xorkey = ((BYTE*)&t)[i];
		if (xorkey > 0x3 && xorkey < 0xf0) {
			break;
		}
	}
	if (xorkey <= 0x3 || xorkey >= 0xf0) {
		xorkey = 0x56;
	}

	addFunc({ LoadProtectedFunctions, (uintptr_t)CheckDriverStatus - (uintptr_t)LoadProtectedFunctions - 0x0, xorkey, false });
	addFunc({ CheckDriverStatus, (uintptr_t)GetProcessIdByName - (uintptr_t)CheckDriverStatus - 0x0, xorkey, false });
	addFunc({ GetProcessIdByName, (uintptr_t)milliseconds_now - (uintptr_t)GetProcessIdByName - 0x0, xorkey, false });

	addFunc({ Driver::SendCommand, (uintptr_t)Driver::GetBaseAddress - (uintptr_t)Driver::SendCommand - 0x0, xorkey, false });
	addFunc({ Driver::GetBaseAddress, (uintptr_t)Driver::copy_memory - (uintptr_t)Driver::GetBaseAddress - 0x0, xorkey, false });
	addFunc({ Driver::copy_memory, (uintptr_t)GetKernelModuleExport - (uintptr_t)Driver::copy_memory - 0x0, xorkey, false });
	addFunc({ GetKernelModuleExport, (uintptr_t)GetKernelModuleAddress - (uintptr_t)GetKernelModuleExport - 0x0, xorkey, false });
	addFunc({ GetKernelModuleAddress, (uintptr_t)Driver::initialize - (uintptr_t)GetKernelModuleAddress - 0x0, xorkey, false });
	addFunc({ Driver::initialize, (uintptr_t)Driver::read_memory - (uintptr_t)Driver::initialize - 0x0, xorkey, false });
	addFunc({ Driver::read_memory, (uintptr_t)Driver::write_memory - (uintptr_t)Driver::read_memory - 0x0, xorkey, false });
	addFunc({ Driver::write_memory, (uintptr_t)Driver::read_memory - (uintptr_t)Driver::write_memory - 0x0, xorkey, false });

	for (size_t i = 0; i < funcCount; i++) {
		if (functions[i].address != LoadProtectedFunctions)
			Protect(functions[i].address);
	}
	Unprotect(_ReturnAddress());
}
bool verify_game() {

	wchar_t name[] = { 'F', 'o', 'r', 't', 'n', 'i', 't', 'e', 'C', 'l', 'i', 'e', 'n', 't', '-', 'W', 'i' , 'n' , '6', '4', '-' , 'S' , 'h', 'i', 'p', 'p', 'i', 'n', 'g', '.','e', 'x', 'e' , 0 };
	//FortniteClient-Win64-Shipping
	Unprotect(GetProcessIdByName);
	processID = GetProcessIdByName(name);
	Protect(GetProcessIdByName);
	memset(name, 0, sizeof(name));

	Unprotect(Driver::GetBaseAddress);
	base_address = Driver::GetBaseAddress(processID);
	Protect(Driver::GetBaseAddress);

	if (base_address != 0) {

		GamePid = processID;
		GameBaseAddress = base_address;


		GamePid = 0;
		GameBaseAddress = 0;

	}
	//ProtectedSleep(2000);

	return true;
}

void HitBoxAimKey()
{
	if (def::hitboxpos == 0)
	{
		def::hitbox = 68; //head
	}
	else if (def::hitboxpos == 1)
	{
		def::hitbox = 67; //neck
	}
	else if (def::hitboxpos == 2)
	{
		def::hitbox = 36; //chest
	}
	else if (def::hitboxpos == 3)
	{
		def::hitbox = 2; //pelvis
	}

	if (def::aimkeypos == 0)
	{
		def::aimkey = 0x01;//left mouse button
	}
	else if (def::aimkeypos == 1)
	{
		def::aimkey = 0x02;//right mouse button
	}
	else if (def::aimkeypos == 2)
	{
		def::aimkey = 0x04;//middle mouse button
	}
	else if (def::aimkeypos == 3)
	{
		def::aimkey = 0x05;//x1 mouse button
	}
	else if (def::aimkeypos == 4)
	{
		def::aimkey = 0x06;//x2 mouse button
	}
	else if (def::aimkeypos == 5)
	{
		def::aimkey = 0x03;//control break processing
	}
	else if (def::aimkeypos == 6)
	{
		def::aimkey = 0x08;//backspace
	}
	else if (def::aimkeypos == 7)
	{
		def::aimkey = 0x09;//tab
	}
	else if (def::aimkeypos == 8)
	{
		def::aimkey = 0x0c;//clear
	}
	else if (def::aimkeypos == 9)
	{
		def::aimkey == 0x0D;//enter
	}
	else if (def::aimkeypos == 10)
	{
		def::aimkey = 0x10;//shift
	}
	else if (def::aimkeypos == 11)
	{
		def::aimkey = 0x11;//ctrl
	}
	else if (def::aimkeypos == 12)
	{
		def::aimkey == 0x12;//alt
	}
	else if (def::aimkeypos == 13)
	{
		def::aimkey == 0x14;//caps lock
	}
	else if (def::aimkeypos == 14)
	{
		def::aimkey == 0x1B;//esc
	}
	else if (def::aimkeypos == 15)
	{
		def::aimkey == 0x20;//space
	}
	else if (def::aimkeypos == 16)
	{
		def::aimkey == 0x30;//0
	}
	else if (def::aimkeypos == 17)
	{
		def::aimkey == 0x31;//1
	}
	else if (def::aimkeypos == 18)
	{
		def::aimkey == 0x32;//2
	}
	else if (def::aimkeypos == 19)
	{
		def::aimkey == 0x33;//3
	}
	else if (def::aimkeypos == 20)
	{
		def::aimkey == 0x34;//4
	}
	else if (def::aimkeypos == 21)
	{
		def::aimkey == 0x35;//5
	}
	else if (def::aimkeypos == 22)
	{
		def::aimkey == 0x36;//6
	}
	else if (def::aimkeypos == 23)
	{
		def::aimkey == 0x37;//7
	}
	else if (def::aimkeypos == 24)
	{
		def::aimkey == 0x38;//8
	}
	else if (def::aimkeypos == 25)
	{
		def::aimkey == 0x39;//9
	}
	else if (def::aimkeypos == 26)
	{
		def::aimkey == 0x41;//a
	}
	else if (def::aimkeypos == 27)
	{
		def::aimkey == 0x42;//b
	}
	else if (def::aimkeypos == 28)
	{
		def::aimkey == 0x43;//c
	}
	else if (def::aimkeypos == 29)
	{
		def::aimkey == 0x44;//d
	}
	else if (def::aimkeypos == 30)
	{
		def::aimkey == 0x45;//e
	}
	else if (def::aimkeypos == 31)
	{
		def::aimkey == 0x46;//f
	}
	else if (def::aimkeypos == 32)
	{
		def::aimkey == 0x47;//g
	}
	else if (def::aimkeypos == 33)
	{
		def::aimkey == 0x48;//h
	}
	else if (def::aimkeypos == 34)
	{
		def::aimkey == 0x49;//i
	}
	else if (def::aimkeypos == 35)
	{
		def::aimkey == 0x4A;//j
	}
	else if (def::aimkeypos == 36)
	{
		def::aimkey == 0x4B;//k
	}
	else if (def::aimkeypos == 37)
	{
		def::aimkey == 0x4C;//L
	}
	else if (def::aimkeypos == 38)
	{
		def::aimkey == 0x4D;//m
	}
	else if (def::aimkeypos == 39)
	{
		def::aimkey == 0x4E;//n
	}
	else if (def::aimkeypos == 40)
	{
		def::aimkey == 0x4F;//o
	}
	else if (def::aimkeypos == 41)
	{
		def::aimkey == 0x50;//p
	}
	else if (def::aimkeypos == 42)
	{
		def::aimkey == 0x51;//q
	}
	else if (def::aimkeypos == 43)
	{
		def::aimkey == 0x52;//r
	}
	else if (def::aimkeypos == 44)
	{
		def::aimkey == 0x53;//s
	}
	else if (def::aimkeypos == 45)
	{
		def::aimkey == 0x54;//t
	}
	else if (def::aimkeypos == 46)
	{
		def::aimkey == 0x55;//u
	}
	else if (def::aimkeypos == 47)
	{
		def::aimkey == 0x56;//v
	}
	else if (def::aimkeypos == 48)
	{
		def::aimkey == 0x57;//w
	}
	else if (def::aimkeypos == 49)
	{
		def::aimkey == 0x58;//x
	}
	else if (def::aimkeypos == 50)
	{
		def::aimkey == 0x59;//y
	}
	else if (def::aimkeypos == 51)
	{
		def::aimkey == 0x5A;//z
	}
	else if (def::aimkeypos == 52)
	{
		def::aimkey == 0x60;//numpad 0
	}
	else if (def::aimkeypos == 53)
	{
		def::aimkey == 0x61;//numpad 1
	}
	else if (def::aimkeypos == 54)
	{
		def::aimkey == 0x62;//numpad 2
	}
	else if (def::aimkeypos == 55)
	{
		def::aimkey == 0x63;//numpad 3
	}
	else if (def::aimkeypos == 56)
	{
		def::aimkey == 0x64;//numpad 4
	}
	else if (def::aimkeypos == 57)
	{
		def::aimkey == 0x65;//numpad 5
	}
	else if (def::aimkeypos == 58)
	{
		def::aimkey == 0x66;//numpad 6
	}
	else if (def::aimkeypos == 59)
	{
		def::aimkey == 0x67;//numpad 7
	}
	else if (def::aimkeypos == 60)
	{
		def::aimkey == 0x68;//numpad 8
	}
	else if (def::aimkeypos == 61)
	{
		def::aimkey == 0x69;//numpad 9
	}
	else if (def::aimkeypos == 62)
	{
		def::aimkey == 0x6A;//multiply
	}
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		xShutdown();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;

	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime;
	(void)io;

	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);




	if (open)
	{
		menu_animation = menu_animation + 6;
		border_animation = border_animation + 6;
		menu_slide = menu_slide + 10;
	}
	else if (!open)
	{
		menu_animation = menu_animation - 6;
		border_animation = border_animation - 6;
		menu_slide = menu_slide - 10;
	}

	if (menu_animation > 254)
		menu_animation = 255;

	if (border_animation > 3.4)
		border_animation = 3.5;
	if (border_animation < 1)
		border_animation = 0;

	if (menu_slide > 560)
		menu_slide = 561;
	if (menu_slide < 1)
		menu_slide = 0;




	ImGuiStyle& Style = ImGui::GetStyle();
	Style.WindowPadding = ImVec2(20.000f, 20.000f);
	Style.WindowRounding = 0.000f;
	Style.ChildRounding = 0.000f;
	Style.FramePadding = ImVec2(20.000f, 5.000f);
	Style.FrameRounding = 0.000f;
	Style.FrameBorderSize = 0.000f;
	Style.TabBorderSize = 8.000f;

	
	////style.AntiAliasedShapes = false;
	//

	ImVec4* Color = ImGui::GetStyle().Colors;
	//colors[ImGuiCol_Text] = ImVec4(0.000f, 0.678f, 0.929f, 1.0f);
	//colors[ImGuiCol_TextDisabled] = ImVec4(0.0f, 0.0263f, 0.0357f, 1.00f);
	//colors[ImGuiCol_WindowBg] = ImVec4(0.059f, 0.051f, 0.071f, 1.00f);
	//colors[ImGuiCol_ChildBg] = ImVec4(0.071f, 0.071f, 0.090f, 1.00f);
	//colors[ImGuiCol_PopupBg] = ImVec4(0.0f, 0.0263f, 0.0357f, 1.00f);
	//colors[ImGuiCol_Border] = ImColor(0.000f, 0.678f, 0.929f, 1.0f);
	//colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0263f, 0.0357f, 0.00f);
	//colors[ImGuiCol_FrameBg] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_FrameBgHovered] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_FrameBgActive] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_TitleBg] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_TitleBgActive] = ImVec4(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_MenuBarBg] = ImVec4(0.0f, 0.263f, 0.357f, 1.00f);
	//colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//colors[ImGuiCol_CheckMark] = ImColor(87, 119, 134, 255);
	//colors[ImGuiCol_SliderGrab] = ImColor(119, 134, 169, 150);
	//colors[ImGuiCol_SliderGrabActive] = ImColor(119, 134, 169, 150);
	//colors[ImGuiCol_Button] = ImColor(26, 23, 31, 255);
	//colors[ImGuiCol_ButtonHovered] = ImColor(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_ButtonActive] = ImColor(0.102f, 0.090f, 0.122f, 1.000f);
	//colors[ImGuiCol_Header] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_HeaderHovered] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_HeaderActive] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	////colors[ImGuiCol_Column] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	////colors[ImGuiCol_ColumnHovered] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	////colors[ImGuiCol_ColumnActive] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_ResizeGrip] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	//colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	//colors[ImGuiCol_ResizeGripActive] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	//colors[ImGuiCol_PlotLines] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_PlotHistogram] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	//colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	////colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);

	Style.WindowBorderSize = 0;

	Style.ChildRounding = 0;
	Style.FrameRounding = 0;
	Style.ScrollbarRounding = 0;
	Style.GrabRounding = 0;
	Style.PopupRounding = 0;
	Style.WindowRounding = 0;
	Style.WindowTitleAlign.x = 0.50f;
	Style.WindowPadding.x = 20.0f;

	Color[ImGuiCol_WindowBg] = ImColor(18, 18, 18, 255);
	Color[ImGuiCol_ChildBg] = ImColor(5, 5, 5, 255);
	Color[ImGuiCol_FrameBg] = ImColor(31, 31, 31, 255);
	Color[ImGuiCol_FrameBgActive] = ImColor(41, 41, 41, 255);
	Color[ImGuiCol_FrameBgHovered] = ImColor(41, 41, 41, 255);

	Color[ImGuiCol_Button] = ImColor(29, 29, 29, 255);
	Color[ImGuiCol_ButtonActive] = ImColor(32, 32, 32, 255);
	Color[ImGuiCol_ButtonHovered] = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_Border] = ImColor(0, 0, 0, 0);
	Color[ImGuiCol_Separator] = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_ResizeGrip] = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripActive] = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripHovered] = ImColor(30, 30, 30, 255);

	Color[ImGuiCol_ChildBg] = ImColor(26, 26, 26, 255);

	Color[ImGuiCol_ScrollbarBg] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrab] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Header] = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_HeaderActive] = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_HeaderHovered] = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);





	XorS(font, "C:\\Windows\\Fonts\\Arial.ttf");
	m_pFont = io.Fonts->AddFontFromFileTTF(font.decrypt(), 14.0f, nullptr, io.Fonts->GetGlyphRangesDefault());

	p_Object->Release();
}
std::wstring MBytesToWString(const char* lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}

std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}

void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), text.c_str());
}

struct HandleDisposer
{
	using pointer = HANDLE;
	void operator()(HANDLE handle) const
	{
		if (handle != NULL || handle != INVALID_HANDLE_VALUE)
		{
			CloseHandle(handle);
		}
	}
};

using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;

struct FString : private TArray<WCHAR> {
	FString() {
		Data = nullptr;
		Max = Count = 0;
	}

	FString(LPCWSTR other) {
		Max = Count = static_cast<INT>(wcslen(other));

		if (Count) {
			Data = const_cast<PWCHAR>(other);
		}
	};

	inline BOOLEAN IsValid() {
		return Data != nullptr;
	}

	inline PWCHAR c_str() {
		return Data;
	}
};

VOID(*FreeInternal)(PVOID) = nullptr;

VOID Free(PVOID buffer) {
	FreeInternal(buffer);
}


#pragma once

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
		static auto do_call(const void* shell, void* shell_param, First first, Second second,
			Third third, Fourth fourth, Pack... pack) -> Ret
		{
			return shellcode_stub_helper< Ret, First, Second, Third, Fourth, void*, void*, Pack... >(shell, first, second, third, fourth, shell_param, nullptr, pack...);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
		static auto do_call(
			const void* shell,
			void* shell_param,
			First first = First{},
			Second second = Second{},
			Third third = Third{},
			Fourth fourth = Fourth{}
		) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
				);
		}
	};
}

template <typename Ret, typename... Args>
static inline auto SpoofCall(Ret(*fn)(Args...), Args... args) -> Ret
{
	static const void* jmprbx = nullptr;
	if (!jmprbx) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(::GetModuleHandleW(NULL));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;

		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x26 };
		const auto              va = ntdll + section->VirtualAddress;
		jmprbx = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}

	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdx;
	};

	shell_params p
	{
		jmprbx,
		reinterpret_cast<void*>(fn)
	};

	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}

namespace SpoofRuntime {
	inline float acosf_(float x)
	{
		return SpoofCall(acosf, x);
	}

	inline float atan2f_(float x, float y)
	{
		return SpoofCall(atan2f, x, y);
	}
}
