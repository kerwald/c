#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[6];
    for( int i=0; i<6; i++ ){
        scanf("%d", &A[i] );
    }
    for( int i=5; i>=0; i-- ){
        printf("%d ", A[i] );
    }

}