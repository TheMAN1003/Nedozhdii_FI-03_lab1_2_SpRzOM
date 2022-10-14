#include <string>
#include <algorithm>
#include <utility>

using namespace std;

unsigned long long fromHexVal(char c) {
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	default:
		cout << "your hex input is incorrect" << endl;
		return NULL;
	}
}

char toHexVal(unsigned long long n) {
	switch (n)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	default:
		cout << "your hex input is incorrect" << endl;
		return NULL;
	}
}

unsigned long long* hexToNumbers(string s) {
	while (s.length() > 512) {
		s.erase(s.begin(), s.begin() + 1);
	}
	while (s.length() % 8 != 0 || s.length() != 512) {
		s = '0' + s;
	}
	reverse(s.begin(), s.end());
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	unsigned long long* temp = new unsigned long long[s.length()];
	for (int i = 0; i < s.length(); i++) {
		temp[i] = fromHexVal(s[i]);
	}
	return temp;
}

unsigned long long* hexTo32(string s) {
	unsigned long long* temp = hexToNumbers(s);
	unsigned long long* result = new unsigned long long[65];
	for (int i = 63; i >= 0; i--) {
		result[i] = (temp[(63 - i) * 8] | (temp[(63 - i) * 8 + 1] << 4) 
			| (temp[(63 - i) * 8 + 2] << 8) | (temp[(63 - i) * 8 + 3] << 12) | (temp[(63 - i) * 8 + 4] << 16) 
			| (temp[(63 - i) * 8 + 5] << 20) | (temp[(63 - i) * 8 + 6] << 24) | (temp[(63 - i) * 8 + 7] << 28));
	}
	reverse(result, result + 64);
	return result;
}

string backToHex(unsigned long long* n) {
	string result;
	for (int i = 63; i >=0; i--) {
		string temp;
		for (int j = 0; j < 29; j += 4) {
			temp += toHexVal(n[i] >> j & 15);
		}
		reverse(temp.begin(), temp.end());
		result += temp;
	}
	while (result[0] == '0') {
		result.erase(result.begin(), result.begin() + 1);
	}
	return result;
}

unsigned long long* toBinary(unsigned long long* n) {
	unsigned long long* result = new unsigned long long[2048];
	for (int i = 63; i >= 0; i--) {
		for (int j = 31; j >= 0; j--) {
			result[32 * i + j] = n[i] >> j & 1;
		}
	}
	return result;
}

unsigned long long* fromBinary(unsigned long long* n) {
	unsigned long long* result = new unsigned long long[65];
	for (int i = 63; i >= 0; i--) {
		result[i] = 0;
		for (int j = 31; j >=0; j--) {
			result[i] |= (n[i * 32 + j] << j);
		}
	}
	return result;
}

unsigned long long* longAdd(unsigned long long* a, unsigned long long* b) {
	unsigned long long* c = new unsigned long long[65];
	unsigned long long temp;
	unsigned long long mod = 4294967295;
	c[64] = 0;
	for (int i = 0; i < 64; i++) {
		temp = a[i] + b[i] + c[64];
		c[i] = temp & mod;
		c[64] = temp >> 32;
	}
	return c;
}

int longCmp(unsigned long long* a, unsigned long long* b) {
	int i = 64;
	while (a[i] == b[i]) i--;
	if (i == -1) return 0;
	else {
		if (a[i] > b[i]) return 1;
		else return -1;
	}
}

unsigned long long* longSub(unsigned long long* a, unsigned long long* b) {
	unsigned long long* nul = new unsigned long long[65];
	for (int i = 0; i < 65; i++) {
		nul[i] = 0;
	}
	if (longCmp(a, b) == -1) {
		cout << "Negative number" << endl;
		return nul;
	}
	unsigned long long* c = new unsigned long long[65];
	long long temp;
	unsigned long long mod = 4294967296;
	c[64] = 0;
	for (int i = 0; i < 64; i++) {
		temp = a[i] - b[i] - c[64];
		if (temp >= 0) {
			c[i] = temp;
			c[64] = 0;
		}
		else {
			c[i] = mod + temp;
			c[64] = 1;
		}
	}
	return c;
}


unsigned long long* longMulOneDigit(unsigned long long* a, unsigned long long b) {
	unsigned long long* c = new unsigned long long[65];
	unsigned long long temp;
	unsigned long long bits = 32;
	unsigned long long mod = 4294967295;
	c[64] = 0;
	for (int i = 0; i < 64; i++) {
		temp = a[i] * b + c[64];
		c[i] = temp & mod;
		c[64] = temp >> bits;
	}
	return c;
}

