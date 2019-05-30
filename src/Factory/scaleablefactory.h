#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

// Umożliwia tworzenie obiektów na podstawie identyfikatorów (nie wymaga switcha!).
// Fabryka skalowalna zależna jest tylko od klasy bazowej!
// Singleton
// Uniezależniona od klas konkretnych
// Sprytne wskaźniki

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
    virtual void write(std::ostream &os) const { os << mName; }
    virtual void read(std::istream& is) { is >> mName; }

    std::string mName;
};

using PFigure = std::shared_ptr<Figure>;

class FigFactory {
public:
//    typedef PFigure (*CreateFig)(); // wsk. na fun. tworzącą
    using CreateFig = std::function<Figure*()>;

    static FigFactory &getInstance() {
        static FigFactory factory;
        return factory;
    }

    void registerFigure(CreateFig fun) {
        mCreators.emplace(mCurrentId, fun);
    }

    Figure *create(int id) {
        Creators::const_iterator i = mCreators.find(id);
        if (i != mCreators.end())
            return (i->second)();
        return nullptr;
    }
private:
    int mCurrentId;
    using Creators = std::map<int, CreateFig>;
    Creators mCreators;
};
