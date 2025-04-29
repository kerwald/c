#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PESSOA ( ( sizeof(char) * 10 ) + (sizeof( int ) * 2 ) )

void* incluir( void* pBuffer, char nome[10], int idade, int telefone );

int main(){

    void* pBuffer = NULL;

    pBuffer = incluir( pBuffer, "felipe", 22, 999674323 );

    void* p = pBuffer;

    printf("%d\n", *(int*)pBuffer);
    p = p + sizeof(int);
    printf("%s\n", (char*)p);
    p = p + sizeof(char)*10;
    printf("%d\n", *(int*)p);
    p = p + sizeof(int);
    printf("%d\n", *(int*)p);


}

void* incluir( void* pBuffer, char nome[10], int idade, int telefone ){

    if( pBuffer == NULL ){
        pBuffer = (void*) malloc( sizeof( int ) + PESSOA );
        *(int *)pBuffer = 1;


    } else {
        pBuffer = realloc( pBuffer, sizeof( int ) + PESSOA * ( *(int*)pBuffer + 1 ) );
        *(int *)pBuffer += 1;

    }

    void* p = pBuffer;
    p = p + sizeof( int ) + *(int*)pBuffer * PESSOA - PESSOA ; 
    for( int i=0; i<strlen( nome ); i++ ){
        *(char*)p = nome[i];
        (char*)p++;
    }
    *(char*)p = '\0';
    p = pBuffer + sizeof( int ) + *(int*)pBuffer * PESSOA - PESSOA + sizeof(char) * 10  ; 
    *(int*)p = idade;
    p = p + sizeof(int);
    *(int*)p = telefone;

    return pBuffer;

}