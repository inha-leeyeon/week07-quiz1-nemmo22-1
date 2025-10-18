#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include "Square.h"

using namespace std;

Point::Point(int px, int py) : x(px), y(py) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int newX) {
    x = newX;
}

void Point::setY(int newY) {
    y = newY;
}

Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), name(n), side(s) {
    area = side * side;
}

unsigned int Square::getSide() const {
    return side;
}

unsigned int Square::getArea() const {
    return area;
}

string Square::getName() const {
    return name;
}

void Square::setSide(unsigned int newSide) {
    side = newSide;
    area = newSide * newSide;
}

void Square::setArea(unsigned int newArea) {
    area = newArea;
}

void Square::setName(string newName) {
    name = newName;
}

int main() {
    int n;
    cin >> n; 

    vector<Square> squares;
    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.emplace_back(name, x, y, side);
    }

    cout << endl; 

    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        return a.getArea() < b.getArea();
        });

    cout << "Squares in increasing order of area" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl; 

    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        return (a.getX() + a.getSide()) < (b.getX() + b.getSide());
        });

    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() + s.getSide() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl; 

    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        return (a.getY() + a.getSide()) < (b.getY() + b.getSide());
        });

    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() + s.getSide()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}