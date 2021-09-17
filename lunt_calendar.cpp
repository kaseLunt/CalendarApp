#include "lunt_calendar.h"

/********************************************************************
   constructor
********************************************************************/

Calendar::Calendar(std::string pTitle, int pNumDays, int pStartingDay)
{
    this->title = pTitle;
    this->numDays = pNumDays;
    this->startingDay = pStartingDay;

    this->daysArr = new Day*[pNumDays];

    //iterate through array of day* and initialize them to new day objects
    for(int i = 0; i < pNumDays; i++)
    {
        //add startingDay to i. That sum mod 7 is casted as a Weekday and passed to day's constructor
        daysArr[i] = new Day(i, ((i + pStartingDay)%7));
    }
    std::cout << "\nYour calendar has been created.\n";
}

//static bool
bool Calendar::continueIntroMenu = true;

/********************************************************************
   default constructor
********************************************************************/

Calendar::Calendar()
{
    this->title = "Calendar";
    this->numDays = 30;
    this->startingDay = Tuesday;
    
    this -> daysArr = new Day*[30];

    //iterate through array of day* and initialize them to new day objects
    for(int i = 0; i < this->numDays; i++)
    {
        //add startingDay to i. That sum mod 7 is casted as a Weekday and passed to day's constructor
        daysArr[i] = new Day(i, ((i + startingDay)%7));
    }
}

/*********************************************************************************
   printAllDays() - print the calendar summary
*********************************************************************************/

void Calendar::printAllDays()
{
    std::cout << "Calendar \"" << this->title << "\":" << std::endl;
 
    for(int i = 0; i < this->numDays; i++)
    {
        //print index and day of week
        std::cout << daysArr[i]->dayIndex + 1 << " - ";
        std::cout << Day::weekdayToString(daysArr[i]->dayOfWeek) << ": ";
        
        //print number of errands
        if(daysArr[i]->numErrands() < 1)
        {
            std::cout << "No Errands\n";
        } else {
            std::cout << daysArr[i]->numErrands() << " Errands\n";
        }
    
    }
    std::cout << std::endl;
}

/********************************************************************
   introMenu() - display intro options
********************************************************************/

Calendar* Calendar::introMenu()
{
    char input = '\0';
   
    while(input != '1' && input != '2' && input != '0')
    {
        std::cout << "\nWelcome to CSE240 Calendar\n\n";
        std::cout << "1. Build a new Calendar\n";
        std::cout << "2. Exit\n";
        std::cin >> input;
    }
    if(input == '2' || input == '0')
    {
        continueIntroMenu = false;
        return NULL;
    } 
    else if(input == '1')
    {
        continueIntroMenu = false;
        //else call newCal to prompt user for Calendar specifications, return the Calendar* 
        return newCal();
    }
    else
    {
        std::cout << "invalid input." << std::endl;
        return NULL;
    }
}

/********************************************************************
   newCal() - prompt user for new calendar specs, feed them into constructor,
              and return the new calendar
********************************************************************/

Calendar* Calendar::newCal()
{
    int numDays, startDay;
    std::string title;


    std::cout << "Building a new calendar.\nGive your calendar a title: \n";
    std::getline(std::cin, title); std::getline(std::cin, title);
    
    // Prompt for numDays
    bool reprompt = false;

    do {
        std::cout << "How many days should this calendar have?\n";
        std::cin >> numDays;
        if(numDays < 1 || numDays > 366) { reprompt = true; }
    } while (reprompt);
    
    // Prompt for startDay
    std::cout << "What day does your calendar start on?\n" <<
    "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday\nSelection >>";
    std::cin >> startDay;

    // Create calendar on the heap, pass user values into constructor, return it
    return new Calendar(title, numDays, startDay);
}

/********************************************************************
   mainMenu() gives user access to calendar methods
********************************************************************/


