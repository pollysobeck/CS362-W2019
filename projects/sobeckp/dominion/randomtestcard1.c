// Author: Polly Sobeck
// Program: randomcardtest1.c
// Date: 2/21/2019
// This test is a random test for the playSmithy method
// in dominion.c. It runs 1000 random test for the function
// and inputs random values for handPos, currentPlayer,
// G.deckCount[currentPlayer], and G.handCount[currentPlayer]

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

void randomTestPlaySmithy() {
    srand(time(0)); 
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

    handPos = rand() % 1000;
    currentPlayer = rand() % numPlayer;
    G.deckCount[currentPlayer] = rand() % 1000;
    G.handCount[currentPlayer] = rand() % 1000;

    initDeckCount = G.deckCount[currentPlayer];
    initHandCount = G.handCount[currentPlayer];

    playSmithy(handPos, currentPlayer, &G);
    endDeckCount = G.deckCount[currentPlayer];
    endHandCount = G.handCount[currentPlayer];

    /** Test 1: Assert that deck has three fewer cards **/
    printf("Test 1: %s\n", asserttrue(3 == (initDeckCount - endDeckCount)) ? "pass" : "fail");

    /** Test 2: Assert that hand has two more cards **/
    printf("Test 2: %s\n", asserttrue(2 == (endHandCount - initHandCount)) ? "pass" : "fail");
}

int main() {
    printf("Random Tests for playSmithy()...\n");
    for (int i = 1; i < 1000; i++) {
        printf("Test %d\n", i + 1);
        randomTestPlaySmithy();
        printf("\n");
    }
}