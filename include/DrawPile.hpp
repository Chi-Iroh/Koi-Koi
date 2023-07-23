#pragma once
#include <array>
#include "Card.hpp"
#include "Deck.hpp"

class DrawPile : public Deck<40> {
private:
    std::string badNumberOfCardsErrorMessage(unsigned nGivenCards);
    sf::RectangleShape cardRectangle{}; // position updated in draw function

    void draw(sf::RenderTarget& target, const sf::RenderStates states) const;

public:
    DrawPile(std::initializer_list<Card> cards, const sf::Vector2f& position);

    Card draw();

    unsigned size() const;
};