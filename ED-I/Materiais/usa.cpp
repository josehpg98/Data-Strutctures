#include <iostream>
#include <stdio.h>

using namespace std;

#include "fila_dinamica.hpp"

int main()
{
    Fila fila, fila2, fila3;
    initQ(&fila);

    Registro reg;
    reg.dado = 10;


    if (!enqueue(&fila, reg))
        cout << "\n Sem memória\n";

    reg.dado = 20;
    enqueue(&fila, reg);

    reg.dado = 30;
    enqueue(&fila, reg);

    showQ(&fila);


    dequeue(&fila, &reg);
    cout << "\n Valor retirado: " << reg.dado;

    showQ(&fila);


    No *no = peekQ(&fila);
    cout << "\n Próximo da fila: " << no->reg.dado;

    resetQ(&fila);
    showQ(&fila);
///montar menu para as opções (incluir, excluir, mostrar, limpar, ver próximo
/// fazer uma função booleana (true/false) para pesquisar se um valor existe na fila
/// fazer uma função que retorna o número de elementos(nós) na fila

}
