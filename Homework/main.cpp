#include <iostream>
using namespace std;

class String {
private:
	char* str;
	int size;
public:
	String() : String(80) {}
	String(int size) : size(size) {
		str = new char[size + 1];
		str[0] = '\0';
	}
	String(const String& other) : size(other.size) {
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = other.str[i];
		}
		str[size] = '\0';
	}
	String& operator= (const String& b) {
		if (this == &b) {
			return *this;
		}
		if (str != nullptr) {
			delete[] str;
		}
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = b.str[i];
		}
		str[size] = '\0';
		return *this;
	}
	String(const char* inputStr) {
		size = 0;
		while (inputStr[size] != '\0') {
			size++;
		}
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = inputStr[i];
		}
		str[size] = '\0';
	}
	String(String&& b) {
		str = b.str;
		b.str = nullptr;
	}
	String& operator= (String&& b) {
		str = b.str;
		b.str = nullptr;
		return *this;
	}
	~String() {
		delete[] str;
	}
	void MyStrcpy(String& obj) {
		int i = 0;
		while (str[i] != '\0') {
			obj.str[i] = str[i];
		}
		obj.str[i] = '\0';
	}
	bool MyStrStr(const char* string) {
		int length = 0;
		while (string[length] != '\0') {
			length++;
		}
		if (length == 0) {
			return true;
		}
		for (int i = 0; i <= size - length; i++) {
			int j = 0;
			while (j < length && str[i + j] == string[j]) {
				j++;
			}
			if (j == length) {
				return true;
			}
		}
		return false;
	}
	int MyChr(char c) {
		int i = 0;
		while (str[i] != '\0') {
			if (str[i] == c) {
				return i;
			}
			i++;
		}
		return -1;
	}
	int MyStrLen() {
		int length = 0;
		while (str[length] != '\0') {
			length++;
		}
		return length;
	}
	void MyStrCat(String& b) {
		int new_size = size + b.size;
		char* new_str = new char[new_size + 1];
		for (int i = 0; i < size; i++) {
			new_str[i] = str[i];
		}
		for (int i = 0; i < size; i++) {
			new_str[size + i] = b.str[i];
		}
		new_str[new_size] = '\0';
		delete[] b.str;
		b.str = new_str;
		size = new_size;
	}
	void MyDelChr(char c) {
		int new_size = 0;
		for (int i = 0; i < size; i++) {
			if (str[i] != c) {
				str[new_size++] = str[i];
			}
		}
		str[new_size] = '\0';
		size = new_size;
	}
	int MyStrCmp(String& b) {
		if (size > b.size) {
			return 1;
		}
		else if (size < b.size) {
			return -1;
		}
		else {
			return 0;
		}
	}
	void input() {
		char InputP[1000];
		cout << "Enter your text: ";
		gets_s(InputP);
		int size_i = 0;
		while (InputP[size_i] != '\0') {
			size_i++;
		}
		size = size_i;
		delete[] str;
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = InputP[i];
		}
		str[size] = '\0';
	}
	void Output() {
		cout << str << endl;
	}
};

int main() {
	String str1;
	str1.input();
	str1.Output();
	/*str1.MyDelChr('w');
	str1.Output();*/
	String str2 = move(str1);
	str2.Output();
	/*str2.input();
	str2.Output();
	cout << "Result : " << str1.MyStrCmp(str2) << endl;*/
	//str1.MyStrCat(str2);
	//str2.Output();
	/*cout << "Lenght string: " << str1.MyStrLen() << endl;
	const char* text = "way";
	cout << "Result: " << str1.MyStrStr(text) << endl;
	char c = 'w';
	cout << "Result: " << str1.MyChr(c) << endl;*/
}