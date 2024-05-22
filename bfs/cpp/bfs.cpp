#include <iostream>

#include "grafo.cpp"
#include "fila.cpp"

using namespace std;

class BFS: public GRAFO {
  public:
    BFS() {
      cout << "Erro, informe o número de vértices";
      exit(-1);
    }

    BFS(int nVertices): GRAFO(nVertices) {}

    void visitaVerticeEmLargura(
      int nVertice, 
      bool* explorado,
      CHAVE chave, 
      bool* chaveFoiEncontrada
    ) {
      FILA* f = new FILA();

      explorado[nVertice] = true;
      REGISTRO* registro = new REGISTRO();
      registro->chave = nVertice;

      if (this->getArranjoVertices()[nVertice].getChave() == chave) {
        *chaveFoiEncontrada = true;
        cout << "Chave " << chave << " encontrada no vertice " << nVertice << endl;
      }

      f->inserir(*registro);

      while (f->inicioDaFila) {
        f->remover(*registro);

        while (f->inicioDaFila) {
          f->remover(*registro);
          ADJACENCIA* vertice = this->getArranjoVertices()[registro->chave].getAdjacencias();

          while (vertice) {
            if (!explorado[vertice->getVerticeDestino()]) {
              explorado[vertice->getVerticeDestino()] = true;

              registro->chave = vertice->getVerticeDestino();
              f->inserir(* registro);
            }
            vertice = vertice->getProximaAdjacencia();
          }
        }

        free(registro);
      }
    };

    bool largura(CHAVE chave){
      bool expl[this->getNVertices()];
      bool chaveFoiEncontrada = false;

      for (int i = 0; i < this->getNVertices(); i++){
        expl[i] = false;
      }

      for (int i = 0; i < this->getNVertices(); i++){
        if (!expl[i]) visitaVerticeEmLargura(i, expl, chave, &chaveFoiEncontrada);
      }

      if (!chaveFoiEncontrada) {
        cout << "Chave " << chave << " nao foi encontrada." << endl;
      }
    }
};