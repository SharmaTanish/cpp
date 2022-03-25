#include <bits/stdc++.h>
using namespace std;

signed main()
{

    string s;
    getline(cin, s);
    string t;
    getline(cin, t);
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] == s[i])
            {
                cnt++;
                int k = 0;
                while ((t[j] == s[i]))
                {
                    i++;
                    k++;
                    j++;
                }
                cnt += (t.size() - j);
                j = j - k;
                if (j > 0)
                {
                    cnt += (j);
                    cnt += 2;
                }
                // cout << cnt << endl;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}