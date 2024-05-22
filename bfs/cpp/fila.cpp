#include <iostream>

#include "tipos.h"

using namespace std;

struct REGISTRO {
  CHAVE chave;
};

struct ELEMENTO {
  REGISTRO registro;
  ELEMENTO *proximoElemento;
};

class FILA {
public:
  ELEMENTO *inicioDaFila;
  ELEMENTO *fimDaFila;

  FILA() {
    inicioDaFila = NULL;
    fimDaFila = NULL;
  }

  int tamanho() {
    ELEMENTO *elemento = inicioDaFila;
    int tamanho = 0;

    while (elemento != NULL) {
      tamanho++;
      elemento = elemento->proximoElemento;
    }

    return tamanho;
  }

  void listar() {
    ELEMENTO *elemento = inicioDaFila;
    cout << "Fila [ ";

    while (elemento != NULL) {
      cout << elemento->registro.chave << " ";
      elemento = elemento->proximoElemento;
    }

    cout << "]\n";
  }

  bool inserir(REGISTRO reg) {
    ELEMENTO *novo = new ELEMENTO;

    novo->registro = reg;
    novo->proximoElemento = NULL;

    if (inicioDaFila == NULL)
      inicioDaFila = novo;
    else
      fimDaFila->proximoElemento = novo;

    fimDaFila = novo;

    return true;
  }

  bool remover(REGISTRO reg) {
    if (inicioDaFila == NULL)
      return false;

    reg = inicioDaFila->registro;
    ELEMENTO *apagar = inicioDaFila;
    inicioDaFila = inicioDaFila->proximoElemento;

    delete apagar;

    if (inicioDaFila == NULL)
      fimDaFila = NULL;

    return true;
  }

  void reiniciar() {
    ELEMENTO *elemento = inicioDaFila;

    while (elemento != NULL) {
      ELEMENTO *apagar = elemento;
      elemento = elemento->proximoElemento;
      delete apagar;
    }

    inicioDaFila = NULL;
    fimDaFila = NULL;
  }
};