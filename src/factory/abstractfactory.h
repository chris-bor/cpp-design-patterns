#pragma once

#include <vector>

// Wiąże inne rodzaje fabryk.
// Hierarchia fabryk i hierarchia konkretnych typów.

namespace AbstractFactory {

class Button {
};
class ScrollBar {
};
class TextBox {
};

class WxButton : public Button {
};
class WxScrollBar : public ScrollBar {
};
class WxTextBox : public TextBox {
};


class GtkButton : public Button {
};
class GtkScrollBar : public ScrollBar {
};
class GtkTextBox : public TextBox {
};

class WidgetFactory { // Abstract factory
public:
    virtual Button* createButton() = 0;
    virtual ScrollBar* createScrollBar() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ~WidgetFactory() {}
};

class WxFactory : public WidgetFactory {
public:
    virtual Button* createButton() { return new WxButton; }
    virtual ScrollBar* createScrollBar() { return new WxScrollBar; }
    virtual TextBox* createTextBox() { return new WxTextBox; }
};

class GtkFactory : public WidgetFactory {
public:
    virtual Button* createButton() { return new GtkButton; }
    virtual ScrollBar* createScrollBar() { return new GtkScrollBar; }
    virtual TextBox* createTextBox() { return new GtkTextBox; }
};

class Framework {
public:
    Framework() {
        if (isWx())
            mFactory = new WxFactory;
        else
            mFactory = new GtkFactory;
    }
private:
    WidgetFactory  *mFactory;
    bool isWx() const { return true; }
};


// Generic version:
template <typename X> struct identity {
    typedef X type;
};

template <typename T> struct AbstractUnit {
    virtual T* doCreate(identity<T>) = 0;
    virtual ~AbstractUnit(){}
};

struct AbstractWidgetFactory : public AbstractUnit<Button>, AbstractUnit<ScrollBar> {
    template<typename T> T* create() {
        AbstractUnit<T>* unit = this;
        return unit->doCreate(identity<T>());
    }
};

template <typename Abstract, typename Concrete, typename Base>
struct ConcreteUnit : public Base {
    virtual Abstract* doCreate(identity<Abstract>) {
        return new Concrete;
    }
};

struct ConcreteWxFactory : public ConcreteUnit<Button, WxButton, ConcreteUnit<ScrollBar, WxScrollBar, AbstractWidgetFactory>>
{};

//typedef AbstractUnit<std::vector<Button, ScrollBar>> WidgetFactoryShort;
//typedef ConcreteUnit<WidgetFactoryShort, std::vector<WxButton, WxScrollBar>> WxFactoryShort;
}
