#ifndef RED_H
#define RED_H
#include "PC.h"
#include <vector>
using namespace std;

class Red
{
	
	private:
		vector <PC*> pcs;
	public:
		Red();
		int convertir(int);
		void ping(string);
		void ingresar(int);
		void agregarPc(PC*);
		void listar();
		vector <PC*> getPcs();
		~Red();
	 
};

#endif