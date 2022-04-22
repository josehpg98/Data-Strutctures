/// lista descritor
typedef struct no{
    int dado;
    struct no *prox;
    no() /// construtor  o criar a ponteiro ou vr, etc..)
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
        cout << "\n Executando o Construtor...";
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~lista() /// desconstrutor /// quando chame delete(ponteiro)
    {
        cout << "\n Executando o Desconstrutor....";
        No *n = inicio;
        while(n){
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} Lista;

///insere no in�cio da lista
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
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado != valor){
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
   /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    { /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (lista->inicio == NULL) ///listar vai ficar vazia
            lista->fim = lista->inicio;
    }else{ /// elemento est� no meio ou no fim
        anterior->prox = atual->prox;
        if (atual->prox == NULL)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;
    delete(atual);
    return true;

}
void mostrar(Lista *lista){
    No *n = lista->inicio;
    while(n){/// enquanto n n�o for NULL fica no la�o
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
void contar_no_par(Lista *lista){
    No *n = lista->inicio;
    int cont = 0,cpar = 0;
    while(n){/// enquanto n n�o for NULL fica no la�o
    cont++;
    if(cont % 2 == 0){
        cpar++;
    }
     n = n->prox;
    }
    cout<<"\n O Número de Nós Pares É: " << cpar << endl;
}
void soma_lista(Lista *lista){
    No *n = lista->inicio;
    int soma = 0;
    while(n){/// enquanto n n�o for NULL fica no la�o
    soma += n->dado;
     n = n->prox;
    }
    cout<<"\n A Soma de Elementos da Lista É: " << soma << endl;
}
void soma_indice_par(Lista *lista){
    No *n = lista->inicio;
    int cont = 0,soma = 0;
    while(n){/// enquanto n n�o for NULL fica no la�o
    cont++;
    if(cont % 2 == 0){
        soma += n->dado;
    }
     n = n->prox;
    }
    cout<<"\n A Soma de Elementos de Nós Pares É: " << soma << endl;
}

