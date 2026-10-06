## 2024-10-26 - Optimizing GetSystemTime overhead in IPC
**Learning:** In Windows C/C++ development, `GetSystemTime` followed by `SystemTimeToFileTime` introduces unnecessary calendar math overhead when only a raw timestamp is needed. Additionally, splitting a raw epoch time into seconds and microseconds just to immediately recombine them wastes CPU cycles, especially on high-frequency paths like IPC messaging.
**Action:** Use `GetSystemTimeAsFileTime` directly (with a Windows CE fallback if needed) and return the raw time unit directly without redundant arithmetic.
