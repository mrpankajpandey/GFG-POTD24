/*

Author : mrpankajpandey
Date : 09/05/2024
Problem : Divisor Game
Difficulty : Easy
Problem Link :https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1
Video Solution : NA

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool divisorGame(int n) {
        // code here
      
        // code here
        return n%2==0;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends