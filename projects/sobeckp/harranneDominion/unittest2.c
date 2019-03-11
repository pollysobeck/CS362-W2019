// Author: Polly Sobeck
// Program: unittest2.c
// Date: 2/9/2019
// This program tests the isGameOver() function in
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

void testIsGameOver() {
    struct gameState G;
    int numPlayer = 2;
    int seed = 1000;    
    int r;
    int gameOver;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    // test for the following non-ending states
    // state 1
    G.supplyCount[province] = 1;
    for (int i = 0; i < 25; i++) {
        G.supplyCount[i] = 3;
    }
    gameOver = isGameOver(&G);
    printf("Test 1: %s\n", asserttrue(gameOver == 0) ? "true" : "false");

    // state 2
    G.supplyCount[province] = 1;
    for (int i = 0; i < 2; i++) {
        G.supplyCount[i] = 0;
    }
    for (int i = 2; i < 25; i++) {
        G.supplyCount[i] = 3;
    }
    gameOver = isGameOver(&G);
    printf("Test 2: %s\n", asserttrue(gameOver == 0) ? "true" : "false");

    // test for the following ending states
    // state 1
    G.supplyCount[province] = 1;
    for (int i = 0; i < 25; i++) {
        G.supplyCount[i] = 0;
    }
    gameOver = isGameOver(&G);
    printf("Test 3: %s\n", asserttrue(gameOver == 1) ? "true" : "false");

    // state 2
    G.supplyCount[province] = 0;
    for (int i = 0; i < 25; i++) {
        G.supplyCount[i] = 0;
    }
    gameOver = isGameOver(&G);
    printf("Test 4: %s\n", asserttrue(gameOver == 1) ? "true" : "false");
}

int main() {
    printf("Testing isGameOver()...\n");
    testIsGameOver();
}
