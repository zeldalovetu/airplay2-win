
## 2026-09-20 - Optimize xdw_get_sys_time_ms to avoid calendar math and redundant arithmetic
**Learning:** The legacy implementation of `xdw_get_sys_time_ms` unnecessarily computes seconds and microseconds using division and modulo just to recombine them, and uses a two-step SystemTime fallback instead of GetSystemTimeAsFileTime by default.
**Action:** Use GetSystemTimeAsFileTime directly for faster time fetching, preserving the fallback only for Windows CE (`_WIN32_WCE`). Eliminate the division/modulo for seconds and return the computed microseconds directly.
