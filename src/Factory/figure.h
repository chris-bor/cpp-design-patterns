#pragma once

#include <cstdint>
#include <ostream>
#include <istream>
#include <string>

class Figure {
public:
    enum class Type : uint8_t {
        NONE,
        SQUARE,
        CIRCLE,
        RECTANGLE
    };
    Figure(const std::string &name) : mName{name} {}
    virtual ~Figure() {}
    virtual void write(std::ostream &os) const
    {
        os << mName;
    }
    virtual void read(std::istream& is)
    {
        is >> mName;
    }

    std::string mName;
};

class Square : public Figure {
public:
    Square() : Figure("SQUARE") {}
    void write(std::ostream &os) const
    {
        os << static_cast<uint8_t>(Type::SQUARE);
        Figure::write(os);
    }
    virtual void read(std::istream& is)
    {
        Figure::read(is);
    }
};

class Circle : public Figure {
public:
    Circle() : Figure("CIRCLE") {}
    void write(std::ostream &os) const
    {
        os << static_cast<uint8_t>(Type::CIRCLE);
        Figure::write(os);
    }
    virtual void read(std::istream& is)
    {
        Figure::read(is);
    }
};


Figure *createObj(Figure::Type type)
{
    switch (type) {
    case Figure::Type::SQUARE:
        return new Square();
    case Figure::Type::CIRCLE:
        return new Circle();
    default:
        return nullptr;
    }
}

Figure *create(std::istream &is) // funkcja fabryczna
{
    uint8_t tmp{0};
    is >> tmp;
    Figure::Type type{static_cast<Figure::Type>(tmp)};
    Figure *obj = createObj(type);
    obj->read(is);
    return obj;
}
