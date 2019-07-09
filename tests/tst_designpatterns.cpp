#include <fstream>
#include "tst_designpatterns.h"
#include "src/factory/abstractfactory.h"
#include "src/factory/figure.h"
#include "src/factory/scaleablefactory.h"
#include "src/prototype/prototype.h"
#include "src/singleton/singleton.h"
#include "src/visitor/visitor.h"

int ScaleableFactory::Circle::mId{0};
int ScaleableFactory::Square::mId{0};

DesignPatterns::DesignPatterns()
{
    qDebug() << __FUNCTION__;
}

DesignPatterns::~DesignPatterns()
{
    qDebug() << __FUNCTION__;
}

void DesignPatterns::initTestCase()
{
    qDebug() << __FUNCTION__;
}

void DesignPatterns::cleanupTestCase()
{
    qDebug() << __FUNCTION__;
}

void DesignPatterns::test_factory()
{
    qDebug() << __FUNCTION__;
    using namespace Factory;
    std::ofstream factoryFile("factory.txt");
    Figure *square = createObj(Figure::Type::SQUARE);
    Figure *circle = createObj(Figure::Type::CIRCLE);
    square->write(factoryFile);
    circle->write(factoryFile);
    factoryFile.close();

    std::ifstream factoryFileToRead("factory.txt");
    Figure *square2 = create(factoryFileToRead);
    Figure *circle2 = create(factoryFileToRead);
//    QCOMPARE(square->mName, square2->mName);
//    QCOMPARE(circle->mName, circle2->mName);

//    ifstream file ("factory.bin", ios::in|ios::binary|ios::ate);
    delete square;
    delete circle;
    delete square2;
    delete circle2;
}

void DesignPatterns::test_scaleableFactory()
{
    qDebug() << __FUNCTION__;
    using namespace ScaleableFactory;
    using Types = std::vector<Square, Circle>;
//    mpl::for_each<Types>(RegisterFigure()); // boost needed

    Square::mId = FigFactory::getInstance().registerFigure(Square::create);
    Circle::mId = FigFactory::getInstance().registerFigure(Circle::create);
    Figure* square = FigFactory::getInstance().create(Square::mId);
    Figure* circle = FigFactory::getInstance().create(Circle::mId);
    QVERIFY(Square::mId != Circle::mId);
    QCOMPARE(Square::mId, 0);
    QCOMPARE(Circle::mId, Square::mId+1);
    QCOMPARE(square->mName, std::string("SQUARE"));
    QCOMPARE(circle->mName, std::string("CIRCLE"));
    delete square;
    delete circle;
}

void DesignPatterns::test_abstractFactory()
{
    qDebug() << __FUNCTION__;
    using namespace  AbstractFactory;
    using WxFactory = struct ConcreteWxFactory;
    WxFactory wxFactory{};
    auto *wxButton = wxFactory.doCreate(identity<Button>());
    QVERIFY(wxButton != nullptr);
    QVERIFY(typeid(*wxButton).name() == typeid(WxButton).name());
    QVERIFY(dynamic_cast<WxButton*>(wxButton));
    delete wxButton;
}

void DesignPatterns::test_prototype()
{
    qDebug() << __FUNCTION__;
    using namespace Prototype;
    Figure* square = new Square;
    Figure* circle = new Circle;
    Figure* circle2 = circle->clone();
    FigureFactory factory{};
    auto circleId = factory.registerFigure(circle);
    auto squareId = factory.registerFigure(square);
    auto circle3 = factory.create(circleId);
    auto square3 = factory.create(squareId);
    QVERIFY(dynamic_cast<Circle*>(circle2));
    QVERIFY(dynamic_cast<Circle*>(circle3));
    QVERIFY(dynamic_cast<Square*>(square3));
    delete square;
    delete circle;
    delete circle2;
    delete circle3;
    delete square3;
}

void DesignPatterns::test_singleton()
{
     qDebug() << __FUNCTION__;
     using namespace singleton;
     Singleton& s = Singleton::getInstance();
     Q_UNUSED(s);
}

void DesignPatterns::test_cyclicVisitor()
{
    using namespace cyclicvisitor;
    typedef std::vector<std::unique_ptr<Unit>> Units;

    Units units;
    auto infantry = std::make_unique<Infantry>();
    infantry->addSoldiers(10);
    auto tank = std::make_unique<Tank>();
    tank->addTanks(20);
    auto rocket = std::make_unique<Rocket>();
    rocket->addRockets(30);
    units.emplace_back(std::move(infantry));
    units.emplace_back(std::move(tank));
    units.emplace_back(std::move(rocket));
    Statistics s;
    for(const auto &u : units) {
        u->accept(s);
    }
    QCOMPARE(10, s.soldiers());
    QCOMPARE(20, s.tanks());
    QCOMPARE(30, s.rockets());
}
