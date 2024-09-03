#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Car {
public:
	int wheels;
	string color;
	Car() {
		wheels = 4;
		color = "";
	};
public:
	int getWheels() {
		return wheels;
	}
	void setColor(string color) {
		this->color = color;
	}
	string getColor() {
		return color;
	}
};


TEST(TestCaseName, testWheels) {
	Car car;
	EXPECT_EQ(4,car.getWheels() );
	
}


TEST(TestCaseName, testColor) {
	Car car;
	EXPECT_EQ("", car.getColor());
	car.setColor("red");
	EXPECT_EQ("red", car.getColor());
	
	;
}


  int main(int argc, char** argv) {
	  testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
  
  }