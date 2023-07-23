#pragma once
#include <array>
#include "Card.hpp"

class DrawPile {
private:
    static constexpr unsigned N_DRAW_PILE_CARDS{ 40 };
    std::array<Card, N_DRAW_PILE_CARDS> cards{};

public:
    DrawPile(const std::initializer_list<Card>& cards);

    Card draw();

    unsigned size() const;
};