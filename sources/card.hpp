#pragma once

#include <string>

namespace ariel {
    class Card {
        std::string value;
        std::string suit;

    public:
        /**
         * @brief Default constructor.
         */
        Card() = default;

        /**
         * @brief Constructor that initializes the card with the given value and suit.
         * @param value The value of the card (e.g. "2", "3", "Ace", etc.).
         * @param suit The suit of the card (e.g. "Spades", "Hearts", "Diamonds", "Clubs").
         */
        Card(std::string value, std::string suit);

        /**
         * @brief Sets the value and suit of the card to the given values.
         * @param value The value of the card (e.g. "2", "3", "Ace", etc.).
         * @param suit The suit of the card (e.g. "Spades", "Hearts", "Diamonds", "Clubs").
         */
        void setCard(const std::string &value, const std::string &suit);

        /**
         * @brief Prints the value and suit of the card to the console.
         */
        void printCard() const;

        /**
         * @brief Returns the numerical value of the card.
         * @return The numerical value of the card, where Ace=1, Jack/King/Queen=10, and other cards have their face value.
         */
        int getValue() const;

        /**
         * @brief Returns the string value of the card.
         * @return The value of the card as a string (e.g. "2", "3", "Ace", etc.).
         */
        std::string stringValue() const;

        /**
         * @brief Returns the string suit of the card.
         * @return The suit of the card as a string (e.g. "Spades", "Hearts", "Diamonds", "Clubs").
         */
        std::string stringSuit() const;
    };
}
