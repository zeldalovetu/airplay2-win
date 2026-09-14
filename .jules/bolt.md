## 2024-05-14 - Direct Time Acquisition and Unit Avoidance
**Learning:** In performance-critical paths like IPC messaging, converting high-resolution file time to calendar structures (SYSTEMTIME) and splitting it into seconds/microseconds just to immediately recombine them back into microseconds burns CPU cycles unnecessarily.
**Action:** On Windows (non-CE), call `GetSystemTimeAsFileTime` directly, and return raw uniform ticks rather than decomposing into `timeval` parts when the result is ultimately an integer microsecond count.
