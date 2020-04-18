#include "AccountArray.h"
#include "BankingCommonDecl.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray() {
	arrlen = MAX;
	arr = new ACCOUNT_PTR[arrlen]; //������ ����� Account ��ü�� �ּ� ���̱� ������ ACCOUNT_PTR �迭�� ����
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
} //const�Լ����� ȣ���ϱ� ���� const�� ���������� �����ε�

int BoundCheckAccountPtrArray::GetArrLen() const {
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
	delete[] arr;
}
