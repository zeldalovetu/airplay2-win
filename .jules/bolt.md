## 2024-05-24 - Avoiding GetSystemTime in Hot Paths
**Learning:** `GetSystemTime` followed by `SystemTimeToFileTime` is an anti-pattern in high-frequency Windows IPC code because it converts file time to calendar time, only to convert it back to file time. `GetSystemTimeAsFileTime` should be used instead. The two-step process was used to support Windows CE, which lacks the API.
**Action:** When finding time functions in hot paths, check if standard Windows builds can bypass Windows CE limitations by using `#if !defined(_WIN32_WCE)` around more efficient APIs like `GetSystemTimeAsFileTime`.
