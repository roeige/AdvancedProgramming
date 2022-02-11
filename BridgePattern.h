//
// Created by roei on 11/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_BRIDGEPATTERN_H
#define ADVANCEDPROGRAMMING1_BRIDGEPATTERN_H


class Device {
    int volume;
    int channel;
    bool enabled;
public:
    Device(int volume, int channel) : volume(volume), channel(channel), enabled(false) {};

    virtual ~Device() = default;

    bool isEnabled() {
        if (this->enabled)
            return true;
        return false;
    }

    void enable() {
        this->enabled = true;
    }

    void disable() {
        this->enabled = false;
    }

    int getVolume() {
        return volume;
    }

    void setVolume(int precent) {
        this->volume = precent;
    }

    int getChannel() {
        return this->channel;
    }

    void setChannel(int channel) {
        this->channel = channel;
    }
};


class Radio : public Device {
    float radio_channel;
public:
    Radio(int volume, float channel) : Device(volume, 0), radio_channel(channel) {};
    ~Radio()override = default;
};

class Remote {
    Device* device;
public:
    Remote(Device* device) : device(device) {};
    void togglePower() {
        if (device->isEnabled())
            device->enable();
        else
            device->disable();
    }

    Remote& volumeDown() {
        device->setVolume(device->getVolume() - 1);
        return *this;
    }

    Remote& volumeUp() {
        device->setVolume(device->getVolume() + 1);
        return *this;
    }

    Remote&  channelDown() {
        device->setChannel(device->getChannel() - 1);
        return *this;
    }

    Remote& channelUp() {
        device->setChannel(device->getChannel() + 1);
        return *this;
    }

};


#endif //ADVANCEDPROGRAMMING1_BRIDGEPATTERN_H
