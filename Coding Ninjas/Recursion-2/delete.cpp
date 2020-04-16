/*
                Name: Mehul Chaturvedi
                IIT-Guwahati
*/
/*
                PROBLEM STATEMENT
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
int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 
    
    double h1, e, t, interval;
    cin>>h1>>e>>t>>interval;

    double l = sqrt((2*h1)/(9.81));

    vector<pair<double, double>> result;
    double time = 0;
    int cycle = 0;
    int fall = 1;
    double time_gone = 0;
    double max_height = h1;
    double speed_from_ground = 0;
    double iterations = 2*t/interval;
    // cout<<iterations;
    // return 0;

    while(time<=t){
        if (fall==1)
        {
            double less_then = time_gone + l*pow(e, cycle);
            for (; time <= less_then && time<=t;)
            {
                double height = max_height-0.5*9.81*(time-time_gone)*(time-time_gone);
                result.push_back({height, time});
                time+=interval;
            }
            if (time>=t)
            {
                break;
            }
            
            fall=0;
            time_gone += l*pow(e, cycle);
            time = time_gone;

            cycle++;
            speed_from_ground = e*sqrt(2*9.81*max_height);
        }

        if (fall == 0)
        {
            double less_then = time_gone + l*pow(e, cycle);
            // cout<<less_then<<endl;
            for ( ; time <= less_then && time<=t; )
            {
                double height = (time-time_gone)*(e*sqrt(2*9.81*max_height))-0.5*((time-time_gone)*(time-time_gone))*9.81;
                result.push_back({height, time});
                time+=interval;
            }
            if (time>=t)
            {
                break;
            }
            max_height = e*e*max_height;
            time_gone += l*pow(e, cycle);
            time = time_gone;
            fall = 1;
        }        
    }

    for (int  i = 0; i < result.size(); i++)
    {
        cout<<result[i].f<<" "<<result[i].s<<endl;
    }
    


    return 0 ; 
}