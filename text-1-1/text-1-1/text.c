#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int* p = malloc(10 * sizeof(int));
//	if (p == NULL);
//	{
//		return 0;
//	}
//	int* ps = realloc(p, 80);
//	if (ps != NULL)
//	{
//		p = ps;
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}



//int main()
//{
//	int* p = realloc(NULL, 20);
//
//	free(p);
//	p = NULL;
//	return 0;
//}


//题目2
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//请问运行Test 函数会有什么样的结果？
//返回局部变量或临时变量的地址: p      会乱码




//题目3
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//改正
//	//free(str);
//	//str=NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//请问运行Test 函数会有什么样的结果？
//代码会运行，但是动态开辟的内存没有释放，导致内存泄漏了






//题目4
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free释放str指向的空间后，并不会吧str置为NULL
//	//str=NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}




//柔性数组
struct S
{
	int a;
	int* arr;
};
int main()
{
	struct S* ps = malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//调整大小
	int* ptr = realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}