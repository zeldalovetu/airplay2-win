
## 2024-05-18 - Avoid redundant math in timestamp micro-optimizations
**Learning:** In C/C++ timing code, it's common to see developers divide a time unit down to seconds and milliseconds/microseconds, only to immediately multiply and add them back together into the original unified format (e.g., extracting `tv_sec` and `tv_usec` just to return `tv_sec * 1000000 + tv_usec`).
**Action:** Always check the return format of time wrapper functions. If the raw format perfectly matches the intended return format, return it directly to save the CPU cycles of unnecessary 64-bit integer division and modulo operations.

## 2024-05-18 - GetSystemTimeAsFileTime optimization on Windows
**Learning:** `GetSystemTimeAsFileTime` returns the current system time much faster than the two-step `GetSystemTime` (which fills a bulky `SYSTEMTIME` struct) followed by `SystemTimeToFileTime` (which performs calendar math). However, Windows CE lacks `GetSystemTimeAsFileTime`.
**Action:** When optimizing high-frequency paths on Windows that need system time, replace `GetSystemTime` + `SystemTimeToFileTime` with `GetSystemTimeAsFileTime`, but use an `#if defined(_WIN32_WCE)` fallback to maintain compatibility.
