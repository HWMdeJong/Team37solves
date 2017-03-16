#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

double eps = 1e-12;

struct State{
	double s;

	bool operator<(const State &rhs) const{
		return	s + eps < rhs.s; //good
	}
};

map<State,bool> mem; //memaries
vector<double> guns (6, 0.0);
double minigun;

int N, K;
double X;

bool solve(State &s){
	//base  case
	if(mem.find(s) != mem.end()){
		return mem[s];
	}
	if(s.s * minigun <= 1 + eps) return true;

	//moveset
	bool result = false;
	for(int i = 0 ; i < K; i++){
		State nxt = s;
		nxt.s *= guns[i];
		result |= !solve(nxt);
	}

	//save
	mem[s] = result;
	return mem[s];
}

int main(){
	cin >> N;
	while(N--){
		//Readin problem
		//cout << "WTF" << endl;
		cin >> X >> K;
		mem.clear();
		minigun = 1;
		//guns.assign(K, 0.0);
		for(int i = 0; i < K; i++){
			cin >> guns[i];
			if(minigun > guns[i]){
				minigun = guns[i];
			}
		}
		//cout << "Hey" << endl;
		State s = {X};
		solve(s) ? cout << "Nils" : cout << "Mikael";
		cout << endl;
		/*for(pair<const State,bool> &p : mem){
			cout << p.first.s << " " << p.second << endl;
		}*/
	}

	return 0;
}