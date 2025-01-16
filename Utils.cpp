#include <iostream>
#include <iomanip>
#include "Utils.h"

using namespace std;

void clearScreen() 
{
    cout << "\x1B[2J\x1B[H";
}

void displayClock(int hrs, int mins, int secs) 
{
    cout << setfill(' ') << setw(50) << "         TIMER         \n\n";
    cout << setfill(' ') << setw(48) << "HR       MIN      SEC\n";
    cout << setfill(' ') << setw(50) << " --------------------------\n";

    cout << setfill(' ') << setw(23) << "|" << setw(2);
    cout << setfill(' ') << "   ";
    cout << setfill('0') << setw(2) << hrs << "   |   ";
    cout << setw(2) << setfill('0') << mins << "   |   ";
    cout << setw(2) << setfill('0') << secs;
    cout << setfill(' ') << setw(4) << "|" << endl;

    cout << setfill(' ') << setw(50) << " --------------------------\n";
}
