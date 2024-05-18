#include <iostream>

#include "grafo.cpp"

using namespace std;

class DFS: public GRAFO {
  public:
    DFS() {
      cout << "Erro, informe o número de vértices";
      exit(-1);
    }

    DFS(int nVertices): GRAFO(nVertices) {}

    void visitarVertice(int vertice, int* cor, CHAVE chave) {
      cor[vertice] = AMARELO;

      ADJACENCIA* adjacencia = this->getArranjoVertices()->getAdjacencias();

      while(adjacencia) {
        if (cor[adjacencia->getVerticeDestino()] == BRANCO) {
          visitarVertice(adjacencia->getVerticeDestino(), cor, adjacencia->getVerticeDestino());
        }

        adjacencia = adjacencia->getProximaAdjacencia();
      }
      cor[vertice] = VERMELHO;
    }

    void profundidade(CHAVE chave) {
      int nVertices = this->getNVertices();
      int cor[nVertices]; // Começamos definindo um arranjo de cores, que armazenará a cor de cada vértice
      int vertice;

      // Iniciamos todos com branco

      /*
        A verificação de todos os
        vértices brancos serve para
        garantir que, uma vez
        esgotada uma árvore de
        busca, possamos reiniciar de
        algum outro vértice não
        visitado.
      */
      for (vertice = 0; vertice < nVertices; vertice++) {
        cor[vertice] = BRANCO;
      }

      for (vertice = 0; vertice < nVertices; vertice++) {
        if (cor[vertice] == BRANCO) {
          this->visitarVertice(vertice, cor, chave);
        }
      }
    }
};