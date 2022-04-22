#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

#include "pilha_dinamica.hpp"

void inserir(Pilha *p);
void exibirTopo(Pilha *p);
void excluir(Pilha *p);
void meuLog(Pilha *p);
void help();
void destruir(Pilha *p);

int main(){
  setlocale(LC_ALL, "Portuguese");
  Pilha pilha;
  init(&pilha);
  //help();
  char menu = ' ';
  while (menu != '0'){
    system("cls");
    help();
    cout << "Opção: ";
    cin >> menu;
    fflush(stdin);
    switch (menu) {
      case '1' : inserir(&pilha);
          break;
      case '2' : excluir(&pilha);
          break;
      case '3' : show(&pilha);
          break;
      case '4' : destruir(&pilha);
          break;
      case '5' : meuLog(&pilha);
          break;
      case '6' : help();
          break;
      case '7' : exibirTopo(&pilha);
          break;
    }
    fflush(stdin);
    getchar();
  }
  return 0;
}

void help(){
  cout << "Opções: \n";
  cout << "   1 : inserir elemento na pilha \n";
  cout << "   2 : excluir topo da pilha\n";
  cout << "   3 : mostrar pilha\n";
  cout << "   4 : destruir (zerar) pilha\n";
  cout << "   5 : exibir log de utilização da pilha \n";
  cout << "   6 : exibir esta mensagem de ajuda \n";
  cout << "   7 : exibir a chave e o endereço do primeiro elemento\n";
  cout << "   0 : sair\n";
}


void inserir(Pilha *p)
{
    int dado;
    cout << "\n Informe valor: ";
    cin >> dado;
    Registro reg;
    reg.dado = dado;
    if(push(p, reg))
        cout << "\n No inserido na pilha" << endl;
    else
        cout << "\n Não foi possível incluir na pilha" << endl;
}


void excluir(Pilha *p)
{
    Registro reg;
    if (pop(p,&reg))
        cout << "\n Valor retirado: " << reg.dado << endl;
    else
        cout << "\n Pilha vazia";

}



void exibirTopo(Pilha *p)
{
  Registro reg;
  if(peek(p, &reg))
        cout << "\n Dado: " << reg.dado << endl;
  else
        cout << "\n Pilha vazia.";
}



void destruir(Pilha *p)
{
    reset(p);
    cout << "\n Pilha zerada!";
}



void meuLog(Pilha *p)
{
   cout << "\n Número de elementos: " << sizePilha(p) << endl;
   cout << "\n Tamanho em bytes: " << sizeBytes(p) << endl;
}






