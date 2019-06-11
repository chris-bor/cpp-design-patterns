#pragma once

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

}
