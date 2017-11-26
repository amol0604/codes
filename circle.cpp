#include <iostream>
#include <string>
using namespace std;

class Circle{
private:
	double radius;
	string color;

public:

	Circle(double r, string c){

		radius = r;
		color = c;
	};

	Circle(){

		radius = 1;
		color = "red";
	};

	~Circle(){
	};

	double getRadius()
	{
		return(radius);
	}

	string getColor()
	{
		return(color);
	};

	double getArea(){
		return(radius*radius*3.1416);

	};
};

int main()
{
	Circle c1 = Circle(1.2, "blue");
	cout << "R = " << c1.getRadius() << endl;
	cout << "col = " << c1.getColor() << endl;
	cout << "Ar = " << c1.getArea() << endl;

	Circle c2 = Circle();
	cout << "R = " << c2.getRadius() << endl;
	cout << "col = " << c2.getColor() << endl;
	cout << "Ar = " << c2.getArea() << endl;

	Circle c3 = Circle(c2);
	cout << "R = " << c2.getRadius() << endl;
	cout << "col = " << c2.getColor() << endl;
	cout << "Ar = " << c2.getArea() << endl;

};
