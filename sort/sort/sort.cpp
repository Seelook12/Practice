// sort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <io.h>
#include <istream>
#include <stdio.h>
#include <sstream>

using namespace std;

int column_to_compare;

bool comp(string a, string b)
{
	string aa;
	string bb;

	float aaa;
	float bbb;
	istringstream iss(a);
	for (int i = 0; i < column_to_compare+1; i++)
	{
		getline(iss, aa, ',');
	}

	istringstream iss1(b);
	for (int i = 0; i < column_to_compare +1; i++)
	{
		getline(iss1, bb, ',');
	}


	try {
		aaa = stof(aa);
		bbb = stof(bb);
	}
	catch (invalid_argument&)
	{
		printf("정렬할 칼럼이 숫자가 아니거나 너무 큰 숫자입니다.");
		cout << aa << bb;
		return 0;
	}


	return aaa < bbb;
}

int main(int argc, char *argv[])
{
	int column_name_exists = 0;
	string address;
	string new_address;
	string column_to_compare1;


	if (argc != 4)
	{
		printf("ex) sort.exe file.csv file_edit.csv 1  ///  번환할파일 생성될파일 정렬할컬럼");
		return 0;
	}


	address = argv[1];
	new_address = argv[2];
	column_to_compare1 = argv[3];


	if ((_access(address.c_str(), 0) == -1))
	{
		printf("%s 파일이 존재하지 않습니다. 다시 입력해주세요.\n", address.c_str());
		return 0;
	}
	else
	{
		if ((_access(address.c_str(), 4) == -1)) {
			printf("%s 파일에 읽기 권한이 없습니다.\n", address.c_str());
			return 0;
		}
		else {

			if ((_access(new_address.c_str(), 0) != -1)) {
				printf("%s 이름의 동일한 파일이름이 존재합니다.\n", new_address.c_str());
				return 0;
			}
			else {
			}
		}
	}



	fstream f;

	string str_buf;

	column_to_compare = stoi(column_to_compare1);

	vector<string> data;

	f.open(address, ios::in);
	while (!f.eof()) {
		getline(f, str_buf);
		data.push_back(str_buf);
	}
	f.close();


	std::sort(data.begin(), data.end(), comp);


	////////////////////////////////////////////////// 파일에 저장
	ofstream File(new_address);

	for (int i = 0; i < data.size(); i++)
	{
		File << data[i] << endl;

	}

	printf("%s 생성완료", new_address.c_str());



	return 0;
}