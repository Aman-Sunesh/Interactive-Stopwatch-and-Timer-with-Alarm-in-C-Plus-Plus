#ifndef UTILS_H
#define UTILS_H

void clearScreen();
void displayClock(int hrs, int mins, int secs);
bool kbhit();
char getch();

template <typename T>
bool isInvalidInput(T &input) {
    std::cin >> input;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error! Invalid Input! Please enter a valid input of the expected type." << std::endl;
        std::cout << std::endl;
        return true;  // Invalid input
    }
    return false;  // Valid input
}

#endif
