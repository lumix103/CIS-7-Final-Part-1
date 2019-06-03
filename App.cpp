#include "App.h"
void App::run()
{
	isRunning = true;
	while (isRunning)
	{
		mainMenu();
	}
}



void App::intInput(int& selection)
{
	std::cin >> selection;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void App::mainMenu()
{
	int selection = -1;
	std::cout << "Vigenere Cipher" << std::endl;
	std::cout << "Exit: 0" << std::endl;
	//std::cout << "Encrypt/Decrypt Files: 1" << std::endl;
	std::cout << "Encrypt/Decrypt Text: 1" << std::endl;
	
	intInput(selection);
	switch (selection)
	{
	case 0:
		isRunning = false;
		break;
		/*
	case 1:
		fileMenu();
		break;
		*/
	case 1:
		textMenu();
		break;
	default:
		while (true)
		{
			std::cout << "Invalid selection!" << std::endl;
			std::cout << "Enter a valid selection" << std::endl;
			intInput(selection);
			if (selection >= 0 && selection <= 1)
				break;
		}
		break;
	}
	selection = -1;
}
/*
void App::fileMenu()
{
	bool local_running = true;
	while (local_running)
	{
		int selection = -1;
		std::cout << "Vigenere Cipher>>File" << std::endl;
		std::cout << "Return: 0" << std::endl;
		std::cout << "Encrypt File: 1" << std::endl;
		std::cout << "Decrypt File: 2" << std::endl;
		intInput(selection);
		switch (selection)
		{
		case 0:
			local_running = false;
			break;
		case 1:
			//TODO ENCRYPT FILE
			break;
		case 2:
			//TODO DECRYPT FILE
			break;
		default:
			while (true)
			{
				std::cout << "Invalid selection!" << std::endl;
				std::cout << "Enter a valid selection" << std::endl;
				intInput(selection);
				if (selection >= 0 && selection <= 2)
					break;
			}
			break;
		}
		selection = -1;
	}
}
*/
void App::textMenu()
{
	bool local_running = true;
	while (local_running)
	{
		int selection = -1;
		std::cout << "Vigenere Cipher>>Text" << std::endl;
		std::cout << "Return: 0" << std::endl;
		std::cout << "Encrypt Text: 1" << std::endl;
		std::cout << "Decrypt Text: 2" << std::endl;
		intInput(selection);
		switch (selection)
		{
		case 0:
			local_running = false;
			break;
		case 1:
			encryptDecryptText(selection);
			break;
		case 2:
			encryptDecryptText(selection);
			break;
		default:
			while (true)
			{
				std::cout << "Invalid selection!" << std::endl;
				std::cout << "Enter a valid selection" << std::endl;
				intInput(selection);
				if (selection >= 0 && selection <= 2)
					break;
			}
			break;
		}
		selection = -1;
	}
}

void App::encryptDecryptText(int selection)
{
	if (selection == 1)
	{
		//Encrypt
		std::string key;
		std::string input;
		getKeyInput(key);
		std::cout << "Enter your text that will be encrypted: " << std::endl;
		std::getline(std::cin, input);
		std::cout << "Your output: " << vc::encrypt(input, key) << std::endl;
	}
	else if (selection == 2)
	{
		//DECRYPT
		std::string key;
		std::string input;
		getKeyInput(key);
		std::cout << "Enter your text that will be decrypted: " << std::endl;
		std::getline(std::cin, input);
		std::cout << "Your output: " << vc::decrypt(input, key) << std::endl;
	}
}

void App::getKeyInput(std::string& key)
{
	do
	{
		std::cout << "Enter a key(Only alpha characters also includes spaces):" << std::endl;
		std::getline(std::cin, key);

	} while (!vc::isValidKey(key));
}
