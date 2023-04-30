#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a = {1,2,3};
	vector<int> b = {2,1,3};

	cout << boolalpha;  

	cout << "Is a sorted : " << is_sorted(a.begin(),a.end()) << "\n";
	cout << "Is b sorted : " << is_sorted(b.begin(),b.end()) << "\n";

	cout << "Is b permutation of a: " << is_permutation(a.begin(),a.end(), b.begin()) << "\n";
}
