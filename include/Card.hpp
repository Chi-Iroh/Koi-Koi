#pragma once
#include <array>
#include <string_view>
#include <type_traits>
#include <SFML/Graphics.hpp>

constexpr unsigned CARDS_PER_MONTH{ 4 };
constexpr unsigned N_CARDS{ 12 * CARDS_PER_MONTH };

constexpr std::array<std::string_view, N_CARDS> CARD_FILEPATHS{
    "Cards/August/Geese (Earth).png",
    "Cards/August/Moon (Bright).png",
    "Cards/August/Susuki Grass 1.png",
    "Cards/August/Susuki Grass 2.png",
    "Cards/December/Paulownia 1.png",
    "Cards/December/Paulownia 2.png",
    "Cards/December/Paulownia 3.png",
    "Cards/December/Phoenix (Bright).png",
    "Cards/January/Crane (Bright).png",
    "Cards/January/Pine 1.png",
    "Cards/January/Pine 2.png",
    "Cards/January/Red Ribbon (Haiku).png",
    "Cards/February/Bush Warbler (Earth).png",
    "Cards/February/Plum Blossom 1.png",
    "Cards/February/Plum Blossom 2.png",
    "Cards/February/Red Ribbon (Haiku).png",
    "Cards/March/Cherry Blossom 1.png",
    "Cards/March/Cherry Blossom 2.png",
    "Cards/March/Curtain (Bright).png",
    "Cards/March/Red Ribbon (Haiku).png",
    "Cards/April/Bird (Earth).png",
    "Cards/April/Red Ribbon.png",
    "Cards/April/Wisteria 1.png",
    "Cards/April/Wisteria 2.png",
    "Cards/July/Boar (Earth).png",
    "Cards/July/Bush Clover 1.png",
    "Cards/July/Bush Clover 2.png",
    "Cards/July/Red Ribbon.png",
    "Cards/June/Blue Ribbon.png",
    "Cards/June/Butterflies (Earth).png",
    "Cards/June/Peony 1.png",
    "Cards/June/Peony 2.png",
    "Cards/May/Eight Plank Bridge (Earth).png",
    "Cards/May/Iris 1.png",
    "Cards/May/Iris 2.png",
    "Cards/May/Red Ribbon.png",
    "Cards/November/Lightning.png",
    "Cards/November/Ono no Michikaze (Bright).png",
    "Cards/November/Red Ribbon.png",
    "Cards/November/Swallow (Earth).png",
    "Cards/October/Blue Ribbon.png",
    "Cards/October/Deer (Earth).png",
    "Cards/October/Maple 1.png",
    "Cards/October/Maple 2.png",
    "Cards/September/Blue Ribbon.png",
    "Cards/September/Chrysanthemum 1.png",
    "Cards/September/Chrysanthemum 2.png",
    "Cards/September/Sake Cup (Earth).png"
};

enum class Month {
    Invalid,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    Max = December
};

enum class CardType {
    Invalid,
    Chaff,
    Earth,
    Bright,
    PlainRibbon = 1 << 2,
    RedRibbon = PlainRibbon | 1,
    BlueRibbon = PlainRibbon | 2,
};

template<typename T>
requires std::is_arithmetic_v<T>
constexpr T CARD_HEIGHT{ 90 };

template<typename T>
requires std::is_arithmetic_v<T>
constexpr T CARD_WIDTH{ 56 };

template<typename T>
requires std::is_arithmetic_v<T>
constexpr sf::Vector2<T> CARD_SIZE{ CARD_WIDTH<T>, CARD_HEIGHT<T> };

class Card : public sf::Drawable {
private:
    std::string filepath;
    Month month{};
    CardType type{};

    // initialized once, but position is updated at each draw, hence mutable
    mutable sf::Sprite sprite{};
    sf::Texture background{};
    sf::Vector2f position{};

    void loadTexture();

    void draw(sf::RenderTarget& target, sf::RenderStates settings) const;

public:
    explicit Card(const std::string& filepath, const sf::Vector2f& position = {});
    explicit Card(const std::string_view& filepath, const sf::Vector2f& position = {});
    Card();

    Card& operator=(const Card& other);

    Month getMonth() const;
    CardType getType() const;
};