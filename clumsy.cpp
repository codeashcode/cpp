#include <iostream>


using namespace std;


int clumsyFactorial(int n, int total) {

	int newTotal;

	if(n==0) newTotal = 0;
	if(n==1) newTotal = 1;
	if(n==2) newTotal = 2;
	if(n==3) newTotal = 6;

	if(n<=3) {
		if(total == 1)
			return newTotal;
		else
			return total-newTotal;
	}
	
	if(total ==1) {
		total = ((n*(n-1))/(n-2)) + (n-3);
	} else {
		newTotal = (((n*(n-1))/(n-2))-(n-3));
		cout <<"newTotal:" <<newTotal <<endl;
		total = total - newTotal;
	}

	cout <<"toal:"<<total<<"n:"<<n-4 <<endl;
	
	return clumsyFactorial(n-4, total);
}


int main() {

	int n = 8;

	cout<<"n:"<<n<<" has clumsyFactorial:"<<clumsyFactorial(n, 1) << endl;
	return 0;
}