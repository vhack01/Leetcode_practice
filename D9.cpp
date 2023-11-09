// #include <iostream>
// #include <climits>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int cost(string &a, string &b)
    {
        int val = 0;
        for (int i = 0; i < a.size(); i++)
        {
            val += abs(a[i] - b[i]);
        }
        return val;
    }

    int minimum_difference(int n, vector<string> &words)
    {
        int a = 0, b = 1, ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (i > 1)
            {
                int alen = 0, blen = 0;
                alen = cost(words[a], words[i]);
                blen = cost(words[b], words[i]);

                if (alen < blen && alen < ans)
                {
                    b = i;
                    ans = alen;
                }
                else if (blen < alen && blen < ans)
                {
                    a = b;
                    b = i;
                    ans = blen;
                }
            }
            else
            {
                ans = min(ans, cost(words[a], words[i]));
                b = i;
            }
        }
        cout << "ans: " << ans << endl;
    }
};

int main()
{
    system("cls");
    Solution s;
    int n = 5;
    vector<string> words = {
        "bqzrdzrr",
        "zyqvkaso",
        "mhmpjwwj",
        "ppdebupe",
        "zvqhrmmj",
        "ebllzxgh",
        "qjttlufs",
        "kbfqnmxu",
        "samuvxac",
        "ybjcveux",
        "czpnbfbq",
        "lzgapkgz",
        "nubkmtyo",
        "udbqnekg",
        "ocdgnaxf",
        "dnjgnhxx",
        "gxtuybws",
        "uufbmabq",
        "dfdpawol",
        "sfldujge",
        "zubvkcdu",
        "rafqvafy",
        "oedktkfk",
        "wwaurqej",
        "kwopqqtg",
        "vgctxeie",
        "flkgkaul",
        "cbsyehfn",
        "isfphhuy",
        "qdtsryex",
        "enfdrysw",
        "dlzunzxh",
        "ysftmsql",
        "xidfbnzo",
        "mknsdwvl",
        "mkqzyixl",
        "lxqrecyi",
        "bdjqjeyx",
        "frxpjsqv",
        "lzlxtrdj",
        "nammaltt",
        "srllnphd",
        "qsmszhav",
        "qutilujw",
        "cuebhbql",
        "mxakwmtp",
        "hedwolbz"};
    s.minimum_difference(words.size(), words);
}