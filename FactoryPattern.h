//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_FACTORYPATTERN_H
#define ADVANCEDPROGRAMMING1_FACTORYPATTERN_H
#include <list>
#include <functional>
using namespace std;
class Worker{
public:
    //we should make it private, but for the example.
    string name;
    Worker(const string& name):name(name){}
    Worker(){}
    virtual Worker& setName(const string& name)=0;
};
class Lecture:public Worker{
public:
    Worker& setName(const string& name) override
    {
        this->name=name;
        return *this;
    }
};
class TA:public Worker{
public:
    Worker& setName(const string& name)override
    {
        this->name=name;
        return *this;
    }
};
class Admin:public Worker{
public:
    Worker& setName(const string& name) override
    {
        this->name=name;
        return *this;
    }
};
class WorkerCreator{
    virtual void create()=0;
};
class WorkerFactory{
public:
    map<string,std::function<Worker*()>> hash_map;
    WorkerFactory(){
        //we assume user inserts names right. otherwise we will fail.
        hash_map.insert({"Lecture",[](){return new Lecture();}});
        hash_map.insert({"TA",[](){return new TA();}});
        hash_map.insert({"Admin",[](){return new Admin();}});
    }
    Worker* getWorker(string& type,string& name) {
        auto it = hash_map.find(type);
        if (it != hash_map.end()) {
            return &hash_map.at(type)()->setName(name);
        }
        return nullptr;
    }
};
class FactoryPatternDemo{
public:
    array<string, 4> arr = {{"Moshe", "David", "Melman", "Roei"}};
    array<string, 3> arr_type = {{"Lecture", "TA", "Admin"}};
    void operate(){
        int random;
        srand(time(0));
        WorkerFactory factory=WorkerFactory();
        list<Worker*> worker_list;
        for(int i=0;i<4;i++){
           random=rand()%2;
            worker_list.push_front(factory.getWorker(arr_type[random],arr[i]));
        }
        for(auto& it:worker_list){
            cout<<"Worker: "<<it->name<<" is a: "<<typeid(*it).name()<<endl;
        }
    }
};

#endif //ADVANCEDPROGRAMMING1_FACTORYPATTERN_H
