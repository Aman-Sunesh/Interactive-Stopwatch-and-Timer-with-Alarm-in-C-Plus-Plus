#include <iostream>
#include <thread>
#include <chrono>
#include "Utils.h"
#include <windows.h>

using namespace std;

void playAlarm() 
{
    PlaySound(L"Alarm.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    char ch;

    while (true) 
    {
        cout << "\nTimer ended! Enter 'Y' to stop alarm: ";
        cin >> ch;

        if (tolower(ch) == 'y') 
        {
            PlaySound(NULL, NULL, 0);
            cout << "Alarm stopped.\n";
            this_thread::sleep_for(chrono::seconds(3));
            clearScreen();
            return;
        }

        cout << "Invalid input! Please enter 'Y' to stop the alarm.\n";
    }
}


void startTimer(int hrs, int mins, int secs) 
{
    while (hrs > 0 || mins > 0 || secs > 0) 
    {
        clearScreen();
        displayClock(hrs, mins, secs);
        this_thread::sleep_for(chrono::seconds(1));

        secs--;
        if (secs < 0) 
        {
            secs = 59;
            mins--;

            if (mins < 0) 
            {
                mins = 59;
                hrs--;

                if (hrs < 0) 
                {
                    hrs = 0;
                }
            }
        }
    }

    clearScreen();
    displayClock(hrs, mins, secs);
    playAlarm();
}

void handleCase2() 
{
    int hr, min, sec;

    do {
        cout << "Enter hours (0-99): ";
    } while (isInvalidInput(hr) || hr < 0 || hr > 99);

    do {
        cout << "Enter minutes (0-59): ";
    } while (isInvalidInput(min) || min < 0 || min > 59);

    do {
        cout << "Enter seconds (0-59): ";
    } while (isInvalidInput(sec) || sec < 0 || sec > 59);

    startTimer(hr, min, sec);
}
