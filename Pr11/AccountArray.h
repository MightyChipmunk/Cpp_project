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
	/*AccountHandler Ŭ������ �����ü�� �Ǵ�
	�迭Ŭ������ �����ڿ� ���ڸ� �ѱ���� ��� ����Ʈ�� ����*/
	T &operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray() {
	arrlen = MAX;
	arr = new T[arrlen]; //������ ����� Account ��ü�� �ּ� ���̱� ������ ACCOUNT_PTR �迭�� ����
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
} //const�Լ����� ȣ���ϱ� ���� const�� ���������� �����ε�

template <class T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[] arr;
}