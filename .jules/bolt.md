## 2024-08-13 - Optimize GetSystemTime to GetSystemTimeAsFileTime
**Learning:** In Windows environments, using `GetSystemTimeAsFileTime` avoids unnecessary calendar calculation overhead compared to `GetSystemTime` followed by `SystemTimeToFileTime`, significantly improving performance on high-frequency paths like IPC messaging. Windows CE requires the two-step fallback.
**Action:** Use `GetSystemTimeAsFileTime` directly when high-resolution, low-overhead time retrieval is needed, taking care to preserve backwards compatibility for Windows CE environments where applicable.
