/// ListaProtetor Tipo

typedef struct Protetores
{
    int cod;
    string nome;
    int telefone;

} Protetores;

typedef struct noProtetor
{
    Protetores protetor;
    struct noProtetor *ant;
    struct noProtetor *prox;
    noProtetor()
    {
        protetor.cod = 0;
        protetor.nome = "";
        protetor.telefone = 0;
        ant = NULL;
        prox = NULL;
    }
} NoProtetor;

typedef struct listaProtetor
{
    NoProtetor *inicio;
    NoProtetor *fim;
    int tamanho;
    listaProtetor()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~listaProtetor()
    {
        NoProtetor *n = inicio;
        while(n)
        {
            NoProtetor *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} ListaProtetor;

bool inserir(ListaProtetor *listaProtetor, Protetores t)
{

    NoProtetor *novo = new NoProtetor();
    novo->protetor = t;
    novo->prox = listaProtetor->inicio;

    if (listaProtetor->fim == NULL) ///listaProtetor vazia
        listaProtetor->fim = novo; /// vai ser o primeiro nó da listaProtetor
    else
        listaProtetor->inicio->ant = novo;  /// atualiza anterior
    listaProtetor->inicio = novo;
    listaProtetor->tamanho++;

}

bool remover(ListaProtetor *listaProtetor, int cod){
    NoProtetor *anterior = NULL;
    NoProtetor *atual = listaProtetor->inicio;
    ///fica no laço enquanto tiver elementos na listaProtetor
    /// e não encontrar o valor procurado
    while(atual && atual->protetor.cod != cod){
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
   /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da listaProtetor
        listaProtetor->inicio = atual->prox;
        if (listaProtetor->inicio == NULL)/// listaProtetor fica vazia
            listaProtetor->fim = listaProtetor->inicio;
        else
            listaProtetor->inicio->ant = NULL; ///se torna o primeiro da listaProtetor

    }else{ /// elemento está no meio ou no fim
        anterior->prox = atual->prox;
        if (atual->prox == NULL)/// se for retirado último da listaProtetor
            listaProtetor->fim = anterior;
        else
            atual->prox->ant = anterior;
    }
    /// libera a memória do elemento
    listaProtetor->tamanho--;
    delete(atual);
    return true;

}

bool removerNoProtetor(ListaProtetor *listaProtetor, NoProtetor *noProtetor){
    if (!noProtetor->ant) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da listaProtetor
        listaProtetor->inicio = noProtetor->prox;
        if (listaProtetor->inicio == NULL)
            listaProtetor->fim = listaProtetor->inicio;
        else
            listaProtetor->inicio->ant = NULL; ///se torna o primeiro da listaProtetor
    }else{ /// elemento está no meio ou no fim
        noProtetor->ant->prox = noProtetor->prox;
        if (noProtetor->prox == NULL){/// se for retirado último da listaProtetor{
            listaProtetor->fim = noProtetor->ant;
        }
        else
            noProtetor->prox->ant = noProtetor->ant;
    }
    /// libera a memória do elemento
    listaProtetor->tamanho--;
    delete(noProtetor);
    return true;
}


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const NoProtetor *n)
{

    /// cout <<< n
    return os << n->protetor.cod << " " << n->protetor.nome<<" "<<n->protetor.telefone<<"\n";
}

/// quanto cout receber uma struct ListaProtetor
ostream& operator << (ostream& os, const ListaProtetor *l)
{
    NoProtetor *n = l->inicio;
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

void mostrarInverso(ListaProtetor *listaProtetor)
{
    NoProtetor *n = listaProtetor->fim;
    while(n)
    {
        cout << n->protetor.cod <<  " " << n->protetor.nome<<" "<<n->protetor.telefone<< "\n";
        n = n->ant;
    }
    cout << endl;
}


NoProtetor* busca(ListaProtetor *listaProtetor, int cod)
{
    NoProtetor *n = listaProtetor->inicio;
    while(n)
    {
        if(n->protetor.cod == cod)
            return n;

        n = n->prox;
    }
    return NULL;
}

