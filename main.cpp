/*
- Gets a date from the user
- Checks to see whether the date is valid
- Passes the date into a formula 
- Returns the passcode to the user
*/

#include <iostream>
#include <cmath>
using namespace std;

string getUserInput()
{
    string userInput{};

    // Setup and getting initial user input
    cout << "Passcode Generator" << endl;
    cout << "Please enter a date in the ddmmyyyy format: ";
    cin >> userInput;
    return userInput;
}

bool inputCheck(string userInput)
{
    bool isDateValid{false};

    // User input verification
    while (!isDateValid)
    {
        int day = stoi(userInput.substr(0, 2));
        int month = stoi(userInput.substr(2, 2));
        int year = stoi(userInput.substr(4, 4));

        // Input length check
        if (userInput.size() != 8)
        {
            cout << "Please enter a date in the ddmmyyyy format: ";
            cin >> userInput;
            continue;
        }

        // Day out of range check
        if (day <= 0 || day > 31)
        {
            cout << "Your day must be between 01 and 31. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
            continue;
        }

        // Month out of range check
        if (month <= 0 || month > 12)
        {
            cout << "Your month must be between 01 and 12. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
            continue;
        }

        // Year check
        if (year < 1900)
        {
            cout << "Let's be honest, you're probably not over 120 years old. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
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
    cin >> exitInput;

    return (exitInput == "exit" || exitInput == "Exit" || exitInput == "EXIT") ?  true :  false;
}

int main()
{
    string userInput = getUserInput();
    bool inputVerified{false};
    bool canExit{false};

    // Checks input
    inputVerified = inputCheck(userInput);

    // Calculates passcode
    int passcode = calculatePasscode(userInput);
    cout << "Passcode is " << passcode << endl;

    // Exit check
    while (!canExit)
    {
        canExit = exitCheck();
    }

    return 0;
}