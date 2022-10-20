# Overview of Memory Types
## Cache
![Cache](/images/cache_levels.png)
### L1 Cache
- Fastest and smallest memory type, usually in 16 - 64 kB range
- Separated into **instruction** (L1i) and **data** (L1d)
- grows in importance with increased speed of CPU
- *Avoids delays in data transmission and helps to make optimum use of CPU's capacity.*

### L2 Cache
- located close to the CPU and has direct connection
- information between L2 and CPU is managed by L2 controller
- size usually < 2 MB
- Choosing between a processor with more clock speed or a larger L2 cache
    - higher clock speed => individual programs run faster
    - larger cache => several programs run simultaneously

### L3 Cache
- Shared amongst all cores (multicore processor)
- [Cache Coherence Protocol (CCP)](https://en.wikipedia.org/wiki/Cache_coherence) can run much faster
   - Compares cache of all cores to maintain data consistency so everyone has access to all the data at the same time
- Intended to simplify and accelerate the CCP and data exchange between cores

### Commands to Try
```bash
# MAC OS
sysctl -a hw

# Debian Linux
lscpu | grep Cache
```
