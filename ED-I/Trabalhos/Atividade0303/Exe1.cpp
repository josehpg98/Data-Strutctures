#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;
#include "PilhaDiamicaCaracter.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Registro r1,r2;
    Pilha p1;
    Pilha p2;
    init(&p1);
    init(&p2);
    bool res;
    char texto[80];
    int tam = 0;
    cout<<"Informe uma palavra: " << endl;
    gets(texto);
    tam = strlen(texto);
    for(int i = 0;i < tam;i++){
        r1.dado = texto[i];
        push(&p1,r1);
    }
     for(int i = tam;i >= 0;i--){
        r2.dado = texto[i];
        push(&p2,r2);
    }
    //show(&p1);
    //show(&p2);
    res = verifica_palindromo(&p1,&p2);
    if(res == true){
        cout<<"A palavra é um palindromo!"<< endl;
    }else{
         cout<<"A palavra não é um palindromo!"<< endl;
    }
}
