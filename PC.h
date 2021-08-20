#ifndef PC_H
#define PC_H
#include<string>
using std::string;
 

class PC
{
	
	
	private:
		
		string ip;
		string maskRed;
		string hostname;
		
	public:
		void show();
		void ping(string);
		string getHostname();
		string getMaskred();
		string getIP();
		PC(string,string,string);
		
	 
};

#endif