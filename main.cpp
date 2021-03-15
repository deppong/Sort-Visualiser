#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "sortArr.hpp"
#include "renderer.hpp"

using namespace sf;
static int width = 1280;
static int height = 720;

static const int numOfRect = 100;

float deltaY = height / float(numOfRect);
float deltaX = width / float(numOfRect);
float values [numOfRect];

int main() {
    RenderWindow window(VideoMode(width, height), "Sort Visualiser");
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
                        sortArr(window, 0, values, numOfRect);
                        break;
                    default:
                        break;
                }
            }
        }
        
        //window.clear(Color::Black);

        /*for(int i = 0; i < numOfRect; i++) {
            RectangleShape rectangle(Vector2f(deltaX, deltaY*values[i]));//make a rectangle with the width being deltaX and the height the size of the monitor - the value it corrisponds to.
            rectangle.setFillColor(Color::White);
            rectangle.move(deltaX*i, height-(deltaY*values[i]));

            window.draw(rectangle);

        }*/
        //window.display();
        //shuffleArray(window, values, numOfRect);
        updateRects(window, values, numOfRect);

    }

    return 0;
}