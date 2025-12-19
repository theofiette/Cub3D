# Cub3D

[![C](https://img.shields.io/badge/language-C-555?style=flat-square&logo=c)](https://www.gnu.org/software/gnu-c-manual/)
![License](https://img.shields.io/badge/license-Educational-lightgrey?style=flat-square)

A minimal 3D first-person shooter game in C, focusing on low-level graphics programming, raycasting, and real-time simulation.

This project reproduces a basic 3D environment inspired by Wolfenstein 3D, including textured walls, floors and ceilings, interactive doors, and simple enemy AI, while emphasizing performance.

---

## Technical Overview

### Features

- 3D rendering using raycasting and DDA (Digital Differential Analyzer)
- Textured walls, floors, ceilings, and sprites
- Interactive doors with smooth opening/closing animation
- Zombie enemies with simple AI:
  - Random movement
  - Targeting the player
  - Collision detection
  - Health
  - Animation
- Player mechanics:
  - Movement with acceleration, deceleration, and collision detection
  - Shooting with bullets and ammo system
  - Head bob effect
- HUD:
  - Crosshair
  - Gun animation and gunshot effect
  - Health and ammo indicators
- Minimap
- Frame-rate independent movement and animations (using delta time)

### Architecture

Cub3D is organized as a layered C application:

- **Parsing** : `parsing.h`
  - Reads map files
  - Loads textures
  - Validates map and color formats
- **Graphics** : `graphic.h`
  - Raycasting engine (DDA)
  - Floor and ceiling rendering
  - Sprite rendering with billboarding
  - HUD and minimap rendering
- **Logic** : `logic.h`
  - Player movement and rotation
  - Input handling (keyboard and mouse)
  - Enemy AI (simple)
  - Door interaction and animation
  - Shooting and collision detection
- **Utilities** : `utils.h`
  - Memory management
  - Vector math and rotation functions
  - Color manipulation and shading

---

### Memory Management

- All dynamic allocations are tracked and freed on exit
- Textures, maps, and image buffers are carefully cleaned
- Use of inline functions and static buffers to minimize runtime allocations

---

## Build & Run

### Requirements
- Linux system
- `minilibx` library with X11 support (downloaded during compiation)
- 
> Note: Cub3D has been developed and tested on **Ubuntu 22.04 LTS**.  
> The project is Linux-only and relies on X11/MinilibX for rendering, which allows efficient single-threaded 3D raycasting.

### Compilation
`make`

### Run
`./cub3d <map_file.cub>`
ex : `./cub3d kino.cub`

---

## Controls

- **W** : Move forward  
- **S** : Move backward  
- **A** : Move left  
- **D** : Move right  
- **Mouse** : Rotate view  
- **Left Click** : Shoot  
- **Right Click** : Reload  

---

## More

### Collaboration

This project was developed collaboratively by:
- Theo Fiette / tfiette
- Teo Chevallier / tcheval

### Educational Context

This project was developed as part of a programming curriculum (42 Paris) and aims to demonstrate:

- Real-time 3D rendering using raycasting
- Collision detection and simple AI
- Efficient memory and resource management
- Clean architecture and maintainable C code

> Note: This project is for educational purposes. It is not intended as a commercial game but as a hands-on learning experience for low-level graphics programming and game logic.

- Some textures and sprites used in this project were sourced from external repositories for educational purposes only.
- Textures were edited and created using Krita and Blender.
- Original sources:
  - [textures.com](https://www.textures.com/download/3d-scanned-soviet-wall-tiles-15x15-meters/141127)
  - [mixamo.com](https://www.mixamo.com/#/?page=1&query=zombie&type=Character)
