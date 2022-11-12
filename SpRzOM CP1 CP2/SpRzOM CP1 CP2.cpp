#include <iostream>
#include "Operations.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

int main()
{
	string a_0 = "170076B15F9575D21DE39D5C429799BBCDDB867016DE2248E3CFDE73A4D70C8636A9E41ABE671E7B9FB4739A5FF64DF9D0D3A64E0C9B20BFE58F1C62B28477EE9FD202010BAC440ADF3CA016A32DB844F23DEC2AB93AE869A6262FC23C5CE419807CDBA930A5433884E3B34B22477289BD3A7712CDD4B4110BD9887E7428FDF7";
	string b_0 = "9D1C2D6E1591932F73C2F499C4E0A2E252DE828CDA7842CE0972C4101FE772B56C45C475EDDEDAEC2DBD13E375E02D2C149B69AB51FF3F94533CA34A815484EC86DACE936BDC62B5F3F9EB6F5BE6BD253E256181D35D7D63EE24459824D462C53676E3DFF98700415ADA65FDA7CBD3B3F359C817F52BEDA70C9DD85F68473C6";
	string c_0 = "A4A28E711996BE9ED7B976871E170770E6B4D48DBCE916AC3D978D2146873AF4DA92CF8D023404EA5D78087C31933D8F2AF0BBE7AB619A5A07AEDBD2E3D582C05826B11F143BD80B64007F8E407DF0F1B9A7678846E0CDD1912B7DFBFBFCB1B9FFF0E54E73FA4248B24771789D2F11885F456545B9ED8C90F925F38B620677DC";
	
	// Лабораторна робота 1 пункт А)
	cout << "input: " << a_0 << endl << "length: " << a_0.length() << endl << endl;
	cout << "input: " << b_0 << endl << "length: " << b_0.length() << endl << endl;

	auto startplus = high_resolution_clock::now();
	string plus = backToHex(longAdd(hexTo32(a_0), hexTo32(b_0)));
	auto stopplus = high_resolution_clock::now();
	auto durationplus = duration_cast<microseconds>(stopplus - startplus);
	cout << "a+b: " << plus << endl << "length: " << plus.length() << endl << "time: " << durationplus.count() << " microseconds" << endl << endl;

	auto startminus = high_resolution_clock::now();
	string minus = backToHex(longSub(hexTo32(a_0), hexTo32(b_0)));
	auto stopminus = high_resolution_clock::now();
	auto durationminus = duration_cast<microseconds>(stopminus - startminus);
	cout << "a-b: " << minus << endl << "length: " << minus.length() << endl << "time: " << durationminus.count() << " microseconds" << endl << endl;

	auto startmult = high_resolution_clock::now();
	string mult = backToHex(longMul(hexTo32(a_0), hexTo32(b_0)));
	auto stopmult = high_resolution_clock::now();
	auto durationmult = duration_cast<microseconds>(stopmult - startmult);
	cout << "a*b: " << mult << endl << "length: " << mult.length() << endl << "time: " << durationmult.count() << " microseconds" << endl << endl;

	auto startdiv = high_resolution_clock::now();
	string div = backToHex(longDivMod(hexTo32(a_0), hexTo32(b_0)).first);
	auto stopdiv = high_resolution_clock::now();
	auto durationdiv = duration_cast<microseconds>(stopdiv - startdiv);
	cout << "a/b: " << div << endl << "length: " << div.length() << endl << "time: " << durationdiv.count() << " microseconds" << endl << endl;

	auto startrest = high_resolution_clock::now();
	string rest = backToHex(longDivMod(hexTo32(a_0), hexTo32(b_0)).second);
	auto stoprest = high_resolution_clock::now();
	auto durationrest = duration_cast<microseconds>(stoprest - startrest);
	cout << "a mod b: " << rest << endl << "length: " << rest.length() << endl << "time: " << durationrest.count() << " microseconds" << endl << endl;

	string d_0 = "FABCED517";
	string e_0 = "AEC";

	auto startpow = high_resolution_clock::now();
	string pow = backToHex(longPowerWindow(hexTo32(d_0), hexTo32(e_0), e_0));
	auto stoppow = high_resolution_clock::now();
	auto durationpow = duration_cast<microseconds>(stoppow - startpow);
	cout << "a**b: " << pow << endl << "length: " << pow.length() << endl << "time: " << durationpow.count() << " microseconds" << endl << endl;
	 
	// пункт Б)
	string one_0 = backToHex(longMul(longAdd(hexTo32(a_0), hexTo32(b_0)), hexTo32(c_0)));
	string two_0 = backToHex(longMul(hexTo32(c_0), longAdd(hexTo32(a_0), hexTo32(b_0))));
	string three_0 = backToHex(longAdd(longMul(hexTo32(a_0), hexTo32(c_0)),longMul(hexTo32(b_0), hexTo32(c_0))));
	if (one_0.compare(two_0) == 0) cout << "(a+b)*c = c*(a+b)" << endl;
	if (one_0.compare(three_0) == 0) cout << "(a+b)*c = a*c + b*c" << endl;
	if (two_0.compare(three_0) == 0) cout << "c*(a+b) = a*c + b*c" << endl;
	string four_0 = backToHex(longMulOneDigit(hexTo32(a_0), 1000));
	unsigned long long* temp_0 = new unsigned long long[1000];
	for (int i = 0; i < 1000; i++) {
		temp_0[i] = 0;
	}
	for (int i = 0; i < 1000; i++) {
		temp_0 = longAdd(temp_0, hexTo32(a_0));
	}
	string five_0 = backToHex(temp_0);
	if (four_0.compare(five_0) == 0) cout << "n*a = a+a+...+a" << endl;
	string six_0 = backToHex(longDivMod(longMul(hexTo32(a_0), hexTo32(b_0)), hexTo32(b_0)).first);
	if (six_0.compare(a_0) == 0) cout << "(a*b)/b = a" << endl;
	string seven_0 = backToHex(longAdd(longSub(hexTo32(a_0), hexTo32(b_0)), hexTo32(b_0)));
	if (seven_0.compare(a_0) == 0) cout << "a-b+b=a" << endl;

	string a_1 = "94EDE1A444B9738ADF06CDB40DCAFA87B25A8BECA2D2262A53D8431A119405F0CBEFB83D2AD547CCE3AE74A8EC74A313C8BED20D4349D9EFBA356FE6E8AD89E2";
	string b_1 = "3";
	string c_1 = "2AB3786D3A85E62EC763A05A73A7F08D21EEE3CBCAE207E40854121BFF8258F7B2B293B0D30277CDB987A6FCB5BF28B68D8E68ABA88DED37BD80A879A1BB53E3";
	string n_1 = "8E06E4DFFB37B57A66ECC52CF2D7D888C49C2794E6FB944C4183A128203932FEBEA4B6E62B2EBDAD4FF0B80DBEDC8439D31280D13E7E523596D92861F6A89E81";

	// Лабораторна робота 2 Пункт А)
	cout << "input a: " << a_1 << endl << "length: " << a_1.length() << endl << endl;
	cout << "input b: " << b_1 << endl << "length: " << b_1.length() << endl << endl;
	cout << "input n: " << n_1 << endl << "length: " << n_1.length() << endl << endl;

	auto startgcd = high_resolution_clock::now();
	string gcdh = backToHex(gcd(hexTo32(a_1), hexTo32(b_1)));
	auto stopgcd = high_resolution_clock::now();
	auto durationgcd = duration_cast<microseconds>(stopgcd - startgcd);
	cout << "gcd(a, b): " << gcdh << endl << "length: " << gcdh.length() << endl << "time: " << durationgcd.count() << " microseconds" << endl << endl;

	auto startplusbrt = high_resolution_clock::now();
	string plusbrt = backToHex(longAddBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)));
	auto stopplusbrt = high_resolution_clock::now();
	auto durationplusbrt = duration_cast<microseconds>(stopplusbrt - startplusbrt);
	cout << "(a+b) mod n: " << plusbrt << endl << "length: " << plusbrt.length() << endl << "time: " << durationplusbrt.count() << " microseconds" << endl << endl;

	auto startminusbrt = high_resolution_clock::now();
	string minusbrt = backToHex(longSubBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)));
	auto stopminusbrt = high_resolution_clock::now();
	auto durationminusbrt = duration_cast<microseconds>(stopminusbrt - startminusbrt);
	cout << "(a-b) mod n: " << minusbrt << endl << "length: " << minusbrt.length() << endl << "time: " << durationminusbrt.count() << " microseconds" << endl << endl;

	auto startmultbrt = high_resolution_clock::now();
	string multbrt = backToHex(longMulBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)));
	auto stopmultbrt = high_resolution_clock::now();
	auto durationmultbrt = duration_cast<microseconds>(stopmultbrt - startmultbrt);
	cout << "(a*b) mod n: " << multbrt << endl << "length: " << multbrt.length() << endl << "time: " << durationmultbrt.count() << " microseconds" << endl << endl;

	auto startsqrbrt = high_resolution_clock::now();
	string sqrbrt = backToHex(longSqrBarrett(hexTo32(a_1), hexTo32(n_1)));
	auto stopsqrbrt = high_resolution_clock::now();
	auto durationsqrbrt = duration_cast<microseconds>(stopsqrbrt - startsqrbrt);
	cout << "(a**2) mod n: " << sqrbrt << endl << "length: " << sqrbrt.length() << endl << "time: " << durationsqrbrt.count() << " microseconds" << endl << endl;

	string d_1 = "D4DA433DBC99DE3D9F192F4B84000A628F00F01D10532B8299BE4987E001E2F23137039D7106217C58800406778F64750E949A6D229AC61FCD424632593C4735";
	string e_1 = "abcde";
	string f_1 = "3921D68215D7FB13151B6CB97C67CEC00B77EE6BB2A5522C3D228077EE78C215A0C2A54B0FAC0D1D99B0634320FA81429B54034B1E2184AB06C9C412EFF8AC55";

	auto startpowbrt = high_resolution_clock::now();
	string powbrt = backToHex(longModPowerBarrett(hexTo32(d_1), hexTo32(e_1), hexTo32(f_1)));
	auto stoppowbrt = high_resolution_clock::now();
	auto durationpowbrt = duration_cast<microseconds>(stoppowbrt - startpowbrt);
	cout << "(a**b) mod n: " << powbrt << endl << "length: " << powbrt.length() << endl << "time: " << durationpowbrt.count() << " microseconds" << endl << endl;

	// Пункт Б)
	string one_1 = backToHex(longMulBarrett(longAddBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)), hexTo32(c_1), hexTo32(n_1)));
	string two_1 = backToHex(longMulBarrett(hexTo32(c_1), longAddBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)), hexTo32(n_1)));
	string three_1 = backToHex(longAddBarrett(longMulBarrett(hexTo32(a_1), hexTo32(c_1), hexTo32(n_1)),longMulBarrett(hexTo32(b_1), hexTo32(c_1), hexTo32(n_1)), hexTo32(n_1)));
	if (one_1.compare(two_1) == 0) cout << "(a+b)*c = c*(a+b) mod n" << endl;
	if (one_1.compare(three_1) == 0) cout << "(a+b)*c = a*c + b*c mod n" << endl;
	if (two_1.compare(three_1) == 0) cout << "c*(a+b) = a*c + b*c mod n" << endl;
	string four_1 = backToHex(longBarOrRes(longMulOneDigit(hexTo32(a_1), 100), hexTo32(n_1)));
	auto startadding = high_resolution_clock::now();
	unsigned long long* temp_1 = new unsigned long long[100];
	for (int i = 0; i < 100; i++) {
		temp_1[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		temp_1 = longAddBarrett(temp_1, hexTo32(a_1), hexTo32(n_1));
	}
	string five_1 = backToHex(temp_1);
	auto stopadding = high_resolution_clock::now();
	auto durationadding = duration_cast<microseconds>(stopadding - startadding);
	if (four_1.compare(five_1) == 0) cout << "n*a = a+a+...+a mod m" << endl;
	cout << "time: " << durationadding.count() << " microseconds" << endl;
	string six_1 = backToHex(longAddBarrett(longSubBarrett(hexTo32(a_1), hexTo32(b_1), hexTo32(n_1)), hexTo32(b_1), hexTo32(n_1)));
	if (six_1.compare(a_1) == 0) cout << "a-b+b=a mod n" << endl;

	string g_1 = "94EDE1A444B9738ADF06CDB40DCAFA87B25A8BECA2D2262A53D8431A119405F0CBEFB83D2AD547CCE3AE74A8EC74A313C8BED20D4349D9EFBA356FE6E8AD89E4";
	string seven_1 = backToHex(longModPowerBarrett(hexTo32(g_1), hexTo32("34"), hexTo32("35")));
	if (seven_1.compare("1") == 0) cout << "a**(p-1)=1 mod p" << endl;
	string eight_1 = backToHex(longModPowerBarrett(hexTo32(g_1), hexTo32("1116"), hexTo32("19A1")));
	if (eight_1.compare("1") == 0) cout << "a**(2*3**(k-1))=1 mod 3**k" << endl;
	return 0;
}
