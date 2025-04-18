#include<stdio.h>
#include<stdlib.h>
int main(){

    int A[8];
    int x;
    int y;

    printf("Escreva 8 valores\n");
    for( int i=0; i<8; i++ ){
        scanf( "%d", &A[i] );
    }
    printf("Escreva 2 valores ( de 0 a 7)\n");
    scanf( "%d %d", &x, &y );
    
    printf( "Soma a[x] + a[y] = %d", A[x]+A[y] );

}