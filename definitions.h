#include <Windows.h>
#include <iostream>

namespace def
{
	// Aimbot Definition's
	bool Aimbot = false;
	static int aimkey;
	static int hitbox;
	static int AimbotFov = 150;
	static int CAimbotFov = 150;
	static int VisDist = 100;
	static int aimkeypos = 1;
	static int hitboxpos = 0;

}
namespace custom_interface {
	bool tab(const char* label, bool selected);
	bool subtab(const char* label, bool selected);
}
static int selected = 0;
static int sub_selected = 0;
// Fov - Crosshair - AimKey
static int fovcircle = false;
static int square_fov = false;
bool crosshair = false;
static int fovcirclefilled = false;
bool circletype = false;
bool CloseAimfov = false;
int keybind = 0;
bool SquareFovFilled = false; 
int CrosshairSize = 0;


// Esp
bool SelfEsp = false;
bool Esp = true;
bool CornerBoxEsp = false;
bool ThreeDBoxEsp = false;
bool BoxEsp = false;
bool TriangleEsp = false;
bool PlayerDistanceEsp = false;
bool Snaplines = false;
bool drawbase = true;
bool slefESP = false;
bool fillbox = false;
bool thick = false;
float BoxWidthValue = 0.300;
int LineThinkness = 1;
int Boxthinkness = 1.8;
float ChangerFOV = 80;
bool Skeleton = false;

// Other
int RenderOption = 0;
int tab;
bool WindowStreamProof = false;
bool targetingcheck = false;







// Menu
bool ShowMenu = true;
