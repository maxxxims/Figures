#include <iostream>
#include <string>
#include "figure.cpp"
using namespace std;



class User_Interface{
private:
    string input;
    string commands[15] = {"create", "get", "perimeter", "perimtr", "area", "triangle", "square", "rectangle", "rhombus", "circle", "angles", "angle", "exit", "info", " "};
    int a[10];                  // массив сторон
    void clean(){
        input = " ";
        for(int i = 0; i < 10; i++)
            a[i] = 0;
    }



    bool what_command(){
        for(int i = 0; i < 15; i++){
            if(input == commands[i])   return true;
        }
        return false;
    }


    void what_triangle(Figure** G){
        for(int i = 0; i<3; i++){
            read();
            a[i] = stoi(input);
        }
        if(a[1]+a[0]>=a[2] && a[2]+a[0]>=a[1] && a[1]+a[2]>=a[0] && a[0]>0 && a[1]>0 && a[2]>0){
            if(a[0]*a[0]+a[1]*a[1] == a[2]*a[2]) *G = new Rectangular(a[0], a[1]);
            else if(a[2]*a[2]+a[1]*a[1] == a[0]*a[0]) *G = new Rectangular(a[2], a[1]);
            else if(a[0]*a[0]+a[2]*a[2] == a[1]*a[1]) *G = new Rectangular(a[0], a[2]);
            else if(a[0]==a[1] && a[1]==a[2])    *G = new Equilateral(a[0],a[1]);
            else if(a[0]==a[1] && a[1]!=a[2])    *G = new Isosceles(a[0],a[2]);
            else if(a[0]==a[2] && a[1]!=a[2])    *G = new Isosceles(a[0],a[1]);
            else if(a[1]==a[2] && a[1]!=a[0])    *G = new Isosceles(a[1],a[0]);
            else    *G = new Versatile(a[0],a[1],a[2]);
        }
        else{
                cout<<"### There is no such triangle"<<endl<<endl;
                //*G = new Figure;
        }
    }

    void what_circle(Figure** G){
        for(int i = 0; i < 2; i++){
            read();
            a[i] = stoi(input);
        }
        if(a[0] == a[1])    *G = new Cricle(a[0]);
        else *G = new Ellipse(a[0],a[1]);

    }

    void what_quadrangle(Figure** G){
        bool st = true;
        for(int i = 0; i < 4; i++){
            read();
            a[i] = stoi(input);
            if(a[i]<=0)     st = false;
        }


        if(st == true && a[0]<=a[1]+a[2]+a[3] && a[1]<=a[0]+a[2]+a[3] && a[2]<=a[1]+a[0]+a[3] && a[3]<=a[1]+a[2]+a[0]){
            if(input == "square")   *G = new Square(a[0]);
            if(input == "rectangle") *G = new Rectangular(a[0], a[1]);
            if(input == "rhombus")  *G = new Rhombus(a[0], a[1]);
            if(input == "quadrangle")   *G = new Arbitrary(a[0], a[1], a[2]);
            cout<<"i am here";
            //else    G = new Arbitrary(a[0],a[1], a[2], a[3]);

        }
        else{
            cout<<"### There is no such quadrilateral"<<endl<<endl;
        }



    }
public:
    User_Interface(){
        input = "info";
        clean();
        for(int i = 0; i<10; i++){
            a[i] = 0;
        }

        //commands[14] = {"create", "get", "perimeter", "perimtr", "area", "triangle", "square", "rectangle", "rhombus", "circle", "angles", "angle", "exit", "info"};

        cout<<"### Hi, username! You can create one of the following figures: triangle, circle, square, rectangle, rhombus"<<endl;
        cout<<"### Write 'info' to learn more about the teams"<<endl<<endl;
    }

    void info(){
        if(input == "info"){
            cout<<"### Hi, username! You can create one of the following figures: triangle, circle, square, rectangle, rhombus"<<endl;
            cout<<"### Write 'create _name_of_figure_' and list the lengths of the sides"<<endl;
            cout<<"### 'triangle' has 3 parameters: a b c - the lengths of the sides."<<endl;
            cout<<"### 'circle' has 2 parameters: a b  - the dimensions of the large and small semi-axes"<<endl;
            cout<<"### 'square' has 1 parameter: a - the length of the side"<<endl;
            cout<<"### 'rectangle' has 2 parameters: a b  - lengths of perpendicular sides"<<endl;
            cout<<"### 'rhombus' has 2 parameters: a b - length of one side and angle"<<endl;
            cout<<"### You can get area, number of angles, perimeter of your figure"<<endl;
            cout<<"### Use such commands: 'get area' 'get perimeter' 'get angles' "<<endl;
            cout<<"### Use 'exit' to close the program"<<endl<<endl;
        }
    }


    void command(){
        if(what_command() == false){
            cout<<"### Unknown command"<<endl<<endl;
        }
    }



    void read(){
        cin>>input;
    }
    bool is_open(){
        if(input == "exit" || input=="Exit"){
                clean();
                return false;
        }
        else{
            clean();
            return true;
        }
    }

    bool create(){
        if(input == "create" || input=="Create")    return true;
        else    return false;
    }


    bool get(){
        if(input == "get" || input=="Get")    return true;
        else    return false;
    }

    void what_get(Figure* G){
        if(input == "Area" || input == "area"){
                G->getArea();
        }
        if(input == "Perimeter" || input == "perimeter" || input == "perimetr"){
                G->getPerimetr();
        }
        if(input == "Angles" || input == "angles" || input == "angle"){
                G->getAngles();
        }
    }

    void type(Figure** D){
        if(input == "triangle"){
            what_triangle(D);
            clean();
        }

        if(input == "circle"){
            what_circle(D);
            clean();
        }



        if(input == "square"){
            cin>>a[0];
            *D = new Square(a[0]);
        }

        if(input == "rectangle"){
            for(int i = 0; i<2; i++){
                cin>>a[i];
            }
            *D = new Straight(a[0], a[1]);
            clean();
        }

        if(input == "rhombus" || input == "romb"){
            for(int i = 0; i<2; i++){
                cin>>a[i];
            }
            *D = new Rhombus(a[0], a[1]);
        }


        if(input == "quadrangle"){
            for(int i = 0; i<3; i++){
                cin>>a[i];
            }
            *D = new Arbitrary(a[0], a[1], a[2]);
        }

    }




};
