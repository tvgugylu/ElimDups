// ElimDups.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

void fcn3()
{
	size_t v1 = 42;
	auto f = [v1]() mutable {return ++v1;};
	v1 = 0;
	auto j = f();
}

int main()
{
	fcn3();
	return 0;
}

