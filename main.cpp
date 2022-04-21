#include <iostream>
#include <cmath>

using tf = double (*)(double);

double methodOfMovableChord(double a, double b, double eps, tf f) {
    while (fabs(a - b) >= eps) {
        a = b - (b - a) * f(b) / (f(b) - f(a));
        b = a - (a - b) * f(a) / (f(a) - f(b));
    }

    return b;
}

double f(double x) {
    return sqrt(x) - 1;
}

int main() {
    double a, b;
    std::cout << "Enter begin of section: " << std::endl;
    std::cin >> a;

    std::cout << "Enter end of section: " << std::endl;
    std::cin >> b;

    std::cout << methodOfMovableChord(a, b, 0.1, f);

    return 0;
}
