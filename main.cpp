#include"Chat.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char choice_menu;
	Chat chat;

	do
	{
		choice_menu = mainMenu();
		incorrectInputMenu(choice_menu);
		if (choice_menu == '1')
		{
			auto login = chat.signUp();
			if (login != "error")
			{
				chat.messageWriteRead(login);
			}
		}
		if (choice_menu == '2')
		{
			auto loginIn = chat.entrance();
			if (loginIn != "error")
			{
				chat.messageWriteRead(loginIn);
			}
		}
	} while (choice_menu != '3');

	return 0;
}


