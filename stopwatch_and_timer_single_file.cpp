#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cctype>
#include <conio.h>

#define NOMINMAX // Prevent windows.h from defining min and max
#include <windows.h>
#pragma comment(lib, "winmm.lib") // Link the winmm.lib for PlaySound

using namespace std;

void displayClock(int hrs, int mins, int secs);
void startStopwatch();
void startTimer(int hrs, int mins, int secs);
void displayMenu();
void playAlarm();

static inline void clearScreen() {
    // ANSI escape code to clear screen
    cout << "\x1B[2J\x1B[H";
}

// General template for non-string types
template <typename T>
inline bool isInvalidInput(T& input)
{
    cin >> input;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error! Invalid Input! Please enter a valid input of the expected type." << endl;
        cout << endl;

        return true; // Invalid input
    }
    return false; // Valid input
}

// Input handling for timer setup
static void handleCase2() {
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

    // Start the timer with validated input
    startTimer(hr, min, sec);
}


int main()
{
    displayMenu();
}

void displayMenu()
{
    do
    {
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
        {
            startStopwatch();
            break;
        }

        case 2:
        {
            handleCase2();
            break;
        }

        case 3:
        {
            cout << "Exiting Menu...\n";
            return;
        }

        default:
        {
            cout << "Invalid Input! Please try again.\n";
        }
        }
    } while (true);
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


void startStopwatch()
{
    int hrs(0), mins(0), secs(0);
    bool isPaused = false; 

    while (true) 
    {
        // Check if not paused
        if (!isPaused) 
        {
            clearScreen();
            displayClock(hrs, mins, secs);
            this_thread::sleep_for(chrono::seconds(1));

            secs++;

            if (secs == 60) {
                mins++;
                secs = 0;

                if (mins == 60) {
                    hrs++;
                    mins = 0;

                    if (hrs == 24) {
                        hrs = 0;
                        mins = 0;
                        secs = 0;
                    }
                }
            }
        }

        // Handle user input for pause and resume
        if (_kbhit()) 
        { 
            while (true) 
            { 
                char ch = _getch(); // Read the key

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

                else if (tolower(ch) == 'e')  // Exit the stopwatch
                { 
                    cout << "\nExiting stopwatch...\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    clearScreen();
                    return;
                }
                else  // Invalid key press
                { 
                    cout << "\nInvalid key! Please enter 'P' to pause/resume or 'E' to exit.\n";
                }
            }
        }
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

void playAlarm() {
    // Play the .wav file in a loop
    PlaySound(L"Alarm.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


    // Prompt the user to stop the alarm
    char ch;
    while (true) {
        cout << "\nTimer ended! Enter 'Y' to stop alarm: ";
        cin >> ch;

        if (tolower(ch) == 'y') {
            PlaySound(NULL, NULL, 0); // Stop the sound
            cout << "Alarm stopped.\n";
            this_thread::sleep_for(chrono::seconds(3));
            clearScreen();
            return;
        }

        cout << "Invalid input! Please enter 'Y' to stop the alarm.\n";
    }
}
