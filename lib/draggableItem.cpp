#pragma once
#include <SFML/Graphics.hpp>

class DraggableItem {
public:
    sf::RectangleShape shape;
    bool isDragging = false;
    sf::Vector2f offset;

    DraggableItem(float x, float y, float size, sf::Color color);

    bool handleMousePress(sf::Vector2f mousePos);
    void handleMouseRelease();
    void updatePosition(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window) const;
};
