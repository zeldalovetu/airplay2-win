## 2024-05-15 - [Base64 whitespace stripping bottleneck]
**Learning:** O(n^2) whitespace stripping using `memmove` inside a loop in base64 decoding can cause major performance degradation for large payloads, and checking padding per character hinders base64 decoding speed.
**Action:** Always prefer two-pointer O(n) array compaction techniques when modifying buffers in-place, and utilize bulk/chunked processing (e.g. 4 bytes at a time) for decoding strings.
