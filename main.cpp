#include <iostream>
#include "BridgePattern.h"

void operateBridgePattern(){
    Device *radio = new Radio(100, 100.00);
    if (!(radio->isEnabled()))
        std::cout << "too bad the radio is not On" << std::endl << "We like to listen on channel:"
                  << radio->getChannel() << std::endl;
    Remote remote=(radio);
    remote.togglePower();
    if(radio->isEnabled())
        std::cout<<"how fun now we can listen to the radio"<<std::endl;
    remote.channelDown();
    remote.volumeUp().volumeUp().volumeUp();
    std::cout<<"new volume: "<<radio->getVolume()<<std::endl;

}
int main() {
   operateBridgePattern();

    return 0;
}
