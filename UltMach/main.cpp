#include <iostream>

class CUltimateMachine{

public:
    CUltimateMachine() : m_bState(false){

        std::cout << "CUltimateMachine Constructor (ctor) called." << std::endl;

    }

    ~CUltimateMachine(){

        std::cout << "CUltimateMachine destructor (dtor) called." << std::endl;

    }

    void displayState(){

        switch (m_bState){
            case true:
                std::cout << "Ultimate Machine is ON." << std::endl;
                break;
            case false:
                std::cout << "Ultimate Machine is OFF." << std::endl;
                break;
        }
    }

    void turnOn(){
        m_bState = true;
        displayState();
        if (m_bState){
            m_bState = false;
        }
        displayState();
    }

private:
    bool m_bState;

};

int main() {
    std::cout << "The Ultimate Machine Simulation." << std::endl;

    CUltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();
    return 0;
}
