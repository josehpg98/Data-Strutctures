///Lista Condominio Trabalho 2 Etapa
typedef struct Casa///Estrutura Casa -
{
    int numero_casa;
    string rua;
    int numero_total_moradores;
} Casa;
typedef struct Moradores///Estrutura Moradores
{
    int codigo;
    string nome;
    string documento;
    int idade;
    string sexo;
} Moradores;
typedef struct moradoresCasa///ESTRUTURA mORADORES DA CASA -
{
    int codMorador;
    struct moradoresCasa *prox;
    noMoradoresCasa()
    {
        codMorador = NULL;
        prox = NULL;
    }
} MoradoresCasa;
typedef struct no_morador///Nó Referente a estrutura morador
{
    Moradores mor;
    struct no_morador *ant;
    struct no_morador *prox;
    no_morador()///Construtor Nó Morador
    {
        mor.codigo = 0;
        mor.nome = "";
        mor.documento = "";
        mor.idade = 0;
        mor.sexo = ' ';
        ant = NULL;
        prox = NULL;
    }
} No_Morador;
typedef struct no_casa///Nó Referente a estrutura CASA -
{
    Casa c;
    struct no_casa *ant;
    struct no_casa *prox;
    struct moradoresCasa *moradoresC;//ponteiro sublista moradores casa
    no_casa()///Construtor Nó Morador
    {
        c.numero_casa = 0;
        c.rua = "";
        c.numero_total_moradores = 0;
        ant = NULL;
        prox = NULL;
        moradoresC = NULL;
    }
} No_Casa;
typedef struct lista_moradores ///ESTRUTURA LISTA MORADORES
{
    No_Morador *inicio;
    No_Morador *fim;
    int tamanho;
    lista() /// construtor
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~lista_moradores() /// desconstrutor /// quando chame delete(ponteiro)
    {
        No_Morador *nm = inicio;
        while(nm)
        {
            No_Morador *aux = nm;
            nm = nm->prox;
            delete aux;
        }
    }
} Lista_Moradores;
typedef struct lista_casa ///ESTRUTURA LISTA CASAS
{
    No_Casa *inicio;
    No_Casa *fim;
    int tamanho;
    lista_casa() /// construtor
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~lista_casa() /// desconstrutor /// quando chame delete(ponteiro)
    {
        No_Casa *nc = inicio;
        while(nc)
        {
            No_Casa *aux = nc;
            nc = nc->prox;
            delete aux;
        }
    }
} Lista_Casa;
bool insere_moradores(Lista_Moradores *listaM, Moradores m) ///INSERÇÃO MORADORES
{

    No_Morador *novo = new No_Morador();
    novo->mor = m;
    novo->prox = listaM->inicio;

    if (listaM->fim == NULL) ///lista vazia
        listaM->fim = novo; /// vai ser o primeiro nó da lista
    else
        listaM->inicio->ant = novo;  /// atualiza anterior
    listaM->inicio = novo;
    listaM->tamanho++;
}
bool insere_casa(Lista_Casa *listaC, Casa cs)///INSERÇÃO CASAS -
{
    No_Casa *novo = new No_Casa();
    novo->c = cs;
    novo->prox = listaC->inicio;

    if(listaC->fim == NULL)
        listaC->fim = novo;
    else
        listaC->inicio->ant = novo;  /// atualiza anterior
    listaC->inicio = novo;
    listaC->tamanho++;
}
ostream& operator<<(ostream& os, const No_Morador *nm)///Quando o Cout Recebe Um No_Morador
{
    return os << nm->mor.codigo << " | " << nm->mor.nome << " | " << nm->mor.documento << " | " << nm->mor.idade << " | " << nm->mor.sexo << endl;
};
ostream& operator<<(ostream& os, const No_Casa *nc)///Quando o Cout Recebe Um No_Casa
{
    return os << nc->c.numero_casa << " | " << nc->c.rua << " | " << nc->c.numero_total_moradores << endl;
};
ostream& operator << (ostream& os, const Lista_Moradores *lm)///Quando o cout receber uma lista do tipo morador
{
    No_Morador *nm = lm->inicio;
    while(nm)
    {
        os << nm;
        nm = nm->prox;
        if(nm)
            os << "\n";
    }
    os << endl;
    return os;
}
ostream& operator << (ostream& os, const Lista_Casa *lc)///cout mostrar sublista CASA -
{
    No_Casa *nc = lc->inicio;
    while(nc)
    {
        os << nc;
        MoradoresCasa *mc = nc->moradoresC;

        if (nc->moradoresC) ///tem sublista
        {
            os << " => ";
            while(mc)
            {
                os << mc->codMorador;
                mc = mc->prox;
                if(mc)
                    os << " | ";
            }
        }
        cout << endl;
        nc = nc->prox;
    }
    return os;
}
void mostrar_morador(Lista_Moradores *lista_moradores)///Mostrar Lista do Tipo Morador
{
    No_Morador *nm = lista_moradores->fim;
    cout<<" Mostrando Lista de Moradores: " << endl;
    cout<<" Código " << " | " << " Nome " << " | " << " Documento " << " | " << " Idade " << " | " << " Sexo " << endl;
    cout<<endl;
    while(nm)
    {
        cout<< nm->mor.codigo <<  " | " << nm->mor.nome  << " | " << nm->mor.documento << " | " << nm->mor.idade  << " | " << nm->mor.sexo << "\n";
        nm = nm->ant;
    }
    cout << endl;
}
void mostrar_casa(Lista_Casa *lista_casa)///Mostrar Lista do Tipo casa
{
    No_Casa *nc = lista_casa->fim;
    cout<<" Mostrando Lista de Casas: " << endl;
    cout<<" Número " << " | " << " Rua " << " | " << " Total Moradores " << endl;
    cout<<endl;
    while(nc)
    {
        cout << nc->c.numero_casa <<  " | " << nc->c.rua  << " | " << nc->c.numero_total_moradores << "\n";
        //cout<<Lista_Casa;
        nc = nc->ant;
    }
    cout << endl;
}
void mostra_numero_moradores(Lista_Moradores *lista_moradores)
{
    No_Morador *nm = lista_moradores->fim;
    int contMasc = 0,contFem = 0;
    cout<<" Mostrando Lista de Moradores Por Sexo: " << endl;
    while(nm)
    {
        if(nm->mor.sexo == "M")
        {
            contMasc += 1;
        }
        if(nm->mor.sexo == "F")
        {
            contFem += 1;
        }
        nm = nm->ant;
    }
    cout<<" Total de Pessoas do Sexo Feminino é: " << contFem << endl;
    cout<<" Total de Pessoas do Sexo Masculino é: " << contMasc << endl;
}
void media_idade_moradores(Lista_Moradores *lista_moradores)
{
    No_Morador *nm = lista_moradores->fim;
    int cont = 0,somaIdade = 0;
    double res;
    while(nm)
    {
        somaIdade += nm->mor.idade;
        cont++;
        nm = nm->ant;
    }
    res = (somaIdade / cont);
    cout<<" A Média de Idade dos Moradores é De: " << res << " Anos! \n";
}
void mostrar_numero_moradores_idade(Lista_Moradores *lista_moradores)
{
    No_Morador *nm = lista_moradores->fim;
    int contC = 0,contA = 0;
    cout<<" Mostrando Lista de Moradores Por Idade: " << endl;
    while(nm)
    {
        if(nm->mor.idade <= 12)
        {
            contC += 1;
        }
        if(nm->mor.idade > 12)
        {
            contA += 1;
        }
        nm = nm->ant;
    }
    cout<<" Total de Crianças é: " << contC << endl;
    cout<<" Total de Adultos é: " << contA << endl;
}
No_Casa* buscaMC(Lista_Casa *LC, int cod)///BUSCA  CASA
{
    No_Casa *nc = LC->inicio;
    while(nc)
    {
        if(nc->c.numero_casa == cod)///verifica se o codigo é
            return nc;

        nc = nc->prox;
    }
    return NULL;
}
bool insereMC(Lista_Casa *lc, int cod, int mor)///INSERE SUBLISTA MORADOR_CASA - errode conversão
{
    No_Casa *nc = buscaMC(lc, cod);
    if (nc)
    {
        MoradoresCasa *novo = new MoradoresCasa();
        novo->codMorador = mor;
        novo->prox = nc->moradoresC;
        nc->moradoresC = novo;
    }
    return true;
}
