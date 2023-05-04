//
// Created by victo on 5/3/2023.
//

#include <iostream>
#include <stdexcept>

class Device {
public:
    Device();
    virtual ~Device();
    void enable();
    void activate();

private:
    bool m_bEnabled;
};

Device::Device() : m_bEnabled(false) { } // Default Constructor
Device::~Device() { }                    // Default Destructor

void Device::enable()
{
    m_bEnabled = true;
}

void Device::activate()
{

    // TODO: Replace this with a try catch block
    // FIXME: Find a way to enable device

    try{
        if (!m_bEnabled){
            throw std::runtime_error("Device must be enabled first!");
        }
        std::cout << "Device is now activated!" << std::endl;
    }
    catch(std::runtime_error ex){
        std::cout << ex.what() << std::endl;
    }

    return;
}

int main(int argc, const char * argv[]) {
    Device device;
    device.enable();
    device.activate();
    return 0;
}
