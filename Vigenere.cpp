#include "Vigenere.h"

int vc::warpAround(int len , int i) { return i % len; }

std::string vc::strToUpper(std::string text)
{
	std::string str = "";
	for (int i = 0; i < text.length(); i++)
	{
		char c = text[i];
		if (std::isalpha(c))
			c = std::toupper(c);
		str.push_back(c);
	}
	return str;
}
std::string vc::encrypt(std::string text, std::string key)
{
	std::string encrypted_text = "";
	std::string upper_text = strToUpper(text);
	key = strToUpper(key);
	for (int i = 0; i < upper_text.length(); i++)
	{
		if (std::isalpha(upper_text[i]))
		{
			int c = (((static_cast<int>(upper_text[i]) + static_cast<int>(key[warpAround(key.length(), i)])) % 26) + 65) % 91;
			encrypted_text.push_back(static_cast<char>(c));
		}
		else
			encrypted_text.push_back(upper_text[i]);
	}
	return encrypted_text;
}
std::string vc::decrypt(std::string encrypted_text, std::string key)
{
	std::string decrypted_text = "";
	std::string upper_text = strToUpper(encrypted_text);
	key = strToUpper(key);
	for (int i = 0; i < upper_text.length(); i++)
	{
		if (std::isalpha(upper_text[i]))
		{
			int c = (((static_cast<int>(upper_text[i]) - static_cast<int>(key[warpAround(key.length(), i)] - 26)) % 26) + 65) % 91;
			decrypted_text.push_back(static_cast<char>(c));
		}
		else
			decrypted_text.push_back(upper_text[i]);
	}
	return decrypted_text;
}

bool vc::isValidKey(std::string key)
{
	bool isValid = true;
	for (int i = 0; i < key.length(); i++)
	{
		if (!isalpha(key[i]))
		{
			isValid = false;
			break;
		}
	}
	return isValid;
}
