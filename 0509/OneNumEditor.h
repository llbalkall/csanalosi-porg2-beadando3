#ifndef ONENUMEDITOR_H
#define ONENUMEDITOR_H
#include <string>
#include "widgets.hpp"

class OneNumEditor : public Widget{
    std::string _s;
public:
    OneNumEditor(int x, int y, int sx, int sy, std::string s);
    virtual bool focusable() const {return true;}
    virtual void draw() const ;
    virtual void handle(genv::event ev) ;
    inline std::string value() {return _s;}
};

#endif // ONENUMEDITOR_H
