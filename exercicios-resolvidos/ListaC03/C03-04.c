#include<stdio.h>
#include<stdlib.h>
int main(){
    for( int cont=0; cont<=100000; cont=cont+1000 ){
        printf( "%d\n", cont );
    }
}