#include <iostream>
#include <stdlib.h>
#include <iomanip>



class ElectronicControlUnit{

public:
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cCommand);

private:
    bool m_ActivateHydraulicJacks;
    bool m_ActivateBeltTires;
    bool m_ActivateIRIllumination;

    void actuateHydraulicJacks();
    void actuateBeltTires();
    void actuateInfaredLights();
    void shutOffVehicle();
    void printSteeringWheel();
};

ElectronicControlUnit::ElectronicControlUnit(){
    std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;
    printSteeringWheel();
}

ElectronicControlUnit::~ElectronicControlUnit(){

}

void ElectronicControlUnit::handleCommand(char cCommand) {

    switch(cCommand){
        case 'A':
        case 'a':
            actuateHydraulicJacks();
            break;

        case 'B':
        case 'b':
            actuateBeltTires();
            break;

        case 'E':
        case 'e':
            actuateInfaredLights();
            break;

        case 'X':
        case 'x':
            shutOffVehicle();
            break;

        default:
            std::cout << "Incorrect command. Try again." << std::endl;
    }
}

void ElectronicControlUnit::printSteeringWheel(){
    //11 CHAR per line
    //each item is three char
    //seven width for top and bottom
        //then output 4 more char
    //third line has five char spaces in between
    std::cout << std::setw(7) << std::right << "(A)";
    std::cout << std::setw(4) << std::endl;
    std::cout << std::setw(11) << "(F) (G) (B)" << std::endl;
    std::cout << std::setw(8) << std::left << "(E)";
    std::cout << std::setw(3) << "(C)" << std::endl;
    std::cout << std::setw(7) << std::right << "(D)";
    std::cout << std::setw(4) << std::endl;

}

void ElectronicControlUnit::actuateHydraulicJacks(){

    if (!m_ActivateHydraulicJacks){
        m_ActivateHydraulicJacks = true;
        std::cout << "Hydraulic Jacks Activated" << std::endl;
        if (m_ActivateBeltTires){
            m_ActivateBeltTires = false;
            std::cout << "Belt Tires Deactivated" << std::endl;
        }
    }
    else{
        m_ActivateHydraulicJacks = false;
        std::cout << "Hydraulic Jacks Deactivated" << std::endl;
    }
    printSteeringWheel();
}

void ElectronicControlUnit::actuateInfaredLights() {

    if (!m_ActivateIRIllumination){
        m_ActivateIRIllumination = true;
        std::cout << "Infrared Illumination Activated" << std::endl;
    }
    else{
        m_ActivateIRIllumination = false;
        std::cout << "Infrared Illumination Deactivated" << std::endl;
    }
    printSteeringWheel();
}

void ElectronicControlUnit::actuateBeltTires() {

    if (!m_ActivateBeltTires){
        m_ActivateBeltTires = true;
        std::cout << "Belt Tires Activated" << std::endl;
    }
    else{
        m_ActivateBeltTires = false;
        std::cout << "Belt Tires Deactivated" << std::endl;
    }
    printSteeringWheel();
}

void ElectronicControlUnit::shutOffVehicle() {
    exit(69420);
}


int main() {
    ElectronicControlUnit ec;
    char c;
    while (c){
        std::cin >> c;
        ec.handleCommand(c);
    }

    return 0;
}
