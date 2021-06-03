#include<iostream>

class Point {
	private:
		float x, y;
	public:
		Point() :x(0), y(0) {}
		Point(float x) : x(x), y(0) {}
		Point(float x, float y) : x(x), y(y) {}
};

int main() {

	Point triangle[3] = {
		Point(),
		Point(10),
		Point(5, 10)
	};                  



	return 0;
}