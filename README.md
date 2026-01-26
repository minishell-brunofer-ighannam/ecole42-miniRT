# miniRT

An École 42 project which objective is to reproduce the Ray Tracing Protocol

## Setup

Install de X11 dependencies

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install libx11-dev libxext-dev libbsd-dev -y
```

Run with params to choose a window size.

```bash
make re && ./miniRT <window-width> <window-height>
```

Or run with no params to create a default 500X500 window

```bash
make re && ./miniRT
```

## Window Resize

Afer the window is open, you can resize it as you see fit.

## Window Events

It is implemented the tracking of some window events, as resize, mouse move, mouse button press/release, and keyboard button press/release.

## MLX Abstraction

There are a good abstraction of minilibx features, as some events and functions.
