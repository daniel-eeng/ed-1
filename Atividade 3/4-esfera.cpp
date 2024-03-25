#include <iostream>
#include <cmath>

const double PI = M_PI;

void calcular(double raio, double &area, double &volume) {

    area = pow(raio, 2) * 4 * PI;
    volume = pow(raio, 3) * (4/3) * PI;

}

int main() {

    double area;
    double volume;

    calcular(2, area, volume);
    std::cout << "Raio: 2" << ". Area: " << area << ". Volume: " << volume << "." << std::endl;

    calcular(5, area, volume);
    std::cout << "Raio: 5" << ". Area: " << area << ". Volume: " << volume << "." << std::endl;

    calcular(23.456, area, volume);
    std::cout << "Raio: 23.456" << ". Area: " << area << ". Volume: " << volume << "." << std::endl;

    return 0;
}

