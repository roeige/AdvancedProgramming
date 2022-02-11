//
// Created by roei on 11/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_COMPOSITE_H
#define ADVANCEDPROGRAMMING1_COMPOSITE_H
class Composite{

};
class Component{
    Composite composite;
public:
    Component(Composite composite):composite(composite){};
    virtual void execute()=0;
};
#endif //ADVANCEDPROGRAMMING1_COMPOSITE_H
