#ifndef FOO_H_   /* Include guard */
#define FOO_H_

#include <stdio.h>
#include <string.h>


int crc32b( char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0) {
      byte = message[i];            // Get next byte.
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i = i + 1;
   }
   return ~crc;
}

char* fixcrc(const char *s2){
	char *s1 = "0x";
	if (strlen(s2) == 8)  s1= "0x";
	if (strlen(s2) == 7)  s1= "0x0";
	if (strlen(s2) == 6)  s1= "0x00";
	if (strlen(s2) == 5)  s1= "0x000";
	if (strlen(s2) == 4)  s1= "0x0000";
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* str2crc(char* param){

	  char*  checksum;
    int code;
    code = crc32b(param);
    //int to hex to char*
    size_t sz;
    sz = snprintf(NULL, 0,"%04x", code);
    checksum = (char *)malloc(sz + 1); /* make sure you check for != NULL in real code */
    snprintf(checksum, sz+1, "%04x", code);    
	checksum = fixcrc(checksum);
    return checksum;
}



#endif // FOO_H_

