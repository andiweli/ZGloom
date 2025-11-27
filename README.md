# ZGloom-x86 – Modern Amiga Gloom port for Windows (x86)

Modern Windows (x86) port of the **ZGloom** engine that reimplements the classic Amiga FPS **Gloom** and its successors for contemporary PCs.

> Play Gloom, Gloom Deluxe, Gloom 3 and Zombie Massacre on Windows with a fixed renderer, widescreen support, post-processing overlays and save/load position – while staying faithful to the original Amiga gameplay.

[![Latest release](https://img.shields.io/github/v/release/andiweli/ZGloom-x86?label=latest%20release)](https://github.com/andiweli/ZGloom-x86/releases/latest)
[![Platform](https://img.shields.io/badge/platform-Windows%20(x86)-blue.svg)](https://github.com/andiweli/ZGloom-x86)
[![Engine](https://img.shields.io/badge/engine-SDL2%20%2B%20LibXMP-brightgreen.svg)](https://github.com/andiweli/ZGloom-x86)

ZGloom-x86 is the Windows edition of the ZGloom source-port family. It focuses on a clean software-style renderer, extended in-game options and subtle post-processing while preserving the original feel of the Amiga release.

For other platforms, see the companion projects [ZGloom-Android](https://github.com/Andiweli/ZGloom-Android), [ZGloom-Vita-Vita2D (PS Vita / PSTV)](https://github.com/Andiweli/ZGloom-Vita-Vita2D) and [ZGloom-macOS](https://github.com/Andiweli/ZGloom-macOS).

---

## 🕹 What is Gloom?

[Gloom](https://en.wikipedia.org/wiki/Gloom_(video_game)) was a 1995 Doom-like first-person shooter from **Black Magic Software** for the Commodore Amiga. It featured very messy and meaty graphics and required a powerful Amiga at the time (an A1200 with 030 CPU was still on the low end). The engine later powered several related games and successors, including:

- **Gloom Deluxe / Ultimate Gloom** – enhanced graphics and effects  
- **Gloom 3**  
- **Zombie Massacre**  
- Various full-game conversions of other 90’s Amiga titles

ZGloom is a modern reimplementation of this engine.

---

## ✨ Key Features

- Modern source port of the Amiga Gloom engine  
  Runs the original Gloom data files on modern Windows PCs (x86) using the modern ZGloom C++ engine.

- Supports multiple official games  
  Play **Gloom**, **Gloom Deluxe / Ultimate Gloom**, **Gloom 3** and **Zombie Massacre** (plus selected mods where available).

- Built-in multi-game launcher  
  If more than one game or mod is present, a simple launcher lets you pick what to play at startup.

- 4:3 and 16:9 display modes with FOV control  
  Switch between the classic 4:3 Amiga look and a widescreen 16:9 mode and adjust the field of view to match your display and taste.

- Improved renderer, lighting and effects  
  Uses the fixed ZGloom renderer with cleaner perspective, fewer glitches and subtle lighting tweaks, including dynamic muzzle flashes and colored floor reflections under projectiles and weapon upgrade orbs.

- Atmospheric post-processing overlays (optional)  
  Enable vignette, film grain and scanlines for a more gritty, CRT-style presentation without changing gameplay.

- Save/Load position and extended options  
  Save your in-level position (including health, weapon and ammo state) and tweak many more options than in the original Amiga release.

---

## 🖼️ Gameplay-Video and Screenshots

https://github.com/user-attachments/assets/ec227046-16db-4989-b374-e137fc0af27c

<img width="1280" height="1440" alt="Gloom-Screenshots" src="https://github.com/user-attachments/assets/4af921eb-7276-497b-b759-122b9ccacebf" />

---

## 📦 Download

Get the latest Windows (x86) build here:

👉 **[Latest ZGloom release](https://github.com/andiweli/ZGloom-x86/releases/latest)**

Each release contains the `ZGloom.exe` and required libraries.  
Game-data is included.

---

## 🚀 Getting Started

Gloom was made freely available by its developers.  
Download the game and extract it somewhere on your drive.
Then simply double-click `ZGloom.exe` to start the game and the launcher appears.

---

## 🎮 Default Controls

Keyboard controls in ZGloom:

- **WASD** – Move and turn  
- **Left Alt** – Strafe  
- **Left Ctrl** – Fire
- **Left Shift** - Run
- **F1** – Skip level  
- **F12** – Toggle fullscreen  
- **ESC** – Pause and open the in-game menu

The extended menu offers more options than the original game and port.  
You can change values with the **left/right arrow keys** (for example for fullscreen, vignette, film grain, scanlines, and other display options).

---

## 🛠 Building from source (Windows)

This repository is currently set up to be built with **Microsoft Visual Studio 2026** on Windows.  
Linux, macOS, CMake- or make-based builds are **not** tested at this time.

The project is structured around the **MSVC toolchain** and Visual Studio project/solution files, so the recommended workflow is:

1. Install **Visual Studio 2026** with the **“Desktop development with C++”** workload.
2. Clone this repository to your PC (working SDL2 and SDL2_Mixer are included in this repo).
3. Open the provided Visual Studio solution (or create a new one and add the sources from this repo).
4. Select a configuration (for example `Release` / `x86`) and build the solution.
5. Copy your original **Gloom** game data next to the compiled executable as described above in the *Getting Started* section.

If you want to experiment with other platforms or compilers (e.g. gcc/clang on Linux), you will currently need to:

- create your own build system files (CMake, Meson, custom Makefiles, etc.),
- and handle any platform-specific fixes yourself.

Clean, optional contributions that add a **portable build setup** without breaking the existing Visual Studio workflow are very welcome.

---

## 🛠️ About This Fork

This repository is a fork of **Swizpig/ZGloom**.  
The goal of this fork is to:

- Fix the renderer using improvements from the PSVITA SDL version  
- Enhance menu navigation and keyboard usability  
- Add post-processing overlays (vignette, film grain, scanlines)  
- Provide a polished Windows (x86) build with its own executable icon

If you enjoy retro Amiga FPS games and want a modern Windows port of **Gloom**, this fork aims to be a convenient, visually enhanced option.

---

## 📜 License & Third-Party Code

The licensing situation around the original Gloom sources is a bit unusual:

> The Gloom source release says only the `.s` and `.bb2` files are open source, but the Gloom executable bakes in some maths lookup tables (generated by the `.bb2` files), bullet and sparks graphics, and the title screen for Classic Gloom.

This fork follows the original release and does **not** add the Classic Gloom executable assets (title screen etc.).  
Instead, it uses alternative imagery such as the Black Magic image.

### Libraries Used

- **LibXMP** – MED / module playback  
  – <http://xmp.sourceforge.net/>  
- **SDL2** and **SDL2_mixer** – Cross-platform media and audio  
  – <https://www.libsdl.org/>  
- **DeCrunchmania** C code by Robert Leffman (license unknown)  
  – <http://aminet.net/package/util/pack/decrunchmania_os4>

---

## 🙌 Credits

- Original **Gloom** game and assets by its original Amiga developers  
- Original PC reimplementation by **Swizpig**  
- This fork and Windows renderer & overlay work by **Andiweli**
- background ambience credit goes to Prophet

**Keywords / Topics:**  
_amiga • gloom • vita • psvita • windows • x86 • android • macos • homebrew • zgloom • gloomdeluxe • zombiemassacre • sdl • libxmp • vita2d • ps tv shooter_

If you enjoy it, feel free to ⭐ star the repo so other PS Vita & Amiga fans can find it more easily.
