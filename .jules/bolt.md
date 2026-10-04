
## 2023-10-27 - Direct Microseconds from Windows FILETIME
**Learning:** In Windows C environments, converting a `FILETIME` struct (100-nanosecond intervals) to POSIX-style `struct timeval` (seconds and microseconds) using division and modulo, only to immediately recombine them back into total microseconds, is a redundant and wasteful anti-pattern on hot paths (like IPC polling or message queuing).
**Action:** When a function requires returning raw milliseconds or microseconds, compute it directly from the 64-bit integer representation of `FILETIME` without splitting it into seconds and microseconds first. Use `GetSystemTimeAsFileTime()` to avoid the overhead of `GetSystemTime()` where possible.
