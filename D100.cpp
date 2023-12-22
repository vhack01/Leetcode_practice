#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string temp = "";
        path = path + "/";
        cout << "path: " << path << endl;
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                cout << "temp : " << temp << endl;
                if (temp == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else if (temp == ".")
                {
                }
                else
                {
                    if (temp.size() > 0)
                    {
                        cout << "in : " << temp << endl;
                        st.push(temp);
                    }
                }
                temp = "";
            }
            else
            {
                temp += path[i];
            }
        }

        cout << "size: " << st.size() << endl;
        string ans = "";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans.size() == 0)
            ans = "/";
        return ans;
    }
};

int main()
{
    system("cls");
    Solution s;
    string str =
        // "/a/./b/../../c/";
        // "/a/../../b/../c//.//";
        // "/../";
        // "/home//foo/";
        // "/home/.../../";
        // "/..hidden";
        "/a//b////c/d//././/..";
    cout
        << "result: " << s.simplifyPath(str);
}
