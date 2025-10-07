#include<stdio.h>
#include<stdlib.h>

int main(){

    int vet[10];
    int maior=0;
    int menor=0;

    for( int i=0; i<10; i++ ){
        scanf( "%d", &vet[i] );
    }
    maior = vet[0];
    menor = vet[0];
    for( int i=0; i<10; i++ ){
        if( vet[i]>maior ){
            maior = vet[i];
        }
        if( vet[i]<menor ){
            menor = vet[i];
        }
    }

    printf( "o numero maior e %d\n", maior );
    printf( "o numero menor e %d\n", menor );

}
