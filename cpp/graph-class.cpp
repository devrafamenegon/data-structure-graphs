#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int TIPOPESO;

class ADJACENCIA {
private:
  int vertice;
  TIPOPESO peso;
  ADJACENCIA *prox;

public:
  int getVertice() {
    return vertice;
  }

  void setVertice(int v) {
    vertice = v;
  }

  TIPOPESO getPeso() {
    return vertice;
  }

  void setPeso(TIPOPESO p) {
    peso = p;
  }

  ADJACENCIA *getProx() {
    return prox;
  }

  void setProx(ADJACENCIA *p) {
    prox = p;
  }
};

class VERTICE {
private:
  ADJACENCIA *cab;

public:
  ADJACENCIA *getCab() {
    return cab;
  }

  void setCab(ADJACENCIA *c) {
    cab = c;
  }
};

class GRAFO {
private:
  int vertices;
  int arestas;
  VERTICE *adj;

public:
  int getVertices() {
    return vertices;
  }

  void setVertices(int v) {
    vertices = v;
  }

  int getArestas() {
    return arestas;
  }

  void setArestas(int a) {
    arestas = a;
  }

  VERTICE *getAdj() {
    return adj;
  }

  void setAdj(VERTICE *a) {
    adj = a;
  }

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
      adj[i].setCab(NULL);
    }
  }

  ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = new ADJACENCIA;
    //(ADJACENCIA *) malloc(sizeof(ADJACENCIA));
    temp->setVertice(v);
    temp->setPeso(peso);
    temp->setProx(NULL);
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
    novo->setProx(adj[vi].getCab());
    adj[vi].setCab(novo);
    arestas++;
    return true;
  }

  void imprime() {
    int i;
    cout << "Vertices: " << vertices << ", Aresta: " << arestas << endl;
    for (i = 0; i < vertices; i++) {
      cout << "v" << i << ": ";
      ADJACENCIA *ad = adj[i].getCab();
      while (ad) {
        cout << "v" << ad->getVertice() << "(" << ad->getPeso() << ") ";
        ad = ad->getProx();
      }
      cout << endl;
    }
  }
};
