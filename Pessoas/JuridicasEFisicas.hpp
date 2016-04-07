#include <iostream>
#include <string>

using namespace std;

class Pessoa{

  protected:
    string nome;
    int idade;
    Pessoa * filhoEsquerda;
    Pessoa * filhoDireita;

  public:

    Pessoa(){
      nome = "";
      idade = 0;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
    };

    Pessoa( string n, int id){
      nome = n;
      idade = id;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
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

        if (this->filhoEsquerda == NULL)
          this->filhoEsquerda = nova;
        else
          this->filhoEsquerda->inserirPessoa(nova);

      }else{

        if (this->filhoDireita == NULL)
          this->filhoDireita = nova;
        else
          this->filhoDireita->inserirPessoa(nova);
      }

    };

    void mostrarPre(){

      cout << this->nome << " : " << this->idade  << endl;

      if (filhoEsquerda != NULL)
        this->filhoEsquerda->mostrarPre();

      if(filhoDireita != NULL)
        this->filhoDireita->mostrarPre();

    };

    void deletar(){

      if (this->filhoEsquerda != NULL)
        this->filhoEsquerda->deletar();

      if (this->filhoDireita != NULL)
        this->filhoDireita->deletar();

      delete this;
    }

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
