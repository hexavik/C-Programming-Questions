# CPU Information Fetcher

**Problem Statement:**

Write a program to fetch and display CPU information from `/proc/cpuinfo` on a Linux-based system.

**Requirements:**

Read the `/proc/cpuinfo` file using file I/O operations and display the extracted information in a readable format.
Parse the contents to extract relevant CPU details such as:

- Processor Number
- Model Name
- CPU Cores
- Clock Speed
- Cache Size

**Constraints:**

- The program should handle multi-core processors and list details for each core.
- `/proc/cpuinfo` is only available on Linux-based systems.
