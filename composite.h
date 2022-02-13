//
// Created by roei on 11/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_COMPOSITE_H
#define ADVANCEDPROGRAMMING1_COMPOSITE_H
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
class CompoundGraphic;
//class Graphic;
////The composite
//class Graphic{
//public:
//    virtual void move(float x, float y)=0;
//    virtual void draw()=0;
//
//};
//class CompoundGraphic:Graphic{
//    //initializing vector of children
//    vector<Graphic>& children;
//public:
//    CompoundGraphic(vector<Graphic>& children): children(children){};
//    void add(Graphic& child){
//        this->children.push_back(child);
//    }
//    void remove(Graphic& child){
//
//    }
//    void move(float x,float y)override{
//      /**
//       * Some Operation
//       */
//    }
//    void draw()override{
//        /**
//         * Drawing the shape
//         */
//    }
//
//};
//class Dot:Graphic{
//    float x,y;
//public:
//    Dot(float x,float y):x(x),y(y){}
//    void move(float x,float y)override{
//       this->x=x;
//       this->y=y;
//    }
//    void draw()override{
//        /**
//         * Drawing the shape
//         */
//    }
//};
/*
 * Another example:
 */
class Employee{
    //common information of all employees
protected:
    string name;
    int age;
public:
    Employee(string& name,int age):name(name),age(age){}
    virtual void remove(Employee* employee)=0;
    virtual void add(Employee*& employee)=0;
    virtual Employee*& getEmployee(int index)=0;
    virtual void operation()=0;
    virtual string getName()const=0;
};
class Manager:public Employee{
    list<Employee*>children;
public:
    Manager(string name,int age,list<Employee*>& children):Employee(name,age),children(children){}
    void remove( Employee* employee)override{
        children.remove(employee);
    }
    void add(Employee*& employee)override{
        children.push_back(employee);
    }
    string getName()const override {
        return this->name;
    }
    Employee*& getEmployee(int index)override{
        auto it=children.begin();
        advance(it,index);
        return *it;
    }
    /**
     * lets say we print all employees
     */
    void operation() override{
        for( auto& it:children){
            cout<<"Employee is:"<<it->getName()<<"is a: "<<typeid(it).name()<<endl;
        }
    }
};
class Engineer:public Employee{
public:
    Engineer(string name,int age):Employee(name,age){}
    void remove(Employee*)override{
    }
    void add(Employee*&)override{}
    string getName()const override {
        return this->name;
    }
    Employee*& getEmployee(int index)override{
        return reinterpret_cast<Employee *&>(*this);
    }
    void operation() override {
        cout << "Employee is:" << this->getName() << "is a: " << typeid(this).name() << endl;
    }
};
#endif //ADVANCEDPROGRAMMING1_COMPOSITE_H
