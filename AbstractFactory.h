//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMING1_ABSTRACTFACTORY_H
class Sword{
public:
virtual void draw()=0;
virtual ~Sword()=default;
};
class PlainSword:public Sword{
public:
    void draw()override{
        cout<<"Plain Sword"<<endl;
    }
};
class Lightsaber:public Sword{
public:
    void draw()override{
        cout<<"Lightsaber Sword!"<<endl;
    }
};
class Shield{
public:
    virtual void draw()=0;
    virtual ~Shield()=default;
};
class PlainShield:public Shield{
public:
    void draw()override{
        cout<<"Plain Shield"<<endl;
    }
};
class Deflector:public Shield{
public:
    void draw()override{
        cout<<"Deflector Shield!"<<endl;
    }
};
class Armory{
public:
    virtual Sword& createSword()=0;
    virtual Shield& createShield()=0;
};
class StarWarsArmory:public Armory{
public:
    virtual Sword& createSword()override{
        return *new Lightsaber();
    }
    virtual Shield& createShield()override{
       return *new Deflector();
    }
};
class PlainArmory:public Armory{
public:
    virtual Sword& createSword()override{
        return *new PlainSword();
    }
    virtual Shield& createShield()override{
       return *new PlainShield();
    }
};
class AbstractFactoryDemo{
public:
    void operate(){
        //its the  factory creator.
        Armory* a=new StarWarsArmory();
        Sword* sword=&a->createSword();
        Shield* shield=&a->createShield();
        sword->draw();
        shield->draw();
        delete(sword);
        delete(shield);
    }
};

#endif //ADVANCEDPROGRAMMING1_ABSTRACTFACTORY_H
