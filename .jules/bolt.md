
## 2024-10-25 - [Optimize IPC timestamp generation]
**Learning:** In performance-critical paths (e.g., IPC messaging), `GetSystemTimeAsFileTime` is much faster than `GetSystemTime` + `SystemTimeToFileTime` due to calendar math overhead. Additionally, splitting raw time into seconds and microseconds to recombine them is a redundant arithmetic operation that wastes CPU cycles.
**Action:** Use `GetSystemTimeAsFileTime` directly for high-frequency time fetches and return the raw computed microseconds instead of redundant division and multiplication.
