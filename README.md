# Front

A small cross-platform package manager base for Linux, BSD and TempleOS.

## C example

```c
#include "package_manager.c"

int main(void) {
    printf("%s\n", detect_package_manager());
    return 0;
}
```

## C++ example

```cpp
#include "package_manager.cpp"
int main() { return 0; }
```

## Perl example

```perl
require './package_manager.pl';
```
