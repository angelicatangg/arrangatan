#pragma once
#include <SFML/Graphics.hpp>

class StorageUnit {
public:
    sf::RectangleShape shape;
    bool isOccupied = false;

    StorageUnit(float x, float y, float w, float h);

    virtual ~StorageUnit() = default;

    virtual void draw(sf::RenderWindow& window) const;
    virtual bool contains(sf::Vector2f point) const;
};
