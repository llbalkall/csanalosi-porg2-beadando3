#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include "OneNumEditor.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class ValamiButton;

bool joe(int x)
{
    return x<100000000 && x>-100000000;
}

string nmbrtstrng(int x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    return str;
}

int strtnbr(string s)
{
    if (s.length()==0) return 0;
    else return atoi(s.c_str());
}

/*void addANum(int &O, int x)
{
    if (joe(O*10))
    {
        O=O*10+x;
    }
    //nmbrtstrng(O);
    //std::cout <<nmbrtstrng(O)<< " d" <<std::endl;
}*/


class JatekMester
{
    public:
    int szamok[9][9];
    JatekMester();

    void beallitEsMegmondjaHogyEzVajonJoE(int i, int j, int v)
    {
        //cout<<i<<" "<<j<<" "<<v;
        szamok[i][j]=v;
        cout<<v;
    }

    /*int value = matrix[1][2];
    matrix[3][1] = 5;*/
};

JatekMester::JatekMester()
{
    /*for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                szamok[i][j]=0;
                cout<<szamok[i][j];
            }
        }*/
}


class MyWindow : public Window {

public:
    std::vector<OneNumEditor*> mezok;
    JatekMester * Joci;
    StaticText * tx1;
    TextEditor * ed1;
    OneNumEditor * ed;
    FunctorButton * funbtn1;
    /*PushButton * button;
    ValamiButton * vButton;
    FvPtrButton * fvptrbutton;
    FunctorButton * functorbutton;
    FunctorButton * funbtnegyenlo;

    FunctorButton * funbtn2;
    FunctorButton * funbtn3;
    FunctorButton * funbtn4;
    FunctorButton * funbtn5;
    FunctorButton * funbtn6;
    FunctorButton * funbtn7;
    FunctorButton * funbtn8;
    FunctorButton * funbtn9;
    FunctorButton * funbtn0;
    FunctorButton * funbtnPlus;
    FunctorButton * funbtnMinus;
    FunctorButton * funbtnDevide;
    FunctorButton * funbtnMultiply;*/
    /*int mainValue =0;
    int currValue =0;
    char prevOp = '+';*/
    MyWindow() ;
    void esemeny(string mitortent) {
        if (mitortent == "egyenlo") {
            tx1->setText(ed1->value());
        }
    }
    static void fv(Window *);
    void teddBeJocihoz()
    {

        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                int k=i*9+j;
                Joci->beallitEsMegmondjaHogyEzVajonJoE(mezok[k]->getKorx(),mezok[k]->getKory(),strtnbr( mezok[k]->value()));
            }
            cout<<endl;
        }
    }
    /*void execute()
    {
        if (prevOp=='+')
        {
            mainValue+=currValue;
            currValue=0;
        }
        if (prevOp=='-')
        {
            mainValue-=currValue;
            currValue=0;
        }
        if (prevOp=='/')
        {
            mainValue/=currValue;
            currValue=0;
        }
        if (prevOp=='*')
        {
            mainValue*=currValue;
            currValue=0;
        }
        if (prevOp=='=')
        {
            //currValue=mainValue;
        }
        tx1->setText(nmbrtstrng(currValue));
    }*/
    void valami() {
        tx1->setText(ed1->value());
    }/*
    void egyenlo() {
        execute();
        prevOp='=';
        tx1->setText(nmbrtstrng(mainValue));
    }
    void btnN(int x) {
        if (joe(currValue*10))
        {
            currValue=currValue*10+x;
        }
        std::cout <<currValue<<std::endl;
        tx1->setText(nmbrtstrng(currValue));
    }
    void plusz()
    {
        execute();
        prevOp='+';
    }
    void minusz()
    {
        execute();
        prevOp='-';
    }
    void devide()
    {
        execute();
        prevOp='/';
    }
    void multiply()
    {
        execute();
        prevOp='*';
    }*/

};

