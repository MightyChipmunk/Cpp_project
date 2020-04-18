#include "AccountArray.h"
#include "BankingCommonDecl.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray() {
	arrlen = MAX;
	arr = new ACCOUNT_PTR[arrlen]; //저장의 대상이 Account 객체의 주소 값이기 때문에 ACCOUNT_PTR 배열을 생성
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
} //const함수에서 호출하기 위해 const의 선언유무로 오버로딩

int BoundCheckAccountPtrArray::GetArrLen() const {
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
	delete[] arr;
}
