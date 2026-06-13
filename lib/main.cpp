#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

struct StorageUnit {
    sf::RectangleShape shape;
    bool isOccupied = false;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 600}), "arrangatan");
    window.setFramerateLimit(60);

    vector<StorageUnit> storageBoxes;

    int totalUnits = 3;
    float unitWidth = 150.f;
    float unitHeight = 200.f;
    float spacing = 40.f;

    float startX = (1000.f - ((unitWidth * totalUnits) + (spacing * (totalUnits - 1)))) / 2.f;
    float startY = 200.f;

    for (int i = 0; i < totalUnits; i++) {
        StorageUnit unit;

        unit.shape.setSize(sf::Vector2f(unitWidth, unitHeight));
        float xPos = startX + i * (unitWidth + spacing);
        unit.shape.setPosition(sf::Vector2f(xPos, startY));

        unit.shape.setFillColor(sf::Color(220, 215, 200));
        unit.shape.setOutlineColor(sf::Color(100, 90, 80));
        unit.shape.setOutlineThickness(5.f);

        storageBoxes.push_back(unit);
    }

    sf::RectangleShape bigRect;
    bigRect.setSize(sf::Vector2f(600.f, 250.f));
    bigRect.setFillColor(sf::Color(255, 200, 180, 120)); 
    bigRect.setOutlineColor(sf::Color(150, 80, 60));
    bigRect.setOutlineThickness(4.f);
    bigRect.setPosition(sf::Vector2f(200.f, 175.f));

    sf::RectangleShape draggableItem;
    draggableItem.setSize(sf::Vector2f(80.f, 80.f)); 
    draggableItem.setFillColor(sf::Color(180, 80, 80));  
    draggableItem.setPosition(sf::Vector2f(450.f, 480.f));   
    
    bool isDragging = false;
    sf::Vector2f mouseOffset;

    while (window.isOpen())
    {   
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        
            //pick the item up
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    // get current mouse position
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    // is mouse on the item, apply offset
                    if (draggableItem.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        mouseOffset = mousePos - draggableItem.getPosition();
                    }
                }
            }

            // drop the item
            if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseReleased->button == sf::Mouse::Button::Left) 
                    isDragging = false;
            }
        }

        if (isDragging) {
            // get current mouse position and move the item with the mouse (maintaining offset)
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            draggableItem.setPosition(mousePos - mouseOffset);
        }

        window.clear(sf::Color(245, 242, 235)); // so dragging doesn't leave a trail behind

        for (const auto& unit : storageBoxes) {
            window.draw(unit.shape); // draw the cabinet sections
        }

        window.draw(bigRect); 
        window.draw(draggableItem);

        window.display();
    }
    return 0;
}
