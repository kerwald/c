#include<stdio.h>
#include<stdlib.h>
int main(){
    int a;
    int b;
    if( &a > &b ){
        printf("%p é maior que %p\n", (void*)&a, (void*)&b );
    } else{
        printf("%p é maior que %p\n", (void*)&b, (void*)&a );
    }
}