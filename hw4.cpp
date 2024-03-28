#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;
const float PI = 3.141592;

int main() {
    float t = 0.0, dt, T;
    dt = 1. / 440. / 20.;
    T = 5. / 440.;

	float f1, f2, f3,f4,f5;
	ofstream kang("sincos.txt");
	for (t = 0.0; t < T; t += dt) {
		f1 = cos(2. * PI * 440 * t);
		f2 = cos(3. * PI * 440 * t);
		f3 = sin(2. * PI * 440 * t);
		f4 = sin(3. * PI * 440 * t);
		f5 = cos((2. * PI * 440 * t) + (3. * PI * 440 * t));

		kang << t << "    " << (f1 * f2) - (f3 * f4);
		kang << "   " << f1 * f2;
		kang << "    " << f3 * f4;
		kang << "   " << f5 << endl;
	}

    kang.close();
    return 123;
}

