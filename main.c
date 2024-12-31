#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

// global data
tree_t *treeGame;

// display the user menu
uint8_t displayMenu(void) {
    uint8_t option;

    printf("======= Animal guessing game =======\n"
    "1) Start a new game\n"
    "2) Save the current game\n"
    "3) Load a previous game\n"
    "4) Quit\n");      

    printf("Select an option: ");
    printf("\n>");
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
            // dbg this need to be changed to a state machine with a switch
            treeGame = initTreeLogic();
            printf("[DBG]: root => question => %s\n", treeGame->data->question);
            printf("[DBG]: root => animal => %s\n", treeGame->data->animal);
            printf("[DBG]: root => yes => question => %s\n", treeGame->yes->data->question);
            printf("[DBG]: root => yes => animal => %s\n", treeGame->yes->data->animal);
            printf("[DBG]: root => no => question => %s\n", treeGame->no->data->question);
            printf("[DBG]: root => no => animal => %s\n", treeGame->no->data->animal);
            // missing to release the memory
            free(treeGame->yes->data);
            free(treeGame->yes);
            free(treeGame->no->data);
            free(treeGame->no);
            free(treeGame->data);
            free(treeGame);

            valid = 1;
        } else {
            valid = 0;
        }
    }
    return 0;
}