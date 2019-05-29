
#include <iostream>
#include <string>
#include "str2crc32.h"
/*
if compile error : file requires compiler and library support for C++ 2011 standard 
Enabling -std=c++11
*/

 
using namespace std;  
int main()
{	
	string param = "hello-world";
	cout <<str2crc(param);
}



 
