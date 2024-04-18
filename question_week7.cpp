#include <iostream>
using namespace std;

int main() {
	//static memory
	int arr1[5];
	for (int i = 0; i < 5; i++) {
		arr1[i] = i + 1;
		cout << arr1[i] << "\n";
	}
	
	cout << "메모리 크기:" << sizeof(arr1) << "\n";

	cout << "-----------------------------------" << "\n";
	//dynamic memory
	int* arr2;
	arr2 = new int[5];
	for (int i = 0; i < 5; i++) {
		arr2[i] = i+1;
		cout << arr2[i] <<"\n";
	}
	cout << "메모리 크기:" << sizeof(arr2);

	delete[] arr2;
	return 123;
}