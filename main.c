#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Erro: pilha cheia\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

void selectionSort(Stack *s) {
    Stack tempStack;
    tempStack.top = -1;

    while (s->top != -1) {
        int min = pop(s);
        
        while (tempStack.top != -1 && tempStack.items[tempStack.top] > min) {
            push(s, pop(&tempStack));  // Erro 1: Deve ser push(&tempStack, pop(&tempStack));
        }
        push(&tempStack, min);
    }

    while (tempStack.top != -1) {
        push(s, pop(&tempStack));  // Erro 2: Deve ser push(s, pop(&tempStack));
    }
}

int main() {
    Stack myStack;
    myStack.top = -1;

    // Inserir números na pilha
    push(&myStack, 8);
    push(&myStack, 3);
    push(&myStack, 1);
    push(&myStack, 5);
    push(&myStack, 4);

    printf("Números antes da ordenação:\n");
    while (myStack.top != -1) {
        printf("%d\n", myStack.items[myStack.top]);
        pop(&myStack);  // Erro 3: O valor já foi removido da pilha com o printf acima, então não deve chamar pop() novamente aqui.
    }

    // Ordenar números
    selectionSort(&myStack);

    printf("\nNúmeros após a ordenação:\n");
    while (myStack.top != -1) {
        printf("%d\n", myStack.items[myStack.top]);
        pop(&myStack);
    }

    return 0;
}
