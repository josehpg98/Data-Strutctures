#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
main()
{
    setlocale(LC_ALL,"Portuguese");
    int quant;
    double total = 0, media = 0;
    cout<<"Informe a quantidade de alunos da turma: " << endl;
    cin>>quant;
    cout<<endl;
    cout<<endl;
    double *vet = new double[quant];
    for(int i = 1;i<=quant;i++){
        cout<<"informe a nota do " << i << " aluno: " << endl;
        cin>>vet[i];
        total += vet[i];
    }
    delete vet;
    total = ( total / quant);
    cout<<" A média aritmética dos " << quant << " alunos é: " << total << endl;
}
