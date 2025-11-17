#include "menuscreen.h"
#include "config.h"
#include "ConfigOverlays.h"
#include "MenuAdapters.h"
#include "cheats/CheatSystem.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>


// ---- Local loader for cheats.txt (no dependency on Cheats::Load) ---------
static bool g_CheatsLoadedOnce = false;

static inline void trim(std::string& s) {
    auto notspace = [](int ch){ return !std::isspace(ch); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), notspace));
    s.erase(std::find_if(s.rbegin(), s.rend(), notspace).base(), s.end());
}
static inline std::string upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return (char)std::toupper(c); });
    return s;
}

static void EnsureCheatsLoaded() {
    if (g_CheatsLoadedOnce) return;
    g_CheatsLoadedOnce = true;
    std::ifstream in("cheats.txt");
    if (!in) return;
    std::string line;
    while (std::getline(in, line)) {
        // strip comments
        auto sc = line.find_first_of(";#");
        if (sc != std::string::npos) line = line.substr(0, sc);
        trim(line);
        if (line.empty()) continue;
        auto eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string k = upper(line.substr(0, eq));
        std::string v = upper(line.substr(eq+1));
        trim(k); trim(v);

        auto isOn = [&](const std::string& s)->bool { return (s=="1" || s=="ON" || s=="TRUE"); };
        auto toInt = [&](const std::string& s)->int { try { return std::stoi(s); } catch(...) { return 0; } };

        if (k == "GOD") { Cheats::SetGodMode(isOn(v)); }
        else if (k == "ONEHIT" || k == "ONEHITKILL") { Cheats::SetOneHitKill(isOn(v)); }
        else if (k == "THERMO" || k == "THERMOGOGGLES") { Cheats::SetThermoGoggles(isOn(v)); }
        else if (k == "BOUNCY" || k == "BOUNCYBULLETS") { Cheats::SetBouncyBullets(isOn(v)); }
        else if (k == "INVIS" || k == "INVISIBILITY") { Cheats::SetInvisibility(isOn(v)); }
        else if (k == "STARTWEAPON" || k == "WEAPON") { Cheats::SetStartWeapon(toInt(v)); }
        // silently ignore unknown keys
    }
}






// --- Cheat wrappers (persist on change) ------------------------------------
static int MenuGetCheatGodMode() { EnsureCheatsLoaded(); return Cheats::GetGodMode() ? 1 : 0; }
static void MenuSetCheatGodMode(int on) { Cheats::SetGodMode(on != 0); Cheats::Save(); }

static int MenuGetCheatOneHitKill() { EnsureCheatsLoaded(); return Cheats::GetOneHitKill() ? 1 : 0; }
static void MenuSetCheatOneHitKill(int on) { Cheats::SetOneHitKill(on != 0); Cheats::Save(); }

static int MenuGetCheatThermo() { EnsureCheatsLoaded(); return Cheats::GetThermoGoggles() ? 1 : 0; }
static void MenuSetCheatThermo(int on) { Cheats::SetThermoGoggles(on != 0); Cheats::Save(); }

static int MenuGetCheatBouncy() { EnsureCheatsLoaded(); return Cheats::GetBouncyBullets() ? 1 : 0; }
static void MenuSetCheatBouncy(int on) { Cheats::SetBouncyBullets(on != 0); Cheats::Save(); }

static int MenuGetCheatInvis() { EnsureCheatsLoaded(); return Cheats::GetInvisibility() ? 1 : 0; }
static void MenuSetCheatInvis(int on) { Cheats::SetInvisibility(on != 0); Cheats::Save(); }

// Start weapon: 0..4 fixed, 5 = DEFAULT
static int MenuGetCheatStartWeapon() { EnsureCheatsLoaded(); return Cheats::GetStartWeapon(); }
static void MenuSetCheatStartWeapon(int idx) { Cheats::SetStartWeapon(idx); Cheats::Save(); }

#ifndef MENUSTATUS_CHEATOPTIONS
#define MENUSTATUS_CHEATOPTIONS 106
#endif



