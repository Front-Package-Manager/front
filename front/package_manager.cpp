#include <iostream>
#include <stdexcept>

/* Simple package manager classes for C++ */

class PackageManager {
public:
    virtual ~PackageManager() = default;
    virtual const char* name() const = 0;
};

class AptManager : public PackageManager {
public:
    const char* name() const override { return "apt"; }
};

class PkgManager : public PackageManager {
public:
    const char* name() const override { return "pkg"; }
};

class TempleManager : public PackageManager {
public:
    const char* name() const override {
        throw std::runtime_error("TempleOS is unsupported");
    }
};

static PackageManager* detect() {
#if defined(__linux__)
    return new AptManager();
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
    return new PkgManager();
#elif defined(__TempleOS__)
    return new TempleManager();
#else
    return nullptr;
#endif
}

int main() {
    PackageManager* pm = detect();
    if (!pm) {
        std::cout << "Unknown package manager\n";
        return 0;
    }
    try {
        std::cout << "Detected package manager: " << pm->name() << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    delete pm;
    return 0;
}
