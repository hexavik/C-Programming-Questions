# Memory Overlay Management

## Problem Statement

Simulate a memory overlay system where multiple code/data segments share the same memory region, but only one overlay is active at a time. This concept is useful in systems with limited memory where modules must be swapped in and out dynamically.

## Requirements

- Simulate a fixed-size memory region using an array.
- Create multiple "overlay" segments, each containing distinct data.
- Implement `load_overlay()` to overwrite memory with a selected overlay.
- Track the currently active overlay with a variable.
- Ensure transitions properly overwrite and replace the previous contents.

## Input

Commands to load or switch overlays into the memory region.

```bash
Load Overlay 1
Load Overlay 2
```

## Output

Confirmation that the overlay was loaded and the memory region was updated.

```bash
Overlay 1 loaded into memory
Overlay 2 loaded into memory (replaced Overlay 1)
```

## Constraints

- Only one overlay can be active at a time.
- Overlays must fit within the predefined memory block size.
- Loading an overlay overwrites existing memory content.
- The system should track the currently loaded overlay.

> [!NOTE]
>
> - This simulation mimics how early operating systems loaded modules into the same RAM space dynamically.
> - Extend the concept to support partial overlaying or memory protection checks.
> - Can be integrated with a command interface for load/unload/query operations.