// ---- Vignette Warmth Bool Mapping (ON=WARM, OFF=COLD) ----------------------
static int MenuGetVignetteWarmthBool() {
    int v = MenuAdapters::GetWarmth01();
    return (v >= 6) ? 1 : 0; // ON -> COLD (1), OFF -> WARM (0)
}
static void MenuSetVignetteWarmthBool(int on) {
    if (on) { MenuAdapters::SetWarmth01(8); } else { MenuAdapters::SetWarmth01(3); }
}


void MenuScreen::Render(SDL_Surface* src, SDL_Surface* dest, Font& font)
{
	SDL_BlitSurface(src, nullptr, dest, nullptr);
	bool flash = (timer / 5) & 1;

	int scale = dest->h / 256;
	if (scale < 1) scale = 1;

	if (status == MENUSTATUS_MAIN)
	{
		DisplayStandardMenu(mainmenu, flash, scale, dest, font);
	}
	else if (status == MENUSTATUS_SOUNDOPTIONS)
	{
		DisplayStandardMenu(soundmenu, flash, scale, dest, font);
	}
	else if (status == MENUSTATUS_CONTROLOPTIONS)
	{
		DisplayStandardMenu(controlmenu, flash, scale, dest, font);
	}
	else if (status == MENUSTATUS_DISPLAYOPTIONS)
	{
		DisplayStandardMenu(displaymenu, flash, scale, dest, font);
	}
	else if (status == MENUSTATUS_CHEATOPTIONS)
	{
		static std::vector<MenuEntry> cheatmenu;
		cheatmenu.clear();
		cheatmenu.push_back(MenuEntry("RETURN", ACTION_SWITCHMENU, MENUSTATUS_MAIN, nullptr, nullptr));
		cheatmenu.push_back(MenuEntry("GOD MODE: ", ACTION_BOOL, 0, MenuGetCheatGodMode, MenuSetCheatGodMode));
		cheatmenu.push_back(MenuEntry("ONE HIT KILL: ", ACTION_BOOL, 0, MenuGetCheatOneHitKill, MenuSetCheatOneHitKill));
		cheatmenu.push_back(MenuEntry("BOUNCY BULLETS: ", ACTION_BOOL, 0, MenuGetCheatBouncy, MenuSetCheatBouncy));
		cheatmenu.push_back(MenuEntry("THERMO GOGGLES: ", ACTION_BOOL, 0, MenuGetCheatThermo, MenuSetCheatThermo));
		cheatmenu.push_back(MenuEntry("INVISIBILITY: ", ACTION_BOOL, 0, MenuGetCheatInvis, MenuSetCheatInvis));
		cheatmenu.push_back(MenuEntry("WEAPON: ", ACTION_INT, 6, MenuGetCheatStartWeapon, MenuSetCheatStartWeapon));
		DisplayStandardMenu(cheatmenu, flash, scale, dest, font);
	}
	else if (status == MENUSTATUS_KEYCONFIG)
	{
		switch (selection)
		{
			case Config::KEY_UP:
				font.PrintMessage("PRESS KEY FOR FORWARD", 120 * scale, dest, scale);
				break;
			case Config::KEY_DOWN:
				font.PrintMessage("PRESS KEY FOR BACK", 120 * scale, dest, scale);
				break;
			case Config::KEY_LEFT:
				font.PrintMessage("PRESS KEY FOR ROTATE LEFT", 120 * scale, dest, scale);
				break;
			case Config::KEY_RIGHT:
				font.PrintMessage("PRESS KEY FOR ROTATE RIGHT", 120 * scale, dest, scale);
				break;
			case Config::KEY_SLEFT:
				font.PrintMessage("PRESS KEY FOR STRAFE LEFT", 120 * scale, dest, scale);
				break;
			case Config::KEY_SRIGHT:
				font.PrintMessage("PRESS KEY FOR STRAFE RIGHT", 120 * scale, dest, scale);
				break;
			case Config::KEY_STRAFEMOD:
				font.PrintMessage("PRESS KEY FOR STRAFE MODIFIER", 120 * scale, dest, scale);
				break;
			case Config::KEY_RUN:
				font.PrintMessage("PRESS KEY FOR RUN", 120 * scale, dest, scale);
				break;
			case Config::KEY_SHOOT:
				font.PrintMessage("PRESS KEY FOR SHOOT", 120 * scale, dest, scale);
				break;
		}
	}
}

