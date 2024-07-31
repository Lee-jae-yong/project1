#include <iostream>
#include <string>
using namespace std;

class customer {
	string id;
	double money;
public: 
	customer() {};
	customer();

	bool login( string id) {}; //사용자 로그인
	double show() { return money; } //계좌 확인
	double in(int price) { return money + price; }; //입금
	double out(int price) { return money - price; }; //출력

};