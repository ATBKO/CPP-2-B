#include <string>
#include "game.hpp"
#include "card.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

namespace ariel {

    // Default constructor
    Game::Game() {};

    // Constructor with two players
    Game::Game(Player &p1, Player &p2) {
        if (!p1.getName().empty() && !p1.getName().empty()) {
            // Assign the pointers to the two players
            this->p1 = &p1;
            this->p2 = &p2;
        }
        // Initialize other variables
        this->drawRate = 0;
        this->set();
        this->winner = nullptr;
    }

    // Set up the deck of cards and distribute them to players
    void Game::set() {
        // Define arrays of card suits and values
        auto suits = std::array<std::string, 4>{"Hearts", "Diamonds", "Clubs", "Spades"};
        auto values = std::array<std::string, 13>{"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

        // Populate the deck with all the possible combinations of suits and values
        auto &stack = this->stack;
        for (const auto &suit: suits) {
            for (const auto &value: values) {
                stack.emplace_back(value, suit);
            }
        }

        // Shuffle the deck randomly
        std::shuffle(stack.begin(), stack.end(), std::default_random_engine(std::random_device()()));

        // Distribute the cards to each player
        for (int i = 0; i < 26; i++) {
            p1->addCard(stack.back());
            stack.pop_back();
            p2->addCard(stack.back());
            stack.pop_back();
        }
    }

    // Get the winner of the game
    Player *Game::getWinner() {
        return this->winner;
    }

// Play a single turn of the game
    void Game::playTurn() {
        if (p1 == p2) {
            throw std::runtime_error("Both players are the same.");
        }
        // Check that both players have cards remaining
        if (p1->stacksize() == 0 || p2->stacksize() == 0) {
            throw std::runtime_error("One of the players has no cards remaining.");
        }

        // Draw a card for each player
        Card p1_card = p1->drawCard();
        Card p2_card = p2->drawCard();

        // Initialize the current winner variable
        string currentWinner = "";

        // Determine which card wins the turn
        if ((p1_card.getValue() == 1 && p2_card.getValue() != 2) || (p1_card.getValue() > p2_card.getValue())) {
            currentWinner = p1->getName();
            p1->winrate()++;
            p1->takeCard();
            p1->takeCard();
        } else if ((p2_card.getValue() == 1 && p1_card.getValue() != 2) || (p1_card.getValue() < p2_card.getValue())) {
            currentWinner = p2->getName();
            p2->winrate()++;
            p2->takeCard();
            p2->takeCard();
        } else {
            // If the cards are equal, initiate a War
            this->drawRate++;
            currentWinner = this->War(p1_card, p2_card, 2);
        }

        this->log.push_back(p1->getName() + " Played " + p1_card.stringValue() + " of " + p1_card.stringSuit()
                            + " " + p2->getName() + " Played " + p2_card.stringValue() + " of " + p2_card.stringSuit()
                            + ". " + currentWinner + " Wins");
    }


    void Game::printLastTurn() {
        // Prints the last turn from the log
        cout << log.back() << endl;
    }

    string Game::War(Card p1_card, Card p2_card, int cards) {
        string currentWinner = "";

        while (p1_card.getValue() == p2_card.getValue()) {
            if (p1->stacksize() < 2 || p2->stacksize() < 2) {
                // One or both players ran out of cards, split the cards on the table and return the winner
                int num_cards = cards / 2;
                p1->takeCards(num_cards);
                p2->takeCards(num_cards);
                throw std::runtime_error("Out of cards during War.");
            }

            // Both players have enough cards to play another turn
            p1_card = p1->drawCard();
            p2_card = p2->drawCard();
            cards += 2;

            if (p1_card.getValue() > p2_card.getValue()) {
                // Player 1 wins the turn, takes all the cards on the table, and increments their win rate
                p1->takeCards(cards);
                currentWinner = p1->getName();
                p1->winrate()++;
            } else if (p1_card.getValue() < p2_card.getValue()) {
                // Player 2 wins the turn, takes all the cards on the table, and increments their win rate
                p2->takeCards(cards);
                currentWinner = p2->getName();
                p2->winrate()++;
            } else {
                // It's still a tie, continue the loop to play another War turn
                this->drawRate++;
                continue;
            }
        }

        return currentWinner;
    }

    int Game::playAll() {
        // Plays the entire game until one of the players runs out of cards
        // Sets the winner to be the player with the most cards at the end
        // Returns 1 to indicate success
        while (p1->stacksize() > 0 && p2->stacksize() > 0) {
            // Play a turn while both players have cards
            this->playTurn();
        }
        // Determine the winner based on who has more cards
        this->winner = (p1->cardesTaken() > p2->cardesTaken()) ? p1 : p2;
        return 1;
    }

    void Game::printWiner() {
        // Prints the name of the winner of the game, or "Tie!" if there was no winner
        if (this->winner) {
            cout << this->winner->getName() << endl;
        } else {
            cout << "Tie!" << endl;
        }
    }

    void Game::printLog() {
        // Loop through the log vector and print each entry to the console
        for (std::vector<std::string>::size_type i = 0; i < log.size(); i++) {
            std::cout << log.at(i) << endl;
        }
    }

    void Game::printStats() {
        // Print player 1's name, win rate, and number of cards won
        cout << "\n" << p1->getName() << ":\n"
             << "Win rate: " << ((double) p1->winrate() / (p1->winrate() + p2->winrate()) * 100) << "%\n"
             << "Cards won: " << p1->cardesTaken()
             << endl;

        // Print player 2's name, win rate, and number of cards won
        cout << "\n" << p2->getName() << ":\n"
             << "Win rate: " << ((double) p2->winrate() / (p1->winrate() + p2->winrate()) * 100) << "%\n"
             << "Cards won: " << p2->cardesTaken()
             << endl;

        // Print the draw rate and number of draws
        cout << "\nDraw rate: " << ((double) this->drawRate / (p1->winrate() + p2->winrate())) * 100 << "%\n"
             << "Amount of draws: " << this->drawRate
             << endl;
    }

} 