struct Grafo
{
    int V, A;              //Vértices e Arestas
    struct Aresta *aresta; //Ponteiroo para a estrutura de Arestas
    //Estrutura responsável pela representação do nosso grafo.
};
struct Aresta
{
    int origem, destino, peso;
    /*Estrutura que representa as arestas. Como estamos trabalhando com dígrafos ponderados, precisamos ter os elementos
    de origem, destino e peso de cada aresta.*/
};
struct Grafo *criaGrafo(int V, int A)
{
    /*Rotina para criação do grafo. Recebe o nº de vértices e arestas no main, é criada a estrutura de arestas com a quantidade obtida pelo usuário.*/
    struct Grafo *grafo = new Grafo;
    grafo->V = V;
    grafo->A = A;
    grafo->aresta = new Aresta[A];

    return grafo;
};
void vertDistancia(int dist[], int n)
{
    cout << "Distancia dos vertices ao nosso nó raiz: " << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "Vertice " << k << " distancia: " << dist[k] << endl;
    }

    //Função para mostrar a distância dos vértices em relação ao vértice raíz escolhido pelo usuário
}
bool BellmanFord(struct Grafo *grafo, int raiz)
{
    int V = grafo->V;    //Recebe a quantidade de vértices
    int A = grafo->A;    //Recebe a quantidade de arestas
    int armazenaDist[V]; //Criamos um vetor para armazenar as distancias dos vértices em relação ao vertice raiz

    for (int i = 0; i < V; i++)
    {
        armazenaDist[i] = INT_MAX; //Aqui inicializamos todos os vértices com a distância infinita, a propriedade INT_MAX atribui o valor por meio da biblioteca <bits/stdc++.h>
    }
    armazenaDist[raiz] = 0; //O nó raiz estabelecido pelo usuário no main e passado na chamada da função recebe a distância "0"

    for (int i = 0; i < V - 1; i++) //Os laços for são responsáveis por fazer o relaxamento nos vértices.
    {
        for (int j = 0; j < A; j++)
        {
            int o = grafo->aresta[j].origem;
            int d = grafo->aresta[j].destino; //Coletamos os dados das arestas (origem,destino,peso) para comparar a distância
            int p = grafo->aresta[j].peso;

            if (armazenaDist[o] + p < armazenaDist[d]) //O nosso vértice somado com o valor da aresta é menor do que o valor vértice do destino? Se sim, atribui a distância ao array
            {
                armazenaDist[d] = armazenaDist[o] + p;
            }
        }
    }
    //Após fazer o relaxamento de todos os vértices e seus respectivos valores, percorremos as arestas e verificamos o valor da distância de cada vértice.
    for (int i = 0; i < A; i++)
    {
        int o = grafo->aresta[i].origem;
        int d = grafo->aresta[i].destino;
        int p = grafo->aresta[i].peso;

        if (armazenaDist[o] + p < armazenaDist[d]) //Se o valor encontrado for menor, foi detectado um ciclo negativo
        {
            return true;
        }
    }

    vertDistancia(armazenaDist, V);
    return false;
}
