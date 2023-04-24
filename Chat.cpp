#include"Chat.h"

HANDLE hConsole;

Chat::Chat() = default;
Chat::~Chat() = default;

std::string Chat::signUp()
{
	std::string login = inputLogin();
	std::string password = inputPass();

	if (_data_users.size())
	{
		auto serch_login = _data_users.find(login);
		if (serch_login != _data_users.end())
		{
			std::cout << "This name/login/password is already registered.\n . Try again. ";
			std::cout << std::endl;
			return "error";
		}
		else
		{
			_data_users.insert({ login, password });
			std::cout << "Congratulations, " << login << ", you are successfully registered. \n";
		}
	}
	else
	{
		_data_users.insert({ login, password });
		std::cout << "Congratulations, " << login << ", the registration was successful. \n";
	}
	return  login;
}

std::string Chat::entrance()
{
	if (!_data_users.empty())
	{
		std::string login = inputLogin();
		std::string password = inputPass();
		auto serch_login = _data_users.find(login);

		if (serch_login != _data_users.end() && password == _data_users[login])
		{
			std::cout << "Login successful" << std::endl;
			return login;
		}
		else
		{
			std::cout << "There is no such login/password" << std::endl;
			return "error";
		}
	}
	else
	{
		std::cout << "Sign up first." << std::endl;
		return "error";
	}
}

template <typename T> void Chat::abonentList(T& login_from)
{
	std::cout << "Subscribers: to everyone   ";

	for (auto& _data_user : _data_users)
	{
		if (login_from != _data_user.first)
		{
			std::cout << _data_user.first << '\t';
		}
	}
}

bool Chat::correctInputAbonent(const std::string& login_to)
{
	auto serch_login_to = _data_users.find(login_to);

	if (serch_login_to != _data_users.end())
		return true;

	return false;
}

void Chat::messageInputAll(const std::string& login_from)
{
	std::string text = massageText();
	_chat_message_all.push_back({ "to everyone", login_from, text });
}

void Chat::messageInputFromTo(const std::string& login_from) {
	std::string text;
	std::string login_to;

	abonentList<const std::string&>(login_from);
	login_to = inputTo();
	if (login_to == "to everyone")
	{
		messageInputAll(login_from);
	}
	else
	{
		if (correctInputAbonent(login_to))
		{
			text = massageText();
			_chat_message.push_back({ login_from, login_to, text });
		}
		else
		{
			incorrectInputMenuMessage();
		}
	}
}

void Chat::messageReadPersonal(const std::string& login_from) {
	auto count = 0;
	if (_chat_message.size())
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << "Private Messages:     " << std::endl;
		for (auto& message : _chat_message)
		{
			SetConsoleTextAttribute(hConsole, 2);
			if (login_from == message.getTo())
			{
				std::cout << "From whom: " << message.getFrom() << "   >>  " << message.getText() << std::endl;
				count++;
			}
		}
		SetConsoleTextAttribute(hConsole, 7);
		if (!count) { noMessages(); }
	}
	else
	{
		noMessages();
	}
}

void Chat::messageReadAll()
{
	if (_chat_message_all.size())
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << "Messages from public chat:     " << std::endl;
		SetConsoleTextAttribute(hConsole, 9);
		for (auto& message_all : _chat_message_all)
		{
			std::cout << "From whom:   " << message_all.getTo() << '\t' << " >>  "
				<< message_all.getText() << std::endl;
		}
		SetConsoleTextAttribute(hConsole, 7);
	}
	else
	{
		std::cout << "No messages from the general chat. " << std::endl;
	}
}

void Chat::messageWriteRead(const std::string& login_from)
{
	char choice;
	do
	{
		choice = menuMessage();
		switch (choice)
		{
		case '1':
			messageReadAll();
			messageReadPersonal(login_from);
			break;

		case '2':
			messageInputFromTo(login_from);
			break;

		case '3':
			system("cls");
			break;
		default:
			incorrectInputMenuMessage();
			break;
		}
	} while (choice != '3');

}