MenuScreen::MenuScreen()
{
	status = MENUSTATUS_MAIN;
	selection = 0;
	timer = 0;

	mainmenu.push_back(MenuEntry("CONTINUE", ACTION_RETURN, MENURET_PLAY, nullptr, nullptr));
	mainmenu.push_back(MenuEntry("CONTROL OPTIONS", ACTION_SWITCHMENU, MENUSTATUS_CONTROLOPTIONS, nullptr, nullptr));
	mainmenu.push_back(MenuEntry("SOUND OPTIONS", ACTION_SWITCHMENU, MENUSTATUS_SOUNDOPTIONS, nullptr, nullptr));
	mainmenu.push_back(MenuEntry("DISPLAY OPTIONS", ACTION_SWITCHMENU, MENUSTATUS_DISPLAYOPTIONS, nullptr, nullptr));
		mainmenu.push_back(MenuEntry("CHEAT OPTIONS", ACTION_SWITCHMENU, MENUSTATUS_CHEATOPTIONS, nullptr, nullptr));
// Halbzeile //
	mainmenu.push_back(MenuEntry("QUIT TO TITLE", ACTION_RETURN, MENURET_QUIT, nullptr, nullptr));

	soundmenu.push_back(MenuEntry("RETURN", ACTION_SWITCHMENU, MENUSTATUS_MAIN, nullptr, nullptr));
	soundmenu.push_back(MenuEntry("SFX VOLUME: ", ACTION_INT, 10, Config::GetSFXVol, Config::SetSFXVol));
	soundmenu.push_back(MenuEntry("MUSIC VOLUME: ", ACTION_INT, 10, Config::GetMusicVol, Config::SetMusicVol));

	controlmenu.push_back(MenuEntry("RETURN", ACTION_SWITCHMENU, MENUSTATUS_MAIN, nullptr, nullptr));
	controlmenu.push_back(MenuEntry("AUTOFIRE: ", ACTION_BOOL, 0, Config::GetAutoFire, Config::SetAutoFire));
	controlmenu.push_back(MenuEntry("CONFIGURE KEYS", ACTION_SWITCHMENU, MENUSTATUS_KEYCONFIG, nullptr, nullptr));
	controlmenu.push_back(MenuEntry("MOUSE SENSITIVITY: ", ACTION_INT, 10, Config::GetMouseSens, Config::SetMouseSens));

	displaymenu.push_back(MenuEntry("RETURN", ACTION_SWITCHMENU, MENUSTATUS_MAIN, nullptr, nullptr));
	displaymenu.push_back(MenuEntry("FULLSCREEN: ", ACTION_BOOL, 0, Config::GetFullscreen, Config::SetFullscreen));
	displaymenu.push_back(MenuEntry("MULTITHREAD RENDERER: ", ACTION_BOOL, 0, Config::GetMT, Config::SetMT));
	// Halbzeile //
	displaymenu.push_back(MenuEntry("BLOOD SIZE: ", ACTION_INT, 5, Config::GetBlood, Config::SetBlood));
	displaymenu.push_back(MenuEntry("MUZZLE FLASH: ", ACTION_BOOL, 0, Config::GetMuzzleFlash, Config::SetMuzzleFlash));
	// Halbzeile //
	displaymenu.push_back(MenuEntry("ATMOSPHERIC VIGNETTE: ", ACTION_BOOL, 0, Config::GetVignetteEnabled, Config::SetVignetteEnabled));
	displaymenu.push_back(MenuEntry("VIGNETTE STRENGTH: ", ACTION_INT, 6, Config::GetVignetteStrength, Config::SetVignetteStrength));
	displaymenu.push_back(MenuEntry("VIGNETTE RADIUS: ", ACTION_INT, 6, Config::GetVignetteRadius, Config::SetVignetteRadius));
	displaymenu.push_back(MenuEntry("VIGNETTE SOFTNESS: ", ACTION_INT, 6, Config::GetVignetteSoftness, Config::SetVignetteSoftness));
	displaymenu.push_back(MenuEntry("VIGNETTE WARMTH: ", ACTION_BOOL, 0, MenuGetVignetteWarmthBool, MenuSetVignetteWarmthBool));
	// Halbzeile //
	displaymenu.push_back(MenuEntry("FILM GRAIN: ", ACTION_BOOL, 0, Config::GetFilmGrain, Config::SetFilmGrain));
	displaymenu.push_back(MenuEntry("FILM GRAIN INTENSITY: ", ACTION_INT, 6, Config::GetFilmGrainIntensity, Config::SetFilmGrainIntensity));
	// Halbzeile //
	displaymenu.push_back(MenuEntry("SCANLINES: ", ACTION_BOOL, 0, Config::GetScanlines, Config::SetScanlines));
	displaymenu.push_back(MenuEntry("SCANLINE INTENSITY: ", ACTION_INT, 6, Config::GetScanlineIntensity, Config::SetScanlineIntensity));
}

