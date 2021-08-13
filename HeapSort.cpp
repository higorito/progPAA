#include <iostream>
using namespace std;

void heapify(int vet[], int n, int i)
{
    int raiz = i;
    int l = 2 * i + 1; //esquerda
    int r = 2 * i + 2;  //direita


    if (l < n && vet[l] > vet[raiz])    //se estiver no vetor e a esquerda for maior que a raiz grava na variavel para auxiliar na troca posterior
        raiz = l;

    if (r < n && vet[r] > vet[raiz])   //mesma coisa pra direita
        raiz = r;


    if (raiz != i) {              //se mudou faz a troca
        swap(vet[i], vet[raiz]);

       //aplicar resursividade pra ir "descendo" a arvore
        heapify(vet, n, raiz);   //aqui agora passa a raiz pq ela mudou...
    }
}

void heapSort(int vet[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)  //ta rearranjando o vet
        heapify(vet, n, i);

    for (int i = n - 1; i >= 0; i--) {  //aqui esta jogando o valor pro final e diminuindo o vet

        swap(vet[0], vet[i]);

    //assim só bagunça o vetor... entao toda troca aplica heapfy dnv... ate 0 dessa vez

        heapify(vet, i, 0);
    }
}
void mostrarVet(int vet[], int n)   //somente uma função pra printar o vetor
{
    for (int i = 0; i < n; ++i)
        cout << vet[i] << ", ";
}

int main()
{
    int vet[] = {9,10,-1,3,6,2,1,-3,1,0,-2,15,8,-7,0};
    int n = sizeof(vet) / sizeof(vet[0]);  //determinando o tamanho

    heapSort(vet, n);  //aplica e ja era

    cout << "Ordenado: "<<endl;
    mostrarVet(vet, n);
}
