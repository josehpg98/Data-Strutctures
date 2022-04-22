#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
#include "tipo.hpp"
#include "animal.hpp"
#include "protetor.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");

//    Lista *lista = new Lista();///executa o construtor....
//
//    Tipos t;
//    t.cod = 1;
//    t.descricao = "Cao";
//    inserir(lista, t);

    ListaTipo *listaTipo = new ListaTipo();
    ListaAnimal *listaAnimal = new ListaAnimal();
    ListaProtetor *listaProtetor= new ListaProtetor();

    Tipos t;
    Animais a;
    Protetores p;

    t.cod = 1;
    t.descricao = "CAO";
    inserir(listaTipo, t);

    a.cod = 1;
    a.idade = 1;
    a.nome = "TOBIAS";
    a.porte = 'G';
    a.raca = "PURA";
    a.tipo = 1;
    inserir(listaAnimal, a);

    p.cod = 1;
    p.nome = "PROTETORNOME";
    p.telefone = 123123123;
    inserir(listaProtetor, p);

    cout<<listaTipo;
//    cout<<"ANIMAL: "<<listaAnimal;
//    cout<<"PROTETOR: "<<listaProtetor;



//    cout<<lista;
}
