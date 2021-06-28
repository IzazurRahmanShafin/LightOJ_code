#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, caseno = 0;
    cin >> T;
    
    while (T--)
    {
        stack<string> br, temp;
        string x = "http://www.lightoj.com/";
        br.push(x);
        printf("Case %d:\n", ++caseno);
        while(1)
        {
            string cmd, webs;
            cin >> cmd;
            int sz = br.size();
            if (cmd == "VISIT")
            {
                cin >> webs;
                br.push(webs);
                cout << br.top() << endl;
                while (!temp.empty()) temp.pop();
            } 
            else if (cmd == "BACK")
            {
                temp.push(br.top());
                br.pop();
                if(!br.empty()) cout << br.top() << endl;
                else
                {
                    cout << "Ignored\n";
                    br.push(temp.top());
                    temp.pop();
                }
            }
            else if(cmd == "FORWARD")
            {
                if (!temp.empty()) 
                { 
                    cout << temp.top() << endl;
                    br.push(temp.top());
                    temp.pop();
                }
                else cout << "Ignored\n"; 
            } else break;
        }
    }
}
