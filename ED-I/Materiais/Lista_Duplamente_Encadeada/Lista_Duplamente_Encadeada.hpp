///Lista Duplamente Encadeada
typedef struct Pessoas//nome da estrutura
{
    int codigo;
    string nome;
} Pessoas; // Nome do tipo
typedef struct no
{
    Pessoas pessoa;
    struct no *anterior;
    struct no *proximo;
    no()///construtor
    {
        pessoa.codigo = 0;
        pessoa.nome = "";
        anterior = NULL;
        proximo = NULL;
    }
} No;
typedef struct lista
{
    No *inicio;
    No *fim;
    int tamanho;
    lista()///construtor
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~lista()///desconstrutor da lista, chama delete(ponteiro)
    {
        No *n = inicio;
        while(n){
            No *aux = n;
            n = n->proximo;
            delete aux;
        }
    }
} Lista;
bool Insere(Lista *lista,Pessoas p)
{
    No *novo = new No();
    novo->pessoa = p;
    novo->proximo = lista->inicio;
    if(lista->fim == NULL)///Lista está vazia
        lista->fim = novo; ///vai ser o primeiro no da lista
    else
        lista->inicio->anterior = novo; ///atualiza anterior
    lista->inicio = novo;
    lista->tamanho++;
    return NULL;
}
bool remover(Lista *lista,int cod)
{
    No *anterior = NULL;
    No *atual = lista->inicio;
    ///Fica no laço até que tive elementos
    ///na lista e não encontrar o valor
    ///desejado
    while(atual && atual->pessoa.codigo != cod)
    {
        anterior = atual;
        atual = atual->proximo;
        ///pode sair do laço sem encontrar o valor (atual = Null)
        ///ao encontrar >>> atual tem o endereço para excluir
        ///Null == false >>> !false = true
        if(!atual)///se atual é null >>> não encontrou
            return false;
        if(!anterior)///se anterior é igual a null
        {
            ///o elemento a ser exluido está no inicio da lista
            lista->inicio = atual->proximo;
            if(lista->inicio == NULL)///lISTA VAZIA
            {
                lista->fim = lista->inicio;
            }
            else
            {
                lista->inicio->anterior = NULL;///se torna o primeiro da lista

            }
        }
        else
        {
            anterior->proximo = atual->proximo;
            if(atual->proximo == NULL)///SE FOR RETIRADO O ÚLTIMO DA LISTA
                lista->fim = anterior;
            else
                atual->proximo->anterior = anterior;
        }
    }
    ///libera a memória
    lista->tamanho--;///diminui o tmanho da lista
    delete(atual);
    return true;
}
bool removerNo(Lista *lista, No *no){
    if (!no->anterior) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da lista
        lista->inicio = no->proximo;
        if (lista->inicio == NULL)
            lista->fim = lista->inicio;
        else
            lista->inicio->anterior = NULL; ///se torna o primeiro da lista
    }else{ /// elemento está no meio ou no fim
        no->anterior->proximo = no->proximo;
        if (no->proximo == NULL){/// se for retirado último da lista{
            lista->fim = no->anterior;
        }
        else
            no->proximo->anterior = no->anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}
///quando o cout receber uma struct no
ostream& operator<<(ostream os, const No *n)
{
    ///cout<<n;
    return os << n->pessoa.codigo << " " << n->pessoa.nome;
}
/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->proximo;
        if(n)
            os << "\n";
    }
    os << endl;
    return os;
}
void mostrar_inverso(Lista *lista)
{
    No *n = lista->fim;
    while (n)
    {
        cout<<n->pessoa.cod << "" << n->pessoa.nome << "\n";
        n = n->anterior;
    }
    cout<<endl;
}
No* busca(Lista lista, int cod)
{
    No *n = lista->inicio;
    while(n)
    {
        if(n->pessoa.codigo == cod)
            return n;

        n = n->proximo;
    }
    return NULL;
}
