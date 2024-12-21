#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

// display the user menu
uint8_t displayMenu(void) {
    uint8_t option;

    printf("======= Animal guessing game =======\n"
    "1) Start a new game\n"
    "2) Save the current game\n"
    "3) Load a previous game\n"
    "4) Quit\n");      

    printf("Select an option: ");
    scanf("%c", &option);
    return option;
}

// ensure that the input is correct
uint8_t isInRange(uint8_t userInput) {
    uint8_t numInput;
    getchar(); // consume newline char '\n'
    if (isdigit((char)userInput) > 0) {
        numInput = userInput - '0';
        if ((numInput >= 1) && (numInput <= 4)) {
            return 1;
        } else {
            printf("The option choose is not the menu, try again\n");
            return 0;
        }
    } else {
        printf("The input is not a valid digit, i.e: 1, 2, ... 4\n");
        return 0;
    }
}

int main() {
    uint8_t currOption;
    uint8_t valid = 0;

    while (valid != 1) {
        currOption = displayMenu();
        if (isInRange(currOption)) {
            valid = 1;
        } else {
            valid = 0;
        }
    }
    return 0;
}