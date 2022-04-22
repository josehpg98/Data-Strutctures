///Estrutura de Lista Simples Encadeada
typedef struct no ///nome da estrutura
{
    int dados;
    struct no *proximo;
} No; ///Nome do tipo
void inicializa(No **lista)
{
    *lista = NULL;
};
bool insere(No **lista,int valor) ///insere no inicio da fila
{
    No *novo = new No();///aloca mem´ria para o nó
    if(!novo)
    {
        return false;
    }
    else
    {
        novo->dados = valor;
        novo->proximo = *lista;
        *lista = novo;
        return true;
    }
};
void mostrar(No *lista)
{
    No *n = lista;
    cout<<"valores da Lista Simples Encadeada: " << endl;
    while(n){
        cout<<n->dados << "\t ";
        n = n->proximo;
    }
    cout<<endl;
};
bool remover(No **lista,int valor){
    No *anterior = NULL;
    No *atual = *lista;
    while(atual && atual->dados != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(!atual){
        return false;
    }
    if(!anterior){
        *lista = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    delete(atual);
    return true;
};
No* busca(No *lista,int valor){///retorna o primeiro no somente
    No *n = lista;
    return n;
};
