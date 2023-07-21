#include <format>
#include <stdexcept>
#include "../include/Card.hpp"

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

Card::Card(const std::string& filepath, const sf::Vector2f& position) :
    filepath{ filepath.data() },
    position{ position }
{
    loadTexture();
}

Card::Card(const std::string_view& filepath, const sf::Vector2f& position) :
    Card::Card(std::string{ filepath }, position)
{}

Card::Card() {}

Card& Card::operator=(const Card& other) {
    filepath = other.filepath;
    position = other.position;
    loadTexture();
    return *this;
}

Month Card::getMonth() const {
    return month;
}

CardType Card::getType() const {
    return type;
}