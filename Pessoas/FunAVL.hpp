#include<iostream>
#include<string>
using namespace std;
int conta=10,idades[10];
class Pessoa{
    // Declara��o de atributos
    private:
        string nome;
        int idade, fb;
        int fd, fe;
        Pessoa *FilhoDireito;
        Pessoa *FilhoEsquerdo;
        Pessoa *pai;
    public:
    // Contrutores
        Pessoa(){};
        Pessoa(int idade,string nome){
            this->idade=idade;
            this->nome=nome;
            this->fb = 0;

            FilhoDireito=NULL;
            FilhoEsquerdo=NULL;
            pai=NULL;
        }

    //getter e setters
        string getNome(){
            return nome;
        };
        void setNome(string nome){
            this->nome=nome;
        }
        int getIdade(){
            return idade;
        };
        void setIdade(int idade){
            this->idade = idade;
        }
        Pessoa *getFilhoDireito(){
            return FilhoDireito;
        };
        void setFilhoDireito(Pessoa *FilhoDireito){
            this->FilhoDireito=FilhoDireito;
        }
         Pessoa *getFilhoEsquerdo(){
            return FilhoEsquerdo;
        };
        void setFilhoEsquerdo(Pessoa *FilhoEsquerdo){
            this->FilhoEsquerdo=FilhoEsquerdo;
        }
        Pessoa *getPai(){
            return pai;
        };
        void setPai(Pessoa *pai){
            this->pai=pai;
        };
        // M�todo recursivo de Inser��o com passagem de objeto pessoa
        void Insere(Pessoa *a){
            //Testa se idade � maior para direcionar inser��o
            if(a->idade>this->idade){
                if(this->FilhoDireito!=NULL)
                    this->FilhoDireito->Insere(a); // Passa para pr�ximo n� e chama novamente a fun��o
                else{
                    this->FilhoDireito=a;
                    this->FilhoDireito->pai =this; //Amarra n� ao seu pai
                }
            }
            else{
                if(this->FilhoEsquerdo!=NULL)
                    this->FilhoEsquerdo->Insere(a);
                else{
                    this->FilhoEsquerdo=a;
                    this->FilhoEsquerdo->pai =this;
                }
            }
        };
        //Pr� ordem (raiz - esquerda - direita)
        void listar_pre_ordem(){
            if(this!=NULL){
                cout << " Idade:" << this->idade << "\tFB: " << this->fb << endl;
                if(FilhoEsquerdo!=NULL){
                    FilhoEsquerdo->listar_pre_ordem();
                }
                if(FilhoDireito!=NULL){
                    FilhoDireito->listar_pre_ordem();
                }
            }
            else
                cout<<"VAZIA!"<<endl;
        }
        //ordem (esquerda - raiz - direita)
        void lista_ordem(){
            if(this!=NULL){
                if(this->FilhoEsquerdo!=NULL){
                    this->FilhoEsquerdo->lista_ordem();
                }
                cout <<"\tNome: "<<this->nome<<" Idade:"<<this->idade<<endl;
                if(this->FilhoDireito!=NULL){
                    this->FilhoDireito->lista_ordem();
                }
            }
            else
                cout<<"VAZIA!"<<endl;
        }
        //P�s ordem (raiz - esquerda - direita)
        void lista_pos(){
            if(this!=NULL){
                if(FilhoEsquerdo!=NULL){
                   FilhoEsquerdo->lista_ordem();
                };
                if(FilhoDireito!=NULL){
                   FilhoDireito->lista_ordem();
                };
                cout <<"\tNome: "<<this->nome<<" Idade:"<<this->idade<<endl;
            }
            else
                cout<<"VAZIA!"<<endl;
        };
        //Conta os n�s de forma recursiva no m�todo em p�s ordem
        int quantidade_no(){
            int conta=0;
            if(FilhoEsquerdo!=NULL){
                conta=FilhoEsquerdo->quantidade_no();
            }
            if(FilhoDireito!=NULL){
                conta=conta+FilhoDireito->quantidade_no();
            }
            return conta+1;
        }
        // Soma os valores do campo idade de todos n�s de forma recursiva, p�s ordem
        int soma_idades(){
            int soma = 0;
            if(FilhoEsquerdo!=NULL){
                 soma = FilhoEsquerdo->soma_idades();
            }
            if(FilhoDireito!=NULL){
                soma = soma + FilhoDireito->soma_idades();
            }
            return soma+this->idade;
        }
        //conta profundidade recursivamente para cada lado da �rvore e compara
        int profundidade(){
            int cont_e=0,cont_d=0;
            if(FilhoEsquerdo!=NULL){
                cont_e =FilhoEsquerdo->profundidade()+1;
            }
            if(FilhoDireito!=NULL){
                cont_d = FilhoDireito->profundidade()+1;
            }
            return (cont_e > cont_d) ? cont_e : cont_d;
        }
        //Deleta por p�s ordem toda a �rvore recursivamente
         void RemocaoCompleta() {
            if(FilhoEsquerdo!=NULL){
                FilhoEsquerdo->RemocaoCompleta();
            }
            if(FilhoDireito!=NULL){
                FilhoDireito->RemocaoCompleta();
            }
            cout <<"Deletado-> Nome: "<<this->nome<<" Idade:"<<this->idade<<endl;
            delete this;
        }
        Pessoa *Substituto(){
        	Pessoa *percorre =  this;
        	if(percorre->FilhoEsquerdo!=NULL){
        	    percorre =percorre->FilhoEsquerdo->Substituto();
        	}
        	return percorre;
    	}

