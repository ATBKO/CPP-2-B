#pragma once
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {
    class Player{
        string name;                // player's name
        int stackSize;              // number of cards in player's deck
        int cardsTaken;             // number of rounds the player has won
        std::vector<Card> deck;     // player's deck of cards
        int winRate;                // percentage of rounds won by the player
        int drawRate;               // percentage of rounds tied by the player

    public:
        /**
         * Default constructor. Initializes all member variables to zero.
         */
        Player();

        /**
         * Constructor. Initializes the player's name to the given name and all
         * other member variables to zero.
         *
         * @param name - the player's name
         */
        Player(string name);

        /**
         * Returns the player's name.
         *
         * @return the player's name
         */
        std::string getName() const;

        /**
         * Sets the player's name to the given name.
         *
         * @param newName - the new name to set
         */
        void setName(string newName);

        /**
         * Adds a card to the player's deck and increments the deck size.
         *
         * @param c - the card to add
         */
        void addCard(Card card);

        /**
         * Returns the number of cards in the player's deck.
         *
         * @return the number of cards in the player's deck
         */
        int stacksize();

        /**
         * Returns the number of rounds the player has won.
         *
         * @return the number of rounds the player has won
         */
        int cardesTaken() const;

        /**
         * Returns a reference to the player's win rate.
         *
         * @return a reference to the player's win rate
         */
        int& winrate();

        /**
         * Increments the number of rounds the player has won.
         */
        void takeCard();

        /**
         * Returns true if the player's deck is empty, false otherwise.
         *
         * @return true if the player's deck is empty, false otherwise
         */
        bool isEmpty() const;

        /**
         * Removes the top card from the player's deck and returns it.
         *
         * @return the top card from the player's deck
         */
        Card drawCard();

        /**
         * Returns a copy of the player's deck.
         *
         * @return a copy of the player's deck
         */
        std::vector<Card> getDeck();

    };

}
