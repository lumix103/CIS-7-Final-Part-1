#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include "Vigenere.h"

class App
{
public:
	void run();
private:
	void intInput(int& selection);
	void mainMenu();
	//void fileMenu();
	void textMenu();
	void encryptDecryptText(int selection);
	void getKeyInput(std::string& key);
	bool isRunning = false;
};
#endif //APP_H
