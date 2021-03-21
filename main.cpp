#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "sortArr.hpp"
#include "renderer.hpp"

using namespace sf;

int main() {
    // ===========================*  INIT  *=================================
    int width = 1280;
    int height = 720;

    int numOfRect = 255;

    float deltaY = height / float(numOfRect);
    float deltaX = width / float(numOfRect);
    float values [numOfRect];

    RenderWindow window(VideoMode(width, height), "Sort Visualizer");
    window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(60);
    
    Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "ERROR FONT NOT LOADED, CHECK fonts/arial.ttf" << std::endl;
    }
    Text text;
    text.setString("Press H for Help");
    text.setFont(font);
    text.setFillColor(Color::Red);
    text.setCharacterSize(24);
    window.draw(text);
    

    for(int i = 0; i < numOfRect; i++) {
        values[i] = i + 1;
    } 

    // Main loop
    while(window.isOpen()) {
        Event event;

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if(event.type == Event::KeyPressed) {
                switch(event.key.code) {
                    case Keyboard::H:
                        text.setString("S - Shuffle\nB - Bubble Sort\nM - Quick sort\nC - Selection Sort");
                    break;
                    case Keyboard::S:
                        shuffleArray(window, values, numOfRect, text);
                        break;
                    case Keyboard::B: 
                        sortArr(window, 0, values, numOfRect, text); //bubble sort 
                        break; 
                    case Keyboard::M: 
                        sortArr(window, 1, values, numOfRect, text); // Quick Sort
                        break;
                    case Keyboard::C:
                        sortArr(window, 2, values, numOfRect, text); // selection sort
                        break;
                    case Keyboard::I:
                        sortArr(window, 3, values, numOfRect, text);
                        break;
                    default:
                    break;
                }
            }
        }

        window.draw(text);
        updateRects(window, values, numOfRect, -1);

    }

    return 0;
}