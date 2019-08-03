#include<iostream>
using namespace std;

int sprintf_s(char* buffer, size_t sizeOfBuffer, const char* format, char* s1, char* s2);

int sprintf_s(char* buffer, size_t sizeOfBuffer, const char* format, char* s1, char* s2)
{
	snprintf(buffer, sizeOfBuffer, format, s1, s2);

	// for test
	//puts(buffer);
}

int main()
{
	char* buffer = (char*)malloc(sizeof(buffer)*100);
	size_t sizeOfBuffer = 20;
	const char* format = "%s%s";
	char* s1 = {"Hello"};
	char* s2 = {"World!"};

	sprintf_s(buffer, sizeOfBuffer, format, "Hello", "World!");

	return 0;
}
