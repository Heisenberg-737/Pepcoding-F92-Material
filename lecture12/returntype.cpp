#include <iostream>
#include <vector>

using namespace std;

//=============================================================

string removeHi(string str)
{
    if (str.length() == 0)
        return "";

    char ch = str[0];

    if (str.length() > 1 && str.substr(0, 2) == "hi")
        return removeHi(str.substr(2));
    else
        return ch + removeHi(str.substr(1));
}

string saveHit(string str)
{
    if (str.length() == 0)
        return "";

    char ch = str[0];

    if (str.length() > 1 && str.substr(0, 2) == "hi")
        if (str.length() > 2 && str[2] == 't')
            return "hit" + saveHit(str.substr(3));
        else
            return saveHit(str.substr(2));

    else
        return ch + saveHit(str.substr(1));
}

void removedupli(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    if (ans[ans.length() - 1] != str[0])
        ans += str[0];

    removedupli(str.substr(1), ans);
}

vector<string> subseq(string str)
{
    if (str.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = str[0];

    vector<string> smallAns = subseq(str.substr(1));
    vector<string> myAns(smallAns);

    for (string s : smallAns)
        myAns.push_back(ch + s);

    return myAns;
}

vector<string> permutation(string str)
{
    if (str.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = str[0];
    vector<string> smallAns = permutation(str.substr(1));
    vector<string> myAns(smallAns);

    for (string s : smallAns)
    {
        for (int i = 0; i <= s.length(); i++)
        {
            string str1 = s.substr(0, i) + ch + s.substr(i);
            myAns.push_back(str1);
        }
    }

    return myAns;
}

void basic()
{
    // cout << removeHi("ihhhhihhhiiiihihihihih") << endl;
    //cout << saveHit("hihihitii") << endl;

    // removedupli("aaaabbbccdeeff", "");

    // vector<string> ans = subseq("abcd");

    vector<string> ans = permutation("abc");

    for (string s : ans)
        cout << s << endl;
}

//============================================================================================================

vector<string> mazePathSimple(int sr, int sc, int er, int ec)
{

    if (sc == ec && sr == er)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    if (sc + 1 <= ec)
    {
        vector<string> Horizontal = mazePathSimple(sr, sc + 1, er, ec);

        for (string s : Horizontal)
        {
            myAns.push_back("H" + s);
        }
    }

    return myAns;
}

vector<string> mazePathDiagnol(int sr, int sc, int er, int ec)
{

    if (sc == ec && sr == er)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    if (sc + 1 <= ec)
    {
        vector<string> Horizontal = mazePathSimple(sr, sc + 1, er, ec);

        for (string s : Horizontal)
        {
            myAns.push_back("H" + s);
        }
    }

    if (sr + 1 <= er)
    {
        vector<string> Vertical = mazePathSimple(sr + 1, sc, er, ec);

        for (string s : Vertical)
        {
            myAns.push_back("V" + s);
        }
    }

    return myAns;
}

void mazePath()
{
    vector<string> ans = mazePathSimple(0, 0, 3, 3);

    for (string s : ans)
        cout << s << endl;
}

//===============================================================================================================

vector<string> words = {"_", "+-/", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "*()%", "#@$"};

vector<string> nokiakeypad(string num)
{
    if (num.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    char ch = num[0];

    string word1 = words[ch - '0'];

    vector<string> onechar = nokiakeypad(num.substr(1));

    for (string s : onechar)
    {
        for (int i = 0; i < word1.length(); i++)
        {
            myAns.push_back(word1[i] + s);
        }
    }

    if (num.length() > 1 && ch != '0')
    {
        int n = (ch - '0') * 10 + (num[1] - '0');

        if (n < 12)
        {
            string word2 = words[n];
            vector<string> SecRes = nokiakeypad(num.substr(2));
            for (string s : SecRes)
            {
                for (int i = 0; i < word2.length(); i++)
                {
                    myAns.push_back(word2[i] + s);
                }
            }
        }
    }

    return myAns;
}

//===============================================================================================================

vector<string> encoding(string num)
{
    if (num.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    char ch = num[0];

    if (ch == '0')
    {
        return encoding(num.substr(1));
    }

    char word1 = (char)(ch - '1' + 'a');

    vector<string> onechar = encoding(num.substr(1));

    for (string s : onechar)
    {
        myAns.push_back(word1 + s);
    }

    if (num.length() > 1)
    {
        int n = (ch - '0') * 10 + (num[1] - '0');

        if (n <= 26)
        {
            char word2 = (char)(n + 'a' - 1);
            vector<string> SecRes = encoding(num.substr(2));
            for (string s : SecRes)
            {
                myAns.push_back(word2 + s);
            }
        }
    }

    return myAns;
}
//===============================================================================================================

bool is_valid(int x, int y, vector<vector<bool>> &board)
{
    if (x < 0 || y < 0 || x > board.size() || y > board[0].size() || board[x][y])
        return false;
    else
        return true;
}

vector<vector<int>> direction = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
vector<string> dir = {"R", "1", "U", "2", "L", "3", "D", "4"};

int floodFill(int sr, int sc, int er, int ec, vector<vector<bool>> &board, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    board[sr][sc] = true;

    for (int d = 0; d < 8; d++)
    {
        int x = sr + direction[d][0];
        int y = sc + direction[d][1];

        if (is_valid(x, y, board))
        {
            count += floodFill(x, y, er, ec, board, ans + dir[d]);
        }
    }

    board[sr][sc] = false;

    return count;
}
//===============================================================================================================
void solve()
{
    // basic();
    // mazePath();

    /* 
    vector<string> ans = nokiakeypad("110089");
    for (string s : ans)
        cout << s << endl;
    
    */
    vector<string> ans = encoding("10011");
    for (string s : ans)
        cout << s << endl;

    /*
    vector<vector<bool>> board(5, vector<bool>(5, false));

    cout << floodFill(0, 1, 4, 3, board, "") << endl;
    */
}

int main(int args, char **argv)
{
    solve();
}