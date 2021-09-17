#include "lunt_reminder.h"

// Reminder's method implementations
/************************************************************************/

Reminder::Reminder()
{
	
}

void Reminder::setText()
{
	//prompt for reminder text and save
	std::cout << "Enter reminder text: ";

	//call getline once to clear the buffer of the \n character, again to get input from user
	std::getline(std::cin, this->text); std::getline(std::cin, this->text);
}

std::string Reminder::getText()
{
	//return the reminder text
	return this->text;
}		

std::string Reminder::toString()
{
	return "Reminder: " + this->text;
}
