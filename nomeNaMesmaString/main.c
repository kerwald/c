#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* AdicionarNome( char* lista );
char* RemoverNome( char* lista );

int main(){
    char* lista = malloc( sizeof( char ) );
    lista[0] = '\0';
    int valor = 0;
    while ( valor != 4 ){
        printf( "digite um valor:\n adicionar nome: 1\n remover nome: 2\n listar: 3\n sair: 4\n" );
        scanf( "%d", &valor );
        if ( valor == 1 ){
            lista = AdicionarNome( lista );
            valor = 0;
        }
        if ( valor == 2 ){
            lista = RemoverNome( lista );
            valor = 0;
        }
        if ( valor == 3 ){
            printf( "%s", lista );
            printf("\n");
            valor = 0;
        }
        if ( valor == 4 ){
            free( lista );
        }
    }

}

/*
==========================================================
AdicionarNome

Adiciona um nome a uma lista de nomes
==========================================================
*/

char* AdicionarNome( char* lista ){
    char nome[30];

    printf( "digite o nome: " );  
    scanf( "%s", nome );

    int tamanhoAtual = strlen( lista ) + 1;
    int tamanho = tamanhoAtual + strlen( nome );
    lista = realloc( lista, sizeof( char ) * tamanho );
    strcat( lista, nome );
    printf( " nome adicionado a lista " );  
    return lista;
}

/*
==========================================================
RemoverNome

Remove nome de uma lista de nomes
==========================================================
*/

char* RemoverNome( char* lista ){
    char nome[30];
    int cont = 0;
    int index = 0;
    printf( "digite o nome: " );  
    scanf( "%s", nome );

    int tamanhoAtual = strlen( lista ) + 1;
    int tam = tamanhoAtual - strlen( nome );
    char* vet = malloc( sizeof( char )* tam );
    
    for ( int i = 0; i < strlen( lista ); i++ ){
        if ( lista[i] == nome[0] ){
            cont = 0;
            for ( int j = 0; j < strlen( nome ); j++ ){
                if ( ( i + j ) < strlen( lista ) && lista[ i + j ] == nome[j] ){
                    cont++;
                }
            }
            if ( cont == strlen( nome ) ){
                index = i;
            }
        }
    }

    int j=0;

    for ( int i=0; i<strlen( lista ); i++ ){
        if ( i < index || i > ( index + strlen( nome ) - 1  ) ){
            vet[j] = lista[i];
            j++;
        }
    }
    vet[j] = '\0';


    free( lista );
    return vet;

}

