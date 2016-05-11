#include "JuridicasEFisicas.hpp"

int main(int argc, char *argv[]) {

  Pessoa* raiz = NULL;
  Pessoa* nova;
  Pessoa* aux;

  int x = 0;
  string nome;
  int idade;

  while (x < 10){
    cout << "--------------------------------------------------- " << endl;
    cout << "Insira o nome da pessoa e idade" << endl;
    cin >> nome;
    cin >> idade;

    nova = new Pessoa(nome, idade);
    //cout << nova->getNome() << endl;
    if (raiz==NULL)  raiz=nova;
    else  raiz->inserirPessoa(nova);
    x ++;
  };

  //raiz->mostrarPre();
  // raiz->mostrarPos();
  cout << "----------Antes---------" << endl;
  raiz->mostrarOrdem();
  // aux = raiz->busca(5);
  // cout << aux->nome << " Agora informe a idade" << aux->idade << endl;
  x=0;
  string matriz[5][2];
  while (x < 5){
    cout << "--------------------------------------------------- " << endl;
    cout << "Informe a idade da "<< x-1 <<" pessoa a ser apagada." << endl;
    cin >> idade;
    raiz->apaga(idade,raiz,&matriz, x);
    x ++;
  };


  cout << "---------Depois---------" << endl;
  cout << "Foram apagadas: " << endl;
  while (x < 5){
    cout << matriz[x][0] << " de " << matriz [x][1] << " anos."<< endl;
    x++;
  };
  cout << "Ficaram: " << endl;
  raiz->mostrarOrdem();
  raiz->deletar();


  return 0;
}
