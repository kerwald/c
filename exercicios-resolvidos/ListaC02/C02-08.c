#include<stdio.h>
#include<stdlib.h>
int main(){
    float n[2];
    for( int i=0; i<2; i++ ){
        printf( "\ndigite a nota %f: ", (1+i) );
        scanf( "%f", &n[i] );
    }
    if( n[0] > 10 && n[0] < 0 || n[1] > 10 && n[1] < 0 ){
        printf( "\nnumero informado e invalido\n" );
    } else{
        printf( "\n%d\n", ( ( n[1]+n[0] )/2 ) );
    }
}