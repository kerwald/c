#include<stdio.h>
#include<stdlib.h>

int main(){

    int vet[10];
    int j=0;
    float somatorio;

    while( j<10 ){
        scanf( "%d", &vet[j] );
        if( vet[j] >= 0 ){
            j++;
        }
    }

    for(int i=0; i<10; i++ ){
        somatorio = somatorio + vet[i];
    }

    printf( "\n%f\n", (somatorio/10) );

}