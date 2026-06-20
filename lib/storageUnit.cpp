#include "storageUnit.hpp"

StorageUnit::StorageUnit(float x, float y, float w, float h) {
    shape.setSize({w, h});
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color(220, 215, 200));
    shape.setOutlineColor(sf::Color(100, 90, 80));
    shape.setOutlineThickness(5.f);
}

void StorageUnit::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool StorageUnit::contains(sf::Vector2f point) const {
    return shape.getGlobalBounds().contains(point);
}
