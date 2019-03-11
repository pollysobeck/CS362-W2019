// Author: Polly Sobeck
// Program: cardtest1.c
// Date: 2/9/2019
// This program tests the testPlayVillage() card function in
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

void testPlayVillage(numPlayers) {
    struct gameState G;
    int numPlayer = 3;
    int seed = 1000;    
    int r, currentPlayer, handPos,
        initHandCount, endHandCount,
        initDeckCount, endDeckCount,
        initNumActions, endNumActions;


    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    handPos = 0;
    currentPlayer = 0;

    initHandCount = G.handCount[currentPlayer];
    initDeckCount = G.deckCount[currentPlayer];
    initNumActions = G.numActions;
    villageEffect(currentPlayer, &G, handPos);

    endHandCount = G.handCount[currentPlayer];
    endDeckCount = G.deckCount[currentPlayer];
    endNumActions = G.numActions;

    /* Test 1: Assert that the player's hand count has not increased */
    /* All other cards drawn should have been discarded */
    printf("Test 1: %s\n", asserttrue((endHandCount - initHandCount) == 0) ? "true" : "false");

    /* Test 2: Assert that the deck's count has decreased by 1 */
    printf("Test 2: %s\n", asserttrue((initDeckCount - endDeckCount) == 1)  ? "true" : "false");

    /* Test 3: Assert that the number of actions increased by 2 */
    printf("Test 3: %s\n", asserttrue((endNumActions - initNumActions) == 2)  ? "true" : "false");
}

int main() {
    printf("Testing playVillage()...\n");
    testPlayVillage(2);
    testPlayVillage(3);
}
