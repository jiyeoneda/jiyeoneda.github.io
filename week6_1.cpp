#include <iostream>
#include <fstream>
using namespace std;

void make_a_note(float T, float f, float A, ofstream&yy) {
	const float pi = 3.141592;
	short * akbo;
	akbo = new short[T];
	float dt = 1. /T;
	
	for (int i = 0; i < T; i++) {
		akbo[i] = short(A * sin(2 * pi * f * i * dt));
	}
	yy.write((char*)akbo, T * sizeof(short));
	delete[] akbo;
}

int main() {
	char header[44];
	ifstream xx;
	xx.open("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
	if (!xx) {
		return 666;
	}
	xx.read(header, sizeof(header));
	xx.close();

	unsigned short* nc, * bs;
	unsigned int* sampleRate;

	nc = (unsigned short*)(header + 22);
	sampleRate = (unsigned int*)(header + 24);
	bs = (unsigned short*)(header + 34);

	nc[0] = 1;
	sampleRate[0] = 8000;
	bs[0] = 16;

	ofstream yy("newave.wav", ios::binary | ios::out);
	if (!yy) {
		return 777;
	}
	yy.write(header, 44);

	float T,f,A;
	cout << "음의 길이를 입력하세요: ";
	cin >> T;
	cout << "음의 주파수를 입력하세요: ";
	cin >> f;
	cout << "음의 세기를 입력하세요: ";
	cin >> A;

	make_a_note(T,f,A,yy);

	cout << "음을 만듭니다." << endl;

	return 888;

}
