/*
- Gets a date from the user
- Checks to see whether the date is valid
- Passes the date into a formula 
- Returns the passcode to the user
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string userInput{};
    bool inputVerified{false};
    int day{};
    int month{};
    int year{};

    // Setup and getting initial user input
    cout << "Passcode Generator" << endl;
    cout << "Please enter a date in the ddmmyyyy format: ";
    cin >> userInput;

    // User input verification
    while (!inputVerified)
    {

        // Input length check
        if (userInput.size() != 8)
        {
            cout << "Please enter a date in the ddmmyyyy format: ";
            cin >> userInput;
            continue;
        }

        int userInputDay = stoi(userInput.substr(0, 2));
        int userInputMonth = stoi(userInput.substr(2, 2));
        int userInputYear = stoi(userInput.substr(4, 4));

        // Day out of range check
        if (userInputDay <= 0 || userInputDay > 31)
        {
            cout << "Your day must be between 01 and 31. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
            continue;
        }

        // Month out of range check
        if (userInputMonth <= 0 || userInputMonth > 12)
        {
            cout << "Your month must be between 01 and 12. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
            continue;
        }

        // Year check
        if (userInputYear < 1900)
        {
            cout << "Let's be honest, you're probably not over 120 years old. Please enter a valid date in the ddmmyyyy format:" << endl;
            cin >> userInput;
            continue;
        }

        inputVerified = true;

        // Passes values to variables in main
        day = userInputDay;
        month = userInputMonth;
        year = userInputYear;

        break;
    }
    
    // Result calculation
    if (inputVerified)
    {
        string exitInput{};

        int result = floor((((day * 7 + month * 11 + year) * day) - 19) / month); 
        cout << "Passcode is " << result << endl;
    }

    bool exit{false};
    string exitInput{};

    // Exit check
    while (!exit)
    {
        cout << "To exit this program, type exit" << endl;
        cin >> exitInput;

        if (exitInput == "exit" || exitInput == "Exit" || exitInput == "EXIT")
        {
            break;
        }

        else
        {
            continue;
        }
    }

    return 0;
}