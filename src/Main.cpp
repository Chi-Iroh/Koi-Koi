#include <format>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Card.hpp"

int main() {
    const sf::VideoMode windowSize{ 1'000, 1'000 };
    sf::RenderWindow window{
        windowSize,
        "Koi-Koi",
        sf::Style::Default,
    };
    std::array<Card, N_CARDS> cards {};

    for (unsigned i = 0; i < static_cast<unsigned>(Month::Max); i++) {
        for (unsigned j = 0; j < CARDS_PER_MONTH; j++) {
            cards[i * CARDS_PER_MONTH + j] = Card{
                window,
                CARD_FILEPATHS[i * CARDS_PER_MONTH + j],
                { i * CARD_WIDTH<float>, j * CARD_HEIGHT<float> }
            };
        }
    }

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                for (std::size_t i{}; const Card& card : cards) {
                    if (card.isClicked()) {
                        std::cout << std::format("Card {} is clicked.", i) << std::endl;
                        break;
                    }
                    i++;
                }
            }
        }

        window.clear();
        for (const Card& card : cards) {
            window.draw(card);
        }
        window.display();
    }

    return 0;
}
