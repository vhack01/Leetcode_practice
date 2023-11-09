#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector <char> mergeString(n + m);
       int c = 0, d = 0, k = 0;
        bool flag=true;
        while (c < n && d < m)
        {
           if(flag) {
                mergeString[k++] = word1[c++];
                flag = false;
           }else{
             mergeString[k++] = word2[d++];
             flag = true;
           }
            
        }
        
        while (c < n) mergeString[k++] = word1[c++];
        while (d < m) mergeString[k++] = word2[d++];
        
        string str = "";
        for(char a : mergeString)
            str += a;
        return str;
        
    }
};

int main() {
    system("cls");
    string word1 = "aasdab";
    string word2 = "qr";
    cout << Solution::mergeAlternately(word1,word2);
}