# include <iostream>
# include <string>

using namespace std;

class Veiculo{

    protected:
      string marca;
      string modelo;
      float preco;

    private:
      int teste;

    public:

      //contrutor
      Veiculo(){
        marca= "";
        modelo= "";
        preco= 0.0;
      };

      //contrutor com parametro. Polimorfismo do tipo sobrecarga
      Veiculo(string mc, string md, float pr){
        marca= mc;
        modelo= md;
        preco= pr;
      };

      //metodo destrutor
      ~Veiculo(){
        cout << "Deletando instancia de veiculo." << endl;
      };

      string getMarca(){
        return marca;
      };

      void setMarca(string mc){
        marca=mc;
      };

      string getModelo(){
        return modelo;
      };

      void setModelo(string md){
        modelo= md;
      };

      float getPreco(){
        return preco;
      };

      void setPreco(float pr){
        preco= pr;
      };

};


class Carro:public Veiculo{
  private:
    int tipoCambio;
    int numeroAssentos;

  public:

    Carro(){

    };

    Carro(string mc, string md, float pr, int tc, int na){
      marca= mc;
      modelo= md;
      preco= pr;

      tipoCambio= tc;
      numeroAssentos= na;
    };

    ~Carro(){

    };

    int getTipoCambio(){
      return tipoCambio;
    };

    void setTipoCambio(int tc){
      tipoCambio= tc;
    };

    int getNumeroAssentos(){
      return numeroAssentos;
    };

    void setNumeroAssentos(int na){
      numeroAssentos= na;
    };

};


class Aviao:public Veiculo{
  private:
    int potencia;
    int numeroAssentos;

  public:

    Aviao(){

    };

    Aviao(string mc, string md, float pr, int pt, int na){
      marca= mc;
      modelo= md;
      preco= pr;

      potencia= pt;
      numeroAssentos= na;
    };

    ~Aviao(){

    };

    int getTipoCambio(){
      return potencia;
    };

    void setTipoCambio(int pt){
      potencia= pt;
    };

    int getNumeroAssentos(){
      return numeroAssentos;
    };

    void setNumeroAssentos(int na){
      numeroAssentos= na;
    };
    
};
