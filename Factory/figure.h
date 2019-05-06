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

class Square : public Figure {
public:
    void write(std::ostream &os) const
    {
        os << static_cast<uint8_t>(Type::SQUARE);
        // other members
    }
    virtual void read(std::istream& is)
    {
    }
};

class Circle : public Figure {
public:
    void write(std::ostream &os) const
    {
        os << static_cast<uint8_t>(Type::CIRCLE);
        // other members
    }
    virtual void read(std::istream& is)
    {
    }
};

