#include<bits/stdc++.h>
using namespace std;

 bool isPalindrome(string s, int end, int start){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
  void func(int index, vector<string> &path, vector<vector<string>> &ans, string s){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, i, index)){
                path.push_back(s.substr(index, i-index+1));
                func(i+1,path, ans, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, path, ans, s);
        return ans;
    }
int main(){
    string str = "aab";
    //  string str = "nitin";
    vector<vector<string>> sol = partition(str);
    for(int i=0; i<sol.size(); i++){
        for(int j=0; j<sol[i].size(); j++)
        {
            cout << sol[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
