#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){

    float n;

    printf( "\ndigite um valor: ");
    scanf( "%f", &n );

    if( n>=0 ){
        printf( "\n%f", sqrt( n ) );
    }
    else{
        printf( "\nO numero e invalido" );
    }
}