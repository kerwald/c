#include<stdio.h>
#include<stdlib.h>
int main(){

    float A[10];
    float B[10];

    for( int i=0; i<10; i++ ){
        scanf( "%f", &A[i] );
    }
    for( int i=0; i<10; i++ ){
        B[i] = A[i]*A[i];
    }
    for( int i=0; i<10; i++ ){
        printf( "%f ", A[i] );
    }
    printf( "\n" );
    for( int i=0; i<10; i++ ){
        printf( "%f ", B[i] );
    }

}