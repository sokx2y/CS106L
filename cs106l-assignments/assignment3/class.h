#include <iostream>
#include <string>

class Panamera{
    private:
        std::string owner;
        std::string color;
        int speed;
        double fuel;
        bool engineON;
        std::string mode; // including Comfort / sport
        void consumeFuel(int distance);
    
    public:
        // constructor
        Panamera();
        Panamera(std::string owner, std::string color, int speed, double fuel);
        // getter
        std::string getowner() const;
        // setter
        void setengineON(bool engineON);
        // more functions
        void drive(int distance);
};