        void DeletarNo (int idade,Pessoa *pai, Pessoa **raiz){
            if(this->idade==idade){ //primeiro checa se encontrou
                if(this->FilhoEsquerdo!=NULL && this->FilhoDireito!=NULL){//caso tenha dois filhos
                    if(this->FilhoDireito->FilhoEsquerdo==NULL){//testa se filhodireita tem filho esquerda (candidato substitituto)
                            if(this==(*raiz)){ // Testa se � a raiz pois se for tem que modific�-la atrav�s de sua refer�ncia
                                this->FilhoDireito->FilhoEsquerdo=this->FilhoEsquerdo;
                                (*raiz)=this->FilhoDireito;
                            }
                        else{
                            if(this->pai->idade>this->idade) // Se pai maior que ele vai para esquerda(est� na direita)
                                this->pai->FilhoEsquerdo=this->FilhoDireito;
                            else
                                this->FilhoDireito->FilhoEsquerdo=this->FilhoEsquerdo;
                        }
                        delete this;
                }else{//testa se filhodireita tem filhoesquerda
                    if(this==(*raiz))
                        (*raiz)= this->Substituto();
                    else{
                        if (this->pai->idade > this->idade) //ele � da esquerda
                            this->pai->FilhoEsquerdo= this->Substituto();
                        else
                            this->pai->FilhoDireito=this->Substituto();
                    }
                    // Mudan�a de refer�ncias
                    this->Substituto()->pai->FilhoEsquerdo=this->Substituto()->FilhoDireito;
                    this->Substituto()->FilhoEsquerdo=this->FilhoEsquerdo;
                    this->Substituto()->FilhoDireito=this->FilhoDireito;
                    delete this;
                }
            }else{
                if(this->FilhoEsquerdo!=NULL || this->FilhoDireito!=NULL){//se tem qualquer filho
                    if(this->FilhoDireito!=NULL){//se s� direita
                        if(this==(*raiz))
                            (*raiz)=this->FilhoDireito;
                        else{
                            if(this->pai->idade>this->idade)
                                this->pai->FilhoEsquerdo=this->FilhoDireito;
                            else
                                this->pai->FilhoDireito=this->FilhoDireito;
                        }
                    }
                    else{ //se s� a esquerda
                        if(this==(*raiz)) // Testa se � a raiz
                            (*raiz)=this->FilhoEsquerdo;
                        else{
                            if(this->pai->idade>this->idade)// para testar para onde vai a troca de refer�ncias
                                this->pai->FilhoEsquerdo=this->FilhoEsquerdo;
                            else
                                this->pai->FilhoDireito=this->FilhoEsquerdo;
                        }
                        delete this;
                    }
                }
                else{// Se nao tem filhos
                    if(this==(*raiz))//se for elemento unico/raiz
                        (*raiz)=NULL;
                    else{// se for folha
                        if(this->pai->idade>this->idade)
                            this->pai->FilhoEsquerdo=NULL;
                        else
                            this->pai->FilhoDireito=NULL;
                    }
                    delete this;
                }
            }
        }
        else{
            if(this->FilhoEsquerdo!=NULL && idade<this->idade)
                this->FilhoEsquerdo->DeletarNo(idade,this,raiz);
            if(this->FilhoDireito!=NULL && idade>this->idade)
                this->FilhoDireito->DeletarNo(idade,this,raiz);
        }
    };

        void Mostrar(){
            int x;
            for(x=1;x<=10;x++){
                cout<<idades[x]<<" \n"<<endl;
            }
        }

        void DeleteComBackup(){
            if(FilhoEsquerdo!=NULL){
                FilhoEsquerdo->DeleteComBackup();
            }
            if(FilhoDireito!=NULL){
                FilhoDireito->DeleteComBackup();
            }
            idades[conta]=this->idade;
            conta--;
            delete this;
        }



		//	-----------------------------
		//	FUN��ES DE INCREMENTA��O DA AVL - ARVORE BINARIA BALANCEADA


		void FB(){														// Fator de balanceamento

			int He = 0, Hd = 0;
            if(FilhoEsquerdo != NULL){
				He = FilhoEsquerdo->profundidade()+1;
            }
            if(this->FilhoDireito != NULL){
				Hd = this->FilhoDireito->profundidade()+1;
            }
            this->fb = (Hd - He);
		};

		void AtualizarFB( ){												// Atualizar fator de balanceamento

			this->FB();
			if(FilhoDireito != NULL) {
				FilhoDireito->AtualizarFB( );
			}
			if(FilhoEsquerdo != NULL) {
				FilhoEsquerdo->AtualizarFB( );
			}
		};

		void VerificarFB( ){								// Verifica se a arvore esta desbalanceada

			if(this->fb < -1 || this->fb > 1){
				if(this->fb < -1  && FilhoEsquerdo->fb < 0)						// NEGATIVO		NEGATIVO
					this->RSD( );
				else if(this->fb > 1  && FilhoDireito->fb >= 0)					// POSITIVO 	POSITIVO
					this->RSE( );
				else if(this->fb < -1  && FilhoEsquerdo->fb >= 0){				// NEGATIVO		POSITIVO
					this->FilhoEsquerdo->RDD( );
					this->RSE( );
				}
				else {															// POSITIVO 	NEGATIVO
					this->FilhoDireito->RDE( );
					this->RSD( );
				}
			}
			AtualizarFB( );
		};

		void RSE( ){										// Rota��o Simples a Esquerda  -  POSITIVO 	POSITIVO
			cout << "Rot. Simp. Esq. " << endl;
			Pessoa *P, *Q, *aux;
			P = this;
			Q = P->FilhoDireito;
			aux = Q->FilhoEsquerdo;

			Q->FilhoEsquerdo = P;

			Q->pai = P->pai;

			P->FilhoDireito = aux;

			if(P->pai != NULL){
				if(P->pai->FilhoDireito == P)
					P->pai->FilhoDireito = Q;
				else
					P->pai->FilhoEsquerdo = Q;
			}
			else{
				this->FilhoDireito->FilhoEsquerdo=this->FilhoEsquerdo;
			}
			P->pai = Q;

			if (aux != NULL)
				aux->pai = P;

			P = Q;
		};

		void RSD( ){										// Rota��o Simples a Direita   -  NEGATIVO  NEGATIVO

			Pessoa *P, *Q, *aux;
			P = this;
			Q = P->FilhoEsquerdo;
			aux = Q->FilhoDireito;

			Q->FilhoDireito = P;
			if(P->pai != NULL) {
				Q->pai = P->pai;
				if(P->pai->FilhoDireito == Q)
					P->pai->FilhoDireito = Q;
				else
					P->pai->FilhoEsquerdo = Q;
				P->pai = Q;
			}
			else {

			}

			if (aux != NULL)
				aux->pai = P;
			P->FilhoEsquerdo = aux;
			P = Q;
			cout << "Rot. Simp. Dir. " << endl;

		};

		void RDD( ){														// Rota��o Dupla a Direita     -  NEGATIVO  POSITIVO

			Pessoa *P, *Q, *aux;
			P = this;
			Q = P->FilhoDireito;
			aux = Q->FilhoEsquerdo;
			Q->FilhoEsquerdo = P;
			P->pai->FilhoEsquerdo = Q;
			Q->pai = P->pai;
			P->pai = Q;
			aux->pai = P;
			P->FilhoDireito = aux;
			P = Q;
			cout << "Rot. Dup. Dir. " << endl;

		};

		void RDE( ){														// Rota��o Dupla a Esquerda    -  POSITIVO  NEGATIVO

			Pessoa *P, *Q, *aux;
			P = this;
			Q = P->FilhoEsquerdo;
			aux = Q->FilhoDireito;
			Q->FilhoDireito = P;
			P->pai->FilhoDireito = Q;
			Q->pai = P->pai;
			P->pai = Q;
			aux->pai = P;
			P->FilhoEsquerdo = aux;
			P = Q;
			cout << "Rot. Dup. Esq. " << endl;



		};

};
