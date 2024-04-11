#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float getLength(int eumpyo) {
	float T = 1;
	if (eumpyo == 4) T = 1.0;
	else if (eumpyo == 8) T = 0.5;
	return T; 
}
float getfrequency(char* hh) {
	float freq = 1;
	switch (hh[0]) {
	case ('C'): freq = 261.63;
		break;
	case ('D'): freq = 293.66;
		break;
	case ('E'): freq = 329.63;
		break;
	case ('F'): freq = 349.23;
		break;
	case ('G'): freq = 392.0;
		break;
	case ('A'): freq = 440.00;
		break;
	case ('B'): freq = 493.88;
		break;
	}
	if (hh[1] == '5') freq *= 2;
	else if (hh[1] == '3') freq /= 2.0;
	return freq;
}
int getAmplitude(int ss) {
	return ss * 1000;
}

int main() {
	const float pi = 3.141592;
	short akbo[44100];
	char header[44];
	ifstream yyy;
	yyy.open("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
	if (!yyy) return 666;
	yyy.read(header, sizeof(header));
	yyy.close();

	ofstream xx("mywave2.wav", ios::binary | ios::out);
	if (!xx) return 777;

	unsigned short* nc, * bs;
	unsigned int* sampleRate;
	nc = (unsigned short*)(header + 22);
	sampleRate = (unsigned int*)(header + 24);
	bs = (unsigned short*)(header + 34);
	nc[0] = 2;
	sampleRate[0] = 44100;
	bs[0] = 16;

	xx.write(header, sizeof(header));

	int n, eu, sh, ss, a;
	float f1, f2, T, dt = 1.0 / sampleRate[0];
	char hh1[3];
	char hh2[3];
	ifstream song("song.txt");
	if (!song) {
		cout << "can't open song.txt\n";
		return 666;
	}
	song >> n;
	for (int i = 0; i < n; i++) {
		song >> eu >> hh1 >> hh2 >> ss;

		f1 = getfrequency(hh1);
		f2 = getfrequency(hh2);
		a = getAmplitude(ss);
		T = getLength(eu);

		int Samples = T * sampleRate[0];

		short* akbo = new short[Samples * 2];

		float t = 0.;
		for (int i = 0; i < Samples; i++) {
			akbo[i * 2] = (a * sin(2 * pi * f1  * t));
			akbo[i * 2 + 1] = (a * sin(2 * pi * f2  * t));
			t += dt;
		}
		xx.write((char*)akbo, Samples * 2 * sizeof(short));
		delete[] akbo;
	}
	song.close();

	xx.close();
	return 1;
}