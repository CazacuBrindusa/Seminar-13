#include <iostream>

#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Shape {
public:
    // Constructor
    Shape(const string& name) : name_(name) {}

    // Pure virtual function to calculate area (abstract method)
    virtual double CalculateArea() const = 0;

    // Virtual function to display shape information
    virtual void DisplayDetails() const {
        cout << "Shape: " << name_ << endl;
    }

protected:
    string name_;
};

// Derived class for a circle
class Circle : public Shape {
public:
    // Constructor
    Circle(const string& name, double radius) : Shape(name), radius_(radius) {}

    // Override method to calculate the area of a circle
    double CalculateArea() const override {
        return 3.14 * radius_ * radius_;
    }

    // Override method to display information about the circle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Circle\nRadius: " << radius_ << endl;
    }

private:
    double radius_;
};

// Derived class for a rectangle
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(const string& name, double length, double width)
        : Shape(name), length_(length), width_(width) {}

    // Override method to calculate the area of a rectangle
    double CalculateArea() const override {
        return length_ * width_;
    }

    // Override method to display information about the rectangle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Rectangle\nLength: " << length_ << "\nWidth: " << width_ << endl;
    }

private:
    double length_;
    double width_;
};

int mainVIM() {
    // Creating an object of type Circle and calling virtual methods
    Circle circle("My Circle", 5.0);
    circle.DisplayDetails();
    cout << "Area: " << circle.CalculateArea() << endl;

    cout << "\n------------------------\n";

    // Creating an object of type Rectangle and calling virtual methods
    Rectangle rectangle("My Rectangle", 4.0, 6.0);
    rectangle.DisplayDetails();
    cout << "Area: " << rectangle.CalculateArea() << endl;

    cout << "\n------------------------\n";

    //Un vector care sa contina atat obiecte circle cat si rectangle si sa evidentiez apelul metodelor virtuale/ pur virtuale
    Shape* v[4];
    //Shape** v; // Shape**v[4] nu merge pt ca *v[4] e matrice deja
    //v=new Shape[4];

    Circle circle1("New Circle", 7.0);
    Rectangle rectangle1("New Rectangle", 5.0, 7.0);

    v[0] = new Circle(circle);
    v[1] = new Rectangle(rectangle);
    v[2] = new Circle(circle1);
    v[3] = new Rectangle(rectangle1);

    for (int i = 0; i < 4; i++)
    {
        v[i]->DisplayDetails();
        cout << "Area: " << v[0]->CalculateArea() << "------------" << endl;
    }
    return 0;
}
