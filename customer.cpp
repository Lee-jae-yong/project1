#include <iostream>
#include <string>
using namespace std;

class customer {
	string id;
	double money;
public: 
	customer() {};
	customer();

	bool login(string id) { return this->id == string id; } //사용자 로그인

	double show() { return money; } //계좌 확인
	double in(int price) { return money + price; }; //입금
	double out(int price) { return money - price; }; //출력

};

//map - id랑 계좌;
//
int main() {
	customer cust;
	cout << "-------------------------------" << endl;
	cout << "         VEDA    BANK" << endl;
	cout << "1. 로그인 2. 회원가입	3.종료" << endl;
	cout << "-------------------------------"<< endl;

	cout << "숫자를 입력하시오 : ";
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:
		cout << "ID: ";
		string logid;
		cin >> logid;
		cust.login(logid);

		

	case 2:
		cout << "생성할 ID :";
		string newid;
		cin >> newid;

	case 3:
		return 0;
	}

}
