/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include "class.h"

void sandbox() {
  Panamera myCar;   

  Panamera myPanamera("Xiangyu Xing", "black", 0, 50.0);  
  std::cout << myPanamera.getowner() << std::endl;
  myPanamera.setengineON(true);
  myPanamera.drive(100);
}