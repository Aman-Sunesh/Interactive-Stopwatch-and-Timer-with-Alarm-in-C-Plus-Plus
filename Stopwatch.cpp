#include <iostream>
#include <thread>
#include <chrono>
#include <cctype>
#include <conio.h>
#include "Utils.h"

using namespace std;

void startStopwatch() 
{
    int hrs(0), mins(0), secs(0);
    bool isPaused = false;

    while (true) 
    {
        if (!isPaused) 
        {
            clearScreen();
            displayClock(hrs, mins, secs);
            this_thread::sleep_for(chrono::seconds(1));

            secs++;
            if (secs == 60) 
            {
                mins++;
                secs = 0;

                if (mins == 60) 
                {
                    hrs++;
                    mins = 0;

                    if (hrs == 24) 
                    {
                        hrs = 0;
                        mins = 0;
                        secs = 0;
                    }
                }
            }
        }

        if (_kbhit()) 
        {
            while (true) 
            {
                char ch = _getch();

                if (tolower(ch) == 'p') 
                {
                    isPaused = !isPaused;

                    if (isPaused) 
                    {
                        cout << "\nStopwatch paused. Press 'P' to continue or 'E' to exit.\n";
                    } 

                    else 
                    {
                        cout << "\nStopwatch resumed.\n";
                    }
                    break;

                } 
                
                else if (tolower(ch) == 'e') 
                {
                    cout << "\nExiting stopwatch...\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    clearScreen();
                    return;
                } 
                
                else 
                {
                    cout << "\nInvalid key! Please enter 'P' to pause/resume or 'E' to exit.\n";
                }
            }
        }
    }
}
