#include <SFML/Graphics.hpp>

int main() {
    const sf::VideoMode windowSize{ 500, 500 };
    sf::RenderWindow window{
        windowSize,
        "Koi-Koi",
        sf::Style::Default,
    };

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
