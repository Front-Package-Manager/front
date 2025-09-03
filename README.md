# Front

A small cross-platform package manager base for Linux, BSD and TempleOS.

## Usage

Run the `front-pkg` launcher with sudo on Linux and BSD:

```
sudo front-pkg
```

On TempleOS, just invoke `front`:

```
front
```

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
