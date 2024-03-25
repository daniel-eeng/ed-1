#include <iostream>
#include <ostream>

int main() {

    int a;
    int b;

    std::cout << "Digite uma variavel: ";
    std::cin >> a;
    std::cout << "Digite outra variavel: ";
    std::cin >> b;

    std::cout << "Enderecos em ordem: " << &a << " e " << &b << std::endl;

    if (&a > &b) {
        std::cout << "Variavel com endereco maior: " << a << std::endl;
    } else {
        std::cout << "Variavel com endereco maior: " << b << std::endl;
    }

    return 0;
}
