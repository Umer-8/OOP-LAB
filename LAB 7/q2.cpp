#include <iostream>
using namespace std;

class Shape {
protected:
    float x, y;
    string color;
    float borderThickness;

public:
    Shape(float x, float y, string col, float thickness = 1.0)
        : x(x), y(y), color(col), borderThickness(thickness) {}

    virtual void draw() const {
        cout << "Drawing a shape at position (" << x << ", " << y << ") with color " << color << " and border thickness " << borderThickness << endl;
    }

    virtual float calculateArea() const = 0;
    virtual float calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float x, float y, float r, string col, float thickness = 1.0)
        : Shape(x, y, col, thickness), radius(r) {}

    void draw() const override {
        cout << "Drawing a circle at position (" << x << ", " << y << ") with radius " << radius << ", color " << color << " and border thickness " << borderThickness << endl;
    }

    float calculateArea() const override {
        return 3.14159f * radius * radius;
    }

    float calculatePerimeter() const override {
        return 2 * 3.14159f * radius;
    }
};

class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(float x, float y, float w, float h, string col, float thickness = 1.0)
        : Shape(x, y, col, thickness), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a rectangle at position (" << x << ", " << y << ") with width " << width << ", height " << height << ", color " << color << " and border thickness " << borderThickness << endl;
    }

    float calculateArea() const override {
        return width * height;
    }

    float calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    float side1, side2, side3;

public:
    Triangle(float x, float y, float s1, float s2, float s3, string col, float thickness = 1.0)
        : Shape(x, y, col, thickness), side1(s1), side2(s2), side3(s3) {}

    void draw() const override {
        cout << "Drawing a triangle at position (" << x << ", " << y << ") with sides " << side1 << ", " << side2 << ", " << side3 << ", color " << color << " and border thickness " << borderThickness << endl;
    }

    float calculateArea() const override {
        float s = (side1 + side2 + side3) / 2;
        return s * (s - side1) * (s - side2) * (s - side3);
    }

    float calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(10, 10, 5, "red");
    Rectangle rectangle(20, 20, 8, 6, "blue");
    Triangle triangle(30, 30, 5, 5, 5, "green");

    circle.draw();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << endl;

    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << endl;

    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << endl;

    return 0;
}