#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long countSubsequence(const string& source,const string& target)
{
    int n = source.size();//j
    int m = target.size();//i
    vector<vector<long long>> dp(n + 1,vector<long long>(m + 1,0));
    for(int j = 0;j < n + 1;j++)
}
int main()
{
    string abbrs[5] = {"CCNU","HUST","HZAU","WHU","WHUT"};
    string s;
    cin >> s;
    string best_abbr;
    long long best_count = -1;
    for(const string& abbr : abbrs)
    {
        long long cnt = countSubsequence(s,abbr);
    }
    return 0;
}