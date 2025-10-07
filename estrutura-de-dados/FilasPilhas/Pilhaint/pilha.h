// estrutura de um nó (nodo) da pilha
typedef struct Nodo {
    int info;
    struct Nodo* prox;
} Nodo;

// estrutura da pilha
typedef struct {
    Nodo* topo;
} Pilha;

// protótipos das funções
Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int estaVazio(Pilha* pilha);
int* maiormenormedia( Pilha* pilha );
void ordenapilha( Pilha* pilha );
void merge( int* v, int esq, int meio, int dir );
void mergeSort( int* v, int esq, int dir );
void imprimir( Pilha* pilha );
int testaiguais( Pilha* pilha1, Pilha* pilha2 );