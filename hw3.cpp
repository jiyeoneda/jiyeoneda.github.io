#include <iostream>
using namespace std;

void main() {
	float k, c, dt, t, num, anal;
	//f(t) : log (k * t + c)
	//�̺�
	cout << "k�� �Է��ϼ���: ";
	cin >> k;
	cout << "c�� �Է��ϼ���: ";
	cin >> c;
	cout << "t�� �Է��ϼ���: ";
	cin >> t;
	cout << "dt�� �Է��ϼ���: ";
	cin >> dt;
	anal =  k * (1 / (k * t + c));
	num = (log(k * (t + dt) + c) - log(k * t + c))/ dt;
	cout << "num: " << num << " anal: " << anal << endl;
	cout << " error = " << (num - anal) / anal * 100 << "%\n";
	//����
	float a, b;
	int N;
	cout << "a�� �Է��ϼ���: ";
	cin >> a;
	cout << "b�� �Է��ϼ���: ";
	cin >> b;
	cout << "N�� �Է��ϼ���: ";
	cin >> N;
	anal = (1 / k) * (((k * b + c) * (log(k * b + c) - 1)) - ((k * a + c) * (log(k * a + c) - 1)));
	dt = (b - a) / N;
	num = 0;
	for (int i = 0; i < N; i++) {
		num += log((k * (a + dt * i)) + c) * dt;
	}
	cout << "num: " << num << " anal: " << anal << endl;
	cout << " error = " << (num - anal) / anal * 100 << "%\n";

}