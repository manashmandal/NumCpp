#include "StandardCplusplus.h"
#include "vector"
#include "string"
#include "serstream"
#include "NumCpp.hpp"
#include "NewPing.h"

#define FRONT_TRIG 11
#define FRONT_ECHO 10

#define LEFT_TRIG 9
#define LEFT_ECHO 8

#define RIGHT_TRIG 13
#define RIGHT_ECHO 12

#define MAX_DIST 100


NewPing frontSonar(FRONT_TRIG, FRONT_ECHO, MAX_DIST);
NewPing leftSonar(LEFT_TRIG, LEFT_ECHO, MAX_DIST);
NewPing rightSonar(RIGHT_TRIG, RIGHT_ECHO, MAX_DIST);

using namespace std;
using namespace numcpp;

array1D<int> frontReading;
array1D<int> leftReading;
array1D<int> rightReading;


namespace std {
	ohserialstream cout(Serial);
}

vector <string> strings;


void setup()
{
	Serial.begin(9600);
	


}

void loop()
{
	frontReading.clear();
	leftReading.clear();
	rightReading.clear();

	delay(500);

	for (int i = 0; i < 70; i++) {

		int front = frontSonar.ping_cm();
		int left = leftSonar.ping_cm();
		int right = rightSonar.ping_cm();

		frontReading.push_back(front);
		leftReading.push_back(left);
		rightReading.push_back(right);

		_delay_us(10);
	}

	delay(500);

	cout << "Left " << " Front " << " Right " << endl;
	array2D<int>::makeSample(rightReading, leftReading, frontReading).transpose(true).print();

	delay(500);

	array2D<int>::clear();



	//frontReading.clear();
	//leftReading.clear();
	//rightReading.clear();

	//cout << "Initializing Reading " << endl;
	//cout << "====================" << endl;

	//for (int i = 0; i < 100; i++) {
	//	_delay_us(20);
	//	frontReading.push_back(frontSonar.ping_cm());
	//	_delay_us(20);
	//	leftReading.push_back(leftSonar.ping_cm());
	//	_delay_us(20);
	//	rightReading.push_back(rightSonar.ping_cm());
	//	_delay_us(20);
	//}

	//delay(500);

	//cout << "Reading Done!" << endl;

	//delay(500);

	//auto sampleData = array2D<int>::makeSample(rightReading, leftReading, frontReading);

	//delay(500);

	//sampleData.transpose(true).print();

	//delay(1000);
	//
	//array2D<int>::clear();

}
