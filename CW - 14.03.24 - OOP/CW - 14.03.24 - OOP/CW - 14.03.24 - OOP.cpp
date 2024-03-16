#include <iostream>
#include<math.h>
using namespace std;

class Figure {
public:
    Figure() {}
    double GetSquare() {return 0;}
    double GetPerimeter() {return 0;}
};

class Ellipse : public Figure {
    double a = 0;
    double b = 0;
public:
    Ellipse() : Ellipse(2, 2) {}
    Ellipse(double a, double b) {
        this->a = a;
        this->b = b;
    }
    double GetSquare(){
        return a * b * 3.14;
    }
    double GetPerimeter(){
        return (3.14 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b))));
    }
};

class Point : public Figure {
    double x = 0;
    double y = 0;
public:
    Point() : Point(2, 2) {}
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double GetSquare(){
        return 0;
    }
    double GetPerimeter(){
        return 0;
    }
};

class Polygon : public Figure {
    Point* point = nullptr;
public:
    Polygon() : Polygon(3) {}

    Polygon(int count) {
        point = new Point[count];
    }

    ~Polygon() {
        delete[] point;
    }
};

class Line : public Figure {
    double y1 = 0;
    double y2 = 0;
    double x1 = 0;
    double x2 = 0;
public:
    Line() : Line(3, 2, 3, 2) {}
    Line(double x1, double x2, double y1, double y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }

    double GetSquare(){
        return 0;
    }

    double GetPerimeter(){
        double dx = x1 - x2;
        double dy = y1 - y2;
        double k1 = pow(dx, 2);
        double k2 = pow(dy, 2);
        return sqrt(k1 + k2);
    }
};

class Triangle : public Polygon {
    double a = 0;
    double b = 0;
    double c = 0;
public:
    Triangle() : Triangle(rand() % 10 * 0.1, rand() % 10 * 0.1, rand() % 10 * 0.1) {}

    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void SetA(double a){
        this->a = a;
    }

    double GetA(){
        return a;
    }

    void SetB(double b){
        this->b = b;
    }

    double GetB(){
        return b;
    }

    void SetC(double c){
        this->c = c;
    }

    double GetC(){
        return c;
    }

    double GetSquare(){
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double GetPerimeter(){
        return a + b + c;
    }

};

class Rectangle : public Polygon {
    double a = 0;
    double b = 0;
public:
    Rectangle() : Rectangle(3, 4) {}
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }
    double GetSquare(){
        return a * b;
    }
    double GetPerimeter(){
        return a * 2 + b * 2;
    }
};

int main()
{
    Rectangle rec;
    cout << rec.GetSquare() << "\n";
    cout << rec.GetPerimeter() << "\n";
}