#pragma once
#include <array>
#include "Card.hpp"
#include "Deck.hpp"

class DrawPile : public Deck<40> {
private:
    std::string badNumberOfCardsErrorMessage(unsigned nGivenCards);

public:
    DrawPile(std::initializer_list<Card> cards);

    Card draw();

    unsigned size() const;
};