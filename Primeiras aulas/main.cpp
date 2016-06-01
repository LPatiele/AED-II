# include "veiculo.hpp"

int main(int argc, char**argv) {

  string texto;
  float valor;
  int numero;

  // instanciando e manipolando um veiculo
  // Veiculo veiculo;
  //
  // cout << "Informe a marca do veiculo: " << endl;
  // cin >> texto;
  // veiculo.setMarca(texto);
  //
  // cout << "Informe o modelo: " << endl;
  // cin >> texto;
  // veiculo.setModelo(texto);
  //
  // cout << "Informe o preço: " << endl;
  // cin >> valor;
  // veiculo.setPreco(valor);
  //
  // cout << "Dados do veiculo: " ;
  // cout << veiculo.getMarca() << " - ";
  // cout << veiculo.getModelo() << " - ";
  // cout << veiculo.getPreco() << endl << endl;
  //
  // //instanciando e manipulando um carro com alocação dinamica
  // Carro *carro;
  // carro = new Carro();
  //
  // cout << "Informe a marca do carro: " << endl;
  // cin >> texto;
  // carro->setMarca(texto);
  //
  // cout << "Informe o modelo: " << endl;
  // cin >> texto;
  // carro->setModelo(texto);
  //
  // cout << "Informe o preço: " << endl;
  // cin >> valor;
  // carro->setPreco(valor);
  //
  // cout << "Informe o tipo de cambio: " << endl;
  // cin >> numero;
  // carro->setTipoCambio(numero);
  //
  // cout << "Informe a quantidade de assentos: " << endl;
  // cin >> numero;
  // carro->setNumeroAssentos(numero);
  //
  // cout << "Dados do carro: " ;
  // cout << carro->getMarca() << " - ";
  // cout << carro->getModelo() << " - ";
  // cout << carro->getPreco() << " - ";
  // cout << carro->getTipoCambio() << " - ";
  // cout << carro->getNumeroAssentos() << endl <<endl;
  //
  // delete carro;
  //
  // //inicializando avião com dados
  // Aviao *aviao;
  // aviao= new Aviao("boing","a320",200000.00,10000, 504);
  //
  // cout << "Dados de avião" << endl;
  // cout << aviao->getMarca() << " - ";
  // cout << aviao->getModelo() << " - ";
  // cout << aviao->getPreco() << " - ";
  // cout << aviao->getTipoCambio() << " - ";
  // cout << aviao->getNumeroAssentos() << endl <<endl;
  //
  // delete aviao;

  //inicaializando varios aviões
  Aviao *vetor_avioes;
  vetor_avioes= new Aviao[3];
  for (int i = 0; i < 3; i++) {
    cout << "Informe a marca do avião: " << endl;
    cin >> texto;
    vetor_avioes[i].setMarca(texto);

    cout << "Informe o modelo: " << endl;
    cin >> texto;
    vetor_avioes[i].setModelo(texto);

    cout << "Informe o preço: " << endl;
    cin >> valor;
    vetor_avioes[i].setPreco(valor);

    cout << "Informe o tipo de cambio: " << endl;
    cin >> numero;
    vetor_avioes[i].setTipoCambio(numero);

    cout << "Informe a quantidade de assentos: " << endl;
    cin >> numero;
    vetor_avioes[i].setNumeroAssentos(numero);
  }
  for (int i = 0; i < 3; i++) {
    cout << "Dados dos aviões" << endl;
    cout << "Avião " << i+1 << endl;
    cout << vetor_avioes[i].getMarca() << " - ";
    cout << vetor_avioes[i].getModelo() << " - ";
    cout << vetor_avioes[i].getPreco() << " - ";
    cout << vetor_avioes[i].getTipoCambio() << " - ";
    cout << vetor_avioes[i].getNumeroAssentos() << endl <<endl;
  }
  delete vetor_avioes;

  return 0;
}
