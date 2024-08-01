#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class customer {
	string id;
	double money;
public:
	customer(string id, double money) { this->id = id; this->money = money; };
	string getid() { return id; }
	string getmoney() { return to_string(money); }
};

class accountmaneger {
	double money;
public:
	accountmaneger() {};
	double show() { return money; } //계좌 확인
	double in(int price) { return money + price; }; //입금
	double out(int price) { return money - price; }; //출력
	void SAVE();
	void LOAD();
};
//map - id랑 계좌;
//

map<string, customer*> mcust;
map<string, customer*> ::iterator it;

int main() {
	accountmaneger mg;
	//customer cust;


	cout << "-------------------------------" << endl;
	cout << "         VEDA    BANK" << endl;
	cout << "1. 로그인 2. 회원가입	3.종료" << endl;
	cout << "-------------------------------" << endl;

	cout << "숫자를 입력하시오 : ";
	int sel;
	cin >> sel;
	string logid;
	string newid;
	switch (sel)
	{
	case 1:
		cout << "ID: ";

		cin >> logid;
		if (mcust.find(logid) == mcust.end()) cout << "해당 ID 없음" << endl;
		else {
			int choice;
			cout << "로그인 성공. 환영합니다." << logid << " 업무 선택 : 1.잔액 조회		2.입금		3.출금" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:   cout << mcust[logid]; //잔액 조회
			case 2:		cout << "입금하실 금액: "; //입금
				double in; cin >> in;
				mcust.insert({ logid, new customer("", +in) });

			case 3: cout << "출금하실 금액: "; //출금
				double out; cin >> out;
				mcust.insert({ logid, new customer("", -out) });

			}

		}
		mg.LOAD();



	case 2:
		cout << "생성할 ID :";
		cin >> newid;
		mcust.insert({ newid, new customer("", 0) });
		mg.SAVE();

	case 3:
		return 0;
	}


}
void accountmaneger::SAVE() {
	ofstream writefile;
	writefile.open("banklist.txt");
	for (auto itr = mcust.begin(); itr != mcust.end(); itr++) {
		cout << itr->first << " " << itr->second << '\n';
		string str = itr->first + "  " + itr->second->getid() + itr->second->getmoney();
		writefile.write(str.c_str(), str.size());
	}
	writefile.close();
}





void  accountmaneger::LOAD() {
	ifstream readfile;
	readfile.open("banklist.txt");
	if (readfile.is_open()) {
		while (!readfile.eof()) {
			string str;
			getline(readfile, str);
			cout << str << endl;
		}
		readfile.close();
	}

}
