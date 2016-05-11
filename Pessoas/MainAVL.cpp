#include<iostream>
#include"FunAVL.hpp"
int main(){
    // ponteiro para raiz da �rvore e para novo
    Pessoa *raiz= NULL,*novo=NULL;
    int opcao,valor;
    string texto;
    do{
        cout<< "\n ------- MENU -------"<<endl;
        cout<< "1- Inserir"<<endl;
        cout<< "2- Lista pre ordem"<<endl;
       // cout<< "3- Lista ordem"<<endl;
        //cout<< "4- Lista pos ordem"<<endl;
        //cout<< "5- Numero de nos"<<endl;
        //cout<< "6- Soma de idades"<<endl;
        //cout<< "7- Profundidade"<<endl;
        cout<< "8- Delete completo"<<endl;
        cout<< "9- Deletar no"<<endl;
        //cout<< "10- Deleta com backup"<<endl;
        cout<< "0- Sair"<<endl;
        cin>>opcao;
        switch(opcao){
            case 1:
                //cout<<" Nome : ";
                //cin >> texto;
                cout<<" Idade : ";
                cin >> valor;
                novo = new Pessoa(valor," ");
                if(raiz==NULL)
                    raiz = novo;
                else{
                    raiz->Insere(novo);
                    raiz->VerificarFB();
                }
            break;
            case 2:
                if(raiz == NULL)
                    cout<<"Arvore vazia! "<<endl;
                else {
                    raiz->listar_pre_ordem(); cout<<""<<endl;
                    raiz->AtualizarFB();
                }
            break;
            case 3:
                if(raiz == NULL)
                    cout<<"Arvore vazia! "<<endl;
                else
                    raiz->lista_ordem(); cout<<""<<endl;
                break;
            case 4:
                if(raiz == NULL)
                    cout<<"Arvore vazia! "<<endl;
                else
                    raiz->lista_pos();
            break;
            case 5:
                if(raiz==NULL)
                    cout<<"VAZIA!"<<endl;
                else
                  cout<<" Quantidade de nos: "<<raiz->quantidade_no()<<endl;
            break;
            case 6:
                if(raiz==NULL)
                    cout<<"VAZIA!"<<endl;
                else
                    cout<<" Soma das idades: "<<raiz->soma_idades()<<endl;
            break;
            case 7:
                if(raiz==NULL)
                    cout<<"VAZIA!"<<endl;
                else
                 cout<<" Profundidade: "<<raiz->profundidade()<<endl;
            break;
            case 8:
                if(raiz == NULL)
                    cout<<" Arvore vazia! "<<endl;
                else
                    raiz->RemocaoCompleta();
                    raiz = NULL;
                cout<<" Remocao completa"<<endl;
            break;
            case 9:
	                if(raiz!=NULL){
                    cout<<"Lista:"<<endl;
                    raiz->lista_pos();
                    cout<<"No a ser removido:"<<endl;
                    cin>>valor;
                    raiz->DeletarNo(valor,NULL,&raiz);
                    //para n�o perder refer�ncia da raiz passamos o endere�o da raiz;
                    // Passamos o pai para manipular as refer�ncia
                    cout<<"\nDepois de removido:\n"<<endl;
                    raiz->VerificarFB();
                    raiz->lista_pos();
                }
                else
                    cout<<"�rvore vazia!!"<<endl;
            break;
            case 10:
                if(raiz == NULL)
                    cout<<" Arvore vazia! "<<endl;
                else {
                    // ao inves de passar todo o vetor, passa o endere�o do primeiro e ele consegue acessar todos
                    raiz->DeleteComBackup();
                    raiz=NULL;
                    raiz->Mostrar();
                }
            break;
            default: cout<<" Op��o invalida !"<<endl;
            }
    }while(opcao!=0);


}
