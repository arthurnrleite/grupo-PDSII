#include<stdlib.h>
#include<stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
}No;

typedef struct{
    No* topo;
}Pilha;

Pilha* pilha_cria(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha; 
}


void pilha_push(Pilha* p, int x){
    No* no =  malloc(sizeof(No));
    no->valor = x; 
    no->proximo = p->topo;
    p->topo = no;
}

int pilha_pop(Pilha* pilha){
    if (pilha->topo != NULL){
        int valor = pilha->topo->valor;
        No* no = pilha->topo->proximo;
        free(pilha->topo);
        pilha->topo = no;
        return valor;
    }
    return -999999;
}

void imprime_no(No* no){
    if(no!=NULL){
        printf(" %d ", no->valor);
        imprime_no(no->proximo);
    }
}
void imprime(Pilha* pilha){
    printf("\nValores da pilha \n");
    imprime_no(pilha->topo);
}

void pilha_apagar(Pilha* pilha, int x) {
    No *atual = pilha->topo;
    No *anterior = NULL;
    
    while (atual != NULL) {
        if (atual->valor == x) {
            if (anterior == NULL) {
                pilha->topo = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}