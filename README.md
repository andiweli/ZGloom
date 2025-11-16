# ZGloom – Modern Amiga **Gloom** Port for Windows (x86)

> Modernized reimplementation of the classic Amiga first-person shooter **Gloom** (including Gloom Deluxe, Gloom 3 and Zombie Massacre) for modern Windows PCs.

[![Latest release](https://img.shields.io/github/v/release/andiweli/ZGloom?label=latest%20release)](https://github.com/andiweli/ZGloom/releases/latest)
[![Platform](https://img.shields.io/badge/platform-Windows%20(x86)-blue.svg)](https://github.com/andiweli/ZGloom)
[![Engine](https://img.shields.io/badge/engine-custom%20software%20renderer-brightgreen.svg)](https://github.com/andiweli/ZGloom)

ZGloom is a modern Windows (x86) source port of the Amiga FPS **Gloom**.  
This fork focuses on an improved renderer, extended in-game options and subtle post-processing effects while staying faithful to the original look and gameplay.

---

## ✨ Key Features

- 🖥️ **Fixed software renderer**  
  – Imported and adapted from the PSVITA SDL version  
  – More accurate perspective and fewer visual glitches than the original PC port

- 🎮 **Extended menu and keyboard navigation**  
  – ESC, arrow keys up/down and left/right work throughout the menu  
  – Additional video and effect options directly accessible in-game

- 🖼️ **Post-processing overlays**  
  – Atmospheric vignette options (radius, softness, strength, warmth)  
  – Optional film grain (with adjustable intensity)  
  – Optional scanlines (with adjustable intensity)

- 🧊 **Faithful Amiga Gloom experience on Windows**  
  – Runs the original Gloom data files  
  – Supports **Gloom**, **Gloom Deluxe**, **Gloom 3** and **Zombie Massacre** (depending on game data)

- 🔊 **In-game MOD music support**  
  – Uses LibXMP to play Amiga-style modules  
  – Per-level music possible via script commands (e.g. `song_blitz.mod`)

- 🧩 **Native Windows executable with icon**  
  – Includes a proper game icon for the `.EXE`  
  – Simple drag-and-play folder layout

---

## 🖼️ Screenshots

Comparison of the original renderer vs. the fixed ZGloom renderer:

![ZGloom renderer comparison – old vs fixed renderer](https://github.com/user-attachments/assets/b4a6257f-c72f-4581-9a2c-28d241b90741)

Menu options and visual overlays (vignette, film grain, scanlines):

![ZGloom menu and overlays – vignette, film grain and scanlines](https://private-user-images.githubusercontent.com/11447150/514820570-930e1f9f-0dea-470a-80f3-3b3e8ecf163c.png)

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

### 2. Install ZGloom

1. Download the latest ZGloom release from GitHub.  
2. Extract the ZIP into a folder of your choice.  
3. Copy the extracted Gloom game data into the same folder as `ZGloom.exe`.

Your final folder might look like this (example with **Gloom Deluxe**):

    ZGloom.exe
    libxmp.dll
    SDL2.dll
    SDL2_mixer.dll
    maps/   (dir)
    misc/   (dir)
    objs/   (dir)
    pics/   (dir)
    sfxs/   (dir)
    txts/   (dir)

Then simply double-click `ZGloom.exe` to start the game.

---

## 🎮 Default Controls

Keyboard controls in ZGloom:

- **Arrow keys** – Move and turn  
- **Left Alt** – Strafe  
- **Left Ctrl** – Fire  
- **F1** – Skip level  
- **F12** – Toggle fullscreen  
- **Print Screen** – Save a screenshot as bitmap  
- **ESC** – Pause and open the in-game menu

The extended menu offers more options than the original game and port.  
You can change values with the **left/right arrow keys** (for example for fullscreen, vignette, film grain, scanlines, and other display options).

---

## 🔊 In-game Music (MOD Support)

ZGloom can play in-game music using any module format supported by **LibXMP**.

1. Put your `.mod` (or other supported module) files in the `sfxs` folder.  
2. Add entries like this to the script (example):

    song_blitz.mod

You can add multiple `song_` commands, which allows **per-level music**.

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
- This fork and Windows renderer & overlay work by **andiweli**

If you like the project, consider giving the repository a ⭐ star on GitHub – it helps other Amiga and retro-FPS fans discover ZGloom.