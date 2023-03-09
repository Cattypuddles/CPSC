//
// Created by Vic on 3/8/2023.
//

#include <iostream>
#include <cfloat>
#include <cmath>
#include <iomanip>

int n;
int k;
double pi = 0.0;

int main(){


    for (n = 2; n <= 1048576; n*2) {
        for (k = 0; k <= n; k++) {
            pi = pi + (4 * ((pow(-1.0, k)) / ((2.0 * k) + 1.0)));
            std::cout << "PI: " << std::setprecision(DBL_DIG) << pi << "; n: " << std::setw(7) << n << std::endl;
        }

    }

}