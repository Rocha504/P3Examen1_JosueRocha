#ifndef PC_H
#define PC_H
#include<string>
using std::string;

class PC
{
	
	
	private:
		
		string IP;
		string maskRed;
		string hostname;
		
	public:
		
		PC(string,string,string);
		~PC();
	 
};

#endif