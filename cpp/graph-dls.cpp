#include "graph-class.cpp"
#include <iostream>
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2
using namespace std;

class Graph_DFS: public GRAFO {
  public:
    Graph_DFS() {
      cout << "Erro, informe o número de vértices";
      exit(-1);
    }

    Graph_DFS(int v): GRAFO(v) {}

    void visitarP(int u, int *cor) {
      cor[u] = AMARELO;
      ADJACENCIA *v = adj[u].cab;

      while(v) {
        if (cor[v->vertice] == BRANCO) {
          visitarP(v->vertice, cor);
        }

        v = v->prox;
      }
      cor[u] = VERMELHO;
    }

    void profundidade() {
      int cor[vertices];
      int u;

      for (u = 0; u < vertices; u++) {
        cor[u] = BRANCO;
      }

      for (u = 0; u < vertices; u++) {
        if (cor[u] == BRANCO) {
          visitarP(u, cor);
        }
      }
    }
};

int main() {
  Graph_DFS *gr = new Graph_DFS(5);
  gr->criaAresta(0, 1, 2);
  gr->criaAresta(1, 2, 4);
  gr->criaAresta(2, 0, 12);
  gr->criaAresta(2, 4, 40);
  gr->criaAresta(3, 1, 3);
  gr->criaAresta(4, 3, 8);
  
  gr->imprime();
  gr->profundidade();
  return 0;
}