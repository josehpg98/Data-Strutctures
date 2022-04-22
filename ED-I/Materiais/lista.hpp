
typedef struct no{
    int dado;
    struct no *prox;
}No;


void inicializa (No **lista){

    *lista = NULL;
}

///insere no início da lista
bool insere(No **lista, int valor){

    No *novo = new No();
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void mostrar(No *lista){

    No *n = lista;
    cout << "\n Valores da lista: \n";
    while(n){/// enquanto n não for NULL fica no laço
     cout << n->dado << "\t";
     n = n->prox;
    }
    cout << "\n";
}

///remover um valor específico da lista
bool remover(No **lista, int valor){
    No *anterior = NULL;
    No *atual = *lista;
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
        *lista = atual->prox;
    }else{ /// elemento está no meio ou no fim
        anterior->prox = atual->prox;
    }
    /// libera a memória do elemento
    delete(atual);
    return true;
}
