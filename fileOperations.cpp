#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

int main() {
	/*
	ofstream out("output.txt", ios::out| ios::binary);

	string 
	out.write() << endl<< "Hello World of file operation";
	out.close();


	ifstream in("output.txt", ios::in);

	in.seekg(10);
	string str;
	cout <<"reading from the file and out to stdout"<<endl;
	while(getline(in, str)) {
		cout << str <<endl;
	}
	*/

	long size;

	ifstream in("binaryFile.jpg", ios::binary|ios::ate);

	size = in.tellg();
	in.seekg(0,ios::beg);

	char *buffer = new char[size];

	in.read(buffer, size);

	cout <<"Complete buffer of size:"<<size<<" in file"<<endl;

	return 0;
}