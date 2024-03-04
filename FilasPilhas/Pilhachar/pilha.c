#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "pilha.h"

int verificaexpressao( char* string ){
    Pilha* pilha = criarPilha();
    if( (int)string[0] == 41 ){
        free( pilha );
        return 0;
    }
    for( int i=0; i<strlen( string ); i++ ){
        if( (int)string[i] == 40 ){
            push( pilha, string[i] );
        } else if( (int)string[i] == 41 ){
            int v = estaVazio( pilha );
            if( v == 1 ){
                free( pilha );
                return 0;
            }
            pop( pilha );
        }
    }
    free( pilha );
    return 1;
}

int verificarpalindromo( char* string ){

    Pilha* pilha = criarPilha();

    for( int i=0; i<strlen( string ); i++ ){
        push( pilha, (char)string[i] );
    }
    for( int i=0; i<strlen( string ); i++ ){
        if( pop( pilha ) != string[i] ){
            free( pilha );
            return 0;
        } 
    }
    free( pilha );
    return 1;

}

int verificarpadraoXY( char* string ){

    int v=0;
    char c;
    int metade = strlen( string )/2;
    Pilha* pilha;

    pilha = criarPilha();

    if( ( strlen( string ) % 2 ) != 0 ){
        free( pilha );
        return 0;
    }

    for( int i=0; i<metade; i++ ){
        push( pilha, (char)string[i] );
    }
    for( int i=metade; i<strlen( string ); i++ ){
        char comp;
        comp = pop( pilha );
        if( comp != string[i] ){
            free( pilha );
            return 0;
        }
        else{
            free( pilha );
            return 1;
        }
    }
}

// função para criar uma pilha vazia
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    return pilha;
}

// função para destruir a pilha e liberar memória
void destruirPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        Nodo* temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
    free(pilha);
}

// função para inserir um elemento no topo da pilha (push)
void push(Pilha* pilha, char valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// função para remover e retornar o elemento do topo da pilha (pop)
char pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        fprintf(stderr, "A pilha esta vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = pilha->topo;
    char valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}

// função para verificar se a pilha está vazia
int estaVazio(Pilha* pilha) {
    return (pilha->topo == NULL);
}