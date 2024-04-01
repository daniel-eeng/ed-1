#include <iostream>
#include <limits>
#include <ostream>
#include <string>

const int MAX = 20;

enum {
    SAIR,
    VAZIO,
    LER,
    UNIAO,
    INTERSECCAO,
    IMPRIMIR,
};

struct Conjunto {

    int n;
    int valores[MAX];
    int pos;

    void vazio() {
        n = 0;
        pos = 0;
    }

    void ler() {

        std::string str;
        std::string valor = "";
        int ultimo = 0;

        std::cout << "Digite o numero de elementos no conjunto: ";
        std::cin >> n;

        if (n > MAX) {
            std::cout << "Erro. Numero inserido excede o valor maximo.\n";
            return;
        }

        std::cout << "Digite os elementos separados por espaco: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, str);

        for (int i = 0; i < str.size(); i++) {
            if (ultimo == n) {
                break;
            }

            if (isdigit(str[i])) {
                valor.push_back(str[i]);
            }

            if (isspace(str[i]) || (i == str.size() - 1)) {
                valores[ultimo] = std::stoi(valor);
                valor = "";
                ultimo++;
            }
        }

        pos = ultimo;
    }

    void imprimir() {

        std::cout << "[";

        for (int i = 0; i < pos; i++) {
            if (i != pos - 1) {
                std::cout << valores[i] << ", ";
            } else {
                std::cout << valores[i] << "]" << std::endl;
            }
        }
    }

    void uniao(struct Conjunto c) {

        int limite = n + c.n;
        int ultimo = 0;

        if (limite > MAX) {
            std::cout << "Erro. Limite de elementos ultrapassado\n";
            return;
        }

        if (n == 0 && c.n == 0) {
            return;
        } else if (n == 0 && c.n > 0) {
            n = c.n;

            for (int i = 0; i < limite; i++) {
                valores[i] = c.valores[i];
            }
        } else if (n > 0 && c.n == 0){
            c.n = n;

            for (int i = 0; i < limite; i++) {
                c.valores[i] = valores[i];
            }

        } else {
            for (int i = n; i < limite; i++) {
                valores[i] = c.valores[i - n];
            }
        }

        pos = limite;
    }

    void interseccao(struct Conjunto c) {

        int limite = n;
        int ultimo = 0;
        int temp[n];

        if (n < c.n) {
            limite = c.n;
        }

        if (n == 0 || c.n == 0) {
            std::cout << "Um dos conjuntos esta vazio. Interseccao nao e possivel.\n";
            return;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < c.n; j++) {
                    if (valores[i] == c.valores[j]) {
                        temp[ultimo] = valores[i];
                        ultimo++;
                    }
                }
            }
        }

        pos = limite;
    }

};

struct Funcoes {

    struct Conjunto c[MAX];
    int ultimo = 0;

    void vazio() {
        if (ultimo < MAX) {
            c[ultimo].vazio();
            ultimo++;
        } else {
            std::cout << "Erro. Numero maximo criado.\n";
        }
    }

    void novo() {
        if (ultimo < MAX) {
            c[ultimo].ler();
            ultimo++;
        } else {
            std::cout << "Erro. Numero maximo criado.\n";
        }
    }

    void unir() {

        int a;
        int b;

        std::cout << "Uniao: escolha dois conjuntos dentre as opcoes abaixo. Para escolher um conjunto, digite os numeros juntos dos 'c's. Exemplo: para unir c1 e c2, digite \"1\", aperte enter, e depois \"2\"\n";

        for (int i = 0; i < ultimo; i++) {
            std::cout << "c" << i << " ";
        }

        std::cout << std::endl;

        std::cin >> a;
        std::cin >> b;

        c[a].uniao(c[b]);
    }

    void encontrar_interseccao() {

        int a;
        int b;

        std::cout << "Interseccao: escolha dois conjuntos dentre as opcoes abaixo. Para escolher um conjunto, digite os numeros juntos dos 'c's. Exemplo: para encontrar a interseccao entre c1 e c2, digite \"1\", aperte enter, e depois \"2\"\n";

        for (int i = 0; i < ultimo; i++) {
            std::cout << "c" << i << " ";
        }

        std::cout << std::endl;

        std::cin >> a;
        std::cin >> b;

        c[a].interseccao(c[b]);
    }

    void print() {

        int a;

        std::cout << "Imprimir: escolha um conjunto dentre as opcoes abaixo. Para escolher um conjunto, digite os numeros juntos dos 'c's. Exemplo: para imprimir c1, digite \"1\" e aperte enter\n";

        for (int i = 0; i < ultimo; i++) {
            std::cout << "c" << i << " ";
        }

        std::cout << std::endl;

        std::cin >> a;

        c[a].imprimir();

    }

};

int main() {

    struct Funcoes f;
    int opcao = -1;

    while (true) {

        std::cout << "\n\n";
        std::cout << "Digite uma opcao: \n";
        std::cout << "Sair: 0\n";
        std::cout << "Criar conjunto vazio: 1\n";
        std::cout << "Novo conjunto: 2\n";
        std::cout << "Unir conjuntos: 3\n";
        std::cout << "Encontrar interseccao: 4\n";
        std::cout << "Imprimir conjunto: 5\n";

        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch(opcao) {
            case SAIR: 
                std::cout << "Terminando programa.\n";
                return 0;
                break;
            case VAZIO:
                f.vazio();
                break;
            case LER:
                std::cout << "\n\n";
                f.novo();
                break;
            case UNIAO:
                std::cout << "\n\n";
                f.unir();
                break;
            case INTERSECCAO:
                std::cout << "\n\n";
                f.encontrar_interseccao();
                break;
            case IMPRIMIR:
                std::cout << "\n\n";
                f.print();
                break;
        }
    }

    return 0;
}

