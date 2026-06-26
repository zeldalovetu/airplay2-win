## 2024-06-26 - O(n²) string manipulation trap in C

**Learning:** When cleaning up whitespace in a buffer using `memmove` inside a loop, the process takes O(n²) time. In `airplay2/lib/base64.c`, this was a hidden bottleneck for processing large strings (like base64).

**Action:** Look for C-style string parsing loops that shift memory per-character. Use a two-pointer approach (read/write index) to filter/compact strings in-place in O(n) time.
