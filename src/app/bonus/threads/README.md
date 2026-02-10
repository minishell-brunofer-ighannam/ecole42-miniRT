# Multithreaded Rendering Module

This module implements a **parallel rendering model based on worker threads**, coordinated by a **main orchestrator thread**, ensuring deterministic frame rendering and safe handling of global events such as *window resizing*.

The architecture is designed to:

* maximize parallelism in *ray tracing*,
* avoid race conditions during critical events,
* maintain precise synchronization between threads on a per-frame basis.

---

## Architectural Overview

The system is composed of two types of threads:

* **Main Thread**

  * Responsible for event processing, global state control, and final frame presentation.
  * Acts as the central synchronization point between frames.

* **Worker Threads**

  * Execute the heavy rendering workload (*ray tracing*).
  * Operate in parallel over independent regions of the image.

Communication and synchronization between threads are achieved through:

* `pthread_mutex_t`
* `pthread_cond_t`
* shared flow-control state counters

---

## Worker Thread Lifecycle

Each worker thread runs in a continuous loop while the application is active. This loop can be divided into **four main phases**.

### 1. Global State Validation and Cooperative Sleep

Before starting any processing, the thread checks whether a global invalid state exists (e.g., an ongoing *window resize*).

```text
- Detects global state changes
- Increments the sleeping thread counter
- Enters cooperative sleep via a condition variable
```

This guarantees that no thread performs rendering while the system is in an inconsistent state.

---

### 2. Work Chunk Recalculation

After resuming execution, the thread:

* validates that the process is still active,
* dynamically recalculates the pixel range (*render chunk*) it is responsible for.

This step enables:

* dynamic adaptation to resolution changes,
* reuse of worker threads without recreation.

---

### 3. Parallel Ray Tracing Execution

Each worker thread performs ray tracing only on its assigned portion of the image.

Key characteristics of this phase:

* no concurrent writes to the same memory region,
* completely independent processing between threads,
* no interaction with the global visual state.

---

### 4. Frame Synchronization Barrier

After completing its portion of the frame, the thread:

* signals that its work is finished,
* enters a **frame synchronization barrier**,
* waits until the main thread authorizes the next cycle.

No thread starts rendering a new frame before:

* all frame parts are completed,
* the current frame has been presented.

---

## Main Thread Responsibilities

The main thread acts as the **rendering cycle orchestrator**.

### Event and Resize Handling

Window resizing is treated as a **global pause event**:

* resizing image buffers and render targets,
* updating camera parameters,
* waiting until all worker threads reach a sleep state,
* releasing execution in a coordinated manner once the state stabilizes.

This mechanism ensures consistency and prevents *undefined behavior* during resolution changes.

---

### Frame Finalization and Presentation

For each frame, the main thread:

1. waits for all worker threads to complete their assigned work,
2. presents the final image to the window,
3. processes additional state (input, metrics, etc.),
4. releases the start of the next frame.

This model guarantees that:

* each frame is rendered completely,
* frames do not overlap,
* the pipeline remains deterministic.

---

## Synchronization Model Summary

The module relies on a synchronization model based on:

* **Condition Variables**

  * cooperative pause control during resize,
  * frame completion barriers.

* **Shared Counters**

  * tracking sleeping threads,
  * controlling completed frame parts.

* **Single Orchestrator**

  * the main thread centralizes flow and state decisions.

---

## Design Benefits

* Efficient parallelism for ray tracing workloads.
* Safe and deterministic handling of global events.
* No need for thread recreation.
* Extensible architecture for additional synchronization events.
