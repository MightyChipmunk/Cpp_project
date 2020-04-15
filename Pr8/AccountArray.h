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
	/*AccountHandler Ŭ������ �����ü�� �Ǵ�
	�迭Ŭ������ �����ڿ� ���ڸ� �ѱ���� ��� ����Ʈ�� ����*/
	ACCOUNT_PTR &operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
