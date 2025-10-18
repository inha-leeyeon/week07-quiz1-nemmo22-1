class Point {
public:
    Point(int px = 0, int py = 0);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
private:
    int x; // The x-axis coordinate of the point
    int y; // The y-axis coordinate of the point
};

Point::Point(int px, int py) : x(px), y(py) {}

int Point::getX() const { return x; }

int Point::getY() const { return y; }

void Point::setX(int px) { x = px; }

void Point::setY(int py) { y = py; }