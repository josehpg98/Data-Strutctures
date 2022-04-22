
typedef struct no{
    int dado;
    struct no *prox;
}No;


void inicializa (No **lista){

    *lista = NULL;
}

///insere no in�cio da lista
bool insere(No **lista, int valor){

    No *novo = new No();
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void mostrar(No *lista){

    No *n = lista;
    cout << "\n Valores da lista: \n";
    while(n){/// enquanto n n�o for NULL fica no la�o
     cout << n->dado << "\t";
     n = n->prox;
    }
    cout << "\n";
}

///remover um valor espec�fico da lista
bool remover(No **lista, int valor){
    No *anterior = NULL;
    No *atual = *lista;
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
        *lista = atual->prox;
    }else{ /// elemento est� no meio ou no fim
        anterior->prox = atual->prox;
    }
    /// libera a mem�ria do elemento
    delete(atual);
    return true;
}
