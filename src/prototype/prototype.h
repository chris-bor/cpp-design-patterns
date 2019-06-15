#pragma once

#include <map>

// Named also virtual constructor.
// Lets make deep copy, using pointer or reference to base class.

namespace Prototype {

class Figure {
public:
    Figure() = default;
    virtual ~Figure(){}
    virtual Figure* clone() const = 0;
};

class Circle : public Figure {
public:
    Circle() = default;
    Circle(const Circle& /*r*/) {}
    virtual Circle* clone() const {
        return new Circle(*this);
    }
};

class Square : public Figure {
public:
    Square() = default;
    Square(const Square& /*r*/) {}
    virtual Square* clone() const {
        return new Square(*this);
    }
};

// Prototype factory:

class FigureFactory {
public:
    int registerFigure(Figure* prototype) {
        mPrototypes.emplace(mCurrentId, prototype);
        return mCurrentId++;
    }
    Figure* create(int id) {
        auto i = mPrototypes.find(id);
        if (i != mPrototypes.end())
            return i->second->clone();
        return nullptr;
    }
private:
    int mCurrentId{0};
    std::map<int, Figure*> mPrototypes;
};

} // namespace Prototype
