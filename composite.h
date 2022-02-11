//
// Created by roei on 11/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_COMPOSITE_H
#define ADVANCEDPROGRAMMING1_COMPOSITE_H
class CompoundGraphic;
class Graphic;
//The composite
class Graphic{
    CompoundGraphic comp_graphic;
public:
    Graphic(CompoundGraphic comp_graphic): comp_graphic(comp_graphic){};
    virtual void move(float x, float y)=0;
    virtual void draw()=0;

};
class CompoundGraphic{
    Graphic child;

};
#endif //ADVANCEDPROGRAMMING1_COMPOSITE_H
