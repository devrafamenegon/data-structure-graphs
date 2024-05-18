#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2
typedef int bool;
typedef int PESO;

typedef struct adjacencia {
  int vertice;
  PESO peso;
  struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
  // outros dados
  ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
  int vertices;
  int arestas;
  VERTICE *adj;
} GRAFO;

GRAFO *criarGrafo(int v) {
  int i;
  GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
  g->vertices = v;
  g->arestas = 0;
  g->adj = (VERTICE *)malloc(sizeof(VERTICE) * v);
  for (i = 0; i < v; i++) {
    g->adj[i].cab = NULL;
  }
  return (g);
}

ADJACENCIA *criaAdj(int v, int peso) {
  ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
  temp->vertice = v;
  temp->peso = peso;
  temp->prox = NULL;
  return (temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf, PESO p) {
  if (!gr) return false;
  if ((vf < 0) || (vf >= gr->vertices)) return false;
  if ((vi < 0) || (vi >= gr->vertices)) return false;
  ADJACENCIA *novo = criaAdj(vf, p);
  novo->prox = gr->adj[vi].cab;
  gr->adj[vi].cab = novo;
  gr->arestas++;
  return true;
}

void imprime(GRAFO *gr) {
  int i;
  printf("Vertices: %d, Arestas: %d\n", gr->vertices, gr->arestas);
  for (i = 0; i < gr->vertices; i++) {
    printf("v%d: ", i);
    ADJACENCIA *ad = gr->adj[i].cab;
    while (ad) {
      printf("v%d(%d) ", ad->vertice, ad->peso);
      ad = ad->prox;
    }
    printf("\n");
  }
}

void visitarP(GRAFO *g, int u, int *cor) {
  cor[u] = AMARELO;
  ADJACENCIA *v = g->adj[u].cab;
  while (v) {
    if (cor[v->vertice] == BRANCO) {
      visitarP(g, v->vertice, cor);
    }
    v = v->prox;
  }
  cor[u] = VERMELHO;
}

void profundidade(GRAFO *g) {
  int cor[g->vertices];
  int u;

  for (u = 0; u < g; u++) {
    cor[u] = BRANCO;
  }

  for (u = 0; u < g->vertices; u++) {
    if (cor[u] == BRANCO) {
      visitarP(g, u, cor);
    }
  }
}

int main() {
  GRAFO *gr = criarGrafo(5);
  criaAresta(gr, 0, 1, 2);
  criaAresta(gr, 1, 2, 4);
  criaAresta(gr, 2, 0, 12);
  criaAresta(gr, 2, 4, 40);
  criaAresta(gr, 3, 1, 3);
  criaAresta(gr, 4, 3, 8);
  imprime(gr);
  profundidade(gr);
}