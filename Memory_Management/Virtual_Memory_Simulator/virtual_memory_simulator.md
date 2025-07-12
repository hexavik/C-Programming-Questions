# Virtual Memory Simulator

## Problem Statement

Simulate virtual memory management by using an array to represent physical memory and a page table array to keep track of loaded pages. On page access, load the page into physical memory if not already present.

## Requirements

- Represent physical memory as a fixed-size array.
- Maintain a page table array mapping virtual pages to physical memory slots.
- Implement an `accessPage(pageNumber)` function that:
  - Checks if the page is already loaded.
  - If not loaded, loads the page into physical memory.
  - Updates the page table accordingly.
- Output which pages are loaded when accessed.

## Input

Sequence of page numbers to be accessed.

```bash
Access page 3
Access page 7
```

## Output

Indicate pages loaded into physical memory.

```bash
Page 3 loaded
Page 7 loaded
```

## Constraints

- Physical memory has limited slots.
- Page table size matches number of virtual pages.
- You may implement simple replacement policies (e.g., FIFO) if physical memory is full.

> [!NOTE]
>
> - Use an array, e.g., `physicalMemory[]`, to hold page data or page numbers.
> - Use a page table array, e.g., `pageTable[]`, with indices as virtual page numbers and values indicating physical frame or -1 if not loaded.
> - When `accessPage` is called:
>   - Check `pageTable[pageNumber]`.
>   - If -1, load page into next free physical slot or replace existing page.
>   - Update page table entry for the loaded page.
> - This simulates page loading and mapping in a basic virtual memory system.
