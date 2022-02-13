//
// Created by roei on 13/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_PROXY_H
#define ADVANCEDPROGRAMMING1_PROXY_H
class Image;

class Image{
public:
    virtual void display() =0;
};
class RealImage:public Image{
public:
    string fileName;
    RealImage(const string&& fileName):fileName(fileName){}
    void display()override{
        cout<<"Picture is: "<<fileName<<endl;
    }
    void loadFromDisk(string& file){
        cout<<"Loading "<<file<<" from disk...."<<endl;
    }
    ~RealImage()=default;

};
class ProxyImage:public Image{
public:
    RealImage* realImage;
    const string fileName;
    //realImage is the object its self, we want to assign it to a pointer, thus we need to assign its address to ref.
    //realImage1 is lvalue.
    ProxyImage(const string&& fileName):fileName(fileName){}
    void display() override{
        if(!(realImage)){
            this->realImage=new RealImage(move(this->fileName));
        }
        realImage->loadFromDisk(realImage->fileName);
        realImage->display();
    }
    ~ProxyImage(){
        delete(realImage);
    }
};
class ProxyPatternDemo{
public:
    void operate(){
        Image* image=new ProxyImage("test_10mb.jpg");
        image->display();
    }
};

#endif //ADVANCEDPROGRAMMING1_PROXY_H
