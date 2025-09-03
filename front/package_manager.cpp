#include <iostream>
#include <memory>

/* Simple Front package manager classes for C++ */

class Front {
public:
    virtual ~Front() = default;
    virtual const char* platform() const = 0;
};

class FrontLinux : public Front {
public:
    const char* platform() const override { return "Linux"; }
};

class FrontBSD : public Front {
public:
    const char* platform() const override { return "BSD"; }
};

class FrontTempleOS : public Front {
public:
    const char* platform() const override { return "TempleOS"; }
};

static std::unique_ptr<Front> create() {
#if defined(__linux__)
    return std::unique_ptr<Front>(new FrontLinux());
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
    return std::unique_ptr<Front>(new FrontBSD());
#elif defined(__TempleOS__)
    return std::unique_ptr<Front>(new FrontTempleOS());
#else
    return nullptr;
#endif
}

int main() {
    auto front = create();
    if (!front) {
        std::cout << "Front is unsupported on this platform\n";
        return 0;
    }
    std::cout << "Front package manager on " << front->platform() << "\n";
    return 0;
}
