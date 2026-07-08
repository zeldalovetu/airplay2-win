## 2023-10-27 - O(N^2) String Whitespace Stripping Anti-pattern
**Learning:** Found a classic O(N^2) string processing anti-pattern in `base64.c` where `memmove` was used inside a loop to remove spaces. Since `memmove` shifts the remainder of the array, repeating it for every space makes the decoding time increase quadratically for strings with many spaces (e.g. badly formatted base64 with many newlines or spaces).
**Action:** Replace in-place string manipulation loops that shift memory with a single-pass O(N) two-pointer approach where valid characters are copied to the write pointer `j`.
