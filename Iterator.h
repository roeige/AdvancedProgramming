//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_ITERATOR_H
#define ADVANCEDPROGRAMMING1_ITERATOR_H

//example for iterator from test 2021A
template<class T>
class ImmutableList {
    T head;
    ImmutableList<T> *tail;

    ImmutableList(T t, ImmutableList<T> *tail) : head(t), tail(tail) {}

public:
    ImmutableList(T t) : head(t), tail(nullptr) {}

    ImmutableList<T> *push(T t) {
        return new ImmutableList(t, this);
    }

    T get() {
        return head;
    }


    ~ImmutableList() {
        delete tail;
    }
    /**
     * Now we implement iterator and its operators
     */
     class Iterator;
     Iterator begin(){
         return Iterator(this);
     }
     Iterator end(){
         //or just could return iterator(nullptr).
         while(tail){
             tail++;
         }
         return Iterator(tail);
     }
     class Iterator{
         ImmutableList<T>*a;
     public:
         Iterator(ImmutableList<T>*a):a(a){}
         bool operator==(Iterator& other){
             return other.a==a;
         }
         bool operator!=(Iterator& other){
             return !(other==*this);
         }
         void operator++(){
             a->tail;
         }
         ImmutableList<T>& operator*(){
             return *a;
         }
     };
};
class TestDemo{
public:
    void operate(){
        ImmutableList<int>* a=new ImmutableList<int>(3);
        a=a->push(2);
        a=a->push(1);
        for_each(a->begin(),a->end(),[](ImmutableList<int>*a){cout<<a->get()<<endl;});
    }
};

#endif //ADVANCEDPROGRAMMING1_ITERATOR_H
