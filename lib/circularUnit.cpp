#include "circularUnit.hpp"
#include <cmath>

CircularUnit::CircularUnit(float x, float y, float radius) {
    shape.setRadius(radius);
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color(220, 215, 200));
    shape.setOutlineColor(sf::Color(100, 90, 80));
    shape.setOutlineThickness(5.f);
}

void CircularUnit::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool CircularUnit::contains(sf::Vector2f point) const {
    sf::Vector2f center = shape.getPosition() + sf::Vector2f(shape.getRadius(), shape.getRadius());
    float dx = point.x - center.x;
    float dy = point.y - center.y;
    return (dx*dx + dy*dy) <= (shape.getRadius() * shape.getRadius());
}
