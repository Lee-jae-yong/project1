#include <iostream>
#include <string>
using namespace std;

class customer {
	string id;
	double money;
public: 
	customer() {};
	customer();

	bool login( string id) {}; //����� �α���
	double show() { return money; } //���� Ȯ��
	double in(int price) { return money + price; }; //�Ա�
	double out(int price) { return money - price; }; //���

};


int main() {
	cout << "-------------------------------" << endl;
	cout << "         VEDA    BANK" << endl;
	cout << "  1. �α���        2. ȸ������" << endl
	cout << "-------------------------------"<< endl;
}