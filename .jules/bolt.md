## 2024-05-20 - [Redundant Calendar Math in High-Frequency Paths]
**Learning:** Legacy Windows CE workarounds (`GetSystemTime` + `SystemTimeToFileTime`) incur significant calendar math overhead when used in high-frequency IPC messaging paths, compared to `GetSystemTimeAsFileTime`. Furthermore, splitting raw epoch time into seconds and microseconds only to recombine them is a common anti-pattern that wastes CPU cycles.
**Action:** Always prefer `GetSystemTimeAsFileTime` outside of Windows CE environments, and avoid redundant unit splitting/recombining arithmetic.
