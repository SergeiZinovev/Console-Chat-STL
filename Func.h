#pragma once
//#include<string>
//#include<iostream>
#include<Windows.h>
#include "sha3.h"

char mainMenu();
char menuMessage();
std::string inputLogin();
std::string inputPass();
std::string inputTo();
std::string massageText();
void incorrectInputMenuMessage();
void incorrectInputMenu(char choice_menu);
void noMessages();

