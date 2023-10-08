#include<stdio.h>
#include<stdlib.h>
int main(){
    float salario;
    float prestacao;

    printf( "\ndigite valor do salario: " );
    scanf( "%f", &salario );
    printf( "\ndigite valor do emprestimo: " );
    scanf( "%f", &prestacao );

    if( prestacao > ((salario*20)/100) ){
        printf( "\nemprestimo invalido\n" );
    } else{
        printf( "\nemprestimo valido\n" );
    }
}