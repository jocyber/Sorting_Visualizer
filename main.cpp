#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <iostream>

using uint = unsigned int;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(700, 500), "Bubble Sort");
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

    //main loop
    //if(input is bubbleSort)
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
                    list.at(j).setSize(Vector2f(1,list.at(j+1).getSize().y));

                    list.at(j + 1).setPosition(list.at(j + 1).getPosition().x, temp);
                    list.at(j+1).setSize(Vector2f(1.0, temp1));
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

    return EXIT_SUCCESS;
}