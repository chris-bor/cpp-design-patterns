#include "tst_modern_cpp.h"

void foo1(std::unique_ptr<int>, int) { std::cout << "Evaluation done" << std::endl; }
int otherFunction(){ return 5; }
void ModernCpp::test_expressionEvaluationOrder()
{
    // Better:
    foo1(std::make_unique<int>(), otherFunction());
    // than:
    foo1(std::unique_ptr<int>(new int), otherFunction()); // can cause memory leak!!!
}

void ModernCpp::test_myContainerRangeLoop()
{
    using namespace mycontainerrangeloop;
    MyContainer myContainer;
    for(const auto &element : myContainer)
        std::cout << element;
}


int foo() { return 5; }
void ModernCpp::test_autoInitialization()
{
    auto copyInitialisation = foo(); Q_UNUSED(copyInitialisation);
    auto directInitialization{foo()}; Q_UNUSED(directInitialization);
    auto initializerListInts = { 1, 2 }; Q_UNUSED(initializerListInts);
    auto initializerListInt = { 3 }; Q_UNUSED(initializerListInt);
    auto intObject{ 3 }; Q_UNUSED(intObject);
}
