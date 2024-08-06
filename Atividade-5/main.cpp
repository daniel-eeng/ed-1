#include <stdio.h>

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

struct Stack {

    Node *top;
    int n;

    Stack() {
        top = NULL;
        n = 0;
    }

    void inserir(int valor) {
        Node *new_node = new Node(valor);
        if (n != 0) {
            new_node->next = top;
        }
        top = new_node;
        n++;
    }

    int remover() {

        if (n == 0) {
            printf("Stack underflow\n");
            return -1;
        }

        int popped = top->key;
        Node *aux = top;

        top = aux->next;
        delete(aux);

        n--;
        return popped;
    }

    int topo() {
        if (n == 0) {
            printf("Pilha vazia\n");
            return -1;
        }

        printf("Topo: %d\n", top->key);

        return top->key;
    }

};

struct Queue {

    Node *head;
    Node *tail;
    int n;

    Queue() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    void queue(int valor) {
        Node *new_node = new Node(valor);
        if (n != 0) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        n++;
    }

    int dequeue() {

        if (n == 0) {
            printf("Fila vazia\n");
            return -1;
        }

        int dequeued= head->key;
        Node *aux = head;

        head = aux->next;
        delete(aux);

        n--;
        return dequeued;
    }

    int frente() {
        if (n == 0) {
            printf("Fila vazia\n");
            return -1;
        }

        printf("Frente: %d\n", head->key);

        return head->key;
    }

};

int main() {

    Stack Pilha;
    Queue Fila;

    Fila.queue(1);
    Fila.queue(2);
    Fila.queue(3);
    Fila.queue(4);
    Fila.queue(5);
    Fila.frente();

    Pilha.inserir(Fila.dequeue());
    Pilha.inserir(Fila.dequeue());
    Pilha.inserir(Fila.dequeue());
    Pilha.inserir(Fila.dequeue());
    Pilha.inserir(Fila.dequeue());

    Fila.queue(Pilha.remover());
    Fila.queue(Pilha.remover());
    Fila.queue(Pilha.remover());
    Fila.queue(Pilha.remover());
    Fila.queue(Pilha.remover());
    Fila.frente();

    return 0;
}
