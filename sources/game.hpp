#pragma once
#include "player.hpp" // Include Player class header file

namespace ariel {
    class Game {
        // Member variables:
        Player* p1; // Pointer to Player object representing player 1
        Player* p2; // Pointer to Player object representing player 2
        Player* winner; // Pointer to Player object representing the winner of the game
        int drawRate; // Number of cards to draw in the event of a tie
        std::vector<string> log; // Vector of strings representing the game log
        std::vector<Card> stack; // Vector of Card objects representing the game stack

    public:
        // Constructor:
        Game(); // Default constructor, initializes member variables to null or 0

        // Overloaded constructor:
        Game(Player&, Player&); // Initializes p1 and p2 to the passed Player objects

        // Setter function:
        void set(); // Sets up the game by shuffling the decks and dealing the cards

        // Getter function:
        Player* getWinner(); // Returns a pointer to the Player object representing the winner

        // Gameplay functions:
        void playTurn(); // Plays one turn of the game
        void printLastTurn(); // Prints the last turn played
        int playAll(); // Plays the entire game and returns the number of turns played
        void printWiner(); // Prints the name of the winner
        void printLog(); // Prints the game log
        void printStats(); // Prints the game statistics

        // Utility function:
        string War(Card p1_card, Card p2_card, int cards); // Handles a tie by drawing the specified number of cards and returning the result as a string
    };
}
