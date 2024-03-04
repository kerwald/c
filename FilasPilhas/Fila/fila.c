#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//13. Faça uma função para retornar o número de elementos da fila que possuem valor
//par.
int numerodepares( Fila* fila ){
    Nodo* aux = fila->inicio;
    int cont = 0;
    while( aux != NULL ){
        
        if( ( aux->info % 2 ) == 0 ){
            cont++;
        }
        aux = aux->prox;

    }

    return cont;
}

//8. Implemente a função reverso, a qual reposiciona os elementos na fila de tal forma
//que o início da fila torna-se o fim, e vice-versa
void reverso( Fila* fila ){

    if( fila->inicio == NULL ){
        fprintf( stderr, "lista vazia " );
        exit( EXIT_FAILURE );
    }

    Nodo* a = fila->inicio;

    recursaoreverso( fila->inicio, fila->inicio->prox );

    fila->inicio->prox = NULL;
    
    fila->inicio = fila->fim;
    fila->fim = a;

    return;

}
void recursaoreverso( Nodo* a, Nodo* b ){

    if( b == NULL ){
        return;
    }
    else{
        recursaoreverso( a->prox, b->prox );
    }
    b->prox = a;
    return;
}

// 9. Escreva uma função que teste se uma fila F1 tem mais nós do que uma fila F2.
int maisnos( Fila* fila1, Fila* fila2 ){

    int cont1 = 0;
    int cont2 = 0;
    Nodo* aux1 = fila1->inicio;
    Nodo* aux2 = fila2->inicio;

    while( aux1 != NULL ){
        cont1++;
        aux1 = aux1->prox;
    }
    while( aux2 != NULL ){
        cont2++;
        aux2 = aux2->prox;
    }

    if( cont1 == cont2 ){
        return 0;
    }else{
        return 1;
    }

}

//10. Dada uma fila de inteiros, escreva um programa que exclua todos os números
//negativos da fila sem alterar a posição dos outros elementos da fila.
void removernegativos( Fila* fila ){

    Fila* aux = criarFila();
    int valor;

    while( !estaVazio( fila ) ){
        valor = dequeue( fila );
        if ( valor >= 0 ){
            enqueue( aux, valor );
        }
    }
    while( !estaVazio( aux ) ){
        valor = dequeue( aux );
        enqueue( fila, valor );
    }

    destruirFila( aux );
    return;

}

// 11. Escreva uma função que, dado duas filas F1 e F2, concatene as duas filas. Retorne
//a fila concatenada em F1. A fila F2 deve ficar vazia.
void concatenaFilas( Fila* fila1, Fila* fila2 ){

    Nodo* aux = fila1->inicio;
    while( aux->prox != NULL ){
        aux = aux->prox;
    }
    aux->prox = fila2->inicio;
    fila1->fim = fila2->fim;
    fila2->fim = NULL;
    fila2->inicio = NULL; 
    return;

}

//12. Faça uma função que inverta a ordem dos elementos da fila.
void inverteelementos( Fila* fila ){

    int valor;
    Fila* aux;
    aux = criarFila();

    recursaoinverteelementos( fila->inicio, &aux );

    while( !estaVazio( fila ) ){
        dequeue( fila );
    }
    while( !estaVazio( aux ) ){
        valor = dequeue( aux );
        enqueue( fila, valor );
    }

    destruirFila( aux );
    return;

}
void recursaoinverteelementos( Nodo* a, Fila** aux ){

    if( a != NULL ){
        recursaoinverteelementos( a->prox, aux );
    } else{
        return;
    }

    enqueue( *aux, a->info );
    return ;

}

// função para imprimir a fila
void imprimir( Fila* fila1 ){
    Nodo* aux = fila1->inicio;
    printf("\n");
    while( aux != NULL ){
        printf("%d ", aux->info );
        aux = aux->prox;
    }
    printf("\n");
    return;
}

// função para criar uma fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a fila\n");
        exit(EXIT_FAILURE);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// função para destruir a fila e liberar memória
void destruirFila(Fila* fila) {
    while (fila->inicio != NULL) {
        Nodo* temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    free(fila);
}

// função para inserir um elemento no final da fila
void enqueue(Fila* fila, int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = NULL;
    if (fila->inicio == NULL) {  // fila vazia
        fila->inicio = novo;
    } else {  // fila não vazia
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// função para remover e retornar o elemento da frente (início) da fila
int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = fila->inicio;
    int data = temp->info;
    fila->inicio = temp->prox;
    free(temp);
    return data;
}

// função para verificar se a fila está vazia
int estaVazio(Fila* fila) {
    return (fila->inicio == NULL);
}

// função para criar uma tadfila vazia
Tadfila* criartad(){
    Tadfila* tadfila = (Tadfila*)malloc( sizeof( Tadfila ) );
     if( tadfila == NULL ){
        fprintf( stderr, "Erro na alocação de memória para a fila\n" );
        exit( EXIT_FAILURE );
    }
    tadfila->fim = NULL;
    return tadfila;
}

void destruirtad( Tadfila* tad ){

    if( tad->fim == NULL){
        free( tad );
        return;
    } 
    Nodo* aux = tad->fim->prox;
    Nodo* temp;

    while( aux != tad->fim ){
        temp = aux;
        aux = aux->prox;
        free( temp );
    }
    free( tad->fim );
    free( tad );
    return;

}

void enqueuetad( Tadfila* tad, int info  ){

    if( tad->fim == NULL ){

        tad->fim = (Nodo*)malloc( sizeof( Nodo ) );
        tad->fim->info = info;
        tad->fim->prox = tad->fim;
        return;

    } else{

        Nodo* novonodo = (Nodo*)malloc( sizeof( Nodo ) );
        
        novonodo->info = info;

        novonodo->prox = tad->fim->prox;
        tad->fim->prox = novonodo;
        tad->fim = novonodo;

        return;

    }

}

void dequeuetad( Tadfila* tad ){

    Nodo* temp;

    if( tad->fim == NULL){

        fprintf( stderr, "lista vazia\n" );
        exit( EXIT_FAILURE );

    } else if( tad->fim == tad->fim->prox ){

        temp = tad->fim;
        tad->fim = NULL;
        free(temp);

    } else{

        temp = tad->fim->prox;
        tad->fim->prox = tad->fim->prox->prox;
        free( temp );

    }

    return;

}

void imprimirtad( Tadfila* tad ){

     if( tad->fim == NULL){

        fprintf( stderr, "lista vazia\n" );
        exit( EXIT_FAILURE );

    }
    Nodo* aux = tad->fim->prox;
    while( aux != tad->fim ){
        printf( " %d ", aux->info );
        aux = aux->prox;
    }
    printf( " %d ", aux->info );
    return;

}