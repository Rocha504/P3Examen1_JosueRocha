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

Red::~Red()
{
	//recorrer vector y eliminar
}