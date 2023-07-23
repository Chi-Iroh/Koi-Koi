#include <algorithm>
#include <format>
#include <random>
#include "../include/DrawPile.hpp"

std::string DrawPile::badNumberOfCardsErrorMessage(unsigned nGivenCards) {
    return std::format("DrawPile initialized with {} cards ({} expected) !", nGivenCards, DECK_SIZE);
}

void DrawPile::draw(sf::RenderTarget& target, const sf::RenderStates states) const {
    target.draw(cardRectangle, states);
}

DrawPile::DrawPile(std::initializer_list<Card> cards, const sf::Vector2f& position) :
    Deck<40>(cards),
    cardRectangle{ CARD_SIZE<float> }
{
    cardRectangle.setPosition(position);
    cardRectangle.setFillColor(sf::Color::Red);
}

Card DrawPile::draw() {
    static unsigned lastIndex{ DECK_SIZE - 1 };

    if (lastIndex == 0) {
        throw std::out_of_range("Attempt to draw a card from an empty pile !");
    }
    return cards[lastIndex--];
}

unsigned DrawPile::size() const {
    return cards.size();
}