#include <string>
#include <iostream>
#include "player.hpp"

using namespace std;

namespace ariel {

    // Default constructor for the Player class
    Player::Player()
            : stackSize(0), cardsTaken(0), winRate(0), drawRate(0) {}

    // Constructor for the Player class with a name argument
    Player::Player(std::string name)
            : name(name), stackSize(0), cardsTaken(0), winRate(0), drawRate(0) {}

    // Returns the name of the player
    std::string Player::getName() const {
        return this->name;
    }

    // Sets the name of the player
    void Player::setName(string newName) {
        if (!newName.empty()) {
            this->name = newName;
        } else {
            std::cout << "Enter valid name" << std::endl;
        }
    }

    // Adds a card to the player's deck
    void Player::addCard(Card card) {
        this->stackSize++;
        deck.push_back(card);
    }

    // Returns the size of the player's deck
    int Player::stacksize() {
        return this->stackSize;
    }

    // Returns the number of cards the player has taken
    int Player::cardesTaken() const {
        return this->cardsTaken;
    }

    // Returns the win rate of the player
    int &Player::winrate() {
        return this->winRate;
    }

    // Increases the number of cards the player has taken by 1
    void Player::takeCard() {
        this->cardsTaken++;
    }

    // Checks if the player's deck is empty
    bool Player::isEmpty() const {
        return stackSize == 0;
    }

    // Draws a card from the player's deck
    Card Player::drawCard() {
        Card result = ((this)->deck.back());
        this->deck.pop_back();
        this->stackSize--;
        return result;
    }

    // Returns the player's deck
    std::vector <Card> Player::getDeck() {
        return this->deck;
    }
}