unsigned long long* longShiftDigitsToHigh(const unsigned long long* a, unsigned long long b) {
	unsigned long long* temp = new unsigned long long[65];
	for (int i = 63; i >= 0; i--) {
		temp[i] = a[i];
	}
	while (b != 0) {
		for (int i = 63; i >=1; i--) {
			temp[i] = temp[i-1];
		}
		temp[0] = 0;
		b--;
	}
	return temp;
}

unsigned long long* longMul(unsigned long long* a, unsigned long long* b) {
	unsigned long long* c = new unsigned long long[257];
	unsigned long long* temp;
	for (int i = 0; i < 257; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < 64; i++) {
		temp = longMulOneDigit(a, b[i]);
		temp = longShiftDigitsToHigh(temp, i);
		c = longAdd(c, temp);
	}
	return c;
}

unsigned long long* longSquareTemp(unsigned long long* a) {
	return longMul(a, a);
}

unsigned long long bitLength(unsigned long long* a) {
	unsigned long long n = 0;
	bool check = false;
	for (int i = 2047; i >=0; i--) {
		if (a[i] == 1) check = true;
		if (check == true) n++;
	}
	return n;
}

unsigned long long* longShiftBitsToHigh(const unsigned long long* a, unsigned long long b) {
	unsigned long long* temp = new unsigned long long[2048];
	for (int i = 2047; i >= 0; i--) {
		temp[i] = a[i];
	}
	while (b != 0) {
		for (int i = 2047; i >= 1; i--) {
			temp[i] = temp[i - 1];
		}
		temp[0] = 0;
		b--;
	}
	return temp;
}

int longCmpBit(unsigned long long* a, unsigned long long* b) {
	int i = 2047;
	while (a[i] == b[i]) i--;
	if (i == -1) return 0;
	else {
		if (a[i] > b[i]) return 1;
		else return -1;
	}
}

pair<unsigned long long*, unsigned long long*> longDivMod(unsigned long long* a, unsigned long long* b) {
	unsigned long long* q = new unsigned long long[2048];
	unsigned long long* r = new unsigned long long[2048];
	unsigned long long* c;
	unsigned long long t;
	unsigned long long* a_bin = toBinary(a);
	unsigned long long* b_bin = toBinary(b);
	unsigned long long k = bitLength(b_bin);
	r = a_bin;
	for (int i = 0; i < 2048; i++) {
		q[i] = 0;
	}
	while (longCmpBit(r, b_bin) == 1 || longCmpBit(r, b_bin) == 0) {
		t = bitLength(r);
		c = longShiftBitsToHigh(b_bin, t - k);
		if (longCmpBit(r, c) == -1) {
			t--;
			delete[] c;
			c = longShiftBitsToHigh(b_bin, t - k);
		}
		r = toBinary(longSub(fromBinary(r), fromBinary(c)));
		q[t - k] = 1;
		delete[] c;
	}
	pair<unsigned long long*, unsigned long long*> res;
	res.first = fromBinary(q);
	res.second = fromBinary(r);
	return res;
}

string numbersToHex(unsigned long long* n) {
	string result;
	for (int i = 63; i >= 0; i--) {
		string temp;
		for (int j = 0; j < 29; j += 4) {
			temp += toHexVal(n[i] >> j & 15);
		}
		reverse(temp.begin(), temp.end());
		result += temp;
	}
	while (result[0] == '0') {
		result.erase(result.begin(), result.begin() + 1);
	}
	return result;
}

unsigned long long* longPowerWindow(unsigned long long* a, unsigned long long* b, string hex_b) {
	unsigned long long* hex_num_b = hexToNumbers(hex_b);
	unsigned long long* c = new unsigned long long[4096];
	c[0] = 1;
	for (int i = 4095; i >= 1; i--) {
		c[i] = 0;
	}
	unsigned long long** d = new unsigned long long*[32];
	d[0] = hexTo32("1");
	d[1] = a;
	for (int i = 2; i < 15; i++) {
		d[i] = longMul(d[i-1], a);
	}
	for (int i = hex_b.length(); i >= 0; i--) {
		c = longMul(c, d[hex_num_b[i]]);
		if (i != 0) {
			for (int k = 1; k <= 4; k++) {
				c = longMul(c, c);
			}
		}
	}
	return c;
}