#include<stdio.h>
#include<stdlib.h>
int main(){
    int n[2];
    for( int i=0; i<2; i++ ){
        printf( "\ndigite o valor %d: ", (1+i) );
        scanf( "%d", &n[i] );
    }
    if( n[0]>n[1] ){
        printf( "\n%d\n", n[0] );
        printf( "%d", (n[0]-n[1]) );
    }
    else{
        printf( "\n%d\n", n[1] );
        printf( "%d", (n[1]-n[0]) );
    }
}