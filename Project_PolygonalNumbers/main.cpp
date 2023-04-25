#include <iostream>
#include <cmath>
#include <fstream>

class CentralPolygonalNumbers{

public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    bool save(std::string strFilename);
    int calculatePizza(int a);

private:
    int m_Max;
    int* mp_iNumbers;
    std::ofstream ofsNumbers;

};

CentralPolygonalNumbers::CentralPolygonalNumbers() {

mp_iNumbers = new int[0];
m_Max = 0;
mp_iNumbers[0] = 1;

}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) {

    m_Max = nMax + 1;
    mp_iNumbers = new int[m_Max];

    for (int i = 0; i < m_Max; i++){
        mp_iNumbers[i] = calculatePizza(i);
    }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers() {

    delete [] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display() {

    for (int i = 0; i < m_Max; i++){
        std::cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << std::endl;
    }
}

bool CentralPolygonalNumbers::save(std::string strFilename) {

    ofsNumbers.open(strFilename);

    for (int i = 0; i < m_Max; i++){
        ofsNumbers << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << "\n";
    }

    ofsNumbers.close();
}

int CentralPolygonalNumbers::calculatePizza(int a) {

    int x = ((pow(a, 2)) + a + 2) / 2;

    return x;
}

int main() {
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN.txt");
    return 0;
}
