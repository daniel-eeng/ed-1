#include <iostream>
#include <ostream>

void analisar_elementos(int vetor[], int ultimo, int &min, int &max) {

    min = vetor[0];
    max = vetor[0];

    for (int i = 1; i < ultimo; i++) {
        if (vetor[i] < min) {
            min = vetor[i];
        }

        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

}

int main() {

    int vetor[10] = {0, -100, 234, 345, 5, 1, 10, 20, 900, 1000};
    int ultimo = 10;
    int min;
    int max;

    analisar_elementos(vetor, ultimo, min, max);

    std::cout << "Menor elemento: " << min << ". Maior elemento: " << max << std::endl;

    return 0;
}

