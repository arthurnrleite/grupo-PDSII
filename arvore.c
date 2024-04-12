#include <stdio.h>
#include <stdlib.h>

/* Struct No */

typedef struct No {
  struct No *esquerda;
  struct No *direita;
  int valor;
} No;

/* Struct Arvore */

typedef struct Arvore {
  No *raiz;
} Arvore;

/* Função cria a Arvore. Referência: raiz. */
Arvore *arvore_cria() {
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  return arvore;
}

/* Função cria um nó. */

No *criar_no(int x) {
  No *no = malloc(sizeof(No));
  no->direita = NULL;
  no->esquerda = NULL;
  no->valor = x;
  return no;
}

void inserir(No *no, int x);

/* Função verifica existência ou não de uma árvore, e a nulidade ou não de sua
 * raiz. */

void inserir_arvore(Arvore *arvore, int x) {
  if (arvore == NULL) {
    return;
  }

  No *no = arvore->raiz;
  if (no == NULL) {
    arvore->raiz = criar_no(x);
  } else {
    inserir(no, x);
  }
}

/* Função insere valor na arvore caso ela já tenha uma raiz. */

void inserir(No *no, int x) {

  if (no->valor < x) {
    if (no->direita == NULL) {
      no->direita = criar_no(x);
    } else {
      inserir(no->direita, x);
    }
  } else {
    if (no->esquerda == NULL) {
      no->esquerda = criar_no(x);
    } else {
      inserir(no->esquerda, x);
    }
  }
}

int buscar_no(No *no, int x);

/* Função verifica se a arvore existe e retorna a função que verifica se o nó
 * com valor de x existe na árvore. */

int arvore_busca(Arvore *arvore, int x) {
  if (arvore == NULL)
    return 0;
  if (arvore->raiz == NULL)
    return 0;

  return buscar_no(arvore->raiz, x);
}

/* Função auxiliar para verificar a exitência de um nó com valor de x. */

int buscar_no(No *no, int x) {
  if (no->valor == x) {
    return 1;
  }
  if (no->valor < x) {
    if (no->direita == NULL) {
      return 0;
    } else {
      return buscar_no(no->direita, x);
    }
  } else {
    if (no->esquerda == NULL) {
      return 0;
    } else {
      return buscar_no(no->esquerda, x);
    }
  }
}

void apagar(No *no, int x);

/* Função que verifica se a árvore é nula e se x é igual à raiz do nó antes de
 * apagar */

void arvore_apagar(Arvore *arvore, int x) {
  if (arvore == NULL) {
    return;
  }

  No *no = arvore->raiz;
  if (no->valor == x) {
    arvore->raiz = NULL;
  } else {
    apagar(no, x);
  }
}

/*Função que apaga um nó específico de uma pilha*/

void apagar(No *no, int x) {
  if (no == NULL) {
    return;
  }

  if (no->valor < x) {
    if (no->direita == NULL) {
      return;
    } else if (no->direita->valor == x) {
      No *temp = no->direita;
      no->direita = NULL;
      free(temp);
    } else {
      apagar(no->direita, x);
    }
  } else {
    if (no->esquerda == NULL) {
      return;
    } else if (no->esquerda->valor == x) {
      No *temp = no->esquerda;
      no->esquerda = NULL;
      free(temp);
    } else {
      apagar(no->esquerda, x);
    }
  }
}

void imprimir(No *no);

/* Imprime todos os elementos de uma árvore. */

void arvore_imprimir(Arvore *arvore) {
  if (arvore == NULL || arvore->raiz == NULL) {
    printf("arvore vazia\n");
    return;
  }

  printf("imprimir em ordem:\n");
  imprimir(arvore->raiz);
  printf("\n");
}

void imprimir(No* no){
  if(no == NULL){
    return;
  }

  imprimir(no->esquerda);
  printf("%d ", no->valor);
  imprimir(no->direita);
}