
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
	char param[200];
	printf("Enter Param: ");
   	scanf("%s", param);
	//char* param= "IENA1305:MRSWGB01";
	char* checksome = str2crc(param);
	printf("%s",checksome);
}



 
