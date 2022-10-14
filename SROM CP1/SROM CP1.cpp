#include <iostream>
#include "Operations.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

int main()
{
	string a = "170076B15F9575D21DE39D5C429799BBCDDB867016DE2248E3CFDE73A4D70C8636A9E41ABE671E7B9FB4739A5FF64DF9D0D3A64E0C9B20BFE58F1C62B28477EE9FD202010BAC440ADF3CA016A32DB844F23DEC2AB93AE869A6262FC23C5CE419807CDBA930A5433884E3B34B22477289BD3A7712CDD4B4110BD9887E7428FDF7";
	string b = "9D1C2D6E1591932F73C2F499C4E0A2E252DE828CDA7842CE0972C4101FE772B56C45C475EDDEDAEC2DBD13E375E02D2C149B69AB51FF3F94533CA34A815484EC86DACE936BDC62B5F3F9EB6F5BE6BD253E256181D35D7D63EE24459824D462C53676E3DFF98700415ADA65FDA7CBD3B3F359C817F52BEDA70C9DD85F68473C6";
	string c = "A4A28E711996BE9ED7B976871E170770E6B4D48DBCE916AC3D978D2146873AF4DA92CF8D023404EA5D78087C31933D8F2AF0BBE7AB619A5A07AEDBD2E3D582C05826B11F143BD80B64007F8E407DF0F1B9A7678846E0CDD1912B7DFBFBFCB1B9FFF0E54E73FA4248B24771789D2F11885F456545B9ED8C90F925F38B620677DC";
	
	// пункт А)
	cout << "input: " << a << endl << "length: " << a.length() << endl;
	cout << "input: " << b << endl << "length: " << b.length() << endl;
	auto startplus = high_resolution_clock::now();
	string plus = backToHex(longAdd(hexTo32(a), hexTo32(b)));
	auto stopplus = high_resolution_clock::now();
	auto durationplus = duration_cast<microseconds>(stopplus - startplus);
	cout << "a+b: " << plus << endl << "length: " << plus.length() << endl << "time: " << durationplus.count() << " microseconds" << endl;
	auto startminus = high_resolution_clock::now();
	string minus = backToHex(longSub(hexTo32(a), hexTo32(b)));
	auto stopminus = high_resolution_clock::now();
	auto durationminus = duration_cast<microseconds>(stopminus - startminus);
	cout << "a-b: " << minus << endl << "length: " << minus.length() << endl << "time: " << durationminus.count() << " microseconds" << endl;
	auto startmult = high_resolution_clock::now();
	string mult = backToHex(longMul(hexTo32(a), hexTo32(b)));
	auto stopmult = high_resolution_clock::now();
	auto durationmult = duration_cast<microseconds>(stopmult - startmult);
	cout << "a*b: " << mult << endl << "length: " << mult.length() << endl << "time: " << durationmult.count() << " microseconds" << endl;
	auto startdiv = high_resolution_clock::now();
	string div = backToHex(longDivMod(hexTo32(a), hexTo32(b)).first);
	auto stopdiv = high_resolution_clock::now();
	auto durationdiv = duration_cast<microseconds>(stopdiv - startdiv);
	cout << "a/b: " << div << endl << "length: " << div.length() << endl << "time: " << durationdiv.count() << " microseconds" << endl;
	auto startrest = high_resolution_clock::now();
	string rest = backToHex(longDivMod(hexTo32(a), hexTo32(b)).second);
	auto stoprest = high_resolution_clock::now();
	auto durationrest = duration_cast<microseconds>(stoprest - startrest);
	cout << "a mod b: " << rest << endl << "length: " << rest.length() << endl << "time: " << durationrest.count() << " microseconds" << endl;

	string d = "FABCED517";
	string e = "AEC";
	auto start = high_resolution_clock::now();
	string pow = backToHex(longPowerWindow(hexTo32(d), hexTo32(e), e));
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "a**b: " << pow << endl << "length: " << pow.length() << endl << "time: " << duration.count() << " microseconds" << endl;
	 
	// пункт Б)
	string one = backToHex(longMul(longAdd(hexTo32(a), hexTo32(b)), hexTo32(c)));
	string two = backToHex(longMul(hexTo32(c), longAdd(hexTo32(a), hexTo32(b))));
	string three = backToHex(longAdd(longMul(hexTo32(a), hexTo32(c)),longMul(hexTo32(b), hexTo32(c))));
	if (one.compare(two) == 0) cout << "(a+b)*c = c*(a+b)" << endl;
	if (one.compare(three) == 0) cout << "(a+b)*c = a*c + b*c" << endl;
	if (two.compare(three) == 0) cout << "c*(a+b) = a*c + b*c" << endl;
	string four = backToHex(longMulOneDigit(hexTo32(a), 1000));
	unsigned long long* temp = new unsigned long long[1000];
	for (int i = 0; i < 1000; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < 1000; i++) {
		temp = longAdd(temp, hexTo32(a));
	}
	string five = backToHex(temp);
	if (four.compare(five) == 0) cout << "n*a = a+a+...+a" << endl;
	string six = backToHex(longDivMod(longMul(hexTo32(a), hexTo32(b)), hexTo32(b)).first);
	if (six.compare(a) == 0) cout << "(a*b)/b = a" << endl;
	string seven = backToHex(longAdd(longSub(hexTo32(a), hexTo32(b)), hexTo32(b)));
	if (seven.compare(a) == 0) cout << "a-b+b=a" << endl;
	return 0;
}
