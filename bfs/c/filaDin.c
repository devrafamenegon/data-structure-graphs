#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 2
typedef int bool;
typedef int CHAVE;
typedef struct {
  CHAVE chave;
  // outros campos ...
} REGISTRO;

typedef struct aux {
  REGISTRO reg;
  struct aux *prox;
} ELEMENTO, *PONT;

typedef struct {
  PONT inicio;
  PONT fim;
} FILA;

void inicializarFila(FILA *f) {
  f->inicio = NULL;
  f->fim = NULL;
}

bool inserirNaFila(FILA *f, REGISTRO reg) {
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->reg = reg;
  novo->prox = NULL;
  if (f->inicio == NULL)
    f->inicio = novo;
  else
    f->fim->prox = novo;
  f->fim = novo;
  return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg) {
  if (f->inicio == NULL) return false;
  *reg = f->inicio->reg;
  PONT apagar = f->inicio;
  f->inicio = f->inicio->prox;
  free(apagar);
  if (f->inicio == NULL) f->fim = NULL;
  return true;
}
