# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# define tamanho 10
using namespace std;

class Ordenar{
private:
  int t;
  int v[tamanho];

public:

  Ordenar() {
    t= tamanho;
    aleatorio();
  };

  ~Ordenar(){};

  void mostrar(){
    for(int i=0; i< t; i++){
      cout << "Valor na posição "<< i <<" é: " << v[i] << endl;
    }
  };

  void aleatorio(){
    srand(time(NULL));
    for(int i=0; i<t ;i++){
      v[i]=1+(rand()%100);
    }
  };

  void bubbleSort() {
    /* Compara de dois em dois numeros e faz a troca entre eles se necessario. */
    for(int i=0; i<t; i++){
      for(int j=0; j<t; j++){
        if(v[i]<v[j]){
          int aux =v[j];
          v[j]=v[i];
          v[i]=aux;
        }
      }
    }
  };

  void selectionSort() {
    /* Ordena por posição. Varre o vetor e seleciona o menor numero e o insere na posição que esta sendo ordenada. */
    for(int i=0; i<t;i++){
      int aux=v[i];
      for(int j=i+1 ; j<t; j++){
        if(aux>v[j]){
          int aux2=v[j];
          v[j]=aux;
          aux=aux2;
        }
      }
      v[i]=aux;
    }
  };

  void insertionSort(){
    /* Compara um trexo ja ordenado com o proximo elemento e entao o ordena*/
    for(int i=1; i<t ; i++){
        int aux=v[i];
        int j=i-1;
        while(j>=0 && v[j]>aux){
          v[j+1]=v[j];
          j--;
        }
        v[j+1]=aux;
    }
  };

  void shellSort(){
    /* Usa uma chave pra diminuir a quantidade de trocas*/
    int metade = t/2;
    while(metade > 0){
      for(int i = 0; i < t-metade; i++){
        if(v[i] > v[i+metade]){
          int aux = v[i];
          v[i] = v[i+metade];
          v[i+metade] = aux;
        }
      }
      metade--;
    }
  };

  void chamarMergeSort(){
    mergeSort(0,t);
  };
  void mergeSort( int inicio, int fim) {
    if(inicio == fim) return;
    int meio = (inicio + fim ) / 2;
    mergeSort(inicio, meio);
    mergeSort(meio + 1, fim);
    int k=0, i = inicio, j = meio + 1;
    int *temporario = new int [fim - inicio + 1];
    while(i < meio + 1 || j  < fim + 1) {
        if (i == meio + 1 ) {
            temporario[k] = v[j];
            j++;
            k++;
        }
        else {
            if (j == fim + 1) {
                temporario[k] = v[i];
                i++;
                k++;
            }
            else {
                if (v[i] < v[j]) {
                    temporario[k] = v[i];
                    i++;
                    k++;
                }
                else {
                    temporario[k] = v[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for(i = inicio; i <= fim; i++) {
        v[i] = temporario[i - inicio];
    }
    delete [] temporario;
}

  void chamarQuicksort() {
    quickSort(0,t);
    cout<<"chamou"<<endl;
  };

  void quickSort(int inicio, int fim){
     /* Usa recursividade */
     int pivor = v[inicio];
     int i=inicio, j=fim, aux;
     while (i<=j) {
       while(v[i]<pivor && i<fim){ i++; }
       while(v[j]>pivor && j>inicio){ j--; }
       if(i<=j){
         aux = v[i];
         v[i]=v[j];
         v[j]= aux;
         i++;
         j--;
       }
     }
     if(j>inicio)       quickSort(inicio,j);
     if(i<fim)    quickSort(i,fim);
  };

};
