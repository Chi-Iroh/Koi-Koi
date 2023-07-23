#include <algorithm>
#include <format>
#include <random>
#include "../include/DrawPile.hpp"

std::string DrawPile::badNumberOfCardsErrorMessage(unsigned nGivenCards) {
    return std::format("DrawPile initialized with {} cards ({} expected) !", nGivenCards, DECK_SIZE);
}

DrawPile::DrawPile(std::initializer_list<Card> cards) :
    Deck<40>(cards)
{}

Card DrawPile::draw() {
    static unsigned lastIndex{ N_DRAW_PILE_CARDS - 1 };

    if (lastIndex == 0) {
        throw std::out_of_range("Attempt to draw a card from an empty pile !");
    }
    return cards[lastIndex--];
}

unsigned DrawPile::size() const {
    return cards.size();
}