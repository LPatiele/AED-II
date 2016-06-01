# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# define tamanho 10
using namespace std;

class Ordenar{
private:
  int t;
  int V[tamanho];

public:

  Ordenar() {
    t= tamanho;
    srand(time(NULL));
    for(int i=0; i<t ;i++){
      V[i]=1+(rand()%100);
    }
  };

  ~Ordenar(){};

  void mostrar(){
    for(int i=0; i< t; i++){
      cout << "Valor na posição "<< i <<" é: " << V[i] << endl;
    }
  };

  void aleatorio(){
    srand(time(NULL));
    for(int i=0; i<t ;i++){
      V[i]=1+(rand()%100);
    }
  };

  void bubbleSort() {
    /* Compara de dois em dois numeros e faz a troca entre eles se necessario. */
    for(int i=0; i<t; i++){
      for(int j=0; j<t; j++){
        if(V[i]<V[j]){
          int aux =V[j];
          V[j]=V[i];
          V[i]=aux;
        }
      }
    }
  };

  void selectionSort() {
    /* Ordena por posição. Varre o vetor e seleciona o menor numero e o insere na posição que esta sendo ordenada. */
    for(int i=0; i<t;i++){
      int aux=V[i];
      for(int j=i+1 ; j<t; j++){
        if(aux>V[j]){
          int aux2=V[j];
          V[j]=aux;
          aux=aux2;
        }
      }
      V[i]=aux;
    }
  };

  void insertioSort(){
    /* Compara um trexo ja ordenado com o proximo elemento e entao o ordena*/
    int tOrd=1;//variavel que indica o tamanho do vetor q ja esta ordenado.
    for(int i=(tOrd-1); i<=0;i--){
        if(V[tOrd]<V[i]){
          int aux=V[j];
          V[j]=V[tOrd];
          V[tOrd]=aux;
        }
        tOrd++;
    }


  };

};
