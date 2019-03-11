// Author: Polly Sobeck
// Program: unittest4.c
// Date: 2/9/2019
// This program tests the whoseTurn() function in
// dominion.c. Some of the initial variable declarations 
// were adapted from the example: testUpdateCoins.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdbool.h>

bool asserttrue(bool isTrue) {
    return isTrue;
}

void testWhoseTurn() {
    struct gameState G;
    int numPlayer = 5;
    int seed = 1000;    
    int r, p, currentPlayer = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    // Asserts that as each turn is incremented,
    // whose turn returns the correct players turn
    for (p = 0; p < numPlayer; p++)
    {
            currentPlayer = whoseTurn(&G);
            printf("Test: %s\n", asserttrue(p == currentPlayer) ? "true" : "false");
            G.whoseTurn++;
    }
}

int main() {
    printf("Testing whoseTurn()...\n");
    testWhoseTurn();
}
