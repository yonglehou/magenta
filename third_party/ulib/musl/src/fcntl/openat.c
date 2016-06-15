#include "libc.h"
#include "syscall.h"
#include <fcntl.h>
#include <stdarg.h>

int openat(int fd, const char* filename, int flags, ...) {
    mode_t mode = 0;

    if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE) {
        va_list ap;
        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);
    }

    return syscall(SYS_openat, fd, filename, flags | O_LARGEFILE, mode);
}

LFS64(openat);