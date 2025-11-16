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

![ZGloom renderer comparison – old vs fixed renderer](https://private-user-images.githubusercontent.com/11447150/514821611-b4a6257f-c72f-4581-9a2c-28d241b90741.png)

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

```text
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