#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string in = "UORDO RKSX KQKB USCS MROOJ UY NSV CO MRKRY ... DY ZEBS UKSXKDR ECCO DEWCO WSVKXO US UYCRSCR WOSX VKQ TKKDS RKS";

    for (int tries = 1; tries <= 26; ++tries)
    {
        string result = in;

        for (int i = 0; i < in.size(); ++i)
        {
            if (!isalpha(result[i])) continue;

            int ch = result[i] - 'A';

            ch = (ch + (26 - (tries - 1))) % 26;

            result[i] = ch + 'A';
        }

        cout << "KEY: " << tries << " " << result << endl;
    }

}
