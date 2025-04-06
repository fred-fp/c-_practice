#include <iostream>
#include <string>
#include <vector>

// creates base class
class Shape {
  private:
    std::string name;
    
  public:
    Shape(const std::string& name) : name(name) {}
    
    virtual ~Shape() {}
    
    std::string getName() const {
      return name;
    }
    
    virtual double calculateArea() const = 0;
    
    virtual void showInfo() const {
      std::cout << "Shape: " << name << std::endl;
    }
};

// creates Circle as a child class of Shape 
class Circle : public Shape {
  private:
    double radius;
    
  public:
    Circle(const std::string& name, double radius) 
      : Shape(name), radius(radius) {}
    
    double calculateArea() const override {
      return 3.14159 * radius * radius;
    }
    
    void showInfo() const override {
      Shape::showInfo();
      std::cout << "Type: Circle, Radius: " << radius 
        << ", Area: " << calculateArea() << std::endl;
    }
};

// creates Rectangle as a child class of Shape
class Rectangle : public Shape {
  private:
    double width;
    double height;
    
  public:
    Rectangle(const std::string& name, double width, double height)
      : Shape(name), width(width), height(height) {}
  
    double calculateArea() const override {
      return width * height;
    }
    
    void showInfo() const override {
      Shape::showInfo();
      std::cout << "Type: Rectangle, Width: " << width 
        << ", Height: " << height
        << ", Area: " << calculateArea() << std::endl;
    }
};

int main() {
  // Polymorphism through base class pointers
  std::vector<Shape*> shapes;
  
  // Dynamic allocation of objects
  shapes.push_back(new Circle("Small Circle", 5.0));
  shapes.push_back(new Rectangle("Large Rectangle", 10.0, 20.0));
  shapes.push_back(new Circle("Big Circle", 15.0));
    
  // Polymorphic behaviour
  std::cout << "Shapes Information:\n";
  for (const auto& shape : shapes) {
    shape->showInfo();
    std::cout << std::endl;
  }
    
  // Clean up memory (proper resource management)
  for (auto& shape : shapes) {
    delete shape;
  }
    
  return 0;
}
