#include <iostream>

using namespace std;

int main(){
	int a1,b1,a2,b2;
	double gunnar,emma;

	cin >> a1 >> b1 >> a2 >> b2;
	gunnar = (a1+b1) /(double)(2) + (a2 + b2) / (double)(2);
	
	cin >> a1 >> b1 >> a2 >> b2;
	emma = (a1+b1) /(double)(2) + (a2 + b2) / (double)(2);

	if (emma == gunnar) cout << "Tie" << endl;
	else if(emma > gunnar) cout << "Emma" << endl;
	else cout << "Gunnar" << endl;

	return 0;
}