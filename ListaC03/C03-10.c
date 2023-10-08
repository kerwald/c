#include<stdio.h>
#include<stdlib.h>
int main(){
    int somatorio=0;
    for( int i=2; i<=50; i=i+2 ){
        somatorio = somatorio + i;
    }
    printf( "\nsomatorio e %d\n", somatorio );

}