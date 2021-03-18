#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "sortArr.hpp"
#include "renderer.hpp"

using namespace sf;

int main() {

    int width = 1280;
    int height = 720;

    int numOfRect = 255;

    float deltaY = height / float(numOfRect);
    float deltaX = width / float(numOfRect);
    float values [numOfRect];

    RenderWindow window(VideoMode(width, height), "Sort Visualizer");
    window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(60);

    for(int i = 0; i < numOfRect; i++) {
        values[i] = i + 1;
    } 

    while(window.isOpen()) {
        Event event;

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if(event.type == Event::KeyPressed) {
                switch(event.key.code) {
                    case Keyboard::S:
                        shuffleArray(window, values, numOfRect);
                        break;
                    case Keyboard::B:
                        sortArr(window, 0, values, numOfRect); //bubble sort
                        break;
                    case Keyboard::M:
                        sortArr(window, 1, values, numOfRect);
                    default:
                        break;
                }
            }
        }

        updateRects(window, values, numOfRect, -1);
    }

    return 0;
}