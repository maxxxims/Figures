#include <iostream>
#include <cmath>
using namespace std;

class Figure{                                    // общий класс
protected:
    float S, P;
    int n;
public:
    Figure() {
    n = 0;
    S = 0;
    P = 0;
    cout<<endl<<"### Your figure created"<<endl;
    }
    void getAngles(){
        cout<<endl<<"### Angles = "<<n<<endl<<endl;
    }
    void getArea(){
        cout<<endl<<"### Area = "<<S<<endl<<endl;
    }
    void getPerimetr(){
        cout<<endl<<"### Perimeter = "<<P<<endl<<endl;
    }

};

class Quadrangle: public Figure{                // подкласс четырехугольник
public:
    Quadrangle() {
    n = 4;
    cout<<"### Your figure with 4 angles created"<<endl;
    }
};

class Straight: public Quadrangle{              // прямой четырехугольник
public:
    Straight(float a, float b):Quadrangle() {
    S = a * b;
    P = 2 * (a + b);
    cout<<"### Your straight quadrangle created"<<endl<<endl;
    }
};

class Square: public Straight{                  // квадрат
public:
    Square(float a):Straight(a, a) {
    S = a * a;
    P = 4 * a;
    cout<<"### Your square created"<<endl<<endl;
    }
};

class Arbitrary: public Quadrangle{               // произвольный четырехугольник
public:
    Arbitrary(float a, float b, float c):Quadrangle() {
    S = a * b * sin(c/57);
    P = 2 * (a + b);
    cout<<"### Your arbitrary quadrangle created"<<endl;
    }
};

class Rhombus: public Arbitrary{               // ромб
public:
    Rhombus(float a, float c):Arbitrary(a, a, c) {
    S = a * a * sin(c/57);
    P = 2 * (a + a);
    cout<<"### Your rhombus created"<<endl<<endl;
    }
};

class Triangles: public Figure{                 // подкласс треугольников
public:
    Triangles() {
    n = 3;
    cout<<"### Your figure with 3 angles created"<<endl;
    }
    virtual void getArea(){
        cout<<"### Area = "<<S<<endl<<endl;
    }
};

class Rectangular: public Triangles{           // прямоугольный треугольник
public:
    Rectangular(float a, float b):Triangles() {
    S = (a * b)/2;
    P = a + b + sqrt(a * a + b * b);
    cout<<"### Your rectangular triangle created"<<endl<<endl;
    }

    virtual void getArea(){
        cout<<"### Area = "<<S<<endl<<endl;
    }
};

class Isosceles: public Triangles{             // равнобедренный треугольник
public:
    Isosceles(float a, float b):Triangles() {
    S = sqrt( (a + b/2) * (b/2) * (b/2)*(a - b/2) );
    P = 2 * a + b;
    cout<<"### Your isosceles triangle created"<<endl<<endl;
    }
};

class Equilateral: public Triangles{           // равносторонний треугольник
public:
    Equilateral(float a, float b):Triangles() {
    S = a * a * sqrt(3)/4;
    P = 3 * a;
    cout<<"### Your equilateral triangle created"<<endl<<endl;
    }
};

class Versatile: public Triangles{            // разносторонний треугольник
public:
    Versatile(float a, float b, float c):Triangles() {
    S = sqrt( ((a + b + c)/2) * ((a - b + c)/2) * ((a + b - c)/2) * ((-a + b + c)/2)) ;
    P = a + b + c;
    cout<<"### Your versatile triangle created"<<endl<<endl;
    }
};

class Cricles: public Figure{                 // подкласс без углов
public:
    Cricles () {
    n = 0;
    cout<<"### Your figure without angles created"<<endl;
    }
};

class Cricle: public Cricles{                 // окружность
public:
    Cricle (float a):Cricles() {
    S = 3.14 * a * a;
    P = 2 * 3.14 * sqrt((a * a + a * a) / 2);
    cout<<"### Your cricle created"<<endl<<endl;
    }
};

class Ellipse: public Cricles{                  // эллипс
public:
    Ellipse (float a, float b):Cricles() {
    S = 3.14 * a * b;
    P = 2 * 3.14 * sqrt((a * a + b * b) / 2);
    cout<<"### Your ellipse created"<<endl<<endl;
    }
};

