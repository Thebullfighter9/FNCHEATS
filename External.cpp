// Source made by Create#5488
// Release Date: 02.02.2023 
// Updated to Latest Patch
// If you need help dm me -> Create#5488
#include "MainIncludes.h"
#include <tchar.h>
#include <Windows.h>
#include <string>
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
IDirect3DDevice9Ex* p_Device = NULL;
const std::string compilation_time = (std::string)skCrypt(__TIME__);
#include "Driver.h"
#include "config.h"
#include "Protect.h"
#include "lazyimp.hpp"
#include <xtree>
#include <map>
#include "Imgui/imgui_internal.h"

#define M_PI 3.14159265358979323846264338327950288419716939937510


inline uintptr_t player_controller;

void DrawESP();

DWORD espthread(LPVOID IN) {
	while (true) {
			DrawESP();
	}
}

// Hmu on discord (Chase.#1803) if you need any help :)


int main()
{
	if (!Driver::initialize() || !CheckDriverStatus()) {
		wchar_t VarName[] = { 'b','l','y','s','c','y','k','\0' };
		UNICODE_STRING FVariableName = UNICODE_STRING();
		FVariableName.Buffer = VarName;
		FVariableName.Length = 14;
		FVariableName.MaximumLength = 30;
		myNtSetSystemEnvironmentValueEx(
			&FVariableName,
			&DummyGuid,
			0,
			0,
			ATTRIBUTES);
		memset(VarName, 0, sizeof(VarName));
		Beep(600, 1000);
		printf(("Driver not Loaded"));
		ProtectedSleep(3000);
		exit(1);
		return 1;
	}


	while (hwnd == NULL)
	{
		XorS(wind, "Fortnite  ");
		hwnd = FindWindowA(0, wind.decrypt());
		Sleep(100);
	}

	LoadProtectedFunctions();
	Protect(LoadProtectedFunctions);
	Unprotect(Driver::initialize);
	Unprotect(CheckDriverStatus);



	Protect(Driver::initialize);
	Protect(CheckDriverStatus);
	Sleep(1000);

	verify_game();



	std::cout << base_address;

	::ShowWindow(::GetConsoleWindow(), SW_HIDE);


	setup_window();
	xInitD3d();
	xMainLoop();
	HANDLE handle = CreateThread_Esp(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(espthread), nullptr, NULL, nullptr);
	xShutdown();
	return 0;
}


bool isVisible(uint64_t mesh)
{

	float LastSumbitTime = Driver::read<float>(processID, OFFSETS::Mesh + 0x360);
	float LastRenderTimeOnScreen = Driver::read<float>(processID, OFFSETS::Mesh + 0x368);

	bool Visible = LastRenderTimeOnScreen + 0.06f >= LastSumbitTime;
	return Visible;
}

void AimAt(DWORD_PTR entity)
{
	uint64_t currentactormesh = Driver::read<uint64_t>(processID, entity + OFFSETS::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, def::hitbox);
	Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
	if (rootHeadOut.y != 0 || rootHeadOut.y != 0)
	{
		aimbot(rootHeadOut.x, rootHeadOut.y);
	}
}

ImU32 RGBtoU32(int r, int g, int b)
{
	float fr = (float)r / 255.0;
	float fg = (float)g / 255.0;
	float fb = (float)b / 255.0;
	return ImGui::GetColorU32(ImVec4(fr, fg, fb, 1));
}
DWORD_PTR CurrentActorMesh;
boolean in_rect(double centerX, double centerY, double radius, double x, double y) {
	return x >= centerX - radius && x <= centerX + radius &&
		y >= centerY - radius && y <= centerY + radius;
}

