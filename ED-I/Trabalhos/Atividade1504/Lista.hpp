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
/**No* busca(No *lista,int valor){///retorna o primeiro no somente
    No *n = lista;
    return n;
};**/
int contlista(No *lista){
    int cont = 0;
    No *n = lista;
     while(n){
        n = n->proximo;
        cont++;
    }
   return cont;
}
bool vazia(No *lista){
    if(lista == NULL){
        cout<<" A lista está vazia!" << endl;
        getchar();
        cout<<endl;
        return true;
    }else{
        cout<<" A lista não está vazia!" << endl;
        getchar();
        cout<<endl;
        return false;
    }
}
bool igual(No *lista1, No *lista2){
     No *n1 = lista1;
     No *n2 = lista2;
    while(n1){
            while(n2){
                if(n1->dados = n2->dados){
                    cout<<"As Listas São Iguais!" << endl;
                    getchar();
                    return true;
                }
                n2 = n2->proximo;
            }
        n1 = n1->proximo;
    }
    return false;
}
No* busca(No *lista,int valor){///retorna o primeiro no somente
    No *n = lista;
    while(n){
        if(n->dados == valor){
            return n;
        }
        n = n->proximo;
    }
};
