#include "PC.h"
#include<iostream>
using namespace std;

PC::PC(string ip,string maskRed,string hostname)
{
	this->ip=ip;
	this->maskRed=maskRed;
	this->hostname=hostname;
}

string PC :: getHostname(){
	return this->hostname;
}

string PC :: getMaskred(){
	return this->maskRed;	
}

string PC :: getIP(){
	return this->ip;
}

void PC :: show(){
	
	cout<<"		IP: "<<this->ip<<endl;
	cout<<"		Netmask: "<<this->maskRed<<endl;
	
}

void PC :: ping(string ip){
		
}
