## 2024-05-23 - [Video Frame Heap Churn]
**Learning:** [Allocating memory buffers using malloc within a video frame render loop (e.g. VideoSource unlock()) can cause significant heap fragmentation and bottleneck CPU execution for realtime streams.]
**Action:** [Cache the allocated memory buffer sizes and pointers, and reuse the pre-allocated buffers across frames. Only call malloc when resolution (width/height) changes.]
