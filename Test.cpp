//
// Created by koazg on 23/03/2023.
//

#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"

using namespace std;
using namespace ariel;

// Test case for game initialization
TEST_CASE("Test Init-Game")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.getName() == "Alice");
    CHECK(p2.getName() == "Bob");
    CHECK_THROWS(Player(""));
    CHECK_NOTHROW(Game game(p1, p2));

}

// Test case for the start of the game
TEST_CASE("Test Start-Game")
{
    Player p1("Alex");
    Player p2("Ben");
    Game game(p1, p2);

    // Check same player
    CHECK_THROWS(Game(p1,p1));

    // Check print last turn without any turns at all
    CHECK_THROWS(game.printLastTurn());

    // Check that each player has 26 cards at the start of the game
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

    // Check that no cards have been taken yet and that the total number of cards is 52
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() + p2.stacksize() == 52);

    // Check that game statistics and log can be printed without errors
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
}

// Test case for playing cards
TEST_CASE("Test Mid-Game")
{
    Player p1("Amir");
    Player p2("Berry");
    Game game(p1, p2);

    // Check that each player has 26 cards at the start of the game
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

    // Play one turn and check that each player now has 25 cards
    game.playTurn();
    CHECK(p1.stacksize() == 25);
    CHECK(p2.stacksize() == 25);

    // Play 5 more turns and check that each player has 21 cards and 10 cards have been taken
    for (int i = 0; i < 5; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
    CHECK(p1.stacksize() == 21);
    CHECK(p2.stacksize() == 21);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 10);

    // Check that the total number of cards is still 52
    CHECK(p1.cardesTaken() + p2.cardesTaken() + p1.stacksize() + p2.stacksize() == 52);

    // Check that game statistics and log can be printed without errors
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
}

// Test case for the end of the game
TEST_CASE("Test End-Game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Play 5 turns and then play all the remaining cards
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    // Play all turns
    CHECK_NOTHROW(game.playAll());

    // Create one more game
    CHECK_NOTHROW(Game(p1,p2));


    // Check that each player has 0 cards and that all 52 cards have been taken
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);


    // Check that the total number of cards is still 52
    CHECK(p1.cardesTaken() + p2.cardesTaken() + p1.stacksize() + p2.stacksize() == 52);

    // Check that game statistics, winner, print last turn and log can be printed without errors
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLastTurn());
}

