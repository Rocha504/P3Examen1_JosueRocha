#include <iostream>
#include "PC.h"
#include "Red.h"
#include <vector>
using namespace std;

 
int menu();
int main(int argc, char** argv) {
	Red* network = new Red();
	int op=menu();
	while(op!=3){
		switch(op){
			case 1:{
				string ip, maskRed, hostname;
				cout<<"---AGREGAR PC---"<<endl;
				cout<<"Ingrese la direccion IP de la PC"<<endl;
				cin>>ip;
				cout<<"Ingrese la mascara de red de la PC"<<endl;
				cin>>maskRed;
				cout<<"Ingrese el hostname de la PC"<<endl;
				cin>>hostname;
				PC* pc=new PC(ip,maskRed,hostname);
				network->agregarPc(pc);
			}
			break;
			case 2:{
				int select;
				cout<<"---INGRESAR A PC---"<<endl;
			 	network->listar();
			 	cout<<"Ingrese el numero de la PC a la que desea ingresar"<<endl;
			 	cin>>select;
			 	cout<<endl;
					
			}
			break;
		}
	}
	 
	
	return 0;
}
int menu(){
	
	int op;
	cout<<"Bienvenido"<<endl;
	cout<<"1-agregar PC"<<endl;
	cout<<"2-ingresar a PC"<<endl;
	cout<<"3-Salir"<<endl;
	cout<<"Ingrese una opcion"<<endl;
	cin>>op;
	
	return op;
}