/*

Author: Kase Lunt

Date:   6/30/21

Description: This is a simple text-based calendar application. It prompts the user for calendar specifications,
             including number of days, starting day of week, and a name for the calendar. Users can then choose
             to display the entire calendar, add/remove errands (reminders and appointments), as well as save 
             the calendar to a file of user's choice. It will loop through the main menu until the exit option
             is chosen.

*/

#include "lunt_calendar.h"
#include "lunt_reminder.h"
#include "lunt_appointment.h"
#include "lunt_day.h"

int main()
{
    //while static bool continueIntroMenu = true
    while(Calendar::continueIntroMenu)
    {
        //create a new Calendar* and assign it to the output of introMenu()
        Calendar* userCalendar = Calendar::introMenu();

        //if introMenu returned NULL, exit program
        if (userCalendar == NULL)
        {
            return 0;
        }

        //begin the mainMenu for created calendar
        userCalendar->continueMainMenu = true;

        while(userCalendar->continueMainMenu)
        {
            userCalendar->mainMenu();
        }    
    }
    return 0;
}