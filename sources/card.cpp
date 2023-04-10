#include <string>
#include <iostream>
#include "card.hpp"

namespace ariel {

    // Use initializer list to set values instead of checking and setting individually
    Card::Card(std::string value, std::string suit)
            : value(value), suit(suit) {}

    // Use const member function to indicate non-modifying behavior
    void Card::printCard() const {
        std::cout << "[" << this->value << ", " << this->suit << "]" << std::endl;
    }

    // Use const member function to indicate non-modifying behavior
    int Card::getValue() const {
        static const std::string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen",
                                             "King"};
        auto it = std::find(std::begin(values), std::end(values), value);
        if (it == std::end(values)) {
            throw std::invalid_argument("Invalid card value");
        }
        int index = std::distance(std::begin(values), it);
        if (index < 0 || index > 12) {
            throw std::out_of_range("Card value out of range");
        }
        return index + 1;
    }

    // Use reference parameters to avoid unnecessary copying
    void Card::setCard(const std::string &value, const std::string &suit) {
        this->value = value;
        this->suit = suit;
    }

    std::string Card::stringValue() const {
        return this->value;
    }

    std::string Card::stringSuit() const {
        return this->suit;
    }
}
