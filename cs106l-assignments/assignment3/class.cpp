#include <iostream>
#include <string>
#include "class.h"

Panamera::Panamera(){
    this->color = "white";
    this->engineON = false;
    this->fuel = 0;
    this->owner = "Jerry Xing";
    this->speed = 0;
}

Panamera::Panamera(std::string owner, std::string color, int speed, double fuel):
owner{owner},color{color},speed{speed},fuel{fuel} {
    this->engineON = false;
}

std::string Panamera::getowner() const{
    return this->owner;
}

void Panamera::setengineON(bool engineON){
    this->engineON = engineON;
}

void Panamera::consumeFuel(int distance){
    fuel -= distance * 0.1;   
    if (fuel < 0) {
        fuel = 0;
    }
}

void Panamera::drive(int distance){
    if (!engineON) {
        std::cout << "The engine is off. Cannot drive.\n";
        return;
    }

    if (fuel <= 0) {
        std::cout << "No fuel. Cannot drive.\n";
        return;
    }
    
    this->speed = 60;
    consumeFuel(distance);

    std::cout << owner << "'s Panamera drove "
              << distance << " units.\n";
    std::cout << "Remaining fuel: " << fuel << std::endl;
}