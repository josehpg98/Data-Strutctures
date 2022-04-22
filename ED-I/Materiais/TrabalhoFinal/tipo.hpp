/// ListaTipo Tipo

typedef struct Tipos
{
    int cod;
    string descricao;

} Tipos;

typedef struct no
{
    Tipos tipo;
    struct no *ant;
    struct no *prox;
    no()
    {
        tipo.cod = 0;
        tipo.descricao = "";
        ant = NULL;
        prox = NULL;
    }
} NoTipo;

typedef struct lista
{
    NoTipo *inicio;
    NoTipo *fim;
    int tamanho;
    lista()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~lista()
    {
        NoTipo *n = inicio;
        while(n)
        {
            NoTipo *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} ListaTipo;

bool inserir(ListaTipo *lista, Tipos t)
{

    NoTipo *novo = new NoTipo();
    novo->tipo = t;
    novo->prox = lista->inicio;

    if (lista->fim == NULL) ///lista vazia
        lista->fim = novo; /// vai ser o primeiro nó da lista
    else
        lista->inicio->ant = novo;  /// atualiza anterior
    lista->inicio = novo;
    lista->tamanho++;

}

bool remover(ListaTipo *lista, int cod){
    NoTipo *anterior = NULL;
    NoTipo *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->tipo.cod != cod){
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
        if (lista->inicio == NULL)/// lista fica vazia
            lista->fim = lista->inicio;
        else
            lista->inicio->ant = NULL; ///se torna o primeiro da lista

    }else{ /// elemento está no meio ou no fim
        anterior->prox = atual->prox;
        if (atual->prox == NULL)/// se for retirado último da lista
            lista->fim = anterior;
        else
            atual->prox->ant = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;
    delete(atual);
    return true;

}

bool removerNoTipo(ListaTipo *lista, NoTipo *no){
    if (!no->ant) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da lista
        lista->inicio = no->prox;
        if (lista->inicio == NULL)
            lista->fim = lista->inicio;
        else
            lista->inicio->ant = NULL; ///se torna o primeiro da lista
    }else{ /// elemento está no meio ou no fim
        no->ant->prox = no->prox;
        if (no->prox == NULL){/// se for retirado último da lista{
            lista->fim = no->ant;
        }
        else
            no->prox->ant = no->ant;
    }
    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const NoTipo *n)
{

    /// cout <<< n
    return os <<"CODIGO: "<<n->tipo.cod << " DESCRICO: " << n->tipo.descricao;
}

/// quanto cout receber uma struct ListaTipo
ostream& operator << (ostream& os, const ListaTipo *l)
{
    NoTipo *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << "\n";
    }
    os << endl;
    return os;
}

void mostrarInverso(ListaTipo *lista)
{
    NoTipo *n = lista->fim;
    while(n)
    {
        cout << n->tipo.cod <<  " " << n->tipo.descricao<< "\n";
        n = n->ant;
    }
    cout << endl;
}


NoTipo* busca(ListaTipo *lista, int cod)
{
    NoTipo *n = lista->inicio;
    while(n)
    {
        if(n->tipo.cod == cod)
            return n;

        n = n->prox;
    }
    return NULL;
}

