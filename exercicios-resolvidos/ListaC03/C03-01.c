#include<stdio.h>
#include<stdlib.h>
int main(){

    int numero = 0;
    int vet[5];
    int i = 0;

    while( i != 5 ){
        if( numero%3 == 0 ){
            vet[i] = numero;
            i++;
        }
        numero++;
    }

    for ( int j=0; j<5; j++ ){
        printf("%d\n", vet[j] );
    }

}