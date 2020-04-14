/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
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


void helper(string input, string output){
	int n = input.size();
	if (n==0)
	{
		cout << output << '\n';
		return;
	}
	if (input.size()==1)
	{
		// cout << int('z') << '\n';
		cout << output+char(input[0]-'1'+'a')<< '\n';
		return ;
	}

	string output1 = output+char(input[0]-'1'+'a');
	helper(input.substr(1,n-1), output1);

	if (10*(input[0]-'0')+(input[1]-'0')<=26)
	{
		string output2 = output+char('a'-1+10*(input[0]-'0')+(input[1]-'0'));
		// debug(10*(input[0]-'0')+(input[1]-'0'))
		helper(input.substr(2, n-2), output2);
	}


	return;
}

void printAllPossibleCodes(string input){
	string output = "";
	helper(input, output);
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	string input;
    cin >> input;

    printAllPossibleCodes(input);

	return 0 ; 
}

