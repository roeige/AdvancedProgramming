//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_SINGELTON_H
#define ADVANCEDPROGRAMMING1_SINGELTON_H
class Singleton{
public:
    static Singleton* singleton;
private:
    Singleton(){}
    ~Singleton(){}
    Singleton& operator=(Singleton&){}

public:
     static Singleton*& getInstance() {
        if (Singleton::singleton!=nullptr) {
            cout<<"singleton already exists!"<<endl;
            return singleton;
        }
        cout<<"New singleton!"<<endl;
        singleton=new Singleton();
        return singleton;
    }
};
Singleton* Singleton::singleton=nullptr;
class DemoSingleton{
public:
    void operate(){
        Singleton* s1=Singleton::getInstance();
        Singleton* s2=Singleton::getInstance();
    }
};

#endif //ADVANCEDPROGRAMMING1_SINGELTON_H
