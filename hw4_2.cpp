#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;
const float PI = 3.141592;

int main() {
	float t = 0.0, dt, T;
	dt = 1. / 440. / 20.;
	T = 5. / 440.;

	float ff1, ff2, ff3, ff4, ff5;
	ofstream kang2("sincos2.txt");
	for (t = 0.0; t < T; t += dt) {
		ff1 = sin(2. * PI * 440 * t);
		ff2 = sin(3. * PI * 440 * t);
		ff3 = cos(2. * PI * 440 * t);
		ff4 = cos(3. * PI * 440 * t);
		ff5 = sin((2. * PI * 440 * t) + (3. * PI * 440 * t));

		kang2 << t << "    " << (ff1 * ff4) + (ff3 * ff2);
		kang2 << "   " << ff5 << endl;
	}

	kang2.close();
	return 123;
}