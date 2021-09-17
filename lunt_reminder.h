#pragma once
#ifndef REMINDER_H
#define REMINDER_H

#include <iostream>
#include <string>

class Reminder
{
	protected:
   		//string to hold reminder text
		std::string text;

	public:
		//constructor
		Reminder();


        //getter and setter
		void virtual setText();
		std::string getText();

        //virtual toString which can be overridden by derived classes
		std::string virtual toString();
	
};

#endif