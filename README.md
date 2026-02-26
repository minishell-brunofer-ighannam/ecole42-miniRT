*This project was created as part of the 42 curriculum by ighannam and brunofer.*

# miniRT

## Description

**miniRT** is a minimal ray tracer developed in C as part of the 42 School curriculum.
The goal of the project is to implement the fundamental principles of ray tracing, including ray–object intersection, lighting models, shadows, reflections, and basic scene parsing.

The program reads a `.rt` scene description file and renders a 3D image using the Phong illumination model. The project focuses on understanding the mathematics behind computer graphics — especially vector algebra, geometric intersections, and light transport — while maintaining clean, modular, and efficient C code.

### Mandatory Features

* Ray–sphere, ray–plane, and ray–cylinder intersections
* Phong lighting model (ambient, diffuse, specular)
* Shadows
* Camera and viewport handling
* Scene parsing from `.rt` files
* Window display using MiniLibX
* Compilation with `make`

### Bonus Features

* Multi-threaded rendering for performance improvement
* Complete Phong lighting model (ambient, diffuse, specular) with reflexion
* Multi-lights with color other than white
* Cone intersections
* Checker pattern option
* Color and Normal maps
* In the bonus part, the restriction on allowed functions is lifted

---

## Instructions

### Requirements

* GCC or Clang
* Make
* MiniLibX (as required by 42 projects)

#### Setup

Install de X11 dependencies

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install libx11-dev libxext-dev libbsd-dev -y
```

### Compilation

**Mandatory version:**

```bash
make
```

**Bonus version:**

```bash
make bonus
```

### Usage

```bash
./miniRT scene.rt
```

```bash
./miniRT_bonus scene.rt
```

The program will open a window and render the scene described in the `.rt` file.
Check Template File in scene/template.rt for .rt instructions.

---

## Resources

### Primary References

* **Ray Tracing in One Weekend** — Peter Shirley
* **The Ray Tracer Challenge** — Jamis Buck
* 42 Linear Algebra specialization materials

### Video Resources

* [Ray Tracing Series - The Cherno](https://www.youtube.com/watch?v=gfW1Fhd9u9Q&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl)
* [Essence of linear algebra - 3blue1brown](https://www.youtube.com/watch?v=fNk_zzaMoSs&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
* [How does Ray Tracing Work in Video Games and Movies? - Branch Education](https://youtu.be/iOlehM5kNSk?si=LYFcXpZuUhfuV8zX)

### Additional Inspiration

The following repositories were consulted to understand expected behavior and scene ideas:

* [Ricardo Reves's git](https://github.com/ricardoreves/42-minirt)
* [Emran BinJamaan's git](https://github.com/Pastifier/miniRT)
* [Caroline Jun's git](https://github.com/juncaroline/42SP_miniRT)
* [Daniel's git](https://github.com/DanielSurf10/miniRT)

These were used strictly for reference and learning purposes.

---

## AI Usage

Artificial intelligence tools were used **only as development aids**, specifically for:

* Clarifying mathematical concepts (vector math, lighting equations, intersections)
* Reviewing theoretical doubts during development
* Assisting in the writing and structuring of this README

All core implementation, design decisions, and debugging were performed by the authors.

---
