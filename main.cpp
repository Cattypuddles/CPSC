#include <iostream>
#include <string>
#include <math.h>

double m_TwelfthRootOfTwo = 1.059463094359;
double m_refFreq = 16.35;
double m_speedOfSound = 345;


double calcFrequency(double v, double half){

    double ret;

    ret = m_refFreq * (pow(2, v)) * (pow(m_TwelfthRootOfTwo, half));

    return ret;

}

double calcWavelength(double freq){
    double urn;

    urn = m_speedOfSound / freq;

    urn = urn * 100;

    return urn;
}

void projectMusic(){

}

int main() {
    std::cout << "Reference Frequency: " << m_refFreq << " Hz" << std::endl;
    std::cout << "Speed of Sound: " << m_speedOfSound << " m/s" << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(0, 0) << " Hz; Wavelength: " <<
        calcWavelength(calcFrequency(0, 0)) << " cm." << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(0, 1) << " Hz; Wavelength: " <<
              calcWavelength(calcFrequency(0, 1)) << " cm." << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(0, 2) << " Hz; Wavelength: " <<
              calcWavelength(calcFrequency(0, 2)) << " cm." << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(4, 0) << " Hz; Wavelength: " <<
              calcWavelength(calcFrequency(4, 0)) << " cm." << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(7, 3) << " Hz; Wavelength: " <<
              calcWavelength(calcFrequency(7, 3)) << " cm." << std::endl;

    std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(8, 0) << " Hz; Wavelength: " <<
              calcWavelength(calcFrequency(8, 0)) << " cm." << std::endl;

    return 0;
}
