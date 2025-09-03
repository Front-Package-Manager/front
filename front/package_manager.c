#include <stdio.h>

/* Simple Front package manager base for C */

const char *front_platform(void) {
#if defined(__linux__)
    return "Linux";
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
    return "BSD";
#elif defined(__TempleOS__)
    return "TempleOS";
#else
    return "Unknown";
#endif
}

int main(void) {
    printf("Front package manager on %s\n", front_platform());
    return 0;
}
