//
// Created by roei on 13/02/2022.
//
#ifndef ADVANCEDPROGRAMMING1_FLYWEIGHT_H
#define ADVANCEDPROGRAMMING1_FLYWEIGHT_H

#include <map>
#include <iostream>
#include <random>

using std::endl;
using std::cout;
using namespace std;

/**
 * Using all shapes
 */
class ShapeFactory {
    map<const string, Shape *> hash_map;
public:
    Shape *getCircle(string &color) {
        Shape* circle;
       if(hash_map.count(color)) {
           circle = hash_map.at(color);
       }
       else{
        //if its new color
            hash_map.insert({color, new Circle(color)});
            circle = hash_map.at(color);
        }
        return circle;
    }
};

class FlyWeightPatternDemo {
private:
    array<string, 4> arr = {{"green", "blue", "yellow", "gray"}};

    string &getRandomColor() {
        int random = rand() % 4;
        return arr[random];
    }

    int getRandomX() {
        return rand() % 100;
    }

    int getRandomY() {
        return rand() % 100;
    }

public:
    void operate() {
        auto shapeFactory = new ShapeFactory();
        Shape *circle_shape = shapeFactory->getCircle(getRandomColor());
        Circle *circle = dynamic_cast<Circle *>(circle_shape);
        if (circle) {
            circle->setX(this->getRandomX());
            circle->setY(this->getRandomY());
            circle->setRadius(this->getRandomX());
            cout << "Circle information: Color:" << circle->getColor() << endl << "Radius:" << circle->getRadius()
                 << endl << "(x,y): " << "("<<circle->getX() <<", "<< circle->getY() << ")"<<endl;

        }
    }
};

#endif //ADVANCEDPROGRAMMING1_FLYWEIGHT_H
