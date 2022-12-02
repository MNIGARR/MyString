#include <iostream>
using namespace std;

//MyString
//1)1 ci xarakter qaytaran method
//2)sonuncu xarakter qaytaran method 
//3) Append(const char* text)  
//4) s.rfind('a') 
//5)s.find('w')//6 xarakterin indexi qayitsin
//6)s.clear()//string silinsin delete edin

//class MyString {
//	char* string = nullptr;
//	int GetLength(const char* strg) {
//		int length = 0;
//		for (int i = 0; strg[i] != '\0'; i++) {
//			length++;
//		}
//		return length;
//	}
//public:
//	MyString() = default;
//
//	MyString(const char* strg) {
//		SetStrg(strg);
//	}
//
//	//Set, get
//	void SetStrg(const char* strg) {
//		delete[] strg;
//		int length = strlen(strg) + 1;
//		string = new char[length];
//		strcpy_s(string, length, strg);
//	}
//
//	const char* GetStrg() const {
//		return string;
//	}
//
//	char FindFirstChar() const {
//		return string[0];
//	}
//
//	char FindLastChar() {
//		int len = 0;
//		for (int i = 0; string[i] != '\0'; i++) {
//			len++;
//		}
//		return string[len - 1];
//	}
//
//	void AppendTxt(const char* text) {
//		if (string != nullptr) {
//			int size = GetLength(string);
//			int sizeOfText = GetLength(text);
//			char* newChArr = new char[size + sizeOfText];
//			for (int i = 0; i < size; i++) {
//				newChArr[i] = string[i];
//			}
//			int j = 0;
//			for (int i = 0; i < (size + sizeOfText); i++) {
//				newChArr[i] = text[j];
//				j++;
//			}
//			newChArr[size + sizeOfText] = '\0';
//			SetStrg(newChArr);
//		}
//		else {
//			SetStrg(text);
//		}
//	}
//	
//	void ClearChArr() {
//		delete[] string;
//	}
//};
//
//int main() {
//	MyString x;
//	x.AppendTxt("smthng");
//	
//}

//1. IntArray class - i yaradin.Bu class massiv rolunu
//oynamalidir.
//Novbeti imkanlar olsun :
//-Massivin evveline reqem elave eden method
//- Massivin sonuna reqem elave eden method
//- Massivi copy etmek imkani yaradin
//- Print

class IntArray {
	int size = 10;
	int* arr = new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
	IntArray() = default;

	IntArray(int s) {
		size = s;
		arr = new int[s] {};
	}

	IntArray(const IntArray& obj) {
		delete[] arr;
		size = obj.size;
		arr = new int[size] {};
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}

	void AddElementToHead(int num) {
		int* newArr = new int[size + 1]{};
		newArr[0] = num;
		for (int i = 0; i < size; i++) {
			newArr[i + 1] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		newArr = nullptr;
		size++;
	}
	void AddElementToEnd(int num) {
		int* newArr = new int[size + 1]{};
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		newArr[size] = num;
		delete[] arr;
		arr = newArr;
		newArr = nullptr;
		size++;
	}

	void ShowArray() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ",";
		}
	}
};

void main() {
	IntArray arr;
	arr.AddElementToHead(1);
	arr.AddElementToHead(2);
	arr.AddElementToEnd(3);
	arr.ShowArray();
}