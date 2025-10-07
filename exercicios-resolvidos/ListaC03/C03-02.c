#include<stdio.h>
#include<stdlib.h>
int main(){

    int cont = 1;
    
    for( cont=1; cont<=100; cont++ ){
        printf( "%d\n", cont );
    }

    cont = 1;

    while( cont <= 100 ){
        printf( "%d\n", cont );
        cont++;
    }

    cont = 0;

    do{
        cont++;
        printf( "%d\n", cont );
    }while( cont < 100 );

}