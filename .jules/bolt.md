## 2024-06-25 - Avoid Windows CE Time Fallbacks in IPC Hot Paths
**Learning:** In Windows C/C++ development, using the two-step `GetSystemTime` followed by `SystemTimeToFileTime` is a legacy fallback originally for Windows CE. This incurs unnecessary calendar math overhead, converting system time to a human-readable structure and back to file time. This is especially problematic in high-frequency hot paths like IPC messaging.
**Action:** Always prefer calling `GetSystemTimeAsFileTime` directly for performance-critical timing logic.
