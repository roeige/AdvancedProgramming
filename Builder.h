//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_BUILDER_H
#define ADVANCEDPROGRAMMING1_BUILDER_H
typedef struct{
    int x,y;
}Position;
typedef struct{
    Position position;
}Character;
typedef struct{
    Position position;
    int len;
}Platform;
class Level{
public:
    vector<Character> enemyLst;
    vector<Character> characterLst;
    Platform platform;
    ~Level(){
        //destruct all allocations.
    }
};
class MarioLevel:public Level{
};
class LevelBuilder{
public:
    virtual void createPlatform(int length)=0;
    virtual void createCharacter(int x ,int y)=0;
    virtual void createEnemy(int x ,int y)=0;
    virtual Level* getLevel()=0;
};
class MarioLevelBuilder:public LevelBuilder{
    Level* level;
public:
    MarioLevelBuilder(){
        level=new MarioLevel();

    }
    virtual void createPlatform(int length)override{
        cout<<"Platformed created!"<<endl;
        this->level->platform.len=length;
    }
    virtual void createCharacter(int x ,int y)override{
        auto charc=new Character;
        charc->position.x=x;
        charc->position.y=y;
        this->level->characterLst.push_back(*charc);
        cout<<"Character created!"<<endl;
    }
    virtual void createEnemy(int x ,int y)override{
        auto enemy=new Character;
        enemy->position.x=x;
        enemy->position.y=y;
        this->level->enemyLst.push_back(*enemy);
        cout<<"Enemy created!"<<endl;
    }
    virtual Level* getLevel() override{
        return this->level;
    }
};
class LevelDirector{
public:
    Level* level;
    virtual void construct(LevelBuilder* builder){
        //to platform we should add poistion, but for the example.
        int length=300;
        builder->createPlatform(length);
        builder->createCharacter(3,4);
        //create 4 enemies
        srand(0);
        for(int i=0;i<4;i++){
            builder->createEnemy(rand()%length,rand()%length);
        }
        level=builder->getLevel();
    }
    virtual void draw(){
        cout<<"Platform is over: "<<level->platform.len<<endl;
        for(auto it:level->enemyLst){
            cout<<"Enemy poistion: ("<<it.position.x<<","<<it.position.y<<" )"<<endl;
        }
        for(auto it:level->characterLst){
            cout<<"Character poistion: ("<<it.position.x<<","<<it.position.y<<" )"<<endl;
        }
    }
};
#endif //ADVANCEDPROGRAMMING1_BUILDER_H
