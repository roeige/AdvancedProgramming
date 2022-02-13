//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_SHAPE_H
#define ADVANCEDPROGRAMMING1_SHAPE_H

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
    string color;
    int x;
    int y;
public:
    const string &getColor() const {
        return color;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getRadius() const {
        return radius;
    }

private:
    int radius;
public:

    Circle(string& color):color(color){}
    Circle(){}
    void setX(int x){
        this->x=x;
    }
    void setY(int y){
        this->y=y;
    }
    void setRadius(int radius){
        this->radius=radius;
    }
    void draw() override {
        cout << "Circle:draw() Color:"<<this->color<<"(x,y): "<<this->x<<","<<this->y<<endl;
    }
};
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Rectangle:draw()" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Square:draw()" << endl;
    }
};

#endif //ADVANCEDPROGRAMMING1_SHAPE_H