void DrawESP() {
		if (drawbase)
		{
			ImGui::GetBackgroundDrawList()->AddText(ImVec2(900, 65), RGBtoU32(255, 0, 0), skCrypt("Alien Private"));
		}
	if (crosshair)
	{
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 - CrosshairSize, Height / 2), RGBtoU32(255, 255, 255));
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 + CrosshairSize, Height / 2), RGBtoU32(255, 255, 255));
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 - CrosshairSize), RGBtoU32(255, 255, 255));
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 + CrosshairSize), RGBtoU32(255, 255, 255));
	}
	if (CloseAimfov) {
		ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(def::CAimbotFov), RGBtoU32(255, 255, 255), 100.0f, 2.5f);
	}
	if (circletype == true)
	{
		if (square_fov) {
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(ScreenCenterX - def::AimbotFov, ScreenCenterY - def::AimbotFov), ImVec2(ScreenCenterX + def::AimbotFov, ScreenCenterY + def::AimbotFov), RGBtoU32(0, 173, 237), 1.5f);
			bool fovcircle = false;
			bool  fovcirclefilled = false;
		}
		if (fovcircle) {
			ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(def::AimbotFov), RGBtoU32(0, 173, 237), 100.0f, 1.0f);
			bool square_fov = false;
			bool fovcircle = false;
			bool  fovcirclefilled = false;
		}
		if (fovcirclefilled) {
			ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(ScreenCenterX, ScreenCenterY), float(def::AimbotFov), ImColor(0, 0, 0, 160), 220.0f);
			ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(def::AimbotFov), RGBtoU32(255, 80, 80), 220.0f, 0.5f);
			bool square_fov = false;
			bool fovcircle = false;
		}
		if (SquareFovFilled)
		{
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(ScreenCenterX - def::AimbotFov, ScreenCenterY - def::AimbotFov), ImVec2(ScreenCenterX + def::AimbotFov, ScreenCenterY + def::AimbotFov), RGBtoU32(255, 80, 80), 0.5f);
			ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(ScreenCenterX - def::AimbotFov, ScreenCenterY - def::AimbotFov), ImVec2(ScreenCenterX + def::AimbotFov, ScreenCenterY + def::AimbotFov), ImColor(0, 0, 0, 160), 1.0f), 0.5f;
		}
	}

	HitBoxAimKey();

	float closestDistance = 100;
	DWORD_PTR closestPawn = NULL;

	Actors::Uworld = Driver::read<DWORD_PTR>(processID, base_address + GWorld);

	DWORD_PTR Gameinstance = Driver::read<DWORD_PTR>(processID, Actors::Uworld + OFFSETS::Gameinstance);

	DWORD_PTR LocalPlayers = Driver::read<DWORD_PTR>(processID, Gameinstance + OFFSETS::LocalPlayers);

	Actors::Localplayer = Driver::read<DWORD_PTR>(processID, LocalPlayers);

	Actors::PlayerController = Driver::read<DWORD_PTR>(processID, Actors::Localplayer + OFFSETS::PlayerController);

	LocalPawn = Driver::read<DWORD_PTR>(processID, Actors::PlayerController + OFFSETS::LocalPawn);

	PlayerState = Driver::read<DWORD_PTR>(processID, LocalPawn + OFFSETS::PlayerState);

	Actors::Rootcomp = Driver::read<DWORD_PTR>(processID, LocalPawn + OFFSETS::RootComponet);

	DWORD_PTR GameState = Driver::read<DWORD_PTR>(processID, Actors::Uworld + OFFSETS::GameState);

	DWORD_PTR PlayerArray = Driver::read<DWORD_PTR>(processID, GameState + OFFSETS::PlayerArray);


	for (unsigned long i = 0; i < 100; ++i)
	{
		const auto& player = Driver::read<uintptr_t>(processID, PlayerArray + i * 0x8);
		const auto& CurrentActor = Driver::read<uintptr_t>(processID, player + OFFSETS::CurrentActor);
		const uint64_t CurrentActorMesh = Driver::read<uint64_t>(processID, CurrentActor + OFFSETS::Mesh);
		const int MyTeamId = Driver::read<int>(processID, PlayerState + OFFSETS::TeamId);
		const DWORD64 otherPlayerState = Driver::read<uint64_t>(processID, CurrentActor + 0x290);
		const int ActorTeamId = Driver::read<int>(processID, otherPlayerState + OFFSETS::TeamId);

		// -- ReloadCheck --
		const uintptr_t CurrentWeapon = Driver::read<uintptr_t>(processID, CurrentActor + 0x8F8);
		const auto bIsReloadingWeapon = Driver::read<bool>(processID, CurrentWeapon + 0x348);
		// -------------------------------------------

		// -- Targeting Check --
		const auto bIsTargeting = Driver::read<bool>(processID, CurrentWeapon + 0xB05);
		// -------------------------------------------

		if (SelfEsp) {
		}
		else {
			if (CurrentActor == Actors::LocalPawn) {
				continue;
			}
		}
	


		// --- Vector3 ---
		Vector3 Headpos = GetBoneWithRotation(CurrentActorMesh, 106);
		Vector3 bone66 = GetBoneWithRotation(CurrentActorMesh, 67);
		Vector3 top = ProjectWorldToScreen(bone66);
		Vector3 bone0 = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 bottom = ProjectWorldToScreen(bone0);
		Vector3 Headbox = ProjectWorldToScreen(Vector3(Headpos.x, Headpos.y, Headpos.z + 15));
		Vector3 w2shead = ProjectWorldToScreen(Headpos);
		Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, 68);
		Vector3 vRootBone = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 vHeadBoneOut = ProjectWorldToScreen(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));
		localactorpos = Driver::read<Vector3>(processID, Actors::Rootcomp + 0x128);

		// --- Float's ---
		float distance = localactorpos.Distance(Headpos) / ChangerFOV;
		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = CornerHeight * BoxWidthValue;

		if (distance < def::VisDist)
		{


			if (WindowStreamProof) {
				SetWindowDisplayAffinity(Window, WDA_EXCLUDEFROMCAPTURE);
			}
			if (!WindowStreamProof) {
				SetWindowDisplayAffinity(Window, !WDA_EXCLUDEFROMCAPTURE);
			}
			if (fillbox)
			{
				DrawFilledRect(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, ImColor(201, 0, 0, 100));
			}
			if (CornerBoxEsp)
			{
				if (isVisible(CurrentActorMesh))
				{
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, RGBtoU32(0, 173, 237), 1);
				}
				else
				{
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, RGBtoU32(0, 173, 237), 1);
				}
			}
			if (BoxEsp)
			{
				if (isVisible(CurrentActorMesh)) {
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(0, 173, 237,255), 1.5);
				}
				else if (!isVisible(CurrentActorMesh)) {
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(0, 173, 237, 255), 1.5);
				}
			}




			if (PlayerDistanceEsp)
			{

				
				char name[128];
				sprintf_s(name, skCrypt("Player: %2.fm"), distance);
				DrawString(16, Headbox.x, Headbox.y - 27, &Col.orange, true, true, name);
			}

			
			if (ThreeDBoxEsp)
			{
				if (vHeadBoneOut.x != 0 || vHeadBoneOut.y != 0 || vHeadBoneOut.z != 0)
				{
					ImU32 ESPSkeleton;
					if (isVisible(CurrentActorMesh))
					{
						ESPSkeleton = RGBtoU32(0, 179, 0);
					}
					else if (!isVisible(CurrentActorMesh))
					{
						ESPSkeleton = RGBtoU32(255, 0, 0);
					}
					Vector3 bottom1 = ProjectWorldToScreen(Vector3(vRootBone.x + 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom2 = ProjectWorldToScreen(Vector3(vRootBone.x - 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom3 = ProjectWorldToScreen(Vector3(vRootBone.x - 40, vRootBone.y + 40, vRootBone.z));
					Vector3 bottom4 = ProjectWorldToScreen(Vector3(vRootBone.x + 40, vRootBone.y + 40, vRootBone.z));
					Vector3 top1 = ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top2 = ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top3 = ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
					Vector3 top4 = ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ESPSkeleton, 2.001f);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ESPSkeleton, 2.001f);
				}
			}
		}
		auto dx = w2shead.x - (Width / 2);
		auto dy = w2shead.y - (Height / 2);
		auto dist = sqrtf(dx * dx + dy * dy);
		if (isVisible(CurrentActorMesh)) {

			if (dist < def::AimbotFov && dist < closestDistance) {
				closestDistance = dist;
				closestPawn = CurrentActor;
			}
		}
	}
	DWORD_PTR LOL;
	if (def::Aimbot)
	{
		if (isVisible(CurrentActorMesh))
		{
			if (keybind == 0)
			{
				if (closestPawn != 0)
				{
					if (closestPawn && GetAsyncKeyState(VK_RBUTTON))
					{
						if (def::Aimbot)
						{
							Vector3 hitbone = ProjectWorldToScreen(GetBoneWithRotation(def::hitbox, LOL));

							if (hitbone.x != 0 || hitbone.y != 0 || hitbone.z != 0)
							{
								if (def::Aimbot && closestPawn && GetAsyncKeyState(VK_RBUTTON) < 0) {
									AimAt(closestPawn);
								}
							}
						}
					}
				}

				else
				{
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
			}
		}
		else {}
		if (isVisible(CurrentActorMesh))
		{
			if (keybind == 1)
			{
				if (closestPawn != 0)
				{
					if (closestPawn && GetAsyncKeyState(VK_LBUTTON))
					{
						if (def::Aimbot)
						{
							Vector3 hitbone = ProjectWorldToScreen(GetBoneWithRotation(def::hitbox, LOL));

							if (hitbone.x != 0 || hitbone.y != 0 || hitbone.z != 0)
							{
								if (def::Aimbot && closestPawn && GetAsyncKeyState(VK_LBUTTON) < 0) {
									AimAt(closestPawn);
								}
							}
						}
					}
				}
				else
				{
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
			}
		}
		else {}
		if (isVisible(CurrentActorMesh))
		{
			if (keybind == 2)
			{
				if (closestPawn != 0)
				{
					if (closestPawn && GetAsyncKeyState(VK_LSHIFT))
					{
						if (def::Aimbot)
						{
							Vector3 hitbone = ProjectWorldToScreen(GetBoneWithRotation(def::hitbox, LOL));

							if (hitbone.x != 0 || hitbone.y != 0 || hitbone.z != 0)
							{
								if (def::Aimbot && closestPawn && GetAsyncKeyState(VK_LSHIFT) < 0) {
									AimAt(closestPawn);
								}
							}
						}
					}
				}
				else
				{
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
			}
		}
		else {}
	}
}

struct tab_anim
{
	int hovered_anim;
	int active_anim;
};

bool custom_interface::tab(const char* label, bool selected)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	ImVec2 pos = window->DC.CursorPos;

	const ImRect rect(pos, ImVec2(pos.x + 50, pos.y + 50));
	ImGui::ItemSize(ImVec4(rect.Min.x, rect.Min.y, rect.Max.x, rect.Max.y + 5), style.FramePadding.y);
	if (!ImGui::ItemAdd(rect, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(rect, id, &hovered, &held, NULL);

	static std::map <ImGuiID, tab_anim> anim;
	auto it_anim = anim.find(id);
	if (it_anim == anim.end())
	{
		anim.insert({ id, {0, 0} });
		it_anim = anim.find(id);
	}

	if (hovered)
		it_anim->second.hovered_anim += 8 * (1.f - ImGui::GetIO().DeltaTime);
	else
		it_anim->second.hovered_anim -= 8 * (1.f - ImGui::GetIO().DeltaTime);

	if (it_anim->second.hovered_anim > 50)
		it_anim->second.hovered_anim = 50;
	else if (it_anim->second.hovered_anim < 0)
		it_anim->second.hovered_anim = 0;

	if (selected)
		it_anim->second.active_anim += 16 * (1.f - ImGui::GetIO().DeltaTime);
	else
		it_anim->second.active_anim -= 16 * (1.f - ImGui::GetIO().DeltaTime);

	if (it_anim->second.active_anim > 155)
		it_anim->second.active_anim = 155;
	else if (it_anim->second.active_anim < 0)
		it_anim->second.active_anim = 0;

	window->DrawList->AddText(ImVec2(rect.Min.x + 25, rect.Min.y + 25), ImColor(255, 255, 255, 100 + it_anim->second.hovered_anim + it_anim->second.active_anim), label);

	return pressed;
}

struct subtab_anim
{
	int active_text_anim;
	int active_rect_alpha;
};

bool custom_interface::subtab(const char* label, bool selected)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	ImVec2 pos = window->DC.CursorPos;

	const ImRect rect(pos, ImVec2(pos.x + label_size.x, pos.y + 20));
	ImGui::ItemSize(ImVec4(rect.Min.x, rect.Min.y, rect.Max.x + 2.f, rect.Max.y), style.FramePadding.y);
	if (!ImGui::ItemAdd(rect, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(rect, id, &hovered, &held, NULL);

	static std::map <ImGuiID, subtab_anim> anim;
	auto it_anim = anim.find(id);
	if (it_anim == anim.end())
	{
		anim.insert({ id, {0, 0} });
		it_anim = anim.find(id);
	}

	if (selected)
		it_anim->second.active_text_anim += 16 * (1.f - ImGui::GetIO().DeltaTime);
	else
		it_anim->second.active_text_anim -= 16 * (1.f - ImGui::GetIO().DeltaTime);

	if (it_anim->second.active_text_anim > 155)
		it_anim->second.active_text_anim = 155;
	else if (it_anim->second.active_text_anim < 0)
		it_anim->second.active_text_anim = 0;

	if (selected)
		it_anim->second.active_rect_alpha += 20 * (1.f - ImGui::GetIO().DeltaTime);
	else
		it_anim->second.active_rect_alpha -= 20 * (1.f - ImGui::GetIO().DeltaTime);

	if (it_anim->second.active_rect_alpha > 255)
		it_anim->second.active_rect_alpha = 255;
	else if (it_anim->second.active_rect_alpha < 0)
		it_anim->second.active_rect_alpha = 0;

	window->DrawList->AddRectFilled(ImVec2(rect.Min.x, rect.Min.y + 22), ImVec2(rect.Max.x, rect.Max.y), ImColor(100, 108, 252, it_anim->second.active_rect_alpha));
	window->DrawList->AddText(ImVec2((rect.Min.x + rect.Max.x) / 2.f - (label_size.x / 2.f), (rect.Min.y + rect.Max.y) / 2.f - (label_size.y / 2.f) - 5), ImColor(255, 255, 255, (100 + it_anim->second.active_text_anim)), label);

	return pressed;
}
void render() {
	switch (keybind)
	{
	case 0:
		def::aimkeypos = 1;
		break;
	case 1:
		def::aimkeypos = 0;
		break;
	case 2:
		def::aimkeypos = 2;
		break;
	}
	if (RenderOption == 0)
	{
		fovcirclefilled = false;
		square_fov = false;
		fovcircle = true;
		SquareFovFilled = false;
	}
	if (RenderOption == 1)
	{
		fovcircle = false;
		fovcirclefilled = false;
		square_fov = true;
		SquareFovFilled = false;
	}
	if (RenderOption == 2)
	{
		square_fov = false;
		fovcircle = false;
		fovcirclefilled = true;
		SquareFovFilled = false;
	}
	if (RenderOption == 3)
	{
		square_fov = false;
		fovcircle = false;
		fovcirclefilled = false;
		SquareFovFilled = true;
	}
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (GetAsyncKeyState(VK_F2) & 1) {  // 0x2D = Insert
		ShowMenu = !ShowMenu;

	}
	if (ShowMenu)
	{






		ImGui::SetNextWindowSize(ImVec2(520, 395));

		static int selected = 0;
		static int sub_selected = 0;

		static bool bullying = false;
		static bool bullythosemfs = false;
		static bool stopbullythemyoushitters = false;
		static bool stop = false;
		static bool niggas = false;
		static bool hihihi = false;
		static bool bro = false;
		static int sliderinc = 0;
		static int combo = 0;
		const char* combo_items[4] = { "head", "chest", "legs", "feet" };
		static float color[4] = { 1.f, 1.f, 1.f, 1.f };

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			/*ImGui::SetNextWindowSize(ImVec2(530.000f, 340.000f), ImGuiCond_Once);*/
			ImGui::Begin("pandora-gui", nullptr, ImGuiWindowFlags_NoDecoration);
			{
				auto draw = ImGui::GetWindowDrawList();
				ImVec2 pos = ImGui::GetWindowPos();
				ImVec2 size = ImGui::GetWindowSize();

				draw->AddRectFilled(pos, ImVec2(pos.x + 55, pos.y + size.y), ImColor(20, 20, 20, 255)); // left rect
				draw->AddRectFilled(ImVec2(pos.x + 55, pos.y), ImVec2(pos.x + size.x, pos.y + 35), ImColor(20, 20, 20, 255)); // upper rect

				draw->AddLine(ImVec2(pos.x + 55, pos.y + 35), ImVec2(pos.x + size.x, pos.y + 35), ImColor(255, 255, 255, 15)); // upper line
				draw->AddLine(ImVec2(pos.x + 55, pos.y), ImVec2(pos.x + 55, pos.y + size.y), ImColor(255, 255, 255, 15)); // left line
				ImGui::SetCursorPos(ImVec2(-1, 11));
				ImGui::BeginGroup();
				if (custom_interface::tab("Aim", 0 == selected)) {
					selected = 0; sub_selected = 0;
				}
				if (custom_interface::tab("Esp", 1 == selected)) {
					selected = 1; sub_selected = 2;
				}
				if (custom_interface::tab("Soon", 7 == selected)) {
					selected = 7;
				}
				ImGui::EndGroup();

				if (selected == 0) {
					ImGui::BeginGroup();
					ImGui::SetCursorPos(ImVec2(65, 14));
					if (custom_interface::subtab("Aimbot", 0 == sub_selected)) {
						sub_selected = 0;
					}
					ImGui::EndGroup();


					if (sub_selected == 0) {
						ImGui::SetCursorPos(ImVec2(65, 44));
						ImGui::BeginChild("Aim Assistance", ImVec2(219, 342));
						{
							ImGui::Checkbox("Aimbot", &def::Aimbot);
							ImGui::Checkbox("Show Fov", &circletype);
							ImGui::SliderInt("Smooth", &Smoothness, 1, 20, "%d", ImGuiSliderFlags_NoInput);
							ImGui::SliderInt("Aim Distance", &def::VisDist, 1, 275, "%d", ImGuiSliderFlags_NoInput);
							ImGui::SliderInt("Fov Size", &def::AimbotFov, 10, 200, "%d", ImGuiSliderFlags_NoInput);
							ImGui::Combo(skCrypt("Aim Key"), &keybind, skCrypt("Right Mouse\0Left Mouse\0LShift\0"));
							ImGui::Combo(skCrypt("Aimbone"), &def::hitboxpos, hitboxes, sizeof(hitboxes) / sizeof(*hitboxes));
						}
						ImGui::EndChild();

					}
				}

				if (selected == 1) {
					ImGui::BeginGroup();
					ImGui::SetCursorPos(ImVec2(65, 14));
					if (custom_interface::subtab("Players", 2 == sub_selected)) {
						sub_selected = 2;
					}
					ImGui::SameLine();

					ImGui::EndGroup();

					static bool name = false;
					static bool distance = false;
					static bool nigggers = false;
					static bool espiguess = false;
					if (sub_selected == 2) {
						ImGui::SetCursorPos(ImVec2(65, 44));
						ImGui::BeginChild("Visuals", ImVec2(219, 342));
						{
							ImGui::SliderInt("Esp distance", &def::VisDist, 1, 275, "%d", ImGuiSliderFlags_NoInput);
							ImGui::Checkbox("Enable 2D Box", &BoxEsp);
							ImGui::Checkbox("Enable 3D Box", &ThreeDBoxEsp);
							ImGui::Checkbox("Enable Distance", &PlayerDistanceEsp);
							//ImGui::SliderInt("Chance prefering baim", &sliderinc, 0, 100, "%d%%", ImGuiSliderFlags_NoInput);
							//ImGui::Combo("Hitboxes", &combo, combo_items, 4);
							//ImGui::Button("cl_fullupdate callback", ImVec2(199, 22));
						}
						ImGui::EndChild();

						ImGui::SetCursorPos(ImVec2(291, 44));
						ImGui::BeginChild("Preview", ImVec2(219, 342), ImGuiWindowFlags_NoScrollbar);
						{
							if (BoxEsp == true) {
								ImGui::SetCursorPos(ImVec2(57, 65));
								ImVec2 pos1 = ImGui::GetCursorScreenPos();
								draw->AddRect(ImVec2(pos1.x, pos1.y), ImVec2(pos1.x + 100, pos1.y + 175), ImColor(0, 173, 237), 5.0f, 15);

							}

						}

						ImGui::EndChild();
						if (selected == 7) {
							ImGui::BeginGroup();
							ImGui::SetCursorPos(ImVec2(65, 14));
							if (custom_interface::subtab("Aimbot", 7 == sub_selected)) {
								sub_selected = 7;
							}
							ImGui::EndGroup();


							if (sub_selected == 7) {
								ImGui::SetCursorPos(ImVec2(65, 44));
								ImGui::BeginChild("Aim Assistance", ImVec2(219, 342));
								{
									ImGui::Checkbox("Aimbot", &def::Aimbot);
									ImGui::Checkbox("Show Fov", &CloseAimfov);
									ImGui::SliderInt("Smooth", &Smoothness, 0, 20, "%d", ImGuiSliderFlags_NoInput);
									ImGui::SliderInt("Aim Distance", &def::VisDist, 1, 275, "%d", ImGuiSliderFlags_NoInput);
									ImGui::SliderInt("Fov Size", &def::CAimbotFov, 10, 300, "%d", ImGuiSliderFlags_NoInput);
								}
								ImGui::EndChild();

							
						
								

							}
						}
					}

				}
			}
			ImGui::End();
		}

	}

	DrawESP();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

D3DPRESENT_PARAMETERS p_Params = { NULL };
HRESULT DirectXInit(HWND hWnd)
{
	//hide_thread(LI_FN(GetCurrentThread).get()());
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		LI_FN(exit).get()(3);

	RtlSecureZeroMemory(&p_Params, sizeof(p_Params));
	p_Params.Windowed = TRUE;
	p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	p_Params.hDeviceWindow = hWnd;
	p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	p_Params.BackBufferWidth = Width;
	p_Params.BackBufferHeight = Height;
	p_Params.EnableAutoDepthStencil = TRUE;
	p_Params.AutoDepthStencilFormat = D3DFMT_D16;
	p_Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;




	p_Object->Release();
	return S_OK;
}
HWND hijacked_hwnd{};

MSG Message = { NULL };
int Loop = 0;
void xMainLoop()
{
	MSG Message;
	RtlZeroMemory(&Message, sizeof(Message));
	DirectXInit(hijacked_hwnd);
	while ((Message.message != WM_QUIT) /* && (dt_info->tm_mday == DAY) */)
	{
		if (PeekMessageA(&Message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessageA(&Message);
			continue;
		}
		HWND hwnd_active = GetForegroundWindow();
		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT rc;
		POINT xy;
		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = NULL;
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	DestroyWindow(Window);
}
