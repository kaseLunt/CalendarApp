#include "lunt_day.h"


//default constructor calls the other constructor and passes in default values 0, Monday
Day::Day()
{
    Day(0, Monday);
}

//constructor which initializes the day with input values
Day::Day(int pDayIndex, int pDayOfWeek)
{
    this->dayIndex = pDayIndex;
    this->dayOfWeek = pDayOfWeek;  
}



/*******************************************************************/
// Add an errand
/*******************************************************************/

void Day::addErrand()
{
    //prompt user for their desired action
    std::cout << "What type of errand?\n" << 
        "1. Reminder\n" <<
        "2. Appointment\n" <<
        "0. Back to main menu\n";
    
    //save their choice
    int choice;
    std::cin >> choice;

    //depending on their choice, create a new errand and push it into errands vector
    if(choice == 1) {
        Reminder* temp = new Reminder();
        temp->setText();
        errands.push_back(temp);
        return;
    } else if(choice == 2) {
        errands.push_back(new Appointment());
        return;
    //return to main menu if 0
    } else if(choice == 0) { 
        return;     
    } else {
        std::cout << "Invalid choice, returning to main menu\n";
        return;
    }
}
/********************************************************************
   Remove an errand
********************************************************************/

void Day::removeErrand()
{
    // Display errands
    std::cout << "Errands:\n";
    for(i = 0; i < (int)errands.size(); i++)
    {
        std::cout << std::to_string(i+1) << ". ";
        std::cout << errands[i]->toString() << std::endl;
    }
    std::cout << "0. Back to main menu\n";

    int choice;
    std::cin >> choice;

    //decrement choice to allign with 0-array.
    choice--;

    //if choice is valid, erase that errand
    if(choice >= 0 && choice < (int)errands.size())
    {
        //save the string text in temp, to print upon successful removal
        std::string temp = errands[choice]->getText();
        //add choice to errands.behin() and erase that index from errands
        errands.erase(errands.begin() + choice);
        //print result
        std::cout << "Errand \"" << temp << "\" deleted.\n";
    }
    return;
}

/********************************************************************
   toString() returns a formatted string
********************************************************************/


std::string Day::toString()
{
    std::string returnString = std::to_string(this->dayIndex + 1) + " - ";
    
    returnString += weekdayToString(this->dayOfWeek);
    returnString += ":\n";

    if(errands.size() == 0)
    {
        returnString += "\tNo Errands\n";
        return returnString;
    }
    for(i = 0; i < (int)errands.size(); i++)
    {
        //first append the index of the errand within errands + 1. (start at 1 instead of 0)
        returnString += "\t" + std::to_string(i+1) + ". ";
        //next call the current errand's toString function and append to returnString
        returnString += errands[i]->toString();
        returnString += "\n";
    }
    return returnString;
}

/********************************************************************
   numErrands() returns the number of errands for that day
********************************************************************/

int Day::numErrands()
{
    return this->errands.size();
}

/*******************************************************************
 Convert weekday enum to string
*******************************************************************/

std::string Day::weekdayToString(int input)
{
    switch(input)
    {
        case 1 : return "Monday"; break;
        case 2 : return "Tuesday"; break;
        case 3 : return "Wednesday"; break;
        case 4 : return "Thursday"; break;
        case 5 : return "Friday"; break;
        case 6 : return "Saturday"; break;
        case 0 : return "Sunday"; break;
        default: return NULL;
    }
}