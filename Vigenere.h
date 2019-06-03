#ifndef  VIGNERE_H
#define VIGNERE_H

#include<string>

namespace vc
{
	//Returns the mod of two numbers
	int warpAround(int, int);
	//Returns a string that is in all caps
	//Will not encrypt non alpha characters
	std::string strToUpper(std::string);
	//Uses Vigenere's cipher in order to encrypt a cipher
	//Will return a string in all caps
	std::string encrypt(std::string, std::string);
	//Decrypts a string with Vigenere's cipher
	//Will return a string in all caps
	std::string decrypt(std::string, std::string);
	
	bool isValidKey(std::string key);
}

#endif //VIGNERE_H

