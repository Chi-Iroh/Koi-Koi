#include <format>
#include <stdexcept>
#include "../include/Card.hpp"
#include "../include/Utils.hpp"

void Card::loadTexture() {
    if (!background.loadFromFile(this->filepath)) {
        throw std::runtime_error(std::format("Card Background Image '{}' not found !", this->filepath));
    }
    sprite.setTexture(background, true);
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates settings) const {
    sprite.setPosition(position); // position may change between calls
    target.draw(sprite, settings);
}

Card::Card(const sf::RenderWindow& parentWindow, const std::string& filepath, const sf::Vector2f& position) :
    parentWindow{ parentWindow },
    filepath{ filepath.data() },
    position{ position }
{
    loadTexture();
}

Card::Card(const sf::RenderWindow& parentWindow, const std::string_view& filepath, const sf::Vector2f& position) :
    Card::Card(parentWindow, std::string{ filepath }, position)
{}

Card::Card() {}

Card& Card::operator=(const Card& other) {
    filepath = other.filepath;
    position = other.position;
    parentWindow = other.parentWindow;
    loadTexture();
    return *this;
}

Month Card::getMonth() const {
    return month;
}

CardType Card::getType() const {
    return type;
}

sf::Vector2f Card::getPosition() const {
    return sprite.getPosition();
}

void Card::setPosition(const sf::Vector2f& newPosition) {
    sprite.setPosition(newPosition);
}

void Card::move(const sf::Vector2f& vector) {
    sprite.move(vector);
}

bool Card::isClicked() const {
    if (!parentWindow.has_value()) {
        throw std::runtime_error("Card has no parent window, cannot determine if clicked !");
    }

    const sf::Vector2f mousePos{ utils::sf::getMousePos<float>(parentWindow.value()) };
    return sprite.getGlobalBounds().contains(mousePos);
}