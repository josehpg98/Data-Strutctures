///pilha_dinamica.hpp
typedef struct registro//define um novo tipo (registro = nome da estrutura)
{
    int dado;
}Registro;//nome do tipo
/**
struct registro
{
    int dado;
}
**/
typedef struct no // defini��o de tipo de estrutura no
{
    Registro reg;//variavel do tipo registro que cont�m o dado guardado
    no *prox;//ponteiro que aponta para o proximo endere�o que est� abaixo, onde tambem armazena uma estrutura no.
} No;//nome do tipo
typedef struct pilha//definicao do tipo da estrutura
{
    No *topo;//aponta para uma estrutura do tipo no
} Pilha;//nome do tipo
void init(Pilha *p)//inicializa��o da pilha
{
    p->topo = NULL; ///pilha vazia /// (*p).topo
}
bool isEmpty(Pilha *p) /// verifica se a pilha esta vazia
{
    if (p->topo == NULL)//se o topo for igual a nulo
        return true;
    else
        return false;
}
bool push(Pilha *p, Registro registro) /// empilhamento
//empilha na pilha definida um novo registro.
{
    No *novo =  new No();//aloca dinamicamente na mem�ria
    if (!novo) /// sistema n o conseguiu alocar a mem ria
        return false;
    novo->reg = registro;//novo (No) na estrutura ->registro, recebe o registro para novo empilhamento
    novo->prox = p->topo;//novo (No) na estrutura->prox recebe o topo do antigo endere�o
    p->topo = novo;//na pilha o topo, recebe o novo no, que agor � o topo
    return true;//conseguiu incluir
}
bool pop (Pilha *p, Registro *reg) /// desempilhamento
//o parametro registro caso quem chamou a fun��o queira trabalhar com o valor desempilhado
{
    if (isEmpty(p))//se a pilh estiver vazia
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg//recebe o rgistro que esta no topo
    No *apagar = p->topo;//apagar recebe quem est� no topo
    p->topo = p->topo->prox;//agora o topo recebe o proximo endere�o
    delete apagar;  /// libera a mem�ria
    return true;
}
void show(Pilha *p)//mostra a pilha
{
    No *no = p->topo;//ponteiro no recebe quem esta no topo
    cout << "\n Pilha:  [ ";
    while (no != NULL)//enqunto no n�o for nulo
    {
        cout << no->reg.dado << "\t ";////mostra a esturtura no do tipo registro o dado
        no = no->prox;//no recebe o proximo no
    }
    cout << " ] \n";
}
bool peek(Pilha* p, Registro *reg)//espiar/ olhar quem est� no topo
{
    if (p->topo != NULL)//se o topo nao for nulo
    {
        *reg= p->topo->reg;//ponteiro recebe quem esta no topo
        return true;
    }
    else
        return false;
}

