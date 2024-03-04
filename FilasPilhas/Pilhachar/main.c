#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    // exemplo de uso da pilha
    Pilha* pilha = criarPilha();
    

    push( pilha, 'a' );
    push( pilha, 'c' );
    push( pilha, 'd' );

    printf ("Elemento removido da pilha: %c\n", pop( pilha ) );
    printf( "Elemento removido da pilha: %c\n", pop( pilha ) );
    printf( "Elemento removido da pilha: %c\n", pop( pilha ) );

    if ( estaVazio( pilha ) )
    	printf( "Pilha vazia.\n" );
    else 
    	printf( "Pilha nao esta vazia.\n" );


    int v=0;
    v = verificarpadraoXY( "aaabcddcbaaa" );
    if( v == 1 ){
        printf( "\npossui o padrao XY\n" );
    } else{
        printf( "\nnao possui o padrao XY\n" );
    }

    v = verificarpalindromo( "arara" );
    if( v == 1 ){
        printf( "\ne palidromo\n" );
    } else{
        printf( "\nnao e palidromo\n" );
    }

    v = verificaexpressao( ")(5+2)*((5-4))(" );
    if( v == 1 ){
        printf( "\nuso correto dos parenteses\n" );
    } else{
        printf( "\nuso incorreto dos parenteses\n" );
    }
    

    destruirPilha( pilha );

    return 0;
}