#include <SFML/Graphics.hpp>
#include <vector>

#include "storageUnit.hpp"
#include "draggableItem.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1000, 600}), "arrangatan");
    window.setFramerateLimit(60);

    // Create storage units (rectangle by default)
    std::vector<StorageUnit> units;
    units.emplace_back(200, 200, 150, 200);
    units.emplace_back(400, 200, 180, 150);
    units.emplace_back(650, 200, 120, 250);

    // Create draggable items
    std::vector<DraggableItem> items;
    items.emplace_back(450, 480, 80, sf::Color(180, 80, 80));
    items.emplace_back(600, 480, 80, sf::Color(244, 196, 48));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse press
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2f mousePos = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));

                for (auto& item : items)
                    item.handleMousePress(mousePos);
            }

            // Mouse release
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left) {

                for (auto& item : items)
                    item.handleMouseRelease();
            }
        }

        // Update dragging
        sf::Vector2f mousePos = window.mapPixelToCoords(
            sf::Mouse::getPosition(window));

        for (auto& item : items)
            item.updatePosition(mousePos);

        // Draw everything
        window.clear(sf::Color(245, 242, 235));

        for (auto& u : units)
            u.draw(window);

        for (auto& item : items)
            item.draw(window);

        window.display();
    }

    return 0;
}
