/// pilha_dinamica.hpp
typedef struct registro
{
    char dado;
}Registro;
/**
struct registro
{
    int dado;
}
*/
typedef struct no
{
    Registro reg;
    no *prox;
} No;
typedef struct pilha
{
    No *topo;
} Pilha;
void init(Pilha *p)
{
    p->topo = NULL; ///pilha vazia /// (*p).topo
}
bool isEmpty(Pilha *p) /// verifica se a pilha est� vazia
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}
bool push(Pilha *p, Registro registro) /// empilhar
{
    No *novo =  new No();
    if (!novo) /// sistema n�o conseguiu alocar a mem�ria
        return false;
    novo->reg = registro;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}
bool pop (Pilha *p, Registro *reg) /// desempilhar
{
    if (isEmpty(p))
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;  /// libera a mem�ria
    return true;
}
void show(Pilha *p)
{
    cout<<"Mostra a Pilha!" << endl;
    No *no = p->topo;
    cout << "\n Pilha:  [ ";
    while (no != NULL)
    {
        cout << no->reg.dado << "\t ";
        no = no->prox;
    }
    cout << " ] \n";
}
bool peek(Pilha *p, Registro *reg)
{
    if (p->topo != NULL)
    {
        *reg= p->topo->reg;
        return true;
    }
    else
        return false;
}
bool verifica_palindromo(Pilha *pi1,Pilha *pi2){
    No *no = pi1->topo;
    No *no1 = pi2->topo;
    while(no != NULL){
        while(no1 != NULL){
            if(no->reg.dado == no1->reg.dado){
                return true;
            }
             no1 = no1->prox;
        }
        no = no->prox;
    }
}

