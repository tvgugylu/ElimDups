// ElimDups.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word,
	const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

void biggies(vector<string> &words, vector<string>::size_type sz,
	ostream &os = cout, char c = ' ')
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
		 bind(isShorter, _1, _2));
	auto wc = find_if(words.begin(), words.end(),
		bind(check_size,_1,sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	/*for_each(wc, words.end(),
		[&os,c](const string &s) {os << s << c;});*/
	for_each(wc, words.end(),
		bind(print,ref(os),_1,' '));
	cout << endl;
}

int main()
{
	vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(words, 4);
	return 0;
}

