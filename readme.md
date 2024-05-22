# Implementação de Busca em Largura (BFS) e Busca em Profundidade (DFS)

## Introdução

Este projeto contém explicações e pseudocódigos de duas técnicas clássicas de busca em grafos: a Busca em Largura (BFS - Breadth-First Search) e a Busca em Profundidade (DFS - Depth-First Search). Ambas são fundamentais para diversas aplicações em ciência da computação, como na resolução de problemas de roteamento, na análise de redes sociais, e em algoritmos de inteligência artificial.

## Busca em Largura (BFS)

### Descrição

A Busca em Largura é uma técnica de busca que explora os vértices de um grafo em camadas, começando por um vértice inicial e explorando todos os seus vizinhos antes de passar para os vizinhos dos vizinhos, e assim por diante. Ela é implementada usando uma fila (FIFO - First In, First Out).

### Pseudocódigo

```plaintext
Função BFS(grafo, início):
    criar uma fila vazia
    criar um conjunto vazio para vértices visitados
    adicionar o vértice início à fila
    enquanto a fila não estiver vazia:
        vértice = remover primeiro elemento da fila
        se vértice não estiver no conjunto visitado:
            marcar vértice como visitado
            adicionar vértice à ordem de visitação
            adicionar todos os vizinhos não visitados do vértice à fila
    retornar ordem de visitação
```

### Como Executar

1. Crie uma função ou um programa seguindo o pseudocódigo acima.
2. Teste o algoritmo com um grafo de exemplo.

## Busca em Profundidade (DFS)

### Descrição

A Busca em Profundidade é uma técnica de busca que explora o grafo de forma profunda, indo o mais fundo possível por cada caminho antes de retroceder. Ela pode ser implementada de forma recursiva ou usando uma pilha (LIFO - Last In, First Out).

### Pseudocódigo

Implementação Recursiva:

```plaintext
Função DFS-Recursivo(grafo, início, visitados):
    se visitados não existe:
        criar um conjunto vazio para vértices visitados
    marcar início como visitado
    para cada vizinho no grafo[início]:
        se vizinho não está em visitados:
            chamar DFS-Recursivo(grafo, vizinho, visitados)
    retornar visitados
```

Implementação Iterativa:

```plaintext
Função DFS-Iterativo(grafo, início):
    criar uma pilha vazia
    criar um conjunto vazio para vértices visitados
    adicionar o vértice início à pilha
    enquanto a pilha não estiver vazia:
        vértice = remover último elemento da pilha
        se vértice não estiver no conjunto visitado:
            marcar vértice como visitado
            adicionar vértice à ordem de visitação
            adicionar todos os vizinhos não visitados do vértice à pilha
    retornar ordem de visitação
```

### Como Executar

1. Crie uma função ou um programa seguindo um dos pseudocódigos acima.
2. Teste o algoritmo com um grafo de exemplo.

## Conclusão

Neste projeto, explicamos e fornecemos pseudocódigos para as buscas em largura (BFS) e profundidade (DFS) em grafos. Ambas as técnicas são essenciais para a exploração de grafos e resolução de diversos problemas em ciência da computação.

## Autor

Rafael Henrique Menegon
