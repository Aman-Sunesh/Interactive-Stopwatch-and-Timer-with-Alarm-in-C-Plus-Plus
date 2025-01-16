#include <iostream>
#include "Stopwatch.h"
#include "Timer.h"
#include "Utils.h"

using namespace std;

void displayMenu();

int main() 
{
    displayMenu();
    return 0;
}

void displayMenu() 
{
    do {
        cout << endl;
        cout << "------------------------------------------\n";
        cout << "|                  Menu                  |\n";
        cout << "| 1. Stopwatch                           |\n";
        cout << "| 2. Timer                               |\n";
        cout << "| 3. Exit                                |\n";
        cout << "------------------------------------------\n";

        int choice;
        do {
            cout << "Enter your choice(1-3): ";

            if (isInvalidInput(choice)) 
            {
                continue;
            }

            if (choice < 1 || choice > 3) 
            {
                cout << "Error! Invalid Choice. Please enter a number between 1 and 3." << endl;
            }

            cout << endl;

        } while (choice < 1 || choice > 3);

        switch (choice) 
        {
            case 1:
                startStopwatch();
                break;
            case 2:
                handleCase2();
                break;
            case 3:
                cout << "Exiting Menu...\n";
                return;
            default:
                cout << "Invalid Input! Please try again.\n";
        }
    } while (true);
}
