// Author: Polly Sobeck
// Program: randomtestadventurer.c
// Date: 2/19/2019
// This program runs 1000 random tests for the 
// playAdventurer method in dominion.c. It randomly assigns
// values for currentPlayer, deckCount[currentPlayer], 
// handCount[currentPlayer], and discardCount[currentPlayer]

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

    int k[10] = {adventurer, council_room, feast, gardens, mine, 
            remodel, smithy, village, baron, great_hall};

        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        
        // Get random values for current player, player's deckCount, handCount, and discardCount
        currentPlayer = rand() % numPlayer;
        G.deckCount[currentPlayer] = rand() % 1000;
        G.handCount[currentPlayer] = rand() % 1000;
        G.discardCount[(currentPlayer == 0 ? 0 : 1)] = rand() % 1000;

        initHandCount = G.handCount[currentPlayer];
        initDeckCount = G.deckCount[currentPlayer];

        playAdventurer(currentPlayer, &G);

        endHandCount = G.handCount[currentPlayer];
        endDeckCount = G.deckCount[currentPlayer];

        /* Test 1: Assert that the player's hand count increased by 2 (treasure cards) */
        /* All other cards drawn should have been discarded */
        printf("Test Player's Hand Count: %s\n", asserttrue((endHandCount - initHandCount) == 2) ? "pass" : "fail");

        /* Test 2: Assert that the deck's count has decreased by at least 2 */
        printf("Test Deck Count: %s\n", asserttrue((initDeckCount - endDeckCount) >= 2) ? "pass" : "fail");

        /* Test 2: Assert that the last drawn card is a treasure card*/
        cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        printf("Test Last Drawn Card: %s\n", asserttrue(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) ? "pass" : "fail");

}

int main() {
    printf("Random Tests for playAdventurer()...\n");
    for (int i = 1; i < 1000; i++) {
        printf("Test %d\n", i + 1);
        randomTestPlayAdventurer();
        printf("\n");
    }
}
