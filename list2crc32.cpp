#include <iomanip>
#include <iostream>
#include <string>
#include "str2crc32.h"
#include <set> // Compare
#include <fstream> // File Reader
 /*
if compile error : file requires compiler and library support for C++ 2011 standard 
Enabling -std=c++11
*/
using namespace std;  
int main()
{
	string param;
	string checksum;

	set<string> checksums;
	set<string> params;
		
	ifstream infile;
	infile.open ("params.txt");
    if (infile.is_open()){
    	while (!infile.eof()) {
    		infile >> param;
    		cout<<param<<'\n';
    		params.insert(param);  		
    		checksum = str2crc(param);
    		cout << checksum <<'\n';
    		checksums.insert(checksum);
 		}
	}	

	infile.close();	
	
	cout << "Params count : " << params.size() <<'\n';
	cout << "checksums count : " << checksums.size();
  
}
 
 
