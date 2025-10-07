#include<stdio.h>
#include<stdlib.h>
int main(){
    float h;
    char g;
    while( g!='f' && g!='m'){
        printf( "\ndigite a primeira letra do seu genero (f ou m): ");
        scanf( "%c", &g );
    }
    printf( "\ndigite sua altura: ");
    scanf( "%f", &h );

    if( g == 'f' ){
        printf( "%f", (62.1*h)-44.7 );
    }
    else{
        printf( "%f", ((72.7*h)-58) );
    }
}