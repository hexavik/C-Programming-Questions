# Memory-Bound Priority Queue

**Problem Statement:**

Design and implement a **priority queue** that operates within a fixed-size **pre-allocated array**, without using dynamic memory allocation (`malloc`, `free`). The highest-priority element should always be removed first.

**Requirements:**

- Use a fixed-size array to store elements. No additional memory allocations (`malloc`, `realloc`) are allowed.
- **Operations:**
  - `Insert (value)`: Insert an element into the queue while maintaining order.
  - `Remove ()`: Remove and return the highest-priority element.
- Implement using a **binary max-heap** (preferred for efficiency) or a **sorted array** (simpler but slower).
- Maintain a **size variable** to track the number of elements.

**Input:**

```bash
Insert 5
Insert 9
Insert 2
Remove
```

**Output:**

```bash
Removed 9
```

**Constraints:**

- **Fixed-size array of N elements** (e.g., `N = 100`).
- **Priority order:** Higher numbers have **higher priority**.
- **Heap-based insertion/removals should run in O(log N) time.**

> [!NOTE]
>
> **Heap Implementation Approach (Preferred)**
>
> - **Heap Representation: Store elements in an array-based max-heap.**
> - **Insert (heapify-up):**
>   - Insert at the end.
>   - Swap upwards until heap property is maintained.
> - **Remove (heapify-down):**
>   - Swap root with last element.
>   - Reduce size and restore heap by bubbling down.
>
> **Heapify-Up (Insertion) Example:**
>
> ```bash
> Insert 5 → [5]
> Insert 9 → [9, 5] (swap 9 and 5)
> Insert 2 → [9, 5, 2]
> ```
>
> **Heapify-Down (Removal) Example:**
>
> ```bash
> Remove → Swap 9 with last element (2), then heapify → [5, 2]
> ```
>
> **Alternative: Sorted Array Approach (Slower)**
>
> - **Insert:** Add to the correct position to keep the array sorted (`O(N)`).
> - **Remove:** Always remove from the last index (`O(1)`).
