// ElimDups.cpp : 定义控制台应用程序的入口点。
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

void fcn4()
{
	size_t v1 = 42;
	auto f2 = [&v1] {return ++v1;};
	v1 = 0;
	auto j = f2();
}

int main()
{
	fcn3();
	fcn4();
	vector<int> vi = { 1,-2,3,-4,5,-6};
	transform(vi.begin(), vi.end(), vi.begin(),
		[](int i) {if (i < 0) return -i;else return i;});
	return 0;
}

