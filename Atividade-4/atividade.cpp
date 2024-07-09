#include <stdio.h>
#include <iostream>

struct Node {

    int key;
    Node *next;

    Node() {
        next = NULL;
    }

    Node(int _key) {
        key = _key;
        next = NULL;
    }

};

struct List {

    Node *head;
    Node *tail;
    int n = 0;

    List() {
        head = NULL;
        tail = NULL;
    }

    void inserir_inicio(int _key) {
        Node *new_node = new Node(_key);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }

        n++;
    }

    void inserir_final(int _key) {
        Node *new_node = new Node(_key);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        n++;
    }

    void remover_inicio() {

        if (n == 0) {
            printf("Nenhum item foi removido. Lista vazia\n");
            return;
        } else if (n == 1) {
            delete(head);
            head = NULL;
            tail = NULL;
            n--;
            return;
        }

        Node *temp = head;
        head = temp->next;
        delete(temp);
        n--;
    }

    void remover_final() {

        if (n == 0) {
            printf("Nenhum item foi removido. Lista vazia\n");
            return;
        } else if (n == 1) {
            delete(head);
            head = NULL;
            tail = NULL;
            n--;
            return;
        }

        Node *temp = head;

        while(temp->next != tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete(tail);
        tail = temp;
        n--;
    }

    void imprimir_lista() {

        if (n == 0) {
            printf("Nao foi possivel imprimir. Lista vazia\n");
            return;
        }

        Node *temp = head;

        while (temp->next != NULL) {
            printf("%d\n", temp->key);
            temp = temp->next;
        }

        printf("%d\n", temp->key);
    }

    void remover_num_final(int num) {

        if (n == 0) {
            printf("Nenhum item foi removido. Lista vazia\n");
            return;
        }

        if (n < num) {
            num = n;
        }

        for (int i = 0; i < num; i++) {
            remover_final();
        }
    }

    void remover_segundo() {

        if (n <= 1) {
            return;
        }

        Node *temp = head->next;
        head->next = temp->next;
        delete(temp);
    }

    void inserir_total_final() {
        inserir_final(n);
    }

    void fatorial(int num) {
        for (int i = 1; i <= num; i++) {
            inserir_final(i);
        }
    }

    void inserir_penultima_pos(int _key) {
        if (n <= 1) {
            return;
        }

        Node *temp = head;
        Node *new_node = new Node(_key);

        while (temp->next != tail) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

};

int main() {

    List l;

    int opcao = -1;
    int num;

    while (true) {

        printf("\n\nSelecione uma opcao: \n");
        printf("0: Sair\n");
        printf("1: Adicionar numero no inicio\n");
        printf("2: Adicionar numero no final\n");
        printf("3: Remover numero no inicio\n");
        printf("4: Remover numero no final\n");
        printf("5: Imprimir lista\n");
        printf("6: Remover numero de elementos do final\n");
        printf("7: Remover segundo elemento\n");
        printf("8: Inserir no final o numero de itens\n");
        printf("9: Inserir numeros de 1 a N no final\n");
        printf("10: Inserir numero na penultima posicao\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                return 0;
                break;
            case 1:
                printf("Digite o numero a ser adicionado:");
                scanf("%d", &num);
                l.inserir_inicio(num);
                break;
            case 2:
                printf("Digite o numero a ser adicionado:");
                scanf("%d", &num);
                l.inserir_final(num);
                break;
            case 3:
                l.remover_inicio();
                break;
            case 4:
                l.remover_final();
                break;
            case 5:
                printf("\n");
                l.imprimir_lista();
                break;
            case 6:
                printf("Digite numero de elementos que quer remover: ");
                scanf("%d", &num);
                l.remover_num_final(num);
                break;
            case 7:
                l.remover_segundo();
                break;
            case 8:
                l.inserir_total_final();
                break;
            case 9:
                printf("Digite o numero N para adicionar [1..N] no final: ");
                scanf("%d", &num);
                l.fatorial(num);
                break;
            case 10:
                printf("Digite o numero a ser adicionado na penultima posicao: ");
                scanf("%d", &num);
                l.inserir_penultima_pos(num);
                break;
        }

    }

    return 0;
}
