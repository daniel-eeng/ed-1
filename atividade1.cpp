#include <iostream>
#include <string>

int const MAX = 10;

enum {
    SAIR,
    LER,
    IMPRIMIR,
    IMPRIMIR_MAX,
};

struct Livro {

    std::string titulo;
    std::string autor;
    int num_paginas;

    void ler() {
        std::cout << "Digite o titulo do livro: ";
        std::cin >> titulo;
        std::cout << "Digite o nome do autor: ";
        std::cin >> autor;
        std::cout << "Digite o numero de paginas: ";
        std::cin >> num_paginas;
    }

    void imprimir() {
        std::cout << "Titulo: ";
        std::cout << titulo << std::endl;
        std::cout << "Autor: ";
        std::cout << autor << std::endl;
        std::cout << "Numero de paginas: ";
        std::cout << num_paginas << std::endl;
    }

};

struct Biblioteca {

    struct Livro l[MAX];
    int ultimo = 0;

    void ler() {

        if (ultimo >= MAX) {
            std::cout << "Erro. Numero maximo registrado.\n";
            return;
        }

        l[ultimo].ler();
        ultimo++;
    }

    void imprimir() {

        for (int i = 0; i < ultimo; i++) {
            l[i].imprimir();
        }
    }

    void imprimir_max() {

        int n = 0;

        for (int i = 0; i < ultimo; i++) {
            if (l[i].num_paginas >= l[n].num_paginas) {
                n = 1;
            }
        }

        l[n].imprimir();
    }


};

int main() {

    struct Biblioteca b;
    int opcao;

    while (opcao != SAIR) {

        std::cout << "\n\nDigite uma opcao:\n";
        std::cout << "Sair: 0.\n";
        std::cout << "Ler: 1.\n";
        std::cout << "Imprimir todos: 2.\n";
        std::cout << "Imprimir o maior livro: 3\n";

        std::cout << "Opcao: ";
        std::cin >> opcao;

        std::cout << "\n\n";

        switch(opcao) {
            case SAIR:
                std::cout << "Terminando programa.\n";
                return 0;
                break;
            case LER:
                b.ler();
                break;
            case IMPRIMIR:
                b.imprimir();
                break;
            case IMPRIMIR_MAX:
                b.imprimir_max();
                break;
        }
    }

    return 0;
}

