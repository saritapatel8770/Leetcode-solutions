#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> idx;
        int ans = 0,n = s.length();

        idx.push(-1);

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push('(');
                idx.push(i);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    idx.pop();
                    ans = max(ans, i - idx.top());
                }
                else{
                    idx.push(i);
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}