void Calendar::mainMenu()
{
    int choice;
    continueMainMenu = true;
    std::cout << std::endl << "What would you like to do?\n" <<
        "1. Display whole calendar\n" <<
        "2. Display a single day\n" <<
        "3. Add an errand\n" <<
        "4. Delete an errand\n" <<
        "5. Save to a file\n" <<
        "0. Exit\n" <<
        "Selection >> ";
    std::cin >> choice;
    std::cout << std::endl;

    switch(choice)
    {
        case 1 : this->printAllDays(); break;
        case 2 : this->displayDay(); break;
        case 3 : this->selectDayErrand(); break;
        case 4 : this->selectDayRemoveErrand(); break;
        case 5 : this->saveToFile(); break;
        case 0 : continueMainMenu = false;
    }
    return;
}

/********************************************************************
   displayDay() - let user choose a day to display
********************************************************************/


void Calendar::displayDay()
{
    int dayChoice = -1;
    this->printAllDays();
   
    //check for valid input
    while(dayChoice < 0 || dayChoice > numDays)
    { 
        std::cout << "Select which day to display: " <<
        "Day (1 - " << this->numDays << ") (0 - Back to main menu)\n>> ";
        std::cin >> dayChoice;
    }
    //call the toString function of the chosen day, print to cout
    std::cout << this->daysArr[dayChoice - 1]->toString();

}

/********************************************************************
   selectDayErrand() - allow user to choose day to add an errand to
********************************************************************/


void Calendar::selectDayErrand()
{
    int dayChoice = -1;
    this->printAllDays();
   
    while(dayChoice < 0 || dayChoice > numDays)
    { 
        std::cout << "Select which day to add an errand to: \n" <<
        "Day (1 - " << this->numDays << ")\n>> ";
        std::cin >> dayChoice;
    }    
    this->daysArr[dayChoice - 1]->addErrand();
}

/*****************************************************************************
   selectDayRemoveErrand() - allow user to choose day to remove an errand from
*****************************************************************************/

void Calendar::selectDayRemoveErrand()
{
     int dayChoice = -1;
    this->printAllDays();
   
    while(dayChoice < 0 || dayChoice > numDays)
    { 
        std::cout << "Select which day to remove an errand from: \n" <<
        "Day (1 - " << this->numDays << ")\n>> ";
        std::cin >> dayChoice;
    }
    //make sure there are errands to remove
    if(this->daysArr[dayChoice - 1]->errands.size() > 0)
    {
        //call the removeErrand function of the chosen day
        this->daysArr[dayChoice - 1]->removeErrand();
        return;
    } else {
        std::cout << "That day doesn't have any errands to remove.";
        return;
    }
    
}

/********************************************************************
   saveToFile()
********************************************************************/

void Calendar::saveToFile()
{
    //get a file name from the user, store in fileName
    std::string fileName;
    std::cout << "Save Calendar to File\n" << "Please enter the filename to store to\n>> ";
    std::cin >> fileName;

    //open the file, check for success
    std::ofstream file(fileName.c_str(), std::ios::app);
    if(!file.is_open())
    {
        std::cout << "Error in opening file";
        return;
    }

    //begin printing to file
    file << "Calendar \"" << this->title << "\":" << std::endl << "---------------------\n";
 
    for(int i = 0; i < this->numDays; i++)
    {
        //print index (starting at 1)
        file << daysArr[i]->dayIndex + 1 << " - ";
        //print the weekday
        file << Day::weekdayToString(daysArr[i]->dayOfWeek) << ": ";
        //print number of errands for that day
        if(daysArr[i]->numErrands() < 1)
        {
            file << "No Errands\n";    
        } else { 
            file << daysArr[i]->numErrands() << " Errand(s)\n";
            //loop through that day's errands array, calling each errand's toString() method
            for(int j = 0; j < (int)daysArr[i]->errands.size(); j++)
            {
                file << "\t" << daysArr[i]->errands[j]->toString() << "\n";
            }

        }
        file << "\n";
    }
    std::cout << std::endl << "Successfully wrote calendar to " << fileName << std::endl;
    
}