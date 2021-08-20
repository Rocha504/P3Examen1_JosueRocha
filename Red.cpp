#include "Red.h"
#include <iostream>
using namespace std;
#include <vector>
#include <sstream> 
#include <math.h> 

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
				int n1,n2,n3,n4;
				string ip1Binario,ip2Binario,mask1Binario,mask2Binario;
				string ip1=	this->pcs[select]->getIP();
				string mask1=this->pcs[select]->getMaskred();
				string ip2=comando.substr(5);
				string mask2;
				
				for(int i=0;i<this->pcs.size();i++){
					if(this->pcs[i]->getIP()==ip2){
						mask2=this->pcs[i]->getMaskred();
					}
				}
				vector <string> numeros;
				string split;
				stringstream prueba(ip1);
				while(getline(prueba,split,'.')){
       				numeros.push_back(split);
    			}
    		    n1=stoi(numeros[0]);
    		    n2=stoi(numeros[1]);
    		    n3=stoi(numeros[2]);
    		    n4=stoi(numeros[3]);
					
			}
	}
}

int convertir(int octeto){
	int decimal=0;
	int binario;
	int i=0;
	while(octeto != 0){
            int aux = octeto%10;
            int res=aux * pow(8,i);
            decimal += res;
            i++;
            octeto/=10;
    }
    i = 1;
    while (decimal != 0){
            int aux = decimal % 2;
            binario += aux * i;
            decimal /= 2;
            i *= 10;
    }
    return binario;
}


Red::~Red()
{
	//recorrer vector y eliminar
}