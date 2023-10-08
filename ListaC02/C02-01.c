#include<stdio.h>
#include<stdlib.h>
int main(){
    int n[2];
    for( int i=0; i<3; i++ ){
        printf( "\ndigite o valor %d: ");
        scanf( "%d", &n[i] );
    }
    if( n[0]>n[1] ){
        printf( "%d", &n[0] );
    }
    else{
        printf( "%d", &n[1] );
    }
}