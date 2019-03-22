#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>


using namespace std;

void print_num(int id, int max) {

}

void run() {
	unique_lock<mutex> mtx;
	mtx.

}
int main() {

	int numofthreads = 10;

	thread threads[numofthreads];

	for(int i=0; i< numofthreads; i++)
		threads[i] = thread(print_num, i, numofthreads);


	return 0;
}