## 2024-07-27 - [Windows C/C++] Time Fetching Overhead
**Learning:** Using `GetSystemTime` followed by `SystemTimeToFileTime` is a legacy fallback for Windows CE and introduces unnecessary calendar math overhead compared to directly fetching file time.
**Action:** On modern Windows, especially on high-frequency paths like IPC messaging, always use `GetSystemTimeAsFileTime` directly to minimize overhead.
