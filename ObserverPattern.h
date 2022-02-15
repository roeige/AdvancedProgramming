//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_OBSERVERPATTERN_H
#define ADVANCEDPROGRAMMING1_OBSERVERPATTERN_H
class Observer;
class Subject;
class Comp;
class Subject{
    vector<Observer*> lst;
    int state;
public:
    virtual int getState(){
        return state;
    }
    virtual void setState(int state1){
        state=state1;
    }
    virtual void attach(Observer* observer){
        lst.push_back(observer);
    }
    virtual void notifyAllObservers(){
        for(auto& observer:lst){
        }
    }
};
class Observer{
public:
    Subject* subject;
    Observer(Subject* subject1):subject(subject1){}
    virtual void update()=0;
};
class BinaryObserver:public Observer{
    BinaryObserver(Subject* subject): Observer(subject){}
    void update()override{
        cout<<"Binary Sring:"<<subject->getState()<<endl;
    }
};
#endif //ADVANCEDPROGRAMMING1_OBSERVERPATTERN_H
