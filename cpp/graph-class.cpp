#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int TIPOPESO;

class ADJACENCIA {
public:
  int vertice;
  TIPOPESO peso;
  ADJACENCIA *prox;
};

class VERTICE {
public:
  // outros dados
  ADJACENCIA *cab;
};

class GRAFO {
public:
  int vertices;
  int arestas;
  VERTICE *adj;

  GRAFO() {
    cout << "Necessario informar o numero de vertices" << endl;
    cout << "Programa sera encerrado" << endl << endl;
    exit(-1);
  }

  GRAFO(int v) {
    int i;
    vertices = v;
    arestas = 0;
    adj = new VERTICE[v];
    for (i = 0; i < v; i++) {
      adj[i].cab = NULL;
    }
  }

  ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = new ADJACENCIA;
    //(ADJACENCIA *) malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return (temp);
  }

  bool criaAresta(int vi, int vf, TIPOPESO p) {
    // if (!gr)
    //   return false;
    if ((vf < 0) || (vf >= vertices))
      return false;
    if ((vi < 0) || (vi >= vertices))
      return false;
    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = adj[vi].cab;
    adj[vi].cab = novo;
    arestas++;
    return true;
  }

  void imprime() {
    int i;
    cout << "Vertices: " << vertices << ", Aresta: " << arestas << endl;
    for (i = 0; i < vertices; i++) {
      cout << "v" << i << ": ";
      ADJACENCIA *ad = adj[i].cab;
      while (ad) {
        cout << "v" << ad->vertice << "(" << ad->peso << ") ";
        ad = ad->prox;
      }
      cout << endl;
    }
  }
};
