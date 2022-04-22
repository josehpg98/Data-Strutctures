///Lista Duplamente Encadeada
typedef struct Pessoas
{
    int cod;
    string nome;

} Pessoas;
typedef struct no{
    Pessoas pessoa;
    struct no *ant;
    struct no *prox;
    no() /// construtor
    {
        pessoa.cod = 0;
        pessoa.nome = "";
        ant  = NULL;
        prox = NULL;
    }
}No;
typedef struct lista{
    No *inicio;
    No *fim;
    int tamanho;
    lista() /// construtor
    {
        inicio = NULL;
        fim = NULL;
        tamanho =0;
    }
    ~lista() /// desconstrutor /// quando chame delete(ponteiro)
    {
        No *n = inicio;
        while(n){
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} Lista;
///insere no início da lista
bool inserir(Lista *lista, Pessoas p){

    No *novo = new No();
    novo->pessoa = p;
    novo->prox = lista->inicio;

    if (lista->fim == NULL) ///lista vazia
        lista->fim = novo; /// vai ser o primeiro nó da lista
    else
        lista->inicio->ant = novo;  /// atualiza anterior
    lista->inicio = novo;
    lista->tamanho++;
}
bool remover(Lista *lista, int cod){
    No *anterior = NULL;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->pessoa.cod != cod){
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
bool removerNo(Lista *lista, No *no){
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
ostream& operator<<(ostream& os, const No *n)
{

    /// cout <<< n
    return os << n->pessoa.cod << " " << n->pessoa.nome;
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
            os << "\n";
    }
    os << endl;
    return os;
}
void mostrarInverso(Lista *lista)
{
    No *n = lista->fim;
    while(n)
    {
        cout << n->pessoa.cod <<  " " << n->pessoa.nome  << "\n";
        n = n->ant;
    }
    cout << endl;
}
No* busca(Lista *lista, int cod)
{
    No *n = lista->inicio;
    while(n)
    {
        if(n->pessoa.cod == cod)
            return n;

        n = n->prox;
    }
    return NULL;
}


