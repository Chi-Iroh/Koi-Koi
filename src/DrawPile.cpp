#include <algorithm>
#include <format>
#include <random>
#include "../include/DrawPile.hpp"

DrawPile::DrawPile(const std::initializer_list<Card>& cards) {
    const auto nGivenCards{ cards.size() };

    if (nGivenCards != 40) {
        throw std::runtime_error(std::format("DrawPile initialized with {} cards (40 expected) !", nGivenCards));
    }
    std::copy(cards.begin(), cards.end(), this->cards.begin());
}

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