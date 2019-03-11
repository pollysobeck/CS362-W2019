// Author: Polly Sobeck
// Program: cardtest3.c
// Date: 2/9/2019
// This program tests the testplayGardens() card function in
// dominion.c. 

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

void testPlayGardens() {
    int gardens;
    gardens = playGardens();

    /* Test 1: Assert that the return value = -1*/
    printf("Test 1: %s\n", asserttrue(gardens == -1) ? "true" : "false");
}

int main() {
    printf("Testing playGardens()...\n");
    testPlayGardens();
}
