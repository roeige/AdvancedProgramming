//
// Created by roei on 12/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_DECORATOR_H
#define ADVANCEDPROGRAMMING1_DECORATOR_H
#include "iostream"
using std::cout;

class GUIitem{
public:
    virtual void paint()=0;
//    virtual void addListener()=0;
};
class Decorator:public GUIitem{
    GUIitem* item;
public:
    Decorator(GUIitem* item):item(item){}
    void paint()override{
        /**
         * Painting
         */
         item->paint();
    }
};
class Scrollbars:public Decorator{
public:
    Scrollbars(GUIitem* item):Decorator(item){}
    void paint()override{
        Decorator::paint();
        paintOver();
    }
    void paintOver(){
        /**
         * Painting over
         */
        cout<<"(scrollbars) ";
    }
};
class Title:public Decorator{
    Title(GUIitem* item): Decorator(item){}
    void paint()override{
        Decorator::paint();
        paintOver();
    }
    void paintOver(){
        /**
         * Painting over
         */
         cout<<"(Title) ";
    }
};
class Border:public Decorator{
public:
    Border(GUIitem* item):Decorator(item){}
    void paint()override{
        Decorator::paint();
        paintOver();
    }
    void paintOver(){
        /**
         * Painting over
         */
        cout<<"(Border) ";
    }
};
class ListView:public GUIitem{
    void paint()override{
        /**
         * Painting
         */
        cout<<"ListView ";
    }
};
class TextView:public GUIitem{
    void paint()override{
        /**
         * Painting
         */
    }
};
class Canvas:public GUIitem{
    void paint()override{
        /**
         * Painting
         */
    }
};

#endif //ADVANCEDPROGRAMMING1_DECORATOR_H
