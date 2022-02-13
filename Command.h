//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_COMMAND_H
#define ADVANCEDPROGRAMMING1_COMMAND_H
class Order{
public:
    virtual void execute()=0;
};
class Stock{
    string name;
    int quantitiy;
public:
    Stock(const string& str,int quant):name(str),quantitiy(quant){}
    virtual void buy(){
        cout<<"Bought!"<<endl;
    }
    virtual void sell(){
        cout<<"Sold!"<<endl;
    }
};
class BuyStock:public Order{
    Stock stock;
public:
    BuyStock(Stock& stock):stock(stock){}
    void execute()override{
        stock.buy();
    }
};
class SellStock:public Order{
    Stock stock;
public:
    SellStock(Stock& stock): stock(stock){}
    void execute()override{
        stock.sell();
    }
};
class Broker{
    vector<Order*> order_lst;
public:
    void takeOrder(Order* order){
        order_lst.push_back(order);
    }
    void placeOrder(){
       for(auto it:order_lst){
           it->execute();
       }
       order_lst.clear();
    }
};
class CommandPatternDemo{
public:
    void operate(){
        Stock abcStock=Stock("Store of the life",4);
        Order* buy=new BuyStock(abcStock);
        Order* sell=new SellStock(abcStock);
        Broker broker=Broker();
        broker.takeOrder(buy);
        broker.takeOrder(sell);
        broker.placeOrder();
    }
};
#endif //ADVANCEDPROGRAMMING1_COMMAND_H
