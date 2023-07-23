#pragma once
#include <algorithm>
#include <array>
#include <format>
#include <stdexcept>
#include <string>
#include "Card.hpp"

template<unsigned Size>
class Deck {
public:
    static constexpr unsigned DECK_SIZE{ Size };

protected:
    std::array<Card, Size> cards{};

    virtual std::string badNumberOfCardsErrorMessage(unsigned nGivenCards) {
        return std::format("Generic Deck initialized with {} cards ({} expected) !", nGivenCards, DECK_SIZE);
    }

public:
    Deck(std::initializer_list<Card> cards) {
        const auto nGivenCards{ cards.size() };

        if (nGivenCards != DECK_SIZE) {
            throw std::out_of_range(badNumberOfCardsErrorMessage(nGivenCards));
        }
        std::copy(cards.begin(), cards.end(), this->cards.begin());
    }

    virtual ~Deck() = 0;
};

template<unsigned Size>
Deck<Size>::~Deck() {}