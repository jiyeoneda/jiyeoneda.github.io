#include <iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

 void multi(int n1, float * arr) {
	for (int i = 0; i < n1; i++) {
		arr[i] = (rand() % 4001) + 1000;
		arr[i] *= 5;
		cout << arr[i] << "\n";
	}
}

void square(int n2, float * arr) {
	float value = -0.5f;
	for (int i = 0; i < n2; i++) {
		float square_value = value + i * 0.5;
		arr[i] = square_value * square_value;
		cout << arr[i]<<"\n";
	}
}


int main() {
	srand(time(NULL));
	float * arr = new float [11]; 
	arr[0] = 1234;
	int n1 = 5;
	multi(n1,arr+1);
	cout << "\n";
	int n2 = 3;
	float* arr2 = (float*)(arr + n1+1);
	square(n2,arr2);

    ofstream yy("mybin.dat", ios::binary | ios::out);
	yy.write((char*)arr, sizeof(float) * 11);
	yy.close();

	cout << "---------파일 내용----------";
	ifstream xx("mybin.dat", ios::binary | ios::in);
	if (!xx) {
		cout << " File not found : " << "mybin.dat\n";
		return 666;
	}
	xx.read((char*)arr, sizeof(float)*11);
	for (int i = 0; i < 9; i++) {
		cout << "\n"<< arr[i] << "\n";
	}
	streampos fileSize = xx.tellg();
	cout << "\n"<< "파일 크기 : " << fileSize << " 바이트" << endl;

	xx.close();
	delete[] arr;
	return 123;
}

