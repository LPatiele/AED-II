#include <iostream>
#include <string>

using namespace std;

class Pessoa{

  protected:

    Pessoa * filhoEsquerda;
    Pessoa * filhoDireita;
    Pessoa * pai;

  public:
    string nome;
    int idade;
    Pessoa(){
      nome = "";
      idade = 0;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      pai = NULL;
    };

    Pessoa( string n, int id){
      nome = n;
      idade = id;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      pai = NULL;
    };

    ~Pessoa(){

    };

    // void setNome(string n){
    //   nome = n;
    // };
    //
    // string getNome(){
    //   return nome;
    // };
    //
    // void setIdade(int id){
    //   idade = id;
    // };
    //
    // int getIdade(){
    //   return idade;
    // };

    void inserirPessoa(Pessoa *nova){
      if (nova->idade < this->idade){
        if (this->filhoEsquerda == NULL) {
          this->filhoEsquerda = nova;
          nova->pai = this;
        }
        else  this->filhoEsquerda->inserirPessoa(nova);
      }else{
        if (this->filhoDireita == NULL) {
          this->filhoDireita = nova;
          nova->pai = this;
        }
        else  this->filhoDireita->inserirPessoa(nova);
      }
    };

    void mostrarPre(){
      cout << this->nome << " : " << this->idade  << endl;
      if (filhoEsquerda != NULL)  this->filhoEsquerda->mostrarPre();
      if(filhoDireita != NULL)  this->filhoDireita->mostrarPre();
    };

    void mostrarOrdem(){
      if (filhoEsquerda != NULL) this->filhoEsquerda->mostrarPre();
      cout << this->nome << " : " << this->idade  << endl;
      if(filhoDireita != NULL) this->filhoDireita->mostrarPre();
    };

    void mostrarPos(){
      if (filhoEsquerda != NULL) this->filhoEsquerda->mostrarPre();
      if(filhoDireita != NULL) this->filhoDireita->mostrarPre();
      cout << this->nome << " : " << this->idade  << endl;
    };

    void deletar(){
      if (this->filhoEsquerda != NULL) this->filhoEsquerda->deletar();
      if (this->filhoDireita != NULL) this->filhoDireita->deletar();
      delete this;
    };

    Pessoa * busca(int idade){
      if (this->idade == idade) return this;
      if(this->idade > idade && this->filhoEsquerda != NULL) return this->filhoEsquerda->busca(idade);
      if(this->idade < idade && this->filhoDireita != NULL) return this->filhoDireita->busca(idade);
      return NULL;
    };

    void apaga(int idade){
      //------------------------folha---------------------------------------
      Pessoa* aux = this->busca(idade);
      if(aux->filhoDireita == NULL && aux->filhoEsquerda == NULL) {
        
        if(aux->pai->filhoDireita == aux) aux->pai->filhoDireita = NULL;
        if(aux->pai->filhoEsquerda == aux) aux->pai->filhoEsquerda = NULL;
        delete aux;
      }
      // ---------------------com um filho----------------------------------
      else if(aux->filhoDireita != NULL && aux->filhoEsquerda == NULL){
        if(aux->pai->filhoDireita == aux) aux->pai->filhoDireita = aux->filhoDireita;
        if(aux->pai->filhoEsquerda == aux) aux->pai->filhoEsquerda = aux->filhoDireita;
        aux->filhoDireita->pai= aux->pai;
        delete aux;
      }else if(aux->filhoEsquerda != NULL && aux->filhoDireita == NULL){
        if(aux->pai->filhoDireita == aux) aux->pai->filhoDireita = aux->filhoEsquerda;
        if(aux->pai->filhoEsquerda == aux) aux->pai->filhoEsquerda = aux->filhoEsquerda;
        aux->filhoEsquerda->pai = aux->pai;
        delete aux;
      }
      // ---------com muitos filhos indo pelo descendente a direita---------
      else {
        //buscar descendente mais proximo
        Pessoa* auxExtra = aux->filhoDireita;
        while(auxExtra->filhoEsquerda != NULL ){
          auxExtra = auxExtra->filhoEsquerda;
        }
        if(auxExtra->filhoDireita != NULL){
          auxExtra->filhoDireita->pai = auxExtra->pai;
        }
        auxExtra->pai->filhoEsquerda = auxExtra->filhoDireita;
        auxExtra->pai = aux->pai;
        auxExtra->filhoDireita = aux->filhoDireita;
        auxExtra->filhoEsquerda = aux->filhoEsquerda;
        delete aux;
      }

    };

};



// class PessoaFisica:public Pessoa{
//
//  protected:
//    string cpf;
//
//  public:
//
//    PessoaFisica(){
//      nome = "";
//      idade = 0;
//      cpf="";
//    };
//
//    PessoaFisica(string n, int id, string c){
//      nome = n;
//      idade = id;
//      cpf = c;
//    };
//
//    void setCpf(string c){
//      cpf = c;
//    };
//
//    string getCpf(){
//      return cpf;
//    };
//
// };
//
// class PessoaJuridica:public Pessoa{
//
//  protected:
//    string cnpj;
//
//  public:
//
//    PessoaJuridica(){
//      nome = "";
//      idade = 0;
//      cnpj="";
//    };
//
//    PessoaJuridica(string n, int id, string c){
//      nome = n;
//      idade = id;
//      cnpj = c;
//    };
//
//    void setCpf(string c){
//      cnpj = c;
//    };
//
//    string getCpf(){
//      return cnpj;
//    };
//
// };