class ValamiButton : public PushButton {
    MyWindow * mywparent;
public:
    ValamiButton(MyWindow * parent, int x, int y, int sx,
                int sy, std::string s)
                :PushButton(x, y, sx, sy, s) {
        mywparent = parent;
    }
    virtual void action() ;
};


MyWindow::MyWindow() {
        Joci= new JatekMester();
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                ed = new OneNumEditor(100+i*25,100+j*25,25,25,"",true,i,j);
                widgets.push_back(ed);
                mezok.push_back(ed);
                std::cout<<ed->getKorx()<<endl;
            }
        }
        for (int i=0; i<81; i++)
        {
                std::cout<<i<<" "<<mezok[i]->getKorx()<<endl;
        }
        /*//button = new MessageButton(this, 10, 10, 60, 60,"oda", "egyenlo");
        //tx1 = new StaticText(75,20,100,40,"0");
        //ed1 = new TextEditor(10,100,100,40,"");
        //ed = new OneNumEditor(10,100,25,25,"",false);
        //vButton = new ValamiButton(this, 10,200,100,40,"vbut");
        //fvptrbutton = new FvPtrButton(this, 10,250,100,40,"fvptr",MyWindow::fv);
        //functorbutton = new FunctorButton(10,300,100,40,"functor",[this](){this->valami();});
        /*funbtnegyenlo = new FunctorButton(240,320,80,40,"=",[this](){this->egyenlo();});*/
        funbtn1 = new FunctorButton(30,20,40,40,"megcsin",[this](){this->teddBeJocihoz();});
        /*funbtn2 = new FunctorButton(240,200,40,40,"2",[this](){this->btnN(2);});
        funbtn3 = new FunctorButton(280,200,40,40,"3",[this](){this->btnN(3);});
        funbtn4 = new FunctorButton(200,240,40,40,"4",[this](){this->btnN(4);});
        funbtn5 = new FunctorButton(240,240,40,40,"5",[this](){this->btnN(5);});
        funbtn6 = new FunctorButton(280,240,40,40,"6",[this](){this->btnN(6);});
        funbtn7 = new FunctorButton(200,280,40,40,"7",[this](){this->btnN(7);});
        funbtn8 = new FunctorButton(240,280,40,40,"8",[this](){this->btnN(8);});
        funbtn9 = new FunctorButton(280,280,40,40,"9",[this](){this->btnN(9);});
        funbtn0 = new FunctorButton(200,320,40,40,"0",[this](){this->btnN(0);});
        funbtnPlus = new FunctorButton(320,320,40,40,"+",[this](){this->plusz();});
        funbtnMinus = new FunctorButton(320,280,40,40,"-",[this](){this->minusz();});
        funbtnDevide = new FunctorButton(320,200,40,40,"/",[this](){this->devide();});
        funbtnMultiply = new FunctorButton(320,240,40,40,"*",[this](){this->multiply();});
        //widgets.push_back(tx1);
        //widgets.push_back(ed1);
        //widgets.push_back(ed);
        //widgets.push_back(button);
        //widgets.push_back(vButton);
        //widgets.push_back(fvptrbutton);
        //widgets.push_back(functorbutton );
        /*widgets.push_back(funbtnegyenlo);*/
        widgets.push_back(funbtn1);
        /*widgets.push_back(funbtn2);
        widgets.push_back(funbtn3);
        widgets.push_back(funbtn4);
        widgets.push_back(funbtn5);
        widgets.push_back(funbtn6);
        widgets.push_back(funbtn7);
        widgets.push_back(funbtn8);
        widgets.push_back(funbtn9);
        widgets.push_back(funbtn0);
        widgets.push_back(funbtnPlus);
        widgets.push_back(funbtnMinus);
        widgets.push_back(funbtnDevide);
        widgets.push_back(funbtnMultiply);*/
}


void MyWindow::fv(Window *w) {
    MyWindow * mw = dynamic_cast<MyWindow*>(w);
    if (mw) {
        mw->valami();
    }
}

void ValamiButton::action() {
    mywparent->valami();
}

int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
