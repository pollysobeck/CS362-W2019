// Author: Polly Sobeck
// Program: randomtestadventurer.c
// Date: 2/19/2019
// 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"
#include <stdbool.h>
#include <time.h> 

bool asserttrue(bool isTrue) {
    return isTrue;
}

void randomTestPlayAdventurer() {
    srand(time(0)); 
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r, currentPlayer, cardDrawn,
        initHandCount, endHandCount,
        initDeckCount, endDeckCount;

    for (int i = 0; i < 1000; i++) {

        int cards[16] = {adventurer, council_room, feast, gardens, mine, 
               remodel, smithy, village, baron, great_hall, gardens, 
              embargo, minion, cutpurse, sea_hag, tribute };
        int k[10];

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

        printf("Test %d\n", i);

        /* Test 1: Assert that the player's hand count increased by 2 (treasure cards) */
        /* All other cards drawn should have been discarded */
        printf("Test Player's Hand Count: %s\n", asserttrue((endHandCount - initHandCount) == 2) ? "pass" : "fail");

        /* Test 2: Assert that the deck's count has decreased by at least 2 */
        printf("Test Deck Count: %s\n", asserttrue((initDeckCount - endDeckCount) >= 2) ? "pass" : "fail");

        /* Test 2: Assert that the last drawn card is a treasure card*/
        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        printf("Test Last Drawn Card: %s\n", asserttrue(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) ? "pass" : "fail");

        printf("\n");
    }
}

int main() {
    printf("Random Test for playAdventurer()...\n");
    randomTestPlayAdventurer();
}
