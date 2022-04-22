/// lista descritor

typedef struct no{
    int dado;
    struct no *prox;
    no() /// construtor
    {
        dado = 0;
        prox = NULL;
    }
}No;

typedef struct lista{
    No *inicio;
    No *fim;
    int tamanho;
    lista() /// construtor
    {
        cout << "\n executando o construtor...";
        inicio = NULL;
        fim = NULL;
        tamanho =0;
    }
    ~lista() /// desconstrutor /// quando chame delete(ponteiro)
    {
        cout << "\n executando o desconstrutor....";
        No *n = inicio;
        while(n){
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} Lista;

///insere no início da lista
bool insere(Lista *lista, int valor){

    No *novo = new No();
    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (lista->fim == NULL)
        lista->fim = lista->inicio;
}



bool remover(Lista *lista, int valor){
    No *anterior = NULL;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor){
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
   /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (lista->inicio == NULL) ///listar vai ficar vazia
            lista->fim = lista->inicio;
    }else{ /// elemento está no meio ou no fim
        anterior->prox = atual->prox;
        if (atual->prox == NULL)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;
    delete(atual);
    return true;

}

void mostrar(Lista *lista){
    No *n = lista->inicio;
    while(n){/// enquanto n não for NULL fica no laço
     cout << n->dado << "\t";
     n = n->prox;
    }
}




/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    return os;
}




