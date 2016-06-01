
# include "ordenar.hpp"

int main(int argc, char const *argv[]) {
  Ordenar vet;

  cout<<"Vetor 1:"<<endl;
  vet.mostrar();
  vet.bubbleSort();
  cout<<endl;
  cout<<"Vetor 1 ordenado com Bubble Sort:"<<endl;
  vet.mostrar();
  cout<<"___________________________________________________________________"<<endl<<endl;

  cout<<"Vetor 2:"<<endl;
  vet.aleatorio();
  vet.mostrar();
  vet.selectionSort();
  cout<<endl;
  cout<<"Vetor 2 ordenado com Selection Sort:"<<endl;
  vet.mostrar();
  cout<<"___________________________________________________________________"<<endl<<endl;

  cout<<"Vetor 3:"<<endl;
  vet.aleatorio();
  vet.mostrar();
  vet.insertioSort();
  cout<<endl;
  cout<<"Vetor 3 ordenado com Selection Sort:"<<endl;
  vet.mostrar();
  cout<<"___________________________________________________________________"<<endl<<endl;


}
