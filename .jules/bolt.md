
## 2024-05-24 - [Avoid Redundant Arithmetic and Calendar Math in Time Retrieval]
**Learning:** Found a hot path in IPC messaging that splits raw epoch time into seconds and microseconds, only to immediately recombine them, wasting CPU cycles on division and modulo. Additionally, retrieving system time via `GetSystemTime` + `SystemTimeToFileTime` incurs heavy calendar math overhead on Windows compared to `GetSystemTimeAsFileTime`.
**Action:** When working on performance-critical paths, skip intermediate struct conversions (like `timeval`) when returning raw time units, and prefer `GetSystemTimeAsFileTime` directly while keeping fallbacks for legacy platforms like Windows CE.
