#include "PC.h"
#include<iostream>
using namespace std;

PC::PC(string IP,string maskRed,string hostname)
{
	this->IP=IP;
	this->maskRed=maskRed;
	this->hostname=hostname;
}

PC::~PC()
{
}