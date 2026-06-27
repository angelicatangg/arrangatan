#include "draggableItem.hpp"

DraggableItem::DraggableItem(float x, float y, float size, sf::Color color) {
    shape.setSize({size, size});
    shape.setPosition({x, y});
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
}

bool DraggableItem::handleMousePress(sf::Vector2f mousePos) {
    if (shape.getGlobalBounds().contains(mousePos)) {
        isDragging = true;
        offset = mousePos - shape.getPosition();
        return true;
    }
    return false;
}

void DraggableItem::handleMouseRelease() {
    isDragging = false;
}

void DraggableItem::updatePosition(sf::Vector2f mousePos) {
    if (isDragging) {
        shape.setPosition(mousePos - offset);
    }
}

void DraggableItem::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
