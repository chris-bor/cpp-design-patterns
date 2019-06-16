#pragma once

namespace singleton {

// Single thread version (c++11 guarantee atomic initialization so it's also thread safe)

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

} // namespace singleton
