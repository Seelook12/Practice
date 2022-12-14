

#include "stdafx.h"
#include <memory>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

namespace kkk {
	template<typename T>
	class vector
	{	
	private:
		T * arr;
		int v_size;
		int v_cap;


	public:


		vector(int size = 0) {
			v_cap = size + 1000;
			arr = new T[v_cap]();
			v_size = size;
		}

		vector(int size, const T value) {
			v_cap = size + 1000;
			arr = new T[v_cap]();
			v_size = size;
			for (register int i = 0; i < v_size; ++i) {
				arr[i] = value;
			}
		}

		vector(const vector& v) {
			if (arr != NULL) {
				delete[] arr;
			}
			arr = new T[v.v_cap]();
			for (int i = 0; i < v.v_size; ++i) {
				arr[i] = v.arr[i];
			}
		}

		~vector() {
			if (arr != NULL)
			{
				delete[] arr;
			}
		}

		void push_back(const T value) {
			
			if (v_size < v_cap){
			}
			else {
				v_cap = v_cap * 2;
				T *tump = new T[v_cap];

				for (int i = 0; i < v_size; i++) {
					tump[i] = arr[i];
				}
				delete[] arr;
				arr = tump;
			}
			arr[v_size] = value;
			v_size += 1;
		}
		


		T& operator [] (int idx) {
			return arr[idx];
		}

		int size(){
			return v_size;
		}

		int cap(){
			return v_cap;
		}

		T* begin() {									
			return arr;
		}
		T* end() {
			return arr + (v_size-1);
		}


	};




}


using namespace std;

#include <fstream>
#include <sstream>
#include <istream>
#include <io.h>


bool compare(string a, string b, int num)
{
	string aa;
	string bb;
	float aaa;
	float bbb;
	istringstream iss(a);
	for (int i = 0; i < num; i++)
	{
		getline(iss, aa, ',');
	}

	istringstream iss1(b);
	for (int i = 0; i < num; i++)
	{
		getline(iss1, bb, ',');
	}

	aaa = stof(aa);
	bbb = stof(bb);

	return aaa < bbb;


};

int main()
{


	kkk::vector<string> data;
	string str_buf;
	fstream f;


	f.open("222.scv", ios::in);
	while (!f.eof()) {
		getline(f, str_buf);
		data.push_back(str_buf);
	}



	std::cout << data[1] << std::endl;


	


    return 0;
}

