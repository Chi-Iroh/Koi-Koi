#pragma once
#include <type_traits>
#include <SFML/Graphics.hpp>

namespace utils::sf::vector2 {
    template<typename From, typename To>
    requires std::is_convertible_v<From, To>
    constexpr ::sf::Vector2<To> convert(const ::sf::Vector2<From>& vector) {
        return {
            static_cast<To>(vector.x),
            static_cast<To>(vector.y)
        };
    }
}

namespace utils::sf {
    template<typename T>
    ::sf::Vector2<T> getMousePos(const ::sf::RenderWindow& parentWindow) {
        const ::sf::Vector2i mousePos{ ::sf::Mouse::getPosition(parentWindow) };

        if constexpr (std::is_same_v<int, T>) {
            return mousePos;
        } else {
            return vector2::convert<int, T>(mousePos);
        }
    }
}