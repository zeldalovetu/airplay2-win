## 2024-05-14 - Optimize Windows System Time Fetching
**Learning:** In Windows C/C++ development, `GetSystemTime` followed by `SystemTimeToFileTime` is inefficient as it performs calendar math unnecessarily. Directly using `GetSystemTimeAsFileTime` is faster and skips the calendar conversion steps, which is especially important on high-frequency paths like IPC messaging.
**Action:** Replace `GetSystemTime` + `SystemTimeToFileTime` with `GetSystemTimeAsFileTime`, but preserve the original approach for Windows CE compatibility using `#if defined(_WIN32_WCE)`.
