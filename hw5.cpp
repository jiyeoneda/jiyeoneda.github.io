#include <iostream>
using namespace std;

int main() {
	int N = 2, M = 2;
	float** A;
	A = new float* [N];
	for (int n = 0; n < N; n++) A[n] = new float[M](); //동적으로 할당된 배열의 각 요소를 0으로 초기화
	float** inverseA; 
	inverseA = new float* [N];
	for (int n = 0; n < N; n++) inverseA[n] = new float[M];

	cout << "행렬의 요소를 입력하세요(2 X 2)"<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "A[" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
	}

	cout << endl<< "입력된 행렬 요소: ";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl << "                  ";
	}

	float detA;
	detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	if (detA == 0) {
		cout << endl<<"행렬 A의 역행렬이 존재하지 않습니다." << endl;
	}
	else {
		inverseA[0][0] = A[1][1] / detA;
		inverseA[0][1] = -A[0][1] / detA;
		inverseA[1][0] = -A[1][0] / detA;
		inverseA[1][1] = A[0][0] / detA;

		cout << endl<< "역행렬: ";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << inverseA[i][j] << " ";
			}
			cout << endl << "        ";
		}
	}

	for (int n = 0; n < N; n++) {
		delete[] A[n];
		delete[] inverseA[n];
	}
	delete[] A;
	delete[] inverseA;

}
