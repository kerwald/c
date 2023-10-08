#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int n;
    scanf( "%d", &n );

    printf( "1\n" );
    for( int i=3; i<=n; i=i+3 ){
        printf( "%d\n", i );
    }

}

