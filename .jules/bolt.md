## 2024-09-27 - Direct SystemTime optimization & Math removal
**Learning:** The legacy `xdw_get_sys_time_ms` pattern was needlessly complex, converting `FILETIME` -> `SYSTEMTIME` for no reason other than compatibility with Windows CE, and then unnecessarily splitting raw time into seconds and microseconds for `timeval`, just to immediately recombine them into microseconds again.
**Action:** Always prefer `GetSystemTimeAsFileTime` directly, but ensure a `#if defined(_WIN32_WCE)` wrapper exists for backward compatibility, and avoid redundant split/recombine calendar math.
