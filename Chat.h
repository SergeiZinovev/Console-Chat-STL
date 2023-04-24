#pragma once
#include"Message.h"
#include<vector>
#include<map>


class Chat
{
	std::vector <Messages> _chat_message;
	std::vector <Messages> _chat_message_all;
	std::map<std::string, std::string> _data_users;

public:
	Chat();
	~Chat();

	std::string signUp();
	std::string entrance();
	template <typename T> void abonentList(T& login_from);
	bool correctInputAbonent(const std::string& login_to);
	void messageInputAll(const std::string& login_from);
	void messageInputFromTo(const std::string& login_from);
	void messageReadPersonal(const std::string& login_from);
	void messageReadAll();
	void messageWriteRead(const std::string& login_from);
};