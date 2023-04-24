#include"Func.h"

HANDLE gConsole;

char mainMenu()
{
	gConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(gConsole, 14);
	char choice;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << " (1) Sign up" << std::endl;
	std::cout << " (2) Sign in" << std::endl;
	std::cout << " (3) Quit" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	SetConsoleTextAttribute(gConsole, 7);
	std::cout << "Selection -  ";
	std::cin >> choice;
	std::cin.ignore(100, '\n');
	return choice;
}

char menuMessage()
{
	SetConsoleTextAttribute(gConsole, 11);
	std::cout << "******************************" << std::endl;
	std::cout << " *1* Receive a message." << std::endl;
	std::cout << " *2* Send message." << std::endl;
	std::cout << " *3* Sign out of your account." << std::endl;
	std::cout << "******************************" << std::endl;
	SetConsoleTextAttribute(gConsole, 7);
	std::cout << " Selection -  ";
	char choice;
	std::cin >> choice;
	std::cin.ignore(100, '\n');
	return choice;
}

std::string inputLogin()
{
	std::string str;
	std::cout << "Login - ";
	std::cin >> str;
	return str;
}

std::string inputPass()
{
	std::string str;
	std::cout << "Password - ";
	std::cin >> str;
	SHA3 sha3;
	std::string pass_hash = sha3(str);
	return pass_hash;
}

std::string inputTo()
{
	std::string str;
	std::cout << std::endl;
	std::cout << "To whom - ";
	/*std::cin.ignore();*/
	/*std::getline(std::cin, str);*/
	std::cin >> str;
	return str;
}

std::string massageText()
{
	std::string text;
	std::cout << ">> ";
	std::cin.ignore();
	std::getline(std::cin, text);

	return text;
}

void incorrectInputMenuMessage()
{
	std::cout << "Incorrect input. Try again." << std::endl;

}

void incorrectInputMenu(char choice_menu)
{
	if (choice_menu < 49 || choice_menu > 52)
	{
		std::cout << "Incorrect input. Try again." << std::endl;
	}
}

void noMessages()
{
	std::cout << "No private message for you." << std::endl;
}
