# Front

A small cross-platform package manager base for Linux, BSD and TempleOS. Front is its own package manager and does not wrap other tools.

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
    printf("Front on %s\n", front_platform());
    return 0;
}
```

## C++ example

```cpp
#include "package_manager.cpp"

int main() {
    auto front = create();
    if (front)
        std::cout << "Front on " << front->platform() << "\n";
    return 0;
}
```

## Perl example

```perl
require './package_manager.pl';
```
