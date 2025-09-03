#include <stdio.h>

/* Simple package manager detector for C */

const char *detect_package_manager(void) {
#if defined(__linux__)
    return "apt";
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
    return "pkg";
#elif defined(__TempleOS__)
    return "unsupported";
#else
    return "unknown";
#endif
}

int main(void) {
    printf("Detected package manager: %s\n", detect_package_manager());
    return 0;
}
