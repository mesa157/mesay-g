
//Polymorphisms
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Shape {
public:
	double height;
	double width;
	shape(double h, double w) {
		height = h;
		width = w;
	}
	virtual double Area() {
		return height * width;
	}
};
class Rectangle : public Shape {
public:
	Rectangle(double h, w) :
		shape(h, w) {
	}
	doubleArea() {
		return height * width;
	}
};
class Triangle : public shape {
public:
	Triangle(double h, w) :
		shape(h, w) {
		return height * width / 2;
	}
};
void ShowArea(shape& shape) {
	std::cout << "area:" << shape.Area() << "\n";
}
int main() {
	Shape Rectangle(19, 12);
	Triangle triangle(4, 6);
	ShowArea(Rectangle);
	ShowArea(Triangle);
	return 0;
}