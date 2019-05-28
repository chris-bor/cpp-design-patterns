#include <QtTest>
#include <fstream>
#include "../../Factory/figure.h"

// add necessary includes here

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
    // Not scaleable factory:
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

    // Scaleable factory:
}

QTEST_APPLESS_MAIN(DesignPatterns)

#include "tst_designpatterns.moc"
