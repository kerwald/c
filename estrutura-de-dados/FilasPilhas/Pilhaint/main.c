#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    // exemplo de uso da pilha
    Pilha* pilha = criarPilha();
    Pilha* pilha2 = criarPilha();

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);

    printf("Elemento removido da pilha: %d\n", pop(pilha));
    printf("Elemento removido da pilha: %d\n", pop(pilha));
    printf("Elemento removido da pilha: %d\n", pop(pilha));

    if (estaVazio(pilha))
    	printf("Pilha vazia.\n");
    else 
    	printf("Pilha não está vazia.\n");

    push(pilha, 10);
    push(pilha, 8);
    push(pilha, 30);
    push(pilha, 5);
    push(pilha, 3);
    push(pilha, 6);

    push(pilha2, 10);
    push(pilha2, 8);
    push(pilha2, 30);
    push(pilha2, 5);
    push(pilha2, 3);
    push(pilha2, 6);

    int* resultado = maiormenormedia( pilha );
    printf("\nmaior = %d, menor = %d, media = %.2f\n", *resultado, *(resultado + sizeof(int)), *((float*)(resultado + 2 * sizeof(int))));

    imprimir( pilha );
    ordenapilha( pilha );
    ordenapilha( pilha2 );
    printf( "\n\n" );
    imprimir( pilha );

    printf( "\n\n" );
    int i = testaiguais( pilha, pilha2 );
    printf( "\n%d\n", i );


    destruirPilha(pilha);

    return 0;
}