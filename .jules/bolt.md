## 2024-05-15 - Redundant Arithmetic and System Call Overhead in Time Retrieval
**Learning:** In Windows C/C++, `GetSystemTime` followed by `SystemTimeToFileTime` incurs unnecessary calendar math overhead. Also, splitting raw time into seconds and microseconds just to recombine them wastes CPU cycles.
**Action:** Use `GetSystemTimeAsFileTime` directly (with `_WIN32_WCE` fallback) and eliminate redundant division/modulo recombination steps on hot paths like IPC messaging.
