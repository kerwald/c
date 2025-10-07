#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[10];
    for( int i=0; i<10; i++ ){
        scanf("%d", &A[i] );
    }
    int maior = A[0];
    int posicao = 0;
    for( int i=1; i<10; i++ ){
        if( maior < A[i] ){
            maior = A[i];
            posicao = i;
        }

    }

    for( int i=0; i<10; i++ ){
        printf("%d ", A[i] );
    }
    printf("\n");
    printf( "maior = %d posicao =  %d", maior, posicao );

}