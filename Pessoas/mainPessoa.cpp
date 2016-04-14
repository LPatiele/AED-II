#include "JuridicasEFisicas.hpp"

int main(int argc, char *argv[]) {

  Pessoa* raiz = NULL;
  Pessoa* nova;
  Pessoa* aux;

  int inserir = 0;
  string nome;
  int idade;

  while (inserir < 5){
    cout << "--------------------------------------------------- " << endl;
    cout << "Insira o nome da pessoa e idade" << endl;
    cin >> nome;
    cin >> idade;

    nova = new Pessoa(nome, idade);
    //cout << nova->getNome() << endl;
    if (raiz==NULL)  raiz=nova;
    else  raiz->inserirPessoa(nova);
    inserir ++;
  };

  //raiz->mostrarPre();
  // raiz->mostrarPos();
  cout << "----------Antes---------" << endl;
  raiz->mostrarOrdem();
  // aux = raiz->busca(5);
  // cout << aux->nome << " tem " << aux->idade << endl;
  raiz->apaga(40);
  cout << "---------Depois---------" << endl;
  cout << "Apagou quem tem 40" << endl;
  raiz->mostrarOrdem();
  raiz->deletar();


  return 0;
}
