#pragma once
#include "BankingCommonDecl.h"

template <class T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray &arr) {}
	BoundCheckArray &operator=(const BoundCheckArray &arr) {}
public:
	BoundCheckArray(); 
	/*AccountHandler 클래스의 멤버객체가 되는
	배열클래스의 생성자에 인자를 넘길수가 없어서 디폴트값 설정*/
	T &operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray() {
	arrlen = MAX;
	arr = new T[arrlen]; //저장의 대상이 Account 객체의 주소 값이기 때문에 ACCOUNT_PTR 배열을 생성
}

template <class T>
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
T BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
} //const함수에서 호출하기 위해 const의 선언유무로 오버로딩

template <class T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[] arr;
}