///arquivos da pilha
struct pilha
(
    int tam;
    int base;
    int topo;
    int *dados;
 );
 void inicializa(pilha *p, int tam){
     //inicializando os dados da pilha
     p->base = -1;//(*p).base = -1
     p->topo = -1;
     p->tam = tam;
     p->dados = new int(tam);// aloca dinamicamente
 }
bool cheia(pilha *p){
    if(p->topo == p->tam-1){
        return true;
    }else{
        return false;
    }
}
bool vazia(pilha *p){
    if(p->topo == p->base){
        return true;
    }else{
        return false;
    }
}
bool empilhar(pilha *p, int valor){
    if(cheia(p)){//caso a pilha está cheia
        return false;//retorna false, pois não consegue incluir
    }else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}
void mostrar(pilha *p){
    int x;
    cout<<" Mostrar Pilha: " << endl;
    cout<<" Tamanho: " << p->tam << endl;
    cout<<" Topo: " << p->topo << endl;
    for(x = p->topo;x > p->base;x--){
        cout<<"  -------" << endl;
        cout<< x <<" |  " << p->dados[x] << "  | " << endl;
        cout<<"  ------ " << endl;
    }
}
int desempilhar2(pilha *p){
    int valor = p->dados[p->topo];
    p->dados[p->topo] = NULL;
    p->topo--;
    return valor;
}
int desempilhar(pilha *p){
    int valor = NULL;
    if(!vazia(p)){
        valor = p->dados[p->topo];
        p->dados[p->topo] = NULL;
        p->topo--;
    }
    return valor;
}
bool buscar(pilha *p, int valor){
    int x;
    for(x = p->topo;x > p->base;x--){
        if(valor == p->dados[x]){
            return true;
        }
    }
    return false;
}
