#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int testaiguais( Pilha* pilha1, Pilha* pilha2 ){

    Nodo* aux = pilha1->topo;
    Nodo* aux2 = pilha2->topo;

    while( aux != NULL && aux2 != NULL ){
        if( aux->info != aux2->info ){
            return 0;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    if( ( aux == NULL ) && ( aux2 == NULL ) ){
        return 1;
    } else{
        return 0;
    }

}

void mergeSort( int* v, int esq, int dir ){
    if( esq < dir ){
        int meio = ( esq + dir )/2;
        mergeSort( v, esq, meio );
        mergeSort( v, meio+1, dir );

        merge( v, esq, meio, dir );
    }
    return;
}

void merge( int* v, int esq, int meio, int dir ){

    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int* esquerda = malloc( sizeof( int ) * n1 );
    int* direita = malloc( sizeof( int ) * n2 );

    for ( i = 0; i < n1; i++ )
        esquerda[i] = v[esq + i];
    for ( j = 0; j < n2; j++ )
        direita[j] = v[meio + 1 + j];


    i = 0; 
    j = 0;
    k = esq; 
    while ( i < n1 && j < n2 ) {
        if ( esquerda[i] <= direita[j] ) {
            v[k] = esquerda[i];
            i++;
        } else {
            v[k] = direita[j];
            j++;
        }
        k++;
    }

    while ( i < n1 ) {
        v[k] = esquerda[i];
        i++;
        k++;
    }
    while ( j < n2 ) {
        v[k] = direita[j];
        j++;
        k++;
    }

    free( esquerda );
    free( direita );

}


void ordenapilha( Pilha* pilha ) {

    if ( pilha->topo == NULL || pilha->topo->prox == NULL ) {
        return;
    }
    
    Nodo* aux = pilha->topo;
    int tamanho = 0;
    while ( aux != NULL ) {
        tamanho++;
        aux = aux->prox;
    }
    int* v = malloc( sizeof(int) * tamanho );
    for ( int i = 0; i < tamanho; i++ ) {
        v[i] = pop(pilha);
    }
    tamanho--;

    mergeSort( v, 0, tamanho );

    for ( int i = tamanho; i >= 0; i-- ) {
        push( pilha, v[i] );
    }

    free( v );
}

void imprimir( Pilha* pilha ){
    Nodo* aux = pilha->topo;

    if ( pilha->topo == NULL ) {
        fprintf( stderr, "A pilha esta vazia\n" );
        exit( EXIT_FAILURE );
    }

    while( aux != NULL ){
        printf( " %d ", aux->info );
        aux = aux->prox;
    }
    return;
}

int* maiormenormedia( Pilha* pilha ){
    int* valores = malloc( sizeof( int )*2 + sizeof( float ) );
    int* maior = valores;
    int* menor = ( valores + sizeof( int ) );
    float* media = ( float* )( valores + sizeof( int ) + sizeof( int ) );
    int valor;
    float soma = 0;
    float cont = 0;
    Nodo* aux = pilha->topo;

    if (pilha->topo == NULL) {
        fprintf(stderr, "A pilha esta vazia\n");
        exit(EXIT_FAILURE);
    }

    *maior = aux->info;
    *menor = aux->info;

    while( aux != NULL ){
        valor = aux->info;
        if( valor > *maior ){
            *maior = valor;
        }
        if( valor < *menor ){
            *menor = valor;
        }
        soma = soma + valor;
        cont++;
        aux = aux->prox;
    }
    *media = (soma/cont);
    return valores;
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
void push(Pilha* pilha, int valor) {
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
int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = pilha->topo;
    int valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}

// função para verificar se a pilha está vazia
int estaVazio(Pilha* pilha) {
    return (pilha->topo == NULL);
}