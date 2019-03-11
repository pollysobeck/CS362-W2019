// Author: Polly Sobeck
// Program: unittest1.c
// Date: 2/9/2019
// This program tests the numHandCards() function in
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

void testNumHandCards() {
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r, p, handCount, numCards;
    int maxHandCount = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            numCards = numHandCards(&G);

            //printf("%d ", G.handCount[p]);
            //printf("%d\n", numCards);

            printf("Test: %s\n", asserttrue(G.handCount[p] == numCards) ? "true" : "false");
        }
        endTurn(&G);
    }
}

int main() {
    printf("Testing numHandCards()...\n");
    testNumHandCards();
}
