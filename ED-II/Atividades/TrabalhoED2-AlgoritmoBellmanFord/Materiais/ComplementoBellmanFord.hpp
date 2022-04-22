///ESTRUTURA PARA A BORDA DO GRAFO
struct Borda{
  int vib; ///vértice inicial da borda / u
  int v;///vértice final da borda
  int w;///peso da borda(u,v)
};
///Grafo conssiste em bordas
struct Grafo{
  int V;///Total de numeros de vertices no grafo
  int E;///Total numeros de bordas no grafo
  struct Borda* borda;/// Array de bordas
};
///Cria o grafo com V vertices e E bordas
struct Grafo* CriaGrafo(int V, int E){
  struct Grafo* grafo = new Grafo;
  grafo->V = V;///Total Vertices
  grafo->E = E;///Total bordas
  ///Array de bordas para o grafo
  grafo->borda = new Borda[E];
  return grafo;
}
///Mostrando a solução
void Mostra(int arr[], int size){
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
    //cout<<arr[i]<<endl;
  }
  printf("\n");
}
void BellmanFord(struct Grafo* grafo,int u){
  int V = grafo->V;
  int E = grafo->E;
  int dist[V];
///Passo 1:Preenche a matriz de distância e matriz antecessor
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
///Marca o vértice fonte
  dist[u] = 0;
///Passo 2:Relaxa bordas | V| - 1 vezes
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
///Obtem o dado da borda
      int u = grafo->borda[j].vib;
      int v = grafo->borda[j].v;
      int w = grafo->borda[j].w;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
    }
  }
///Passo 3: detecta ciclo negativo
///Se o valor mudar, então temos um ciclo negativo no gráfo
///e não se pode encontrar distâncias mais curtas
  for (int i = 0; i < E; i++) {
    int u = grafo->borda[i].vib;
    int v = grafo->borda[i].v;
    int w = grafo->borda[i].w;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      printf("Grafo contèm ciclo negativo!");
      printf("\n");
      return;
    }
  }
///Ciclo de altura negativa não encontrado!
///Print a distancia do predecessor do array
  Mostra(dist, V);
  return;
}
