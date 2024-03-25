#include <iostream>
#include <ostream>
#include <string>
#include <cctype>
#include <ctime>

const int MAX = 50;

enum {
    SAIR,
    CADASTRAR,
    LISTAR
};

struct Data {
    int dia;
    int mes;
    int ano;

    time_t horario = time(nullptr);

    tm *horario_agora = localtime(&horario);

    int dia_hoje;
    int mes_hoje;
    int ano_hoje;

    int calcular_idade() {
        if ((horario_agora->tm_mon + 1 - mes > 0) || ((horario_agora->tm_mon + 1 - mes == 0) && (horario_agora->tm_mday - dia >= 0))) {
            return (horario_agora->tm_year + 1900) - ano;
        } else {
            return (horario_agora->tm_year + 1900) - ano - 1;
        }
    }

};

struct Cliente {

    std::string nome;
    struct Data d;
    int idade;
    char sexo;

    void cadastrar() {

        std::string data_string;
        std::string str = "";

        std::cout << "Digite o nome do cliente: ";
        std::cin >> nome;
        std::cout << "Digite o sexo do cliente: ";
        std::cin >> sexo;
        std::cout << "Digite a data de nascimento no formato DD/MM/AAAA: ";
        std::cin >> data_string;

        for (int i = 0; i < data_string.size(); i++) {
            if (isdigit(data_string[i])) {
                str.push_back(data_string[i]);
            } else if (data_string[i] == '/') {
                if (i == 2) {
                    d.dia = std::stoi(str);
                    str = "";
                } else {
                    d.mes = std::stoi(str);
                    str = "";
                }
            }

            if (i == data_string.size() - 1) {
                d.ano = std::stoi(str);
                str = "";
            }
        }

        idade = d.calcular_idade();


    }

    void listar() {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Sexo: " << sexo << std::endl;
        std::cout << "Idade: " << idade << std::endl;
        std::cout << "\n";
    }

};


int main() {

    struct Cliente c[MAX];
    int ultimo = 0;
    int opcao = -1;

    while (true) {

        std::cout << "Digite uma opcao: \n";
        std::cout << "Sair: 0\n";
        std::cout << "Cadastrar cliente: 1\n";
        std::cout << "Listar clientes: 2\n";

        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch(opcao) {
            case 0: 
                std::cout << "Terminando programa.\n";
                return 0;
                break;
            case 1:
                if (ultimo < MAX) {
                    c[ultimo].cadastrar();
                    ultimo++;
                } else {
                    std::cout << "Erro. Numero maximo atingido.\n";
                }
                break;
            case 2:
                std::cout << "\n\n";
                for (int i = 0; i < ultimo; i++) {
                    c[i].listar();
                }
        }

    }


    return 0;
}
