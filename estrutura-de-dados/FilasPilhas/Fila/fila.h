// Estrutura de um nó (nodo) da fila
struct nodo {
    int info;
    struct nodo* prox;
}; typedef struct nodo Nodo;

// estrutura da fila
struct fila {
    struct nodo* inicio;
    struct nodo* fim;
};typedef struct fila Fila;

// estrutura da fila tad
struct tadfila{
    struct nodo* fim;
}; typedef struct tadfila Tadfila;

// Protótipos das funções
Fila* criarFila();
void destruirFila(Fila* fila );
void enqueue(Fila* fila, int data );
int dequeue(Fila* fila );
int estaVazio(Fila* fila );
int maisnos( Fila* fila1, Fila* fila2 );
void concatenaFilas( Fila* fila1, Fila* fila2 );
void imprimir( Fila* fila1 );
void reverso( Fila* fila );
void recursaoreverso( Nodo* a, Nodo* b );
void removernegativos( Fila* fila );
void inverteelementos( Fila* fila );
void recursaoinverteelementos( Nodo* a, Fila** aux );
int numerodepares( Fila* fila );

Tadfila* criartad();
void destruirtad( Tadfila* tad );
void enqueuetad( Tadfila* tad, int info  );
void dequeuetad( Tadfila* tad );
void imprimirtad( Tadfila* tad );
