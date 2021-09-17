#include "lunt_appointment.h"



// Appointment's method implementations
/************************************************************************/

Appointment::Appointment()
{
    this->setTime();
	this->setText();
}
void Appointment::setStartHour()
{
	bool valid = false;
	int input;

	// check for valid input, reprompt until valid
	while(!valid)
	{
		std::cout << "Enter start time hour (24-hour clock): ";
		std::cin >> input;
		if(input >= 0 && input <= 24) valid = true;
	}
	// set startHour
	this->startHour = input;	
}

void Appointment::setStartMin()
{
	bool valid = false;
	int input;
	
	// check for valid input, reprompt until valid
	while(!valid)
	{
		std::cout << "Enter start time minute: ";
		std::cin >> input;
		if(input >= 0 && input < 60) valid = true;
	}
	// set startMin
	this->startMin = input;	
}

void Appointment::setEndHour()
{
	bool valid = false;
	int input;

	// check for valid input, reprompt until valid
	while(!valid)
	{
		std::cout << "Enter end time hour (24-hour clock): ";
		std::cin >> input;
		if(input >= 0 && input <= 24) valid = true;
	}
	// set endHour
	this->endHour = input;	
}

void Appointment::setEndMin()
{
	bool valid = false;
	int input;
	
	// check for valid input, reprompt until valid
	while(!valid)
	{
		std::cout << "Enter end time minute: ";
		std::cin >> input;
		if(input >= 0 && input < 60) valid = true;
	}

	// set endMin
	this->endMin = input;	
}

void Appointment::setText()
{
	//prompt for reminder text and save
	std::cout << "Enter appointment name: ";

	//call getline once to clear the buffer of the \n character, again to get input from user
	std::getline(std::cin, this->text); std::getline(std::cin, this->text);
}

void Appointment::setTime()
{
    this->setStartHour();
    this->setStartMin();
    this->setEndHour();
    this->setEndMin();
}

int Appointment::getStartHour()
{
	return this->startHour;
}

int Appointment::getStartMin()
{
	return this->startMin;
}

int Appointment::getEndHour()
{
	return this->endHour;
}

int Appointment::getEndMin()
{
	return this->endMin;
}

std::string Appointment::toString()
{
    //construct a string by calling getter functions
    std::string rString = "Appointment - ";
	if(this->startHour < 10) { rString += "0"; } 
    rString += std::to_string(this->getStartHour()) + ":";
	if(this->startMin < 10) { rString += "0"; }
    rString += std::to_string(this->getStartMin()) + " - ";
	if(this->endHour < 10) { rString += "0"; } 
    rString += std::to_string(this->getEndHour()) + ":";
	if(this->endMin < 10) { rString += "0"; } 
    rString += std::to_string(this->getEndMin()) + " - " +
        this->getText();

    return rString;   
}
