#include <iostream>
#include <stdio.h>
#include <string.h>
#define LEN_MAX 64
char* findC(char const* source, char const* obj) {
	int size_source = strlen(source), size_obj = strlen(obj),i;
	bool flag;
	char* idx = nullptr;
	for (i = 0; i <= (size_source - size_obj); i++)
	{//Iterate over the source string
		flag = true;
		idx = (char*)source + i;
		for (int j = 0; j < size_obj; j++)
		{//Iterate over the object string
			if (*idx != *(obj + j))
			{
				flag = 0;
				break;
			}
			idx++;
		}
		if (flag) {
			break;
		}
	}
	if (!flag)
		return nullptr;
	else
		return (char*)source + i;
}
int main()
{
	char s1[LEN_MAX], s2[LEN_MAX];
	char* res;
	for (;;) {
		std::cout << "Please enter two strings" << std::endl;
		std::cin >> s1 >> s2;
		res = findC(s1, s2);
		if (res == nullptr)printf("no such sub string\r\n");
		else printf("%c\r\n", *res);
	}
}