void MenuScreen::HandleKeyMenu(SDL_Keycode sym)
{
	Config::SetKey((Config::keyenum)selection, SDL_GetScancodeFromKey(sym));
	selection++;
	if (selection == Config::KEY_END)
	{
		selection = 0;
		status = MENUSTATUS_MAIN;
	}
}

MenuScreen::MenuReturn MenuScreen::HandleStandardMenu(SDL_Keycode sym, std::vector<MenuEntry>& menu)
{
    switch (sym)
    {
    case SDLK_DOWN:
        // Auswahl nach unten (mit Wrap-Around)
        selection++;
        if (selection >= (int)menu.size())
            selection = 0;
        break;

    case SDLK_UP:
        // Auswahl nach oben (mit Wrap-Around)
        selection--;
        if (selection < 0)
            selection = (int)menu.size() - 1;
        break;

    case SDLK_ESCAPE:
        // ESC: im Hauptmenü zurück ins Spiel, sonst zurück ins Hauptmenü
        if (status == MENUSTATUS_MAIN)
        {
            return MENURET_PLAY;
        }
        else
        {
            status    = MENUSTATUS_MAIN;
            selection = 0;
        }
        break;

    // RECHTS (wie Enter): nächster Wert
    case SDLK_RIGHT:
    // und auch Space/Enter/Strg wie bisher
    case SDLK_SPACE:
    case SDLK_RETURN:
    case SDLK_LCTRL:
        switch (menu[selection].action)
        {
        case ACTION_BOOL:
        {
            // Toggle ON/OFF
            menu[selection].setval(!menu[selection].getval());
            break;
        }
        case ACTION_INT:
        {
            // Wert +1 mit Wrap-Around 0..arg-1
            int x = menu[selection].getval() + 1;
            if (x >= menu[selection].arg)
                x = 0;
            menu[selection].setval(x);
            break;
        }
        case ACTION_SWITCHMENU:
        {
            status    = (MENUSTATUS)menu[selection].arg;
            selection = 0;
            break;
        }
        case ACTION_RETURN:
        {
            return (MenuReturn)menu[selection].arg;
        }
        default:
            break;
        }
        break;

    // LINKS: vorheriger Wert (nur INT/BOOL)
    case SDLK_LEFT:
        if (menu[selection].action == ACTION_INT)
        {
            int x = menu[selection].getval() - 1;
            if (x < 0)
                x = menu[selection].arg - 1;
            menu[selection].setval(x);
        }
        else if (menu[selection].action == ACTION_BOOL)
        {
            // BOOL auch mit Links/Rechts toggeln
            menu[selection].setval(!menu[selection].getval());
        }
        break;

    default:
        break;
    }

    return MENURET_NOTHING;
}

