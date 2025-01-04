#include <SFML/Graphics.hpp>
#include <iostream>
#include "benchmark.cpp"

void loadFirstFile() {
    std::cout << "Executing benchmark.cpp functions..." << std::endl;
    void run();  // Call the function from benchmark.cpp
}

void loadSecondFile() {
    std::cout << "Loading second file..." << std::endl;
    // Code to load second file
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");
    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }
    
    sf::Text title("Main Menu", font, 50);
    title.setPosition(280, 50);

    sf::Text button1("Load File 1", font, 30);
    button1.setPosition(300, 200);
    
    sf::Text button2("Load File 2", font, 30);
    button2.setPosition(300, 270);
    
    sf::Text button3("Placeholder 1", font, 30);
    button3.setPosition(300, 340);
    
    sf::Text button4("Placeholder 2", font, 30);
    button4.setPosition(300, 410);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    loadFirstFile();
                }
                if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    loadSecondFile();
                }
            }
        }

        window.clear();
        window.draw(title);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.display();
    }

    return 0;
}

