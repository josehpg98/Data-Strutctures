///arquivos da pilha
struct pilha //sTRUCT Pilha
{
    int tam;
    int base;
    int topo;
    int *dados;
};
void inicializa(pilha *p, int tam)
{
    //inicializando os dados da pilha
    p->base = -1;//(*p).base = -1
    p->topo = -1;
    p->tam = tam;
    p->dados = new int(tam);// aloca dinamicamente o tamanho desejado na pilha
}
bool cheia(pilha *p)
{
    if(p->topo == p->tam-1)
    {
        return true;
        cout<<" A pilha está cheia!" << endl;
        getchar();
    }
    else
    {
        return false;
    }
}
bool vazia(pilha *p)
{
    if(p->topo == p->base)
    {
        return true;
        cout<<" A pilha está vazia!" << endl;
        getchar();
    }
    else
    {
        return false;
    }
}
bool empilhar(pilha *p, int valor)
{
    if(cheia(p)) //caso a pilha está cheia
    {
        return false;//retorna false, pois não consegue incluir
    }
    else
    {
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}
void mostrar(pilha *p)
{
    int x;
    cout<<" Mostrar Pilha: " << endl;
    cout<<" Tamanho: " << p->tam << endl;
    cout<<" Topo: " << p->topo << endl;
    for(x = p->topo; x > p->base; x--)
    {
        cout<<"  -------" << endl;
        cout<< x <<" |  " << p->dados[x] << "  | " << endl;
        cout<<"  ------ " << endl;
    }
}
/**int desempilhar2(pilha *p)
{
    int valor = p->dados[p->topo];
    p->dados[p->topo] = NULL;
    p->topo--;
    return valor;
}**/
int desempilhar(pilha *p)
{
    int valor = NULL;
    if(!vazia(p))// for diferente de vazia
    {
        valor = p->dados[p->topo];
        p->dados[p->topo] = NULL;
        p->topo--;
    }
    return valor;
}
bool buscar(pilha *p, int valor)
{
    int x;
    for(x = p->topo; x > p->base; x--)
    {
        if(valor == p->dados[x])
        {
            return true;
            cout<<" O valor existe!" << endl;
            getchar();
        }
    }
    return false;
}
void verifica_par(pilha *p){
    int cont = 0;
    for(int x = p->topo; x > p->base; x--)
    {
        if(p->dados[x] % 2 == 0)
        {
           cont += 1;
        }
    }
    cout<<"O número de elementos pares é: " << cont << endl;
    getchar();
}
void verifica_impar(pilha *p){
    int cont = 0;
    for(int x = p->topo; x > p->base; x--)
    {
        if(p->dados[x] % 2 == 1)
        {
           cont += 1;
        }
    }
    cout<<"O número de elementos impares é: " << cont << endl;
    getchar();
}
int verifica_pilhas(pilha *p1, pilha *p2){
    int cont = 0;
      for(int x = p1->topo; x > p1->base; x--){
          for(int y = p2->topo; y > p2->base; y--){
            if(p1->dados[x] == p2->dados[y]){
                    cont += 1;
                    //return cont;
                //cout<<"As pilhas contém valores iguais!" << endl;
            }
          }
      }
      return cont;
}