MenuScreen::MenuReturn MenuScreen::Update(SDL_Event& tevent)
{
	if (tevent.type == SDL_KEYDOWN)
	{
		switch (status)
		{
		case MENUSTATUS_MAIN:
		{
			return HandleStandardMenu(tevent.key.keysym.sym, mainmenu);
			break;
		}
		case MENUSTATUS_KEYCONFIG:
		{
			HandleKeyMenu(tevent.key.keysym.sym);
			break;
		}

		case MENUSTATUS_SOUNDOPTIONS:
		{
			HandleStandardMenu(tevent.key.keysym.sym, soundmenu);
			break;
		}

		case MENUSTATUS_CONTROLOPTIONS:
		{
			HandleStandardMenu(tevent.key.keysym.sym, controlmenu);
			break;
		}

		case MENUSTATUS_DISPLAYOPTIONS:
		{
			HandleStandardMenu(tevent.key.keysym.sym, displaymenu);
			break;
		}
		case MENUSTATUS_CHEATOPTIONS:
		{
			static std::vector<MenuEntry> cheatmenu;
			cheatmenu.clear();
			cheatmenu.push_back(MenuEntry("RETURN", ACTION_SWITCHMENU, MENUSTATUS_MAIN, nullptr, nullptr));
			cheatmenu.push_back(MenuEntry("GOD MODE: ", ACTION_BOOL, 0, MenuGetCheatGodMode, MenuSetCheatGodMode));
			cheatmenu.push_back(MenuEntry("ONE HIT KILL: ", ACTION_BOOL, 0, MenuGetCheatOneHitKill, MenuSetCheatOneHitKill));
			cheatmenu.push_back(MenuEntry("BOUNCY BULLETS: ", ACTION_BOOL, 0, MenuGetCheatBouncy, MenuSetCheatBouncy));
			cheatmenu.push_back(MenuEntry("THERMO GOGGLES: ", ACTION_BOOL, 0, MenuGetCheatThermo, MenuSetCheatThermo));
			cheatmenu.push_back(MenuEntry("INVISIBILITY: ", ACTION_BOOL, 0, MenuGetCheatInvis, MenuSetCheatInvis));
			cheatmenu.push_back(MenuEntry("WEAPON: ", ACTION_INT, 6, MenuGetCheatStartWeapon, MenuSetCheatStartWeapon));
			HandleStandardMenu(tevent.key.keysym.sym, cheatmenu);
			break;
		}

		default:
			break;
		}
	}

	return MENURET_NOTHING;
}

void MenuScreen::DisplayStandardMenu(std::vector<MenuEntry>& menu, bool flash, int scale, SDL_Surface* dest, Font& font)
{
	int starty = 50 * scale;
	int yinc = 10 * scale;

	for (size_t i = 0; i < menu.size(); i++)
	{
		// Halbzeile: grafischer Abstand vor bestimmten Einträgen
		if (menu[i].name == "QUIT TO TITLE" ||
		    menu[i].name == "BLOOD SIZE: " ||
		    menu[i].name == "ATMOSPHERIC VIGNETTE: " ||
		    menu[i].name == "FILM GRAIN: " ||
		    menu[i].name == "SCANLINES: ")
		{
			starty += yinc / 2;
		}
		if (menu[i].action == ACTION_INT)
		{
			if (flash || (selection != i))
			{
				std::string menustring = menu[i].name;
				// Pretty names for WEAPON cheat (0..5)
				if (menustring.rfind("WEAPON", 0) == 0)
				{
					static const char* kWeaponNames[6] = {
						"PLASMA CANNON",
						"BLASTER UPGRADE",
						"BOOSTER UPGRADE",
						"ION UPGRADE",
						"PHOTON UPGRADE",
						"GAME DEFAULT"
					};
					int v = menu[i].getval();
					if (v < 0) v = 0;
					if (v > 5) v = 5;
					menustring += kWeaponNames[v];
				}
				else
				{
					menustring += std::to_string(menu[i].getval());
				}
				font.PrintMessage(menustring, starty, dest, scale);
			}
		}
		else if (menu[i].action == ACTION_BOOL)
		{
			if (flash || (selection != i))
			{
				std::string menustring = menu[i].name;
				if (menustring.rfind("VIGNETTE WARMTH", 0) == 0)
				{
					menustring += menu[i].getval() ? "WARM" : "COLD";
				}
				else
				{
					menustring += menu[i].getval() ? "ON" : "OFF";
				}
				font.PrintMessage(menustring, starty, dest, scale);
			}
		}
		else
		{
			if (flash || (selection != i)) font.PrintMessage(menu[i].name, starty, dest, scale);
		}
		starty += yinc * ((i==0)? 2 : 1);
	}
}