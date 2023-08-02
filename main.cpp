/*
-------------------------------------------------
Program Specification
-------------------------------------------------
- Gets a date from the user
- Checks to see whether the date is valid
- Passes the date into a formula 
- Returns the passcode to the user
-------------------------------------------------
Dates to test inputCheck()
-------------------------------------------------
Input Length
    010820223
Day Out Of Range
    00082023
    32082023
Long Month
    31022023
    31042023
    31062023
    31092023
    31112023
Month Out Of Range
    01002023
    01132023
Leap Year
    29022012 (should pass)
    30022012
    28022023 (should pass)
    29022023
Year
    01081899
-------------------------------------------------
*/

#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string.h>
using namespace std;

string getUserInput()
{
    string userInput{};

    // Get initial user input
    //cin >> userInput;
    getline(cin, userInput);
    return userInput;
}

bool inputCheck(string userInput)
{
    /*
    - Check that every character entered is a digit
    - Check that there are 8 digits Y
    - Check that the day is greater than 0 but less than 31 Y
    - Check that the day is not 31 if the month is not January(01), March(03), May(05), July(07), August(08), October(10), December(12) Y
    - Check that the month is greater than 0 and less than 12
    - If the month is February, check whether the year is a leap year. If yes, check that the day is not more than 29. If no, check that the day is not more than 28 Y
    - Check that the year is after 1900
    */

    bool isDateValid{false};
    int longMonthArray[7] = {1, 3, 5, 7, 8, 10, 12};
    bool longMonth{false};

    // User input verification
    while (!isDateValid)
    {
        bool allDigits{true};

        // Checks whether characters entered are all numbers
        for (int i = 1; i < userInput.size() - 1; i++)
        {
            if (!isdigit(i) || isspace(i))
            {
                allDigits = false;
                break; 
            }
        }

        if (!allDigits)
        {
            cout << "Your date contains characters that aren't numbers." << endl;
            cout << "Please enter a date using the ddmmyyyy format: ";
            //cin >> userInput;
            cin.clear();
            getline(cin, userInput);
            continue;
        }

        int day = stoi(userInput.substr(0, 2));
        int month = stoi(userInput.substr(2, 2));
        int year = stoi(userInput.substr(4, 4));

        // Input length check
        if (userInput.size() != 8)
        {
            cout << "Your date contains more than 8 digits." << endl;
            cout << "Please enter a date using the ddmmyyyy format: ";
            //cin >> userInput;
            cin.clear();
            getline(cin, userInput);
            continue;
        }

        // Day out of range check
        if (day <= 0 || day > 31)
        {
            cout << "Your day must be between 01 and 31." << endl;
            cout << "Please enter a valid date using the ddmmyyyy format: ";
            //cin >> userInput;
            getline(cin, userInput);
            continue;
        }

        // Check for day 31 in the correct month
        if (day == 31)
        {
            for (int i = 0; i < 6; i++)
            {
                if (month == longMonthArray[i])
                {
                    longMonth = true;
                    break;
                }
            }

            if (!longMonth)
            {
                cout << "The month you entered doesn't have 31 days." << endl;
                cout << "Please enter a valid date using the ddmmyyyy format: ";
                //cin >> userInput;
                getline(cin, userInput);
                continue;
            }
        }
        

        // Month out of range check
        if (month <= 0 || month > 12)
        {
            cout << "Your month must be between 01 and 12." << endl;
            cout << "Please enter a valid date using the ddmmyyyy format:";
            //cin >> userInput;
            getline(cin, userInput);
            continue;
        }

        // Leap year check
        if (month == 2)
        {
            // If the year is a leap year
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                if (day <= 29)
                {
                    // Pass
                }
                else
                {
                    cout << "There are only 29 days in this month." << endl;
                    cout << "Please enter a valid date using the ddmmyyyy format: ";
                    //cin >> userInput;
                    getline(cin, userInput);
                    continue;
                }
            }
            else
            {
                if (day <= 28)
                {
                    // Pass
                }
                else
                {
                    cout << "There are only 28 days in this month." << endl;
                    cout << "Please enter a valid date in the ddmmyyyy format: ";
                    //cin >> userInput;
                    getline(cin, userInput);
                    continue;
                }
            }
        }

        // Year check
        if (year < 1900)
        {
            cout << "Please enter a year after 1899." << endl;
            cout << "Please enter a valid date in the ddmmyyyy format: ";
            //cin >> userInput;
            getline(cin, userInput);
            continue;
        }

        isDateValid = true;
    }

    return isDateValid;
}

int calculatePasscode(string userInput)
{
    int day = stoi(userInput.substr(0, 2));
    int month = stoi(userInput.substr(2, 2));
    int year = stoi(userInput.substr(4, 4));

    int result = floor((((day * 7 + month * 11 + year) * day) - 19) / month);
    return result;
}

bool exitCheck()
{
    string exitInput;
    cout << "To exit this program, type exit: ";
    //cin >> exitInput;
    getline(cin, exitInput);

    return (exitInput == "exit" || exitInput == "Exit" || exitInput == "EXIT") ?  true :  false;
}

int main()
{
    bool inputVerified{false};
    bool canExit{false};

    // Greeting and get user input
    cout << "Passcode Generator." << endl;
    cout << "Please enter a date using the ddmmyyyy format: ";
    string userInput = getUserInput();

    // Checks input
    inputVerified = inputCheck(userInput);

    // Calculates passcode
    int passcode = calculatePasscode(userInput);
    cout << "Passcode is " << passcode  << "." << endl;

    // Exit check
    while (!canExit)
    {
        canExit = exitCheck();
    }

    return 0;
}