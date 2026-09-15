## 2026-09-15 - [Optimize Windows Time Fetching on Hot Paths]
 **Learning:** Using GetSystemTime followed by SystemTimeToFileTime introduces unnecessary calendar math overhead. Additionally, splitting raw epoch time into seconds and microseconds only to recombine them wastes CPU cycles on high-frequency paths like IPC messaging.
 **Action:** Prefer calling GetSystemTimeAsFileTime directly (while keeping Windows CE fallback) and returning the raw time unit directly.
