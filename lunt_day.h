#pragma once
#ifndef DAY_H
#define DAY_H

#include "lunt_reminder.h"
#include "lunt_appointment.h"
#include <vector>

enum Weekday {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};


class Day 
{
    public:
        //vector of Reminder pointers
        std::vector<Reminder*> errands;

        //dayIndex will hold the day's index within the array of days  
        int dayIndex, i;

        //current will hold each day's day of the week
        int dayOfWeek;

        //constructors
        Day();
        Day(int pDayIndex, int pDayOfWeek);

        //convert Weekday to string
        static std::string weekdayToString(int);

        void addErrand();
        void removeErrand();
        int numErrands();
        std::string toString();



};

#endif
