#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[10];
    int cont=0;
    for( int i=0; i<10; i++ ){
        scanf("%d", &A[i] );
    }
    for( int i=0; i<10; i++ ){
        if( A[i] % 2 == 0 ){
            cont++;
        }
    }
    printf( "Numero de pares = %d", cont );

}