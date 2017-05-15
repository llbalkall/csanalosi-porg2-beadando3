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

class ValamiButton;

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

class JatekMester
{
    public:
    int szamok[9][9];
    JatekMester();

    void beallit(int i, int j, int v)
    {
        szamok[i][j]=v;
    }
    bool chekkoljaHogyJoE(int x, int y)
    {
        if (szamok[x][y]<1)
        {
            return false;
        }
        for (int i=0; i<9;i++)
        {
            if (i!=x)
            {
                if (szamok[i][y]==szamok[x][y]) return true;
            }
            if (i!=y)
            {
                if (szamok[x][i]==szamok[x][y]) return true;
            }
        }
        for (int i=x/3*3; i<x/3*3+3; i++)
        {
            for (int j=y/3*3; j<y/3*3+3; j++)
            {
                if (!(i==x && j==y))
                {
                    if (szamok[i][j]==szamok[x][y]) return szamok[i][j];
                }
            }
        }
        return false;
    }
};

JatekMester::JatekMester()
{
}


class MyWindow : public Window {

public:
    int palyak[3][81]= {   {6,0,0,5,0,9,0,0,0,
                            0,9,0,7,0,3,0,6,0,
                            0,0,8,0,4,0,0,0,0,
                            7,4,0,0,0,0,0,8,5,
                            0,0,2,0,0,0,6,0,0,
                            1,6,0,0,0,0,0,7,4,
                            0,0,0,0,5,0,9,0,0,
                            0,7,0,1,0,8,0,4,0,
                            0,0,0,0,3,0,2,0,6},
                           {0,0,0,0,0,0,7,0,2,
                            0,0,0,6,0,2,0,9,0,
                            0,0,0,7,3,4,0,6,1,
                            0,8,7,0,0,1,2,5,0,
                            0,0,2,0,0,0,9,0,0,
                            0,1,9,2,0,0,6,8,0,
                            9,0,0,1,2,7,0,0,0,
                            0,7,6,9,0,3,0,0,0,
                            4,0,3,0,0,0,0,0,0},
                           {0,0,0,7,0,0,0,0,0,
                            0,0,1,0,3,0,0,0,2,
                            5,0,0,0,0,6,0,0,1,
                            0,9,0,0,0,7,4,0,0,
                            0,1,3,0,0,0,7,2,0,
                            0,0,6,0,0,0,0,0,0,
                            0,4,0,3,6,0,0,0,9,
                            0,0,2,0,0,0,0,0,0,
                            0,0,0,0,0,4,0,5,0}};
    std::vector<OneNumEditor*> mezok;
    JatekMester * Joci;
    StaticText * tx1;
    TextEditor * ed1;
    OneNumEditor * ed;
    FunctorButton * funbtn1;
    FunctorButton * funbtn2;
    MyWindow() ;
    void esemeny(string mitortent) {
        if (mitortent == "egyenlo") {
            tx1->setText(ed1->value());
        }
    }
    static void fv(Window *);
    void palyavaltas()
    {
        int f=rand()%3;
        for (int j=0; j<9; j++)
        {
            for (int i=0; i<9; i++)
            {

                int k=i+j*9;
                //cout<<palyak[f][k];
                if (palyak[f][k]>0)
                {
                    mezok[k]->setNoEdit();
                    mezok[k]->setvalue(nmbrtstrng(palyak[f][k]));
                }
                if (palyak[f][k]==0)
                {
                    mezok[k]->setEdit();
                    mezok[k]->setvalue("");
                }
            }
        }
    }
    void teddBeJocihoz()
    {
        for (int j=0; j<9; j++)
        {
            for (int i=0; i<9; i++)
            {
                int k=i*9+j;
                Joci->beallit(j,i,strtnbr( mezok[k]->value()));
                bool kalap = Joci->chekkoljaHogyJoE(j,i)<<strtnbr( mezok[k]->value());
                mezok[k]->setbad(kalap);
            }
        }
        for (int j=0; j<9; j++)//ez azért kell ide mert ettõl jól mûködik, ha ezt kiszedjük
        {
            for (int i=0; i<9; i++)
            {
                int k=i*9+j;
                Joci->beallit(j,i,strtnbr( mezok[k]->value()));
                bool kalap = Joci->chekkoljaHogyJoE(j,i)<<strtnbr( mezok[k]->value());
                mezok[k]->setbad(kalap);
            }
        }
    }
    void valami() {
        tx1->setText(ed1->value());
    }

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
        //palyak[1] = {1,2,3,4};
        Joci= new JatekMester();
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                ed = new OneNumEditor(100+i*25,100+j*25,25,25,"",true,i,j);
                widgets.push_back(ed);
                mezok.push_back(ed);
                //std::cout<<ed->getKorx()<<endl;
            }
        }
        funbtn1 = new FunctorButton(30,20,100,40,"ellenorzes",[this](){this->teddBeJocihoz();});
        funbtn2 = new FunctorButton(200,20,100,40,"uj palya",[this](){this->palyavaltas();});
        widgets.push_back(funbtn1);
        widgets.push_back(funbtn2);
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
