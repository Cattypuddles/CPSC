#include <iostream>
#include <cfloat>
#include <cmath>
#include <iomanip>

int n;
int k;
double pi = 0.0;

int main() {
    std::cout << "Enter the upper bound: " << std::endl;
    std::cin >> n;

    for (k = 0; k <= n; k++){
        pi += (4 *((pow(-1.0, k))/((2.0 * k) + 1.0)));
    }

    std::cout << std::fixed << "PI (approx): " << std::setprecision(15) << pi << "; n: " << std::setw(7) << n << std::endl;
    std::cout << "PI (actual): " << "3.141592653589793" << std::endl;

    std::cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
    std::cout << "Number of base 2 mantissa digits of double precision floating point value: "
              <<  DBL_MANT_DIG << std::endl;
    std::cout << "Next representable number from 3.141592653589793: "
              << std::nextafter(3.141592653589793, 3.14) << std::endl;


    return 0;
}
