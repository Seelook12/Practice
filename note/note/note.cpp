// note.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

 class BB
{
public:
	int c;

	BB(int a)
	{
		c = a;
	}

	int add(int a, int b)
	{
		return a + b + c;
	}
};
//
 int ddd(int a)
 {
	 return a + 4;
 }

int main()
{	

	int d;
	int (BB::*a)(int, int) = &BB::add;

	int(*aa)(int);
	aa = ddd;








    return 0;
}

