
# include "ordenar.hpp"

int main(int argc, char const *argv[]) {
  Ordenar vet;

  // cout<<"Vetor 1:"<<endl;
  // vet.mostrar();
  // vet.bubbleSort();
  // cout<<endl;
  // cout<<"Vetor 1 ordenado com Bubble Sort:"<<endl;
  // vet.mostrar();
  // cout<<"___________________________________________________________________"<<endl<<endl;
  //
  // cout<<"Vetor 2:"<<endl;
  // vet.aleatorio();
  // vet.mostrar();
  // vet.selectionSort();
  // cout<<endl;
  // cout<<"Vetor 2 ordenado com Selection Sort:"<<endl;
  // vet.mostrar();
  // cout<<"___________________________________________________________________"<<endl<<endl;
  //
  // cout<<"Vetor 3:"<<endl;
  // vet.aleatorio();
  // vet.mostrar();
  // vet.insertionSort();
  // cout<<endl;
  // cout<<"Vetor 3 ordenado com Insertion Sort:"<<endl;
  // vet.mostrar();
  // cout<<"___________________________________________________________________"<<endl<<endl;
  //
  // cout<<"Vetor 4:"<<endl;
  // vet.aleatorio();
  // vet.mostrar();
  // vet.shellSort();
  // cout<<endl;
  // cout<<"Vetor 4 ordenado com Shell Sort:"<<endl;
  // vet.mostrar();
  // cout<<"___________________________________________________________________"<<endl<<endl;

  cout<<"Vetor 5:"<<endl;
  vet.aleatorio();
  vet.mostrar();
  vet.chamarQuicksort();
  cout<<endl;
  cout<<"Vetor 5 ordenado com quickSort:"<<endl;
  vet.mostrar();
  cout<<"___________________________________________________________________"<<endl<<endl;

  cout<<"Vetor 6:"<<endl;
  vet.aleatorio();
  vet.mostrar();
  vet.chamarMergeSort();
  cout<<endl;
  cout<<"Vetor 6 ordenado com MergeSort:"<<endl;
  vet.mostrar();
  cout<<"___________________________________________________________________"<<endl<<endl;
}
