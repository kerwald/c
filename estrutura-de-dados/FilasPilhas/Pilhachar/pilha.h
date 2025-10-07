// estrutura de um nó (nodo) da pilha
typedef struct Nodo {
    char info;
    struct Nodo* prox;
} Nodo;

// estrutura da pilha
typedef struct {
    Nodo* topo;
} Pilha;

// protótipos das funções
Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
void push(Pilha* pilha, char valor);
char pop(Pilha* pilha);
int estaVazio(Pilha* pilha);
int verificarpadraoXY( char* string );
int verificarpalindromo( char* string );
int verificaexpressao( char* string );