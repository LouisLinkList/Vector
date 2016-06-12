#include <iostream>
using namespace std;

template <typename T>
class MyVector{
	T * MyVectorPtr = NULL;
	int size;
	int top;
public:
	MyVector(){
		size = 0;
		top = -1;
	}
	MyVector(int _size) : size(_size){
		MyVectorPtr = new T[size];
		top = -1;
	}
	MyVector(MyVector<T>& temp){
		size = temp.size;
		top = temp.top;
		MyVectorPtr = new T[size];
		for (int i = 0; i < size; ++i)
			MyVectorPtr[i] = temp[i];
	}
	MyVector(T* temp, size_t _size){
		size = _size;
		top = size - 1;
		MyVectorPtr = new T[size];
		for (int i = 0; i < size; ++i)
			MyVectorPtr[i] = temp[i];
	}

	bool push(T item){
		if (top == size - 1)
			return false;
		MyVectorPtr[++top] = item;
		return true;
	}
	bool pop(){
		if (top == -1)
			return false;
		MyVectorPtr[top--] = 0;
		return true;
	}

	MyVector& operator=(MyVector& _temp){

		return this;
	}

	int GetSize(){ return size; }
	T& operator[](int i){ return MyVectorPtr[i]; }
	//friend ostream& operator<<(ostream& os, MyVector<char>& vect);

};

ostream& operator<<(ostream& os, MyVector<int>& vect){
	for (int i = 0; i < vect.GetSize(); ++i)
		os << vect[i];

	return os << '\n';
}

ostream& operator<<(ostream& os, MyVector<char>& vect){
	for (int i = 0; i < vect.GetSize(); ++i)
		os << vect[i];
	return os << '\n'; }

#include <vector>
int main(int argc, char **argv) {

	MyVector<char> a("privet", 6);

	a.pop();
	a.pop();
	a.pop();
	a.push('s');
	a.push('e');
	a.push('t');
	a.push('s');
	cout << a;

	system("pause");
	return 0;
}
