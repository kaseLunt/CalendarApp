#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "lunt_reminder.h"
#include <iostream>
#include <string>

class Appointment : public Reminder
{
    int startHour, startMin, endHour, endMin;

    public:

        //constructor
        Appointment();

        //setters
        void setText();
        void setStartHour();
        void setStartMin();
        void setEndHour();
        void setEndMin();

        //setTime aggregates and calls the above 4 methods
        void setTime();

        //getters
        int getStartHour();
        int getStartMin();
        int getEndHour();
        int getEndMin();

        //override toString to work with Appointments correctly
        std::string toString();
        
};

#endif