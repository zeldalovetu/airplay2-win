## 2024-05-24 - [Optimize SystemTime calls in high frequency IPC]
**Learning:** In performance-critical paths (e.g., IPC messaging), calling GetSystemTime() + SystemTimeToFileTime() is redundant on modern Windows where GetSystemTimeAsFileTime() exists. Additionally, splitting raw epoch time into seconds and microseconds (via division and modulo) only to immediately recombine them wastes CPU cycles.
**Action:** Use GetSystemTimeAsFileTime() directly when not on Windows CE, and return the raw time unit directly to eliminate unnecessary calendar math and arithmetic overhead.
