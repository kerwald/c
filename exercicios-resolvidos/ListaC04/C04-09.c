#include<stdio.h>
#include<stdlib.h>
int main(){

    int A[6];
    int ctrl;

    printf("Digite 6 valores pares:\n");

    do{
        ctrl = 0;
        for( int i=0; i<6; i++ ){
            scanf("%d", &A[i] );
        }
        for( int i=0; i<6; i++ ){
            if( A[i] % 2 != 0 ){
                ctrl++;
            }  
        }
        if( ctrl>0 ){
            printf("Digite somente valores pares por favor:\n");
        }

    }while( ctrl > 0 );

    for( int i=5; i>=0; i-- ){
        printf("%d ", A[i] );
    }

}