// Author: Polly Sobeck
// Program: cardtest1.c
// Date: 2/9/2019
// This program tests the testPlaySmithy() card function in
// dominion.c. Some of the initial variable declarations 
// were adapted from the example: testUpdateCoins.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"
#include <stdbool.h>

bool asserttrue(bool isTrue) {
    return isTrue;
}

void testPlaySmithy() {
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r, currentPlayer, handPos, 
        initDeckCount, endDeckCount,
        initHandCount, endHandCount;


    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    handPos = 0;
    currentPlayer = 0;

    initDeckCount = G.deckCount[currentPlayer];
    initHandCount = G.handCount[currentPlayer];
    
    smithyEffect( &G, currentPlayer, handPos);
    endDeckCount = G.deckCount[currentPlayer];
    endHandCount = G.handCount[currentPlayer];
    
    /** Test 1: Assert that deck has three fewer cards **/
    printf("Test 1: %s\n", asserttrue(3 == (initDeckCount - endDeckCount)) ? "true" : "false");

    /** Test 2: Assert that hand has two more cards **/
    printf("Test 2: %s\n", asserttrue(2 == (endHandCount - initHandCount)) ? "true" : "false");
}

int main() {
    printf("Testing playSmithy()...\n");
    testPlaySmithy();
}
