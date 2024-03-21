#include <iostream>
#include<cmath>
using namespace std;

void main() {
	float k, c, dt, t, num, anal;
	//f(t) : log (k * t + c)
	//미분
	cout << "k를 입력하세요: ";
	cin >> k;
	cout << "c를 입력하세요: ";
	cin >> c;
	cout << "t를 입력하세요: ";
	cin >> t;
	cout << "dt를 입력하세요: ";
	cin >> dt;
	anal =  k * (1 / (k * t + c));
	num = (log(k * (t + dt) + c) - log(k * t + c))/ dt;
	cout << "num: " << num << " anal: " << anal << endl;
	cout << " error = " << abs(num - anal) / anal * 100 << "%\n";
	//적분
	float a, b;
	int N;
	cout << "a를 입력하세요: ";
	cin >> a;
	cout << "b를 입력하세요: ";
	cin >> b;
	cout << "N를 입력하세요: ";
	cin >> N;
	anal = (1 / k) * (((k*b+c)*log(k*b+c))-(k*b)-((k*a+c)*log(k*a+c))+(k*a));
	dt = (b - a) / N;
	num = 0;
	for (int i = 0; i < N; i++) {
		num += log((k * (a + dt * i)) + c) * dt;
	}
	cout << "num: " << num << " anal: " << anal << endl;
	cout << " error = " << abs(num - anal) / anal * 100 << "%\n";

}
