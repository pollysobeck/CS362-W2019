// Author: Polly Sobeck
// Program: unittest3.c
// Date: 2/9/2019
// This program tests the kingdomCards() function in
// dominion.c.

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdbool.h>

bool asserttrue(bool isTrue) {
    return isTrue;
}

void testKingdomCards() {
    int* k = malloc(10 * sizeof(int));
    k = kingdomCards(estate, province, adventurer, feast, gardens, 
                    village, baron, steward, tribute, sea_hag);

    printf("Test 1: %s\n", asserttrue(k[0] == estate) ? "true" : "false");
    printf("Test 2: %s\n", asserttrue(k[1] == province) ? "true" : "false");
    printf("Test 3: %s\n", asserttrue(k[2] == adventurer) ? "true" : "false");
    printf("Test 4: %s\n", asserttrue(k[3] == feast) ? "true" : "false");
    printf("Test 5: %s\n", asserttrue(k[4] == gardens) ? "true" : "false");
    printf("Test 6: %s\n", asserttrue(k[5] == village) ? "true" : "false");
    printf("Test 7: %s\n", asserttrue(k[6] == baron) ? "true" : "false");
    printf("Test 8: %s\n", asserttrue(k[7] == steward) ? "true" : "false");
    printf("Test 9: %s\n", asserttrue(k[8] == tribute) ? "true" : "false");
    printf("Test 10: %s\n", asserttrue(k[9] == sea_hag) ? "true" : "false");

}

int main() {
    printf("Testing kingdomCards()...\n");
    testKingdomCards();
}
