#ifndef ONENUMEDITOR_H
#define ONENUMEDITOR_H
#include <string>
#include "widgets.hpp"

class OneNumEditor : public Widget{
    std::string _s;
    bool editable;
    bool bad=false;
    int korx, kory;
public:
    OneNumEditor(int x, int y, int sx, int sy, std::string s, bool ee, int korx, int kory);
    virtual bool focusable() const {return true;}
    virtual void draw() const ;
    virtual void handle(genv::event ev) ;
    inline std::string value() {return _s;}
    void setbad(bool mi) {bad=mi;}
    int getKorx() {return korx;}
    int getKory() {return kory;}
    void setvalue(std::string sss) {_s=sss;}
    void setEdit() {editable=true;}
    void setNoEdit() {editable=false;}
};

#endif // ONENUMEDITOR_H
