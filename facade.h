//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_FACADE_H
#define ADVANCEDPROGRAMMING1_FACADE_H

#include "Shape.h"
#include <map>




class Facade {
    Circle*circle;
    Rectangle* rectangle;
    Square* square;

public:
    Facade() {
        circle = new Circle();
        rectangle = new Rectangle();
        square = new Square();
    }
    void drawCircle(){
        circle->draw();
    }
    void drawRectangle(){
        rectangle->draw();
    }
    void drawSquare(){
        square->draw();
    }
    ~Facade(){
//        for(auto& it:hash_map){
//            delete(&it.second);
//        }
        delete(circle);
        delete(rectangle);
        delete(square);
    }

};

#endif //ADVANCEDPROGRAMMING1_FACADE_H
