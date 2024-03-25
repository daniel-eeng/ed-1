#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

const int MAX = 10;

enum {
    SAIR,
    CADASTRAR,
    LISTAR,
    MEDIA,
    MAIOR
};

struct Funcionario {

    std::string nome;
    std::string cargo;
    double salario;
    double beneficios;
    double descontos;
    double valor_final;

    void ler() {
        std::cout << "Digite o nome do funcionario: ";
        std::cin >> nome;
        std::cout << "Digite o cargo do funcionario: ";
        std::cin >> cargo;
        std::cout << "Digite o salario base do funcionario: ";
        std::cin >> salario;
        std::cout << "Digite os beneficios do funcionario: ";
        std::cin >> beneficios;
        std::cout << "Digite os descontos do funcionario: ";
        std::cin >> descontos;

        valor_final = salario + beneficios - descontos;
    }


    void imprimir() {

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "\n";
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Cargo: " << cargo << std::endl;
        std::cout << "Salario base: " << salario << std::endl;
        std::cout << "Beneficios: " << beneficios << std::endl;
        std::cout << "Descontos: " << descontos << std::endl;
        std::cout << "Salario liquido: " << valor_final << std::endl;
    }

};

struct Loja {

    struct Funcionario f[MAX];
    int ultimo = 0;

    void cadastrar() {
        if (ultimo < MAX) {
            f[ultimo].ler();
            ultimo++;
        } else {
            std::cout << "Erro. Numero maximo atingido.";
        }
    }

    void listar() {
        for (int i = 0; i < ultimo; i++) {
            f[i].imprimir();
        }
    }

    void media() {

        double media = 0;

        for (int i = 0; i < ultimo; i++){
            media += f[i].valor_final;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "A media salarial e: R$ " << media / (ultimo) << std::endl;
    }

    void maior() {

        int n = 0;

        for (int i = 0; i < ultimo; i++) {
            if (f[i].valor_final >= f[n].valor_final) {
                n = i;
            }
        }

        std::cout << "Informacoes sobre o funcionario mais bem pago: ";
        f[n].imprimir();
    }


};

int main() {

    struct Loja l;
    int opcao = -1;

    while (true) {

        std::cout << "\n\n";
        std::cout << "Digite uma opcao: \n";
        std::cout << "Sair: 0\n";
        std::cout << "Cadastrar funcionario: 1\n";
        std::cout << "Listar funcionarios: 2\n";
        std::cout << "Exibir media salarial: 3\n";
        std::cout << "Exibir dados do funcionario com maior salario: 4\n";

        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch(opcao) {
            case SAIR: 
                std::cout << "Terminando programa.\n";
                return 0;
                break;
            case CADASTRAR:
                l.cadastrar();
                break;
            case LISTAR:
                std::cout << "\n\n";
                l.listar();
                break;
            case MEDIA:
                std::cout << "\n\n";
                l.media();
                break;
            case MAIOR:
                std::cout << "\n\n";
                l.maior();
                break;
        }
    }

    return 0;

}

