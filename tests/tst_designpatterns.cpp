#include <QtTest>
#include <fstream>
#include "src/factory/figure.h"
#include "src/factory/scaleablefactory.h"

// add necessary includes here

int ScaleableFactory::Circle::mId{0};
int ScaleableFactory::Square::mId{0};

class DesignPatterns : public QObject
{
    Q_OBJECT

public:
    DesignPatterns();
    ~DesignPatterns();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_factory();
    void test_scaleableFactory();

};

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
}

QTEST_APPLESS_MAIN(DesignPatterns)

#include "tst_designpatterns.moc"
