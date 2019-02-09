// Author: Polly Sobeck
// Program: cardtest1.c
// Date: 2/9/2019
// This program tests the testplayAdventurer() card function in
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

void testPlayAdventurer() {
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r, currentPlayer, cardDrawn,
        initHandCount, endHandCount,
        initDeckCount, endDeckCount;


    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    currentPlayer = 0;
    initHandCount = G.handCount[currentPlayer];
    initDeckCount = G.deckCount[currentPlayer];
    // printf("%d ", initDeckCount);
    playAdventurer(currentPlayer, &G);

    endHandCount = G.handCount[currentPlayer];
    endDeckCount = G.deckCount[currentPlayer];
    // printf("%d\n", endDeckCount);

    /* Test 1: Assert that the player's hand count increased by 2 (treasure cards) */
    /* All other cards drawn should have been discarded */
    printf("Test 1: %s\n", asserttrue((endHandCount - initHandCount) == 2) ? "true" : "false");

    /* Test 2: Assert that the deck's count has decreased by at least 2 */
    printf("Test 2: %s\n", asserttrue((initDeckCount - endDeckCount) >= 2) ? "true" : "false");

    /* Test 2: Assert that the last drawn card is a treasure card*/
    cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    printf("Test 3: %s\n", asserttrue(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) ? "true" : "false");

}

int main() {
    printf("Testing playAdventurer()...\n");
    testPlayAdventurer();
}
