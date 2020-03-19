#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

namespace func {
	void ShowMenu() {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 ";
	}
	void GetAccount(int &num, char* name, int &money) {
		cout<<"[계좌개설]"<<endl;
		cout<<"계좌ID: "; cin>>num;
		cout<<"이름: "; cin>>name;
		cout<<"입금액: "; cin>>money;
	}
	void DepositMenu(Account **acc) {
		int num, money;
		cout<<"[입금]"<< endl;
		cout<<"계좌ID: "; cin>>num;
		cout<<"입금액: "; cin>>money;
		for (int i = 0; i < MAX; i++) {
			if (acc[i]->Accnum == id) {
				acc[i]->AddMoney(money);
				cout<<"입금완료"<<endl;
				break;
			}
			else {
				cout<<"잘못된 ID입니다."<<endl;
			}
		}
	}
	void WithdrawMenu(Account **acc) {
		int num, money;
		cout<<"[출금]"<<endl;
		cout<<"계좌ID: "; cin>>num;
		cout<<"출금액: "; cin>>money;
		for (int i = 0; i < MAX; i++) {
			if (acc[i]->Accnum == id) {
				acc[i]->SubMoney(money);
				cout<<"출금완료"<<endl;
				break;
			}
			else {
				cout<<"잘못된 ID입니다."<<endl;
			}
		}
	}
	void Print(Account **acc) {
		for (int i = 0; i < index; i++) {
			acc[i]->PrintAccount();
		}
	}
}

class Account {
	int Accnum;
	char* Accname;
	int Accmoney;
	
public:
	Account(int num, char* name, int money) : Accnum(num), Accmoney(money) {
		int len = strlen(name) + 1;
		Accname = new char[len];
		strcpy(Accname, name);
	}
	
	Account() {
		Accnum = 0;
		Accname = NULL;
		Accmoney = 0;
	} //객체 배열 선언을 위한 생성자
	
	void AddMoney(int num) {
		Accmoney += num;
	}
	
	void SubMoney(int num) {
		Accmoney -= num;
	}
	
	void PrintAccount() const {
		cout<<"계좌ID: "<<Accnum<<endl;
		cout<<"이름: "<<Accname<<endl;
		cout<<"잔액: "<<Accmoney<<endl;
	}
	
	~Account() {
		delete[] Accname;
	}
};

int main(void) {
	Account *acc[MAX];
	int index = 0;

	while (1) {
		func::ShowMenu();
		
		int choice;
		cin >> choice;

		if (choice == 1) {
			int num, money;
			char* name = new char[MAX];
			func::GetAccount(num, name, money);
			acc[index] = new Account(num, name, money);
			index++;
			cout<<endl;
		}
		else if (choice == 2) {
			func::DepositMenu(acc);
			cout<<endl;
		}
		else if (choice == 3) {
			func::WithdrawMenu(acc);
			cout<<endl;
		}
		else if (choice == 4) {
			Print(acc);
			cout<<endl;
		}
		else if (choice == 5) {
			break;
		}
	}

	return 0;
}