#include "JuridicasEFisicas.hpp"

int main(int argc, char *argv[]) {

  Pessoa* raiz = NULL;
  Pessoa* nova;

  string inserir = "sim";
  string nome;
  int idade;

  while (inserir != "não"){

    cout << "Insira o nome da pessoa." << endl;
    cin >> nome;
    cout << " Inserir idade" << endl;
    cin >> idade;

    nova = new Pessoa(nome, idade);
    //cout << nova->getNome() << endl;

    if (raiz==NULL){
      raiz=nova;
    }else{
      raiz->inserirPessoa(nova);
    }

    cout << "Caso não deseje inserir nova pessoa digite 'não' " << endl;
    cin >> inserir;

  };

  raiz->mostrarPre();

  raiz->deletar();


  return 0;
}
