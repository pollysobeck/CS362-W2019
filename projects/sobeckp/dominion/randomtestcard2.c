// Author: Polly Sobeck
// Program: randomCardTest2.c
// Date: 2/21/2019
// This test is a random test for the playSmithy method
// in dominion.c. It runs 1000 random test for the function
// and inputs random values for handPos, G.deckCount[currentPlayer],
// G.numActions, and G.handCount[currentPlayer]

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

void randomTestPlayVillage() {
    srand(time(0));
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r, currentPlayer, handPos,
        initHandCount, endHandCount,
        initDeckCount, endDeckCount,
        initNumActions, endNumActions;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    currentPlayer = 0;

    handPos = rand() % 1000;
    G.numActions = rand() % 1000;
    G.deckCount[currentPlayer] = rand() % 1000;
    G.handCount[currentPlayer] = rand() % 1000;

    initHandCount = G.handCount[currentPlayer];
    initDeckCount = G.deckCount[currentPlayer];
    initNumActions = G.numActions;
    playVillage(handPos, currentPlayer, &G);

    endHandCount = G.handCount[currentPlayer];
    endDeckCount = G.deckCount[currentPlayer];
    endNumActions = G.numActions;

    /* Test 1: Assert that the player's hand count has not increased */
    /* All other cards drawn should have been discarded */
    printf("Test 1: %s\n", asserttrue((endHandCount - initHandCount) == 0) ? "pass" : "fail");

    /* Test 2: Assert that the deck's count has decreased by 1 */
    printf("Test 2: %s\n", asserttrue((initDeckCount - endDeckCount) == 1)  ? "pass" : "fail");

    /* Test 3: Assert that the number of actions increased by 2 */
    printf("Test 3: %s\n", asserttrue((endNumActions - initNumActions) == 2)  ? "pass" : "fail");
}

int main() {
    printf("Random Test for playVillage()...\n");
        for (int i = 1; i < 1000; i++) {
        printf("Test %d\n", i + 1);
        randomTestPlayVillage();
        printf("\n");
    }
}