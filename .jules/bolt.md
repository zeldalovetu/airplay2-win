
## 2024-05-18 - Avoid two-step timestamp retrieval and unnecessary math in IPC message queue
**Learning:** Using GetSystemTime followed by SystemTimeToFileTime introduces unnecessary overhead compared to GetSystemTimeAsFileTime directly. Furthermore, in high-frequency messaging code (e.g. `xdw_socket_ipc.c`), separating total microseconds into a seconds and microseconds structure (`struct timeval`) and then immediately recombining them mathematically adds unneeded CPU instructions.
**Action:** Always prefer GetSystemTimeAsFileTime unless backward compatibility with Windows CE requires otherwise (`#if defined(_WIN32_WCE)`), and always avoid intermediate formatting structures if the caller just needs a raw scalar time unit.
