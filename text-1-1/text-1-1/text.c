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


//��Ŀ2
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
//��������Test ��������ʲô���Ľ����
//���ؾֲ���������ʱ�����ĵ�ַ: p      ������




//��Ŀ3
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
//	//����
//	//free(str);
//	//str=NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//��������Test ��������ʲô���Ľ����
//��������У����Ƕ�̬���ٵ��ڴ�û���ͷţ������ڴ�й©��






//��Ŀ4
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free�ͷ�strָ��Ŀռ�󣬲������str��ΪNULL
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




//��������
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
	//������С
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