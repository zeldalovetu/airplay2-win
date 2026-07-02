
## 2024-07-02 - O(N^2) Anti-Pattern in Base64 decoding
**Learning:** Found an O(N^2) architectural anti-pattern in `airplay2/lib/base64.c` where space-skipping was implemented by repeatedly calling `memmove` on the remainder of the buffer inside a loop. For large Base64 blobs, this creates a severe performance bottleneck.
**Action:** When inspecting string parsing or sanitization code, explicitly check for O(N^2) behavior from nested array-shifting operations (like `memmove` in a loop) and replace them with O(N) two-pointer implementations.
