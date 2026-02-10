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

## Window Events

It is implemented the tracking of some window events, as resize, mouse move, mouse button press/release, and keyboard button press/release.

### Window Resize

Afer the window is open, you can resize it as you see fit.

## MLX Abstraction

There are a good abstraction of minilibx features, as some events and functions.


## Multithreaded Rendering Module

This module implements a **parallel rendering model based on worker threads**, coordinated by a **main orchestrator thread**, ensuring deterministic frame rendering and safe handling of global events such as *window resizing*.

The architecture is designed to:

* maximize parallelism in *ray tracing*,
* avoid race conditions during critical events,
* maintain precise synchronization between threads on a per-frame basis.

### The Module Implements:

* Efficient parallelism for ray tracing workloads.
* Safe and deterministic handling of global events.
* No need for thread recreation.
* Extensible architecture for additional synchronization events.


