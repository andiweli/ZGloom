# ZGloom - Modern Amiga **Gloom** Port for Windows (x86)

> Modernized reimplementation of the classic Amiga first-person shooter **Gloom** (including Gloom Deluxe, Gloom 3 and Zombie Massacre) for modern Windows PCs.

[![Latest release](https://img.shields.io/github/v/release/andiweli/ZGloom?label=latest%20release)](https://github.com/andiweli/ZGloom/releases/latest)
[![Platform](https://img.shields.io/badge/platform-Windows%20(x86)-blue.svg)](https://github.com/andiweli/ZGloom)
[![Engine](https://img.shields.io/badge/engine-custom%20software%20renderer-brightgreen.svg)](https://github.com/andiweli/ZGloom)

ZGloom is a modern Windows (x86) source port of the Amiga FPS **Gloom**.  
This fork focuses on an improved renderer, extended in-game options and subtle post-processing effects while staying faithful to the original look and gameplay.

---

## ✨ Key Features

- **Modern Windows port of Amiga Gloom**  
  Faithful software-rendered Windows (x86) version of the original Amiga FPS engine.

- **Built-in multi-game launcher**  
  If more than one game or mod is installed, a simple launcher lets you choose between **Gloom**, **Gloom Deluxe**, **Gloom 3**, **Zombie Massacre** or supported mods at startup.

- **4:3 / 16:9 display modes with FOV control**  
  Switch between classic 4:3 and widescreen 16:9 and adjust the **field of view** to match your display and taste.

- **Improved software renderer**  
  Cleaner perspective, fewer glitches and subtle polish compared to the original PC port.

- **Dynamic muzzle flash and projectile reflections**  
  Each shot briefly brightens the floor, and colored reflection ellipses are rendered under projectiles and weapon upgrade orbs, matching weapon type and upgrade level.

- **Optional post-processing overlays**  
  Configurable **vignette**, **film grain** and **scanlines** to add atmosphere without changing gameplay.

- **Save/Load position option**
  Saves your position in the game as well as weapon and ammo.

---

## 🖼️ Screenshots and Video

Comparison of the original renderer vs. the fixed ZGloom renderer:

![ZGloom renderer comparison – old vs fixed renderer](https://github.com/user-attachments/assets/b4a6257f-c72f-4581-9a2c-28d241b90741)

Menu options and visual overlays (vignette, film grain, scanlines):

![ZGloom menu and overlays – vignette, film grain and scanlines](https://github.com/user-attachments/assets/930e1f9f-0dea-470a-80f3-3b3e8ecf163c)

Game Preview video

https://github.com/user-attachments/assets/7e1427e0-9a1e-416a-b115-55faf4cbe8fa

---

## 📦 Download

Get the latest Windows (x86) build here:

👉 **[Latest ZGloom release](https://github.com/andiweli/ZGloom/releases/latest)**

Each release contains the `ZGloom.exe` and required libraries.  
You still need the original Gloom game data (see below).

---

## 🚀 Getting Started

### 1. Download the original Gloom data

Gloom was made freely available by its developers.  
Download the game data (for example the GloomAmiga archive) and extract it somewhere on your drive.

You can use data files from:

- **Gloom**
- **Gloom Deluxe**
- **Gloom 3**
- **Zombie Massacre**
- **several available mods***

### 2. Install ZGloom

1. Download the latest ZGloom release from GitHub.  
2. Extract the ZIP into a folder of your choice.  
3. Copy the extracted Gloom game data dirs into the same folder as `ZGloom.exe`.

Your final folder might look like this (example with **Gloom Deluxe**):

    ZGloom.exe
    libxmp.dll
    SDL2.dll
    SDL2_mixer.dll
    gloom/      (dir)
    deluxe/     (dir)
    gloom3/     (dir)
    massacre/   (dir)
    8bitkiller/ (dir)
    other mod/  (dir)

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

If you like the project, consider giving the repository a ⭐ star on GitHub – it helps other Amiga and retro-FPS fans discover ZGloom.
