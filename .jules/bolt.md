
## 2024-10-31 - Direct time API calls and avoiding redundant math

**Learning:** When porting or maintaining Windows CE legacy code, `GetSystemTime` followed by `SystemTimeToFileTime` is sometimes used because Windows CE lacked `GetSystemTimeAsFileTime`. However, this incurs unnecessary calendar math overhead. Additionally, older code might unnecessarily split a 64-bit microsecond counter into seconds and microseconds using integer division/modulo, only to immediately multiply and add them back to return microseconds.

**Action:** For non-Windows CE environments (`#ifndef _WIN32_WCE`), directly use `GetSystemTimeAsFileTime`. Eliminate any mathematically redundant steps (like dividing and immediately multiplying by 1,000,000) that exist purely for intermediate struct variables, returning the original value directly to save CPU cycles on hot paths.
