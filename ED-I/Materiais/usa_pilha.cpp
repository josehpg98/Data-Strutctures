#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "pilha.hpp";

int main()
{
   pilha p1;
   inicializa(&p1, 10);
   empilhar(&p1, 8);
   empilhar(&p1, 10);
   empilhar(&p1, 20);
   mostrar(&p1);
   int valor = desempilhar(&p1);
   cout << "\n Valor retirado: " << valor << endl;
   mostrar(&p1);

   return 0;
}
