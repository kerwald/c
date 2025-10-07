#include<stdio.h>
#include<stdlib.h>
int main(){
    float F;
    scanf( "%f", &F );
    printf( "%f", ( 5.0 * ( F - 32.0 )/9.0 ) );
}