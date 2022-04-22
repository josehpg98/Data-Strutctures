#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void lervetor(int *v,int t);
main()
{
    setlocale(LC_ALL,"Portuguese");
    int tam;
    cout<<"informe o tamanho do vetor: " << endl;
    cin>>tam;
    int *vetor = new int[tam];
    lervetor(vetor,tam);
    cout<<"IMPRIMINDO VALORES NA FUNÇÃO!"<<endl;
      for(int i = 1;i <= tam;i++){
        cout<<vetor[i]<<endl;
    }
    delete vetor;
}
void lervetor(int *v,int t){
    cout<<"LENDO VALORES NA FUNÇÃO!"<<endl;
    for(int i = 1;i <= t;i++){
        cin>>v[i];
    }
}
