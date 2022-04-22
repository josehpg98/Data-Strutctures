#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "BellmanEstrutura.hpp"
main()
{
    int V, A, raiz;

    cout << "Digite o numero de vertices do grafo: " << endl;
    cin >> V;
    cout << "Digite o numero de arestas: " << endl;
    cin >> A;
    cout << "Digite o vertice raíz" << endl;
    cin >> raiz;

    struct Grafo *grafo = criaGrafo(V, A);

    for (int i = 0; i < A; i++)
    {
        cout << "Informe as propriedades das arestas: Origem, Destino e Peso: " << endl;
        cin >> grafo->aresta[i].origem;
        cin >> grafo->aresta[i].destino;
        cin >> grafo->aresta[i].peso;
    }

    if (BellmanFord(grafo, raiz))
    {
        cout << "Grafo possuí um ciclo negativo.";
    }
    else
    {
        cout << "Esse grafo não contem ciclo negativo." << endl;
    }
}
