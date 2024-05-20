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

    void visitarVertice(
      int vertice, 
      int* cor, 
      CHAVE chave,
      bool* chaveFoiEncontrada
    ) {
      cor[vertice] = AMARELO;

      if (this->getArranjoVertices()[vertice].getChave() == chave) {
        *chaveFoiEncontrada = true;
        cout << "Chave " << chave << " encontrada no vertice " << vertice << endl;
      }

      ADJACENCIA* adjacencia = this->getArranjoVertices()[vertice].getAdjacencias();

      while(adjacencia) {
        if (cor[adjacencia->getVerticeDestino()] == BRANCO) {
          visitarVertice(adjacencia->getVerticeDestino(), cor, chave, chaveFoiEncontrada);
        }

        adjacencia = adjacencia->getProximaAdjacencia();
      }
      cor[vertice] = VERMELHO;
    }

    bool profundidade(CHAVE chave) {
      int nVertices = this->getNVertices();
      int cor[nVertices]; // Começamos definindo um arranjo de cores, que armazenará a cor de cada vértice
      int vertice;
      bool chaveFoiEncontrada = false;

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
          this->visitarVertice(vertice, cor, chave, &chaveFoiEncontrada);
        }
      }

      if (!chaveFoiEncontrada) {
        cout << "Chave " << chave << " nao foi encontrada." << endl;
      }
    }
};