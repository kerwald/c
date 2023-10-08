#include<stdio.h>
#include<stdlib.h>
int main(){
    int n[3];

    for( int i=0; i<3; i++ ){
        printf( "Digite o valor numero %d\n", ( i+1 ) );
        scanf( "%d", &n[i] );
    }
   
    printf( "%d", n[0]+n[1]+n[2] );
}
