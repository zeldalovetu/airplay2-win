## 2024-06-25 - Windows CE vs Modern Windows API divergence
**Learning:** `GetSystemTime` followed by `SystemTimeToFileTime` introduces calendar math overhead because `SYSTEMTIME` is a parsed struct. `GetSystemTimeAsFileTime` directly writes the filetime ticks. However, legacy systems like Windows CE do not have `GetSystemTimeAsFileTime`, requiring developers to conditionally use the slow path.
**Action:** Always prefer `GetSystemTimeAsFileTime` directly over the two-step parsing, but ensure fallback paths with `#if defined(_WIN32_WCE)` for libraries claiming CE compatibility.
