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
				string ip2=comando.substr(5);
				int acum=0;
				for(int i=0;i<this->pcs.size();i++){
					if(this->pcs[i]->getIP()==ip2){
						acum+=1;
					}
				}
				if(acum==0){
					cout<<"Pinging to "<<ip2<<" with 32 bytes of data: "<<endl;
					cout<<"Request timed out"<<endl;
					cout<<"Request timed out"<<endl;
					cout<<"Request timed out"<<endl;
					cout<<"Request timed out"<<endl;
					cout<<endl;
					cout<<"Ping statistics for "<<ip2<<": "<<endl;
					cout<<"		Packets: Sent = 4, Received = 0, Lost = 4 (100% loss)"<<endl;
					cout<<pcActual->getHostname()<<"#";
					cin>>comando;
				}
				else{
					long n1,n2,n3,n4;
					string ip1Binario="",ip2Binario="",mask1Binario="";
					string ip1=	this->pcs[select]->getIP();
					string mask1=this->pcs[select]->getMaskred();
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
				    //convertidos a binario
				    n1=convertir(stoi(numeros[0]));
				    n2=convertir(stoi(numeros[1]));
				    n3=convertir(stoi(numeros[2]));
				    n4=convertir(stoi(numeros[3]));
				    ip1Binario+=n1;
				    ip1Binario+=n2;
				    ip1Binario+=n3;
				    ip1Binario+=n4;
					numeros.clear();
					//2
					stringstream prueba2(ip2);
					while(getline(prueba2,split,'.')){
				    	numeros.push_back(split);
				    }
				    n1=convertir(stoi(numeros[0]));
				    n2=convertir(stoi(numeros[1]));
				    n3=convertir(stoi(numeros[2]));
				    n4=convertir(stoi(numeros[3]));
				    ip2Binario+=n1;
				    ip2Binario+=n2;
				    ip2Binario+=n3;
				    ip2Binario+=n4;
				    numeros.clear();
				    //3
				    stringstream prueba3(mask1);
					while(getline(prueba3,split,'.')){
				    	numeros.push_back(split);
				    }
				    n1=convertir(stoi(numeros[0]));
				    n2=convertir(stoi(numeros[1]));
				    n3=convertir(stoi(numeros[2]));
				    n4=convertir(stoi(numeros[3]));
				    mask1Binario+=n1;
				    mask1Binario+=n2;
				    mask1Binario+=n3;
				    mask1Binario+=n4;
				    numeros.clear();
				    //4
				int acumD1=0;
				for(int z=0;z<mask1Binario.length();z++){
					char aux=mask1Binario[z];
					if(aux=='1'){
						acum+=1;
					}
				} 
				string temp1=ip1Binario.substr(0,acum);
				string temp2=ip2Binario.substr(0,acum);
				if(temp1==temp2){
					cout<<"Pinging to "<<ip2<<"with 32 bytes of data: "<<endl;
					cout<<"Reply from"<<ip2<<": "<<" bytes=32 time=37ms TTL=446"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" bytes=32 time=37ms TTL=446"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" bytes=32 time=37ms TTL=446"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" bytes=32 time=37ms TTL=446"<<endl;
					cout<<"Ping statistics for "<<ip2<<": "<<endl;
					cout<<"		Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)"<<endl;
					cout<<pcActual->getHostname()<<"#";
					cin>>comando;
				}
				else{
					cout<<"Pinging to "<<ip2<<"with 32 bytes of data: "<<endl;
					cout<<"Reply from"<<ip2<<": "<<" Destination host unreachable"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" Destination host unreachable"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" Destination host unreachable"<<endl;
					cout<<"Reply from"<<ip2<<": "<<" Destination host unreachable"<<endl;
					cout<<"Ping statistics for "<<ip2<<": "<<endl;
					cout<<"		Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)"<<endl;
					cout<<pcActual->getHostname()<<"#";
					cin>>comando;
				}
			} 
				 
				
		}	
	}
}

void Red :: ping(string ip){
		
	 
}

int  Red :: convertir(int octeto){
	
	int decimal=0;
	long binario;
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