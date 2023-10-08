#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){

    int n;

    printf( "\ndigite um valor: ");
    scanf( "%d", &n );

    if( (n%2) == 0 ){
        printf( "\n%d e par", n );
    } else{
        printf( "\n%d e impar", n );
    }

}