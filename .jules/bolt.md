## 2024-10-12 - Optimize System Time Retrieval in IPC Path
**Learning:** Avoid redundant arithmetic splitting raw epoch time to seconds and microseconds just to recombine them. Also, use GetSystemTimeAsFileTime instead of GetSystemTime+SystemTimeToFileTime for faster time fetches on non-CE Windows platforms.
**Action:** Use GetSystemTimeAsFileTime with #if defined(_WIN32_WCE) fallback and return the raw time unit directly.
