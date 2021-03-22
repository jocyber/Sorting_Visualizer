#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <iostream>

using uint = unsigned int;
using namespace sf;

void bubbleSort(RenderWindow &window, std::vector<RectangleShape> &list);
void selectionSort(RenderWindow& window, std::vector<RectangleShape>& list);

int main()
{
    const Color background(0,0,0);
    const Color item(255, 255, 255);

    RectangleShape rect;
    std::vector<RectangleShape> list(700);

    uint random;
    srand(time(0));

    for (uint i = 0; i < list.size(); i++) {
        random = rand() % 450 + 1;

        list.at(i).setSize(Vector2f(1, random));
        list.at(i).setFillColor(item);
        list.at(i).setPosition(float(i), 500 - random);
    }

    char input;
    std::cout << "Which sorting algorithm do you want to use? (b - bubble sort, s - selection sort)" << std::endl;
    std::cin >> input;
    std::cin.ignore();

    RenderWindow window(VideoMode(700, 500), "Sorting Algorithms");

    switch (input) {
        case 'b':
            bubbleSort(window, list);
            break;

        case 's':
            selectionSort(window, list);
            break;

        default:
            std::cout << "Input not valid." << std::endl;
            std::cin.get();
            break;
    }

    return EXIT_SUCCESS;
}

void bubbleSort(RenderWindow &window, std::vector<RectangleShape> &list) {

    while (window.isOpen()) {
        static uint waitTime = 2;
        Sleep(waitTime);
        static uint i = 0;
        static uint a = 0;

        Event ev;

        while (window.pollEvent(ev)) {

            switch (ev.type) {
            case ev.Closed:
                window.close();

            case ev.KeyPressed:
                if (ev.key.code == Keyboard::Escape)
                    window.close();
            }
        }

        window.clear();

        for (uint i = 0; i < list.size(); i++) {
            window.draw(list.at(i));
        }

        if (i < list.size() - 1) {
            for (uint j = 0; j < list.size() - i - 1; j++) {
                if (list[j].getSize().y > list[j + 1].getSize().y) {
                    float temp = list.at(j).getPosition().y;
                    float temp1 = list.at(j).getSize().y;

                    list.at(j).setPosition(list.at(j).getPosition().x, list.at(j + 1).getPosition().y);
                    list.at(j).setSize(Vector2f(1, list.at(j + 1).getSize().y));

                    list.at(j + 1).setPosition(list.at(j + 1).getPosition().x, temp);
                    list.at(j + 1).setSize(Vector2f(1.0, temp1));
                }
            }
            i++;
        }
        else {
            waitTime = .075;
            if (a < list.size()) {
                list.at(a).setFillColor(Color(0, 255, 0));
                a++;
            }
        }

        window.display();

    }

    window.close();
}

void selectionSort(RenderWindow& window, std::vector<RectangleShape>& list) {
    while (window.isOpen()) {
        static uint waitTime = 2;
        Sleep(waitTime);
        static uint i = 0;
        static uint a = 0;

        Event ev;

        while (window.pollEvent(ev)) {

            switch (ev.type) {
            case ev.Closed:
                window.close();

            case ev.KeyPressed:
                if (ev.key.code == Keyboard::Escape)
                    window.close();
            }
        }

        window.clear();

        for (uint i = 0; i < list.size(); i++) {
            window.draw(list.at(i));
        }

        if (i < list.size()) {
            int min = i;
            for (uint j = i; j < list.size(); j++) {
                if (list[min].getSize().y > list[j].getSize().y) {
                    min = j;
                }
                float temp = list.at(i).getPosition().y;
                float temp1 = list.at(i).getSize().y;

                list.at(i).setPosition(list.at(i).getPosition().x, list.at(min).getPosition().y);
                list.at(i).setSize(Vector2f(1, list.at(min).getSize().y));

                list.at(min).setPosition(list.at(min).getPosition().x, temp);
                list.at(min).setSize(Vector2f(1.0, temp1));
            }
            i++;
        }
        else {
            waitTime = .075;
            if (a < list.size()) {
                list.at(a).setFillColor(Color(0, 255, 0));
                a++;
            }
        }

        window.display();

    }

    window.close();
}
