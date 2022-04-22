/// ListaAnimal Animal
//código, tipo, nome, idade, raça, e porte (P,M,G).

typedef struct Animais
{
    int cod;
    int tipo;
    string nome;
    int idade;
    string raca;
    char porte;

} Animais;

typedef struct noAnimal
{
    Animais animal;
    struct noAnimal *ant;
    struct noAnimal *prox;
    noAnimal()
    {
        animal.cod = 0;
        animal.tipo = 0;
        animal.nome = "";
        animal.idade = 0;
        animal.raca = "";
        animal.porte = ' ';
        ant = NULL;
        prox = NULL;
    }
} NoAnimal;

typedef struct listaAnimal
{
    NoAnimal *inicio;
    NoAnimal *fim;
    int tamanho;
    listaAnimal()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~listaAnimal()
    {
        NoAnimal *n = inicio;
        while(n)
        {
            NoAnimal *aux = n;
            n = n->prox;
            delete aux;
        }
    }
} ListaAnimal;

bool inserir(ListaAnimal *listaAnimal, Animais t)
{

    NoAnimal *novo = new NoAnimal();
    novo->animal = t;
    novo->prox = listaAnimal->inicio;

    if (listaAnimal->fim == NULL) ///listaAnimal vazia
        listaAnimal->fim = novo; /// vai ser o primeiro nó da listaAnimal
    else
        listaAnimal->inicio->ant = novo;  /// atualiza anterior
    listaAnimal->inicio = novo;
    listaAnimal->tamanho++;

}

bool remover(ListaAnimal *listaAnimal, int cod){
    NoAnimal *anterior = NULL;
    NoAnimal *atual = listaAnimal->inicio;
    ///fica no laço enquanto tiver elementos na listaAnimal
    /// e não encontrar o valor procurado
    while(atual && atual->animal.cod != cod){
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
   /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da listaAnimal
        listaAnimal->inicio = atual->prox;
        if (listaAnimal->inicio == NULL)/// listaAnimal fica vazia
            listaAnimal->fim = listaAnimal->inicio;
        else
            listaAnimal->inicio->ant = NULL; ///se torna o primeiro da listaAnimal

    }else{ /// elemento está no meio ou no fim
        anterior->prox = atual->prox;
        if (atual->prox == NULL)/// se for retirado último da listaAnimal
            listaAnimal->fim = anterior;
        else
            atual->prox->ant = anterior;
    }
    /// libera a memória do elemento
    listaAnimal->tamanho--;
    delete(atual);
    return true;

}

bool removerNoAnimal(ListaAnimal *listaAnimal, NoAnimal *noAnimal){
    if (!noAnimal->ant) /// se anterior é igual a NULL
    { /// o elemento a ser excluído está no início da listaAnimal
        listaAnimal->inicio = noAnimal->prox;
        if (listaAnimal->inicio == NULL)
            listaAnimal->fim = listaAnimal->inicio;
        else
            listaAnimal->inicio->ant = NULL; ///se torna o primeiro da listaAnimal
    }else{ /// elemento está no meio ou no fim
        noAnimal->ant->prox = noAnimal->prox;
        if (noAnimal->prox == NULL){/// se for retirado último da listaAnimal{
            listaAnimal->fim = noAnimal->ant;
        }
        else
            noAnimal->prox->ant = noAnimal->ant;
    }
    /// libera a memória do elemento
    listaAnimal->tamanho--;
    delete(noAnimal);
    return true;
}


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const NoAnimal *n)
{
    string tipo ="";
    if(n->animal.tipo == 1)
        tipo= "CACHORRO";
    else if (n->animal.tipo == 2)
        tipo= "GATO";
        else if (n->animal.tipo == 3)
        tipo= "CAVALO";

    /// cout <<< n
    if
    return os <<"Codigo: "<< n->animal.cod << " Tipo: " <<tipo<<" Nome: "<<n->animal.nome;
}

/// quanto cout receber uma struct ListaAnimal
ostream& operator << (ostream& os, const ListaAnimal *l)
{
    NoAnimal *n = l->inicio;
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

void mostrarInverso(ListaAnimal *listaAnimal)
{
    NoAnimal *n = listaAnimal->fim;
    while(n)
    {
        cout << n->animal.cod <<  " " << n->animal.nome<< "\n";
        n = n->ant;
    }
    cout << endl;
}


NoAnimal* busca(ListaAnimal *listaAnimal, int cod)
{
    NoAnimal *n = listaAnimal->inicio;
    while(n)
    {
        if(n->animal.cod == cod)
            return n;

        n = n->prox;
    }
    return NULL;
}

