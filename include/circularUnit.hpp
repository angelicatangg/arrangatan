#pragma once
#include "storageUnit.hpp"

class CircularUnit : public StorageUnit {
public:
    sf::CircleShape shape;

    CircularUnit(float x, float y, float radius);

    void draw(sf::RenderWindow& window) const override;
    bool contains(sf::Vector2f point) const override;
};
