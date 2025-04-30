#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PESSOA ( ( sizeof(char) * 10 ) + (sizeof( int ) * 2 ) )
#define NOME ( sizeof( char ) * 10 )
#define IDADE ( sizeof( int ) )
#define TELEFONE ( sizeof( int ) )

void* incluir( void* pBuffer, char nome[10], int idade, int telefone );
void* apagar( void* pBuffer, char nome[10] );
void buscar( void* pBuffer, char nome[10] );
void listar( void* pBuffer );

int main(){

    void* pBuffer = NULL;

    pBuffer = incluir( pBuffer, "felipe", 22, 999674323 );

    pBuffer = incluir( pBuffer, "joao", 19, 999674521 );

    pBuffer = incluir( pBuffer, "ricardo", 12, 998765425 );

    pBuffer = incluir( pBuffer, "roberto", 34, 991402222 );

    pBuffer = apagar( pBuffer, "felipe" );

    pBuffer = incluir( pBuffer, "lucas", 22, 999674323 );

    pBuffer = incluir( pBuffer, "cristian", 19, 999674521 );

    pBuffer = incluir( pBuffer, "tubarao", 12, 998765425 );

    pBuffer = incluir( pBuffer, "vaitepega", 34, 991402222 );

    pBuffer = apagar( pBuffer, "ricardo" );

    pBuffer = apagar( pBuffer, "tubarao" );
 

    listar( pBuffer );

    buscar(pBuffer, "joao");
    buscar(pBuffer, "ivete");

    free(pBuffer);

}

void* incluir( void* pBuffer, char nome[10], int idade, int telefone ){

    if( pBuffer == NULL ){
        pBuffer = (void*) malloc( sizeof( int ) + PESSOA );
        *(int *)pBuffer = 1;


    } else {
        pBuffer = realloc( pBuffer, sizeof( int ) + PESSOA * ( *(int*)pBuffer + 1 ) );
        *(int *)pBuffer = *(int *)pBuffer + 1;

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

void* apagar( void* pBuffer, char nome[10] ){

    void* p = pBuffer;
    void* troca = pBuffer;
    int var = *(int*)pBuffer;

    p = p + sizeof(int);
    troca = troca + sizeof(int);

    for( int i=1; i<= var; i++){

        if( strcmp( (char*)p, nome ) == 0) {

            troca = troca + PESSOA;

            for( int j=i; j<= var ; j++ ){

                void* trocav = troca;
                void* pv = p;

                for( int k=1; k < NOME; k++ ){
                    *(char*)pv = *(char*)trocav;
                    (char*)pv++;
                    (char*)trocav++;
                }
                *(char*)pv = '\0';

                trocav = troca + NOME;
                pv = p + NOME;

                *(int*)pv = *(int*)trocav;
    
                pv = pv + sizeof(int);
                trocav = trocav + sizeof(int);

                *(int*)pv = *(int*)trocav;

                troca = troca + PESSOA;
                p = p + PESSOA;
                
            }

            *(int*)pBuffer = *(int*)pBuffer - 1;
            return pBuffer;

        } else{
            p = p + PESSOA;
            troca = troca + PESSOA;
        }

    }

    return pBuffer;

}

void listar( void* pBuffer ){

    void* p = pBuffer + sizeof(int) ;
    
    for( int i=0; i<*(int*)pBuffer; i++ ){

        printf("%s\n", (char*)p);
        p = p + NOME;

        printf("%d\n", *(int*)p);
        p = p + IDADE;

        printf("%d\n", *(int*)p);
        p = p + TELEFONE;

    }
}

void buscar( void* pBuffer, char nome[10] ){

    void* p = pBuffer;
    p = p + sizeof(int);
    int ctrl = 0;

    for( int i=1; i <= *(int*)pBuffer; i++){

        if( strcmp( (char*)p, nome ) == 0) {

            printf("%s\n", (char*)p);
            p = p + NOME;

            printf("%d\n", *(int*)p);
            p = p + IDADE;

            printf("%d\n", *(int*)p);
            p = p + TELEFONE;

            ctrl++;

        } else{
            p = p + PESSOA;
        }

    }
    if( ctrl == 0 ){
        printf("\npessoa nao encontrada\n");
    }

}