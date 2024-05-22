#include <iostream>

#include "bfs.cpp"

using namespace std;

int main() {
  BFS *grafo = new BFS(5);
  grafo->criaAresta(0, 1, 2);
  grafo->criaAresta(1, 2, 4);
  grafo->criaAresta(2, 0, 12);
  grafo->criaAresta(2, 4, 40);
  grafo->criaAresta(3, 1, 3);
  grafo->criaAresta(4, 3, 8);

  grafo->getArranjoVertices()[0].setChave(10);
  grafo->getArranjoVertices()[1].setChave(11);
  grafo->getArranjoVertices()[2].setChave(11);
  
  grafo->imprime();

  grafo->largura(9);
  grafo->largura(10);
  grafo->largura(11);
  
  return 0;
}