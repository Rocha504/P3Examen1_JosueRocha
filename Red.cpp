#include "Red.h"
#include <iostream>
using namespace std;

Red::Red()
{
}

vector <PC*> Red:: getPcs(){
	return this->pcs;
}

void Red :: agregarPc(PC* pc){
	this->pcs.push_back(pc);
}

void Red :: listar(){
	for(int i=1;i<=this->pcs.size();i++){
		cout<<i<<"-";
		cout<<this->pcs[i]->getHostname();
		cout<<endl;
	}
}
void Red :: ingresar(int select){

	string comando;
	PC* pcActual=this->pcs[select];
	cout<<pcActual->getHostname()<<"#";
	cin>>comando;
	while(comando!="exit"){
		if(comando=="show"){
			this->pcs[select]->show();
			cout<<endl;
			cout<<this->pcs[select]->getHostname()<<"#";
			cin>>comando;
		}	
		else
			if(comando.find("ping") != string::npos){
		    	
				string ip1=	this->pcs[select]->getIP();
				string mask1=this->pcs[select]->getMaskred();
				string ip2=comando.substr(5);
				string mask2;
				for(int i=0;i<this->pcs.size();i++){
					if(this->pcs[i]->getIP()==ip2){
						mask2=this->pcs[i]->getIP();
					}
				}
				
				
					 
			}
		}
}

Red::~Red()
{
	//recorrer vector y eliminar
}