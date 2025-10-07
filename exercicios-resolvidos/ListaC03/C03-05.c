#include<stdio.h>
#include<stdlib.h>

int main(){

    int vet[10];

    for( int i=0; i<10; i++ ){
        scanf( "%d", &vet[i] );
    }

    for(int i=0; i<10; i++ ){
        vet[i+1] = vet[i+1] + vet[i];
    }

    printf( "\n%d\n", vet[9] );

}