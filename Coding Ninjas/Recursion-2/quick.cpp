/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
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

void print(int* input, int n){
	for (int i = 0; i < n; ++i)
	{
		cout << input[i] << ' ';
	}
	cout <<  '\n';
}

int partition(int *input, int start, int end, int n){
	int element = input[start];
	int small_count = 0;
	for (int i = start; i <= end; ++i)
	{
		if (input[i]<element)
		{
			small_count++;
		}
	}

	swap(input[start], input[start+small_count]);
	// if (element ==3)
	// {
	// 	print(input, 3);
	// 	cout << small_count << '\n';
	// }

	int i = start;
	int j = start+small_count+1;
	int pivot = start+small_count;

	while(i<pivot && j<=end){
		if (input[i]>=element && input[j]<element)
		{
			swap(input[i], input[j]);
			i++;
			j++;
		}else if (input[i]>=element)
		{
			j++;
		}else{
			i++;
		}
	}


	return pivot;


}

void helper(int* input, int start, int end, int n){
	if (n==1 || n==0)
	{
		return;
	}

	int pivot = partition(input, start, end, n);
	helper(input, start, pivot-1, pivot-start);
	helper(input, pivot+1, end, end-pivot);
}



void quickSort(int* input , int n){

	helper(input, 0, n-1, n);
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	 int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    // cout <<   '\n';
    
    delete [] input;

	return 0 ; 

}

