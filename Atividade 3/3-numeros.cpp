#include <iostream>
#include <ostream>

void partes(double valor, double &fracao, int &inteiro) {
    
    inteiro = valor;
    fracao = valor - inteiro;

}

int main() {

    int inteiro;
    double fracao;

    partes(234.56, fracao, inteiro);
    std::cout << "Valor inicial: 234.56. Valor inteiro: " << inteiro << ". Fracao: " << fracao << "." << std::endl;    

    partes(345.234, fracao, inteiro);
    std::cout << "Valor inicial: 345.234. Valor inteiro: " << inteiro << ". Fracao: " << fracao << "." << std::endl;    

    return 0;
}

