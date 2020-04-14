/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

Print Permutations - String
Send Feedback
Given a string, find and print all the possible permutations of the input string.
Note : The order of permutations are not important. Just print them in different lines.
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


void helper(string input, int l, int r){
	if (l==r)
	{
		cout << input << '\n';
		return;
	}

	for (int i = l; i < r+1; ++i)
	{
		swap(input[l], input[i]);
		helper(input, l+1, r);
		swap(input[l], input[i]);
		// cout <<  << '\n';
	}
}

//It will have reps
void printPermutations(string input){
	int n= input.size();
    helper(input, 0, n-1);
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string input;
    cin >> input;
    printPermutations(input);
    return 0;

}
