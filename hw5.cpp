#include <iostream>
using namespace std;

int main() {
	int N = 2, M = 2;
	float** A;
	A = new float* [N];
	for (int n = 0; n < N; n++) A[n] = new float[M](); //�������� �Ҵ�� �迭�� �� ��Ҹ� 0���� �ʱ�ȭ
	float** inverseA; 
	inverseA = new float* [N];
	for (int n = 0; n < N; n++) inverseA[n] = new float[M];

	cout << "����� ��Ҹ� �Է��ϼ���(2 X 2)"<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "A[" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
	}

	cout << endl<< "�Էµ� ��� ���: ";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl << "                  ";
	}

	float detA;
	detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	if (detA == 0) {
		cout << endl<<"��� A�� ������� �������� �ʽ��ϴ�." << endl;
	}
	else {
		inverseA[0][0] = A[1][1] / detA;
		inverseA[0][1] = -A[0][1] / detA;
		inverseA[1][0] = -A[1][0] / detA;
		inverseA[1][1] = A[0][0] / detA;

		cout << endl<< "�����: ";
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
	delete[] inverseA;
	delete[] A;

}