#include "Point.h"
#include <string>

class Square : public Point {
public:
    Square(const std::string, int, int, unsigned int = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    std::string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(std::string);
private:
    unsigned int side;
    unsigned int area{ 0 };
    std::string name;
};

Square::Square(const std::string n, int px, int py, unsigned int s) 
    : Point(px, py), name(n), side(s) {
    area = side * side;
}

unsigned int Square::getSide() const { return side; }

unsigned int Square::getArea() const { return area; }
    
std::string Square::getName() const { return name; }

void Square::setSide(unsigned int s) { 
    side = s; 
    area = side * side; // Update area when side is set
}

void Square::setArea(unsigned int a) { area = a; }

void Square::setName(std::string n) { name = n; }