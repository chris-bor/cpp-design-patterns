#pragma once

#include <cstdint>
#include <ostream>
#include <istream>

class Figure {
public:
    enum class Type : uint8_t {
        SQUARE,
        CIRCLE,
        RECTANGLE
    };
    virtual void write(std::ostream &os) const = 0;
    virtual void read(std::istream& is) = 0;
};

