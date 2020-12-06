/**
 * Main unit testing file.
 * 
 * Please copy the two #includes into any other .cpp file in this folder
 * and the unit testing system will automatically pick up the tests.
 * 
 * The Doctest guide can be found here:
 * https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
 * 
 */

// Do not repeat this header:
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// Every set of unit tests MUST include these two files.
#include "../main.h"
#include "doctest.h"

// Simple test case asserting that constants are set correctly.
TEST_CASE("Ensure constants are correct according to requirements")
{
    // It's a bit silly to test these, but I'd like to ensure that the
    // constants conform to the project requirements.
    CHECK(BLUE_CARDS == 20);
    CHECK(CHILI_CARDS == 18);
    CHECK(STINK_CARDS == 16);
    CHECK(GREEN_CARDS == 14);
    CHECK(SOY_CARDS == 12);
    CHECK(BLACK_CARDS == 10);
    CHECK(RED_CARDS == 8);
    CHECK(GARDEN_CARDS == 6);

    // The deck size should be the sum of the cards above.
    CHECK(DECK_SIZE == 104);
}
