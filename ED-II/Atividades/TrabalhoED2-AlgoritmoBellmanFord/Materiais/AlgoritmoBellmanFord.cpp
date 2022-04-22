#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
#include "ComplementoBellmanFord.hpp"
int main()
{
///Cria o grafo
    int V = 5;///Total de Vertices
    int E = 8;///Total de Bordas
///arry de bordas para o grafo
    struct Grafo* grafo = CriaGrafo(V, E);
    /*
    adicionando as bordas do gráfico
    - borda(u, v)
      onde u = vertice inicial da borda (u,v)
      v = vúrtice final da borda (u,v)
      w é o peso da borda (u,v)
    */
    ///Borda 0 --> 1
    grafo->borda[0].vib = 0;
    grafo->borda[0].v = 1;
    grafo->borda[0].w = 5;

    ///Borda 0 --> 2
    grafo->borda[1].vib = 0;
    grafo->borda[1].v = 2;
    grafo->borda[1].w = 4;

    ///Borda 1 --> 3
    grafo->borda[2].vib = 1;
    grafo->borda[2].v = 3;
    grafo->borda[2].w = 3;

    ///Borda 2 --> 1
    grafo->borda[3].vib = 2;
    grafo->borda
    [3].v = 1;
    grafo->borda[3].w = 6;

    ///Borda 3 --> 2
    grafo->borda[4].vib = 3;
    grafo->borda[4].v = 2;
    grafo->borda[4].w = 2;

    BellmanFord(grafo, 0); //0 é o vértice fonte
    return 0;
}
