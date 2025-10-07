#include<stdio.h>
#include<stdlib.h>
int main(){
    float A[15];
    float media=0;
    for( int i=0; i<15; i++ ){
        scanf("%f", &A[i] );
    }
    for( int i=0; i<15; i++ ){
        media = media + A[i];
    }
    media = media/15;
    printf( "media dos alunos = %f", media );

}