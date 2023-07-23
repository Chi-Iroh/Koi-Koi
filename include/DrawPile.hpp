#pragma once
#include <array>
#include "Card.hpp"
#include "Deck.hpp"

class DrawPile : public Deck<40> {
private:
    static constexpr unsigned N_DRAW_PILE_CARDS{ 40 };
    std::array<Card, N_DRAW_PILE_CARDS> cards{};

    std::string badNumberOfCardsErrorMessage(unsigned nGivenCards);

public:
    DrawPile(std::initializer_list<Card> cards);

    Card draw();

    unsigned size() const;
};