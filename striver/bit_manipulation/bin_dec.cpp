#include <bits/stdc++.h>
using namespace std;

string dec_to_bin(int num)
{
    string res = "";

    while (num != 1)
    {
        num % 2 == 0 ? res = res + "0" : res += "1";
        num /= 2;
    }
    res += "1";

    reverse(res.begin(), res.end());
    return res;
}

int bin_to_dec(string bin)
{
    int num = 0;
    int n = bin.size() - 1;
    for (char ch : bin)
    {
        if (ch == '0')
        {
            n -= 1;
            continue;
        }
        num += 1 * (pow(2, n));
        n -= 1;
    }
    return num;
}

int main()
{

    string res = dec_to_bin(13);
    cout << res << endl;
    string inp;
    cin >> inp;
    cout << bin_to_dec(inp) << endl;
    return 0;
}