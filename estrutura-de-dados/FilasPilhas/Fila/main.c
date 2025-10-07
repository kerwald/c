#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {

    int valor;

    // exemplo de uso da fila
    Fila* fila1 = criarFila();
    Fila* fila2 = criarFila();
    Tadfila* tad = criartad();

    enqueue(fila1, 1);
    enqueue(fila1, 2);
    enqueue(fila1, 3);
    enqueue(fila1, 4);
    enqueue(fila1, -5);
    enqueue(fila1, 6);
    enqueue(fila1, -7);
    enqueue(fila1, -8);
    enqueue(fila1, 9);

    enqueue(fila2, 10);
    enqueue(fila2, 20);
    enqueue(fila2, 30);
    enqueue(fila2, 40);
    enqueue(fila2, 50);
    enqueue(fila2, 60);
    enqueue(fila2, 70);

    printf( "\n" );
    printf( " Elemento removido da fila1: %d\n", dequeue( fila1 ) );
    printf( " Elemento removido da fila1: %d\n", dequeue( fila1 ) );
    printf( " Elemento removido da fila1: %d\n", dequeue( fila1 ) );
    printf( "\n" );

    if ( estaVazio( fila1 ) ){
        printf( " Fila vazia.\n" );
    }else{
        printf( " Fila nao esta vazia.\n" );
    }

    valor = maisnos( fila1, fila2 );
    if( valor == 0 ){
        printf( "\n f1 e f2 possui mesmo numero de nodos\n" );
    } else{
        printf( "\n f1 e f2 possui  numero de nodos diferentes\n" );
    }

    printf( "\n fila 1 impressa abaixo \n" );
    imprimir( fila1 );
    printf( "\n fila 2 impressa abaixo \n" );
    imprimir( fila2 );

    concatenaFilas( fila1, fila2);
    printf( "\n filas concatenadas abaixo \n" );
    imprimir( fila1 );
    
    reverso( fila1 ); 
    printf( "\n fila revertida abaixo \n" );
    imprimir( fila1 );

    removernegativos( fila1 );
    printf( "\n fila sem negativos \n" );
    imprimir( fila1 );

    inverteelementos( fila1 );
    printf( "\n fila com os elementos invertidos \n" );
    imprimir( fila1 );

    printf( "\n numero de pares = %d\n", numerodepares( fila1 ) );

    enqueuetad( tad, 10 ); 
    enqueuetad( tad, 6 );
    enqueuetad( tad, 4 );
    enqueuetad( tad, -8 );
    enqueuetad( tad, 64 );
    enqueuetad( tad, 32 );
    enqueuetad( tad, 12 );

    dequeuetad( tad );
    dequeuetad( tad );
    dequeuetad( tad );

    printf( "\n tad impressa abaixo \n\n" );
    imprimirtad( tad );

    destruirtad( tad );
    destruirFila( fila1 );
    destruirFila( fila2 );


    return 0;

}
