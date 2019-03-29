#include<sstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

unsigned Add(unsigned, unsigned);

unsigned multiply(unsigned x, unsigned y) {
	unsigned sum = 0;

	while(x) {
		if(x&1) 
			sum = Add(sum,y);
		x = x>>1;
		y = y<<1;
	}
	return sum;
}

unsigned Add(unsigned a, unsigned b) {
	int sum = 0;
	int k =1;
	int atemp = a;
	int btemp = b;

	int carryIn = 0;
	while(atemp || btemp) {
		int ak = a & k;
		int bk = b & k;

		int carryout = (ak&carryIn) | (bk&carryIn) | (ak&bk);
		sum |= ak ^ bk ^ carryIn;
		carryIn = carryout <<1;
		atemp=atemp>>1;
		btemp=btemp>>1;
		k <<=1;
	}
	return sum | carryIn;
}

int main() {
	int x =4, y=3;
	cout <<x<<"*"<<y<<"="<<multiply(x,y) <<endl;
}