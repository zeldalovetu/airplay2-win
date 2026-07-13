## 2024-07-13 - [O(N^2) memmove in loops]
**Learning:** Found an O(N^2) anti-pattern in `base64_decode` where `memmove` was being called inside a loop to remove spaces. This is especially bad for base64 which can be used on large payloads.
**Action:** Always check for `memmove` or `strcpy` type operations inside loops, particularly for string sanitization/filtering, and replace them with an O(N) two-pointer approach.
