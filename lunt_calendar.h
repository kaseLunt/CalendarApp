#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <string>
#include "lunt_day.h"
#include "lunt_appointment.h"
#include "lunt_reminder.h"
#include <fstream>


class Calendar
{
    public:
        std::string title;
        Day** daysArr;
        int numDays;
        int startingDay;
        static bool continueIntroMenu;
        bool continueMainMenu;
                
        Calendar(std::string title, int numDays, int startingDay);
        Calendar();

        static Calendar* newCal();
        static Calendar* introMenu();
        void mainMenu();

        void displayDay();
        void selectDayRemoveErrand();
        void selectDayErrand();
        
        void printAllDays();
        void saveToFile();

};

#endif