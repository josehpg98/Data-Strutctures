///pilha.hpp

struct pilha
{
    int tam;
    int base;
    int topo;
    int *dados; /// int dados[TAM];
};

void inicializa(pilha *p, int tam)
{ ///inicialização dos dados da pilha
  p->base = -1; ///  (*p).base = -1;
  p->topo = -1;
  p->tam  =  tam;
  p->dados = new int(tam);///aloca memória dinamicamente

}

bool cheia(pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vazia(pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

bool empilhar(pilha *p, int valor)
{
    if (cheia(p)) /// retorna true se cheia....
        return false; /// não consegue incluir, por isso retorna false
    else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

void mostrar(pilha *p)
{
    int x;
    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    for(x = p->topo; x > p->base; x--){
        cout << "    ---------" << endl;
        cout << x << " |    " << p->dados[x] << "    |" << endl;
        cout << "    ---------" << endl;
    }
}

int desempilhar2(pilha *p)
{
    int valor = p->dados[p->topo];
    p->dados[p->topo] = NULL;
    p->topo--;
    return valor;
}

int desempilhar(pilha *p)
{
    int valor = NULL;
    if (!vazia(p))///se não estiver vazia, retira valor
    {
        valor = p->dados[p->topo];
        p->dados[p->topo] = NULL;
        p->topo--;
    }
    return valor;
}

bool buscar(pilha *p, int valor)
{/// retorna true se o valor existe na pilha
    /// retorna false se o valor não existe na pilha
   int x;
   for(x = p->topo ; x > p->base; x--)
   {
       if (valor == p->dados[x])
          return true;
   }
   return false;

}







