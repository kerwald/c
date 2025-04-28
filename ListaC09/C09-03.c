#include<stdio.h>
#include<stdlib.h>
int main(){
    int a;
    int b;
    printf("digite os valores para a e para b: ");
    scanf("%d", &a);
    scanf("%d", &b);
    if( &a > &b ){
        printf("o endereco maior contem o conteudo: %d\n", a );
    } else{
        printf("o endereco maior contem o conteudo: %d\n", b );
    }
}