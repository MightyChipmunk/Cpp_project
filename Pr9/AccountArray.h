#pragma once
#include "Account.h"
#include "BankingCommonDecl.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
private:
	ACCOUNT_PTR *arr;
	int arrlen;
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray &arr) {}
	BoundCheckAccountPtrArray &operator=(const BoundCheckAccountPtrArray &arr) {}
public:
	BoundCheckAccountPtrArray(); 
	/*AccountHandler 클래스의 멤버객체가 되는
	배열클래스의 생성자에 인자를 넘길수가 없어서 디폴트값 설정*/
	ACCOUNT_PTR &operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
