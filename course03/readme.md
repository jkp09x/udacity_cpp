# Memory Managmenet

## Overview of Memory Types

### Cache
![Cache](/images/cache_levels.png)

#### L1 Cache
- Fastest and smallest memory type, usually in 16 - 64 kB range
- Separated into **instruction** (L1i) and **data** (L1d)
- grows in importance with increased speed of CPU
- *Avoids delays in data transmission and helps to make optimum use of CPU's capacity.*

#### L2 Cache
- located close to the CPU and has direct connection
- information between L2 and CPU is managed by L2 controller
- size usually < 2 MB
- Choosing between a processor with more clock speed or a larger L2 cache
    - higher clock speed => individual programs run faster
    - larger cache => several programs run simultaneously

#### L3 Cache
- Shared amongst all cores (multicore processor)
- [Cache Coherence Protocol (CCP)](https://en.wikipedia.org/wiki/Cache_coherence) can run much faster
   - Compares cache of all cores to maintain data consistency so everyone has access to all the data at the same time
- Intended to simplify and accelerate the CCP and data exchange between cores

### Temporal & Spacial Locality
Rough overview of the latency of various memory operations. Values might change based on system but the order of magnitude will be similar.
![Cache Locality](/images/cache_locality.png)
Originally from Peter Norvig: http://norvig.com/21-days.html#answers

#### Temporal Locality
- Over time the same memory address is accessed frequently (eg. in a loop)
- Keeps memory areas accessible as quickly as possible

#### Spatial Locality
- After an access to an address range, the next access to an address in the immediate vicinity is highly probable (e.g. in arrays)
- exploited by moving the adjacent address areas upwards into the next hierarchy level during a memory access.

```C++
#include <chrono>
#include <iostream>

int main()
{
    // create array
    const int size = 4;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x[j][i] = i + j;
            std::cout << &x[j][i] << ": i=" << i << ", j=" << j << std::endl;
        }
    }

    // print execution time to console
    auto t2 = std::chrono::high_resolution_clock::now(); // stop time measurement
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    return 0;
}
```
Code example provided by: Udacity C++ Nanodegree

#### Commands to Try
```bash
# MAC OS
sysctl -a hw

# Debian Linux
lscpu | grep Cache
```

### Virtual Memory
- Virtual memory is a very useful concept in computer architecture because it helps with making your software work well given the configuration of the respective hardware on the computer it is running on.
- In a nutshell, virtual memory guarantees us a fixed-size address space which is largely independent of the system configuration. Also, the OS guarantees that the virtual address spaces of different programs do not interfere with each other.
- The task of mapping addresses and of providing each program with its own virtual address space is performed entirely by the operating system, so from a programmer’s perspective, we usually don’t have to bother much about memory that is being used by other processes.
- Two important terms which are often used in the context of caches and virtual memory:
   - Memory Page: number of successive memory locations in a virtual memory defined by the computer architecture and the OS.
   - Memory Frame: Same as memory page but is located in the physical memory space and **NOT** the virtual memory space.
   ![Virtual Memory](/images/virtual_memory.png)
   Image by *Udacity C++ Nanodegree*

   As can be seen, both processes have their own virtual memory space. Some of the pages are mapped to frames in the physical memory and some are not. If process 1 needs to use memory in the memory page that starts at address 0x1000, a page fault will occur if the required data is not there. The memory page will then be mapped to a vacant memory frame in physical memory. Also, note that the virtual memory addresses are not the same as the physical addresses. The first memory page of process 1, which starts at the virtual address 0x0000, is mapped to a memory frame that starts at the physical address 0x2000.

   > **NOTE**
   > Relocating virtual swap file to a SSD Location would help with performance.
