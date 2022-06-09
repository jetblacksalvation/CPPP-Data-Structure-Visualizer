// CPPP Data Structure Visualizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
sf::RenderWindow window({ 800,800 }, "Data Structures");
constexpr int SCREEN_SIZE = 800;
void draw_vector(std::vector<sf::RectangleShape*>& rows);

enum {
    sorted, notsorted
};
std::vector<float> yvals;
int main()
{   
    srand(time(NULL));
    int size;
    std::cout << "what is size of array?\n";
    std::cin >> size;
    int div = SCREEN_SIZE / size;
    std::vector<sf::RectangleShape* >  columns;//intentianally left empty
    for (int x = 1; x <= size; x++) {

        columns.push_back(new sf::RectangleShape(sf::Vector2f(div, div *rand()%SCREEN_SIZE)));
        columns[x - 1]->setFillColor(sf::Color::Black);

    }
    

    
    sf::Event event;
    std::cout << "Hello World!\n";
    while (window.isOpen() == true) {
        while (window.pollEvent(event)) {//events

            if (sf::Keyboard::Escape == true) {
                window.close();
                std::cout << "closing program...\n";
                exit(0);
            }

        }//end eventss
        //start drawing here
        window.clear(sf::Color::White);
        //draw
        draw_vector(columns);
        window.display();


    }

}
void draw_vector(std::vector<sf::RectangleShape*>& rows) {
    int count = 0;
    float it = float(SCREEN_SIZE / rows.size());
    bool status= notsorted;
   
    for (auto elem : rows) {
        yvals.push_back(elem->getSize().y);
        elem->setPosition(it, 800-elem->getSize().y);
        window.draw(*elem);
        it = it + it;
        
        window.clear(sf::Color::White);
    }
    while (status == notsorted) {
        std::cout << yvals.size() << std::endl;
        for (auto elem : rows) {
            elem->setFillColor(sf::Color::Red);
            count++;
            if (yvals[count] < elem->getSize().y) {
                auto temp = yvals[count];
                yvals[count] = elem->getSize().y;
                yvals[count - 1] = temp;


            }
        }
        count = 0;
        for (auto elem : yvals) {
            if (elem < yvals[count + 1]) {

            }
            else if (elem > yvals[count + 1]) {
                std::cout << "not\n";
            }
            else {
                std::cout << "not\n";
            }
            count++;
        }
        count = 0;
    }
}; 