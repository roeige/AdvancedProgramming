#include <iostream>
#include "BridgePattern.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "FlyWeight.h"
#include "Proxy.h"
#include "FactoryPattern.h"
#include "AbstractFactory.h"
#include <functional>
#include "Prototype.h"
#include "Builder.h"
#include "Singelton.h"
#include "Command.h"
#include "Iterator.h"
#include "ObserverPattern.h"

void operateBridgePattern() {
    Device *radio = new Radio(100, 100.00);
    if (!(radio->isEnabled()))
        std::cout << "too bad the radio is not On" << std::endl << "We like to listen on channel:"
                  << radio->getChannel() << std::endl;
    Remote remote = (radio);
    remote.togglePower();
    if (radio->isEnabled())
        std::cout << "how fun now we can listen to the radio" << std::endl;
    remote.channelDown();
    remote.volumeUp().volumeUp().volumeUp();
    std::cout << "new volume: " << radio->getVolume() << std::endl;

}

//void compositeOperate(){
//    auto lst=list<Employee>();
//    Employee* high_tech=new Manager("Alice", 28, lst);
//    Employee* engineer1=new Engineer("Bob",24);
//    Employee* engineer2=new Engineer("David",26);
//    auto lst2=list<Employee>();
//    Employee* manager=new Manager("Roei",30,lst2);
//    high_tech->add(*manager);
//    high_tech->add(*engineer1);
//    high_tech->add(*engineer2);
//    high_tech->operation();
//}
void decorate() {
    GUIitem *g1 = new Scrollbars(new Border(new ListView()));
    g1->paint();
    cout<<endl;
}
void facade(){
    /**
     * Everything is getting done by the Facade, all we have to do is to acknowledge it and use it
     */
    Facade shape_maker=Facade();
    shape_maker.drawCircle();
    shape_maker.drawRectangle();
    shape_maker.drawSquare();
}
void flyWeight(){
    FlyWeightPatternDemo demo=FlyWeightPatternDemo();
    demo.operate();
}
void proxy(){
    ProxyPatternDemo demo=ProxyPatternDemo();
    demo.operate();
}
void factoryPattern(){
    FactoryPatternDemo demo=FactoryPatternDemo();
    demo.operate();
}
void abstractFactoryPattern(){
    AbstractFactoryDemo demo=AbstractFactoryDemo();
    demo.operate();
}
void builder(){
    LevelDirector levelDirector=LevelDirector();
    LevelBuilder* mario_level=new MarioLevelBuilder();
    levelDirector.construct(mario_level);
    levelDirector.draw();
    delete(mario_level);
}
//void singelton(){
//    Singelton* obj=&Singelton::getInstance();
//}
void command(){
    CommandPatternDemo demo=CommandPatternDemo();
    demo.operate();
}
void iteratorTest(){
    TestDemo demo=TestDemo();
    demo.operate();
}
int main() {
    operateBridgePattern();
//   compositeOperate();
    decorate();
    facade();
    flyWeight();
    proxy();
    factoryPattern();
    abstractFactoryPattern();
    builder();
    command();
    iteratorTest();
    return 0;
}
