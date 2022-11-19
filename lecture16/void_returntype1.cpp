#include <iostream>
#include <string>
#include <vector>

using namespace std;

void subseq(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    subseq(ques.substr(1), ans + ch);
    subseq(ques.substr(1), ans);
}

void Asciisubseq(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    int ch1 = ques[0];
    Asciisubseq(ques.substr(1), ans + ch);
    Asciisubseq(ques.substr(1), ans);
    Asciisubseq(ques.substr(1), ans + to_string(ch1));
}

void permutations_00(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    int arr[26] = {0};

    for (int i = 0; i < ques.length(); i++)
    {
        if (arr[ques[i] - 'a'] == 0)
        {
            arr[ques[i] - 'a'] = 1;
            char ch = ques[i];
            permutations_00(ques.substr(0, i) + ques.substr(i + 1), ans + ch);
        }
    }
}

void permutations_01(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    int arr;
    for (int i = 0; i < ques.length(); i++)
    {
        int mask = (1 << i);

        if ((arr & mask) == 0)
        {
            arr &= (~mask);
            char ch = ques[i];
            permutations_00(ques.substr(0, i) + ques.substr(i + 1), ans + ch);
        }
    }
}

//=====================================================================================================================================

void mazepath_01(int sr, int er, int sc, int ec, string ans)
{
    if (sc == ec && sr == er)
    {
        cout << ans << endl;
        return;
    }

    if (sr + 1 <= er)
    {
        mazepath_01(sr + 1, er, sc, ec, ans + "V");
    }

    if (sc + 1 <= ec)
    {
        mazepath_01(sr, er, sc + 1, ec, ans + "H");
    }
}

void mazepath_02(int sr, int er, int sc, int ec, string ans)
{
    if (sc == ec && sr == er)
    {
        cout << ans << endl;
        return;
    }

    if (sr + 1 <= er)
    {
        mazepath_02(sr + 1, er, sc, ec, ans + "V");
    }

    if (sc + 1 <= ec)
    {
        mazepath_02(sr, er, sc + 1, ec, ans + "H");
    }

    if (sc + 1 <= ec && sr + 1 <= er)
    {
        mazepath_02(sr + 1, er, sc + 1, ec, ans + "D");
    }
}

//=====================================================================================================================================

vector<string> words = {"_", "+-/", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "*()%"};

void nokia_keyword(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];

    string word1 = words[ch - '0'];

    for (int i = 0; i < word1.length(); i++)
    {
        nokia_keyword(ques.substr(1), ans + word1[i]);
    }

    if (ques.length() > 1 && ch != '0')
    {
        int num = ((ch - '0') * 10) + (ques[1] - '0');

        if (num < 12)
        {
            string word2 = words[num];

            for (int i = 0; i < word2.length(); i++)
            {
                nokia_keyword(ques.substr(2), ans + word2[i]);
            }
        }
    }
}

void encoding(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];

    if (ch == '0')
    {
        encoding(ques.substr(1), ans);
    }

    char word1 = (char)(ch - '1' + 'a');

    encoding(ques.substr(1), ans + word1);

    if (ques.length() > 1)
    {
        int num = ((ch - '0') * 10) + (ques[1] - '0');

        if (num <= 26)
        {
            char word2 = (char)(num + 'a' - 1);

            encoding(ques.substr(2), ans + word2);
        }
    }
}

//=====================================================================================================================================

int targetSum(vector<int> &arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += targetSum(arr, i + 1, tar - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

int equiSet(vector<int> &arr, int idx, int set1, int set2, string ans1, string ans2)
{
    if (idx == arr.size())
    {
        if (set1 == set2) //checking if summation of set1==set2
        {
            cout << ans1 << " = " << ans2 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    count += equiSet(arr, idx + 1, set1 + arr[idx], set2, ans1 + to_string(arr[idx]) + " ", ans2);
    count += equiSet(arr, idx + 1, set1, set2 + arr[idx], ans1, ans2 + to_string(arr[idx]) + " ");

    return count;
}

void basic()
{
    // subseq("abc", "");
    //Asciisubseq("abc", "");
    // permutations_01("aba", "");

    //mazepath_02(0, 2, 0, 2, "");

    // nokia_keyword("112","");

    // encoding("118", "");
}

//=====================================================================================================================================

int queenBoxCombi(int tnq, int tnb, int lqpsf, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i <= tnb; i++)
    {

        count += queenBoxCombi(tnq - 1, tnb, i + 1, ans + "B" + to_string(i) + "Q" + to_string(tnq) + " ");
    }
    return count;
}

int queenBoxPermu(int tnq, vector<bool> tnb, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < tnb.size(); i++)
    {
        if (!tnb[i])
        {
            tnb[i] = true;
            count += queenBoxPermu(tnq - 1, tnb, ans + "B" + to_string(i) + "Q" + to_string(tnq) + " ");
            tnb[i] = false;
        }
    }
    return count;
}

int queen2dBoxCombi(int tnq, vector<vector<bool>> &tnb, int lqpsf, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < tnb.size() * tnb[0].size(); i++)
    {
        int x = i / tnb[0].size();
        int y = i % tnb[0].size();

        count += queen2dBoxCombi(tnq - 1, tnb, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
    }
    return count;
}

int queen2DBoxPermu(int tnq, vector<vector<bool>> &tnb, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < tnb.size() * tnb[0].size(); i++)
    {
        int x = i / tnb[0].size();
        int y = i % tnb[0].size();

        if (!tnb[x][y])
        {
            tnb[x][y] = true;
            count += queen2DBoxPermu(tnq - 1, tnb, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            tnb[x][y] = false;
        }
    }
    return count;
}

void queenBox()
{
    // vector<bool> tnb(5,false);
    // cout << queenBoxCombi(4, 16, 1, "") << endl;
    // cout<<queenBoxPermu(3,tnb,"")<<endl;

    vector<vector<bool>> tnb(4, vector<bool>(4, 0));
    cout << queen2dBoxCombi(4, tnb, 0, "") << endl;
    // cout << queen2DBoxPermu(4, tnb, "") << endl;
}

//=====================================================================================================================================

bool isSafeToPlaceQueen(vector<vector<bool>> &boxes, int x, int y)
{
    int xdir[4] = {0, -1, -1, -1};
    int ydir[4] = {-1, -1, 0, 1};

    for (int rad = 1; rad < max(boxes.size(), boxes[0].size()); rad++)
    {
        for (int d = 0; d < 4; d++)
        {
            int r = x + rad * xdir[d];
            int c = y + rad * ydir[d];
            if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes[0].size() && boxes[r][c])
                return false;
        }
    }
    return true;
}

int nQueen(int tnq, vector<vector<bool>> &boxes, int lqpsf, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if (isSafeToPlaceQueen(boxes, x, y))
        {
            boxes[x][y] = true;
            count += nQueen(tnq - 1, boxes, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            boxes[x][y] = false;
        }
    }
    return count;
}

void nqueen()
{
    vector<vector<bool>> boxes(4, vector<bool>(4, 0));
    cout << nQueen(4, boxes, 0, "") << endl;
}

//=====================================================================================================================================

int subseqnqueen(int tnq, vector<vector<bool>> &boxes, int lqpsf, string ans)
{
    if (tnq == 0 || lqpsf == boxes.size() * boxes[0].size())
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int x = lqpsf / boxes[0].size();
    int y = lqpsf % boxes[0].size();
    int count = 0;

    if (isSafeToPlaceQueen(boxes, x, y))
    {
        boxes[x][y] = true;
        count += subseqnqueen(tnq - 1, boxes, lqpsf + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
        boxes[x][y] = false;
    }

    count += subseqnqueen(tnq, boxes, lqpsf + 1, ans);

    return count;
}

void subqueen()
{
    vector<vector<bool>> chess(4, vector<bool>(4, false));
    cout << subseqnqueen(4, chess, 0, "") << endl;
}

//=====================================================================================================================================

string str1 = "send";
string str2 = "more";
string str3 = "money";

vector<int> mapCharToNumber(26, 0);
vector<bool> numberUsed(10, 0);

int stringtonumber(string str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
        num = num * 10 + mapCharToNumber[str[i] - 'a'];
    return num;
}

int cryptoSimple(string s, int idx)
{
    if (idx == s.length())
    {
        int num1 = stringtonumber(str1);
        int num2 = stringtonumber(str2);
        int num3 = stringtonumber(str3);

        if (num1 + num2 == num3 && mapCharToNumber[str3[0] - 'a'] != 0)
        {
            cout << num1 << endl
                 << "+" << num2 << "\n------------\n"
                 << num3 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int num = 9; num >= 0; num++)
    {
        if (!numberUsed[num])
        {
            numberUsed[num] = true;
            mapCharToNumber[s[idx] - 'a'] = num;

            count += cryptoSimple(s, idx + 1);

            numberUsed[num] = false;
        }
    }

    return count;
}

void crypto()
{
    vector<int> freqMap(26, 0);

    string str = str1 + str2 + str3;

    for (int i = 0; i < str.length(); i++)
        freqMap[str[i] - 'a']++;

    string s = "";

    for (int i = 0; i < 26; i++)
    {
        if (freqMap[i] > 0)
            s += (char)(i + 'a');
    }

    cout << cryptoSimple(s, 0) << endl;
}

void crypto_basic()
{
    crypto();
}
//=====================================================================================================================================

bool isSafePlaceNumber(vector<vector<int>> &board, int num, int r, int c)
{

    //loop1 for rows
    for (int i = 0; i < 9; i++)
    {
        if (board[r][i] == num)
            return false;
    }

    //loops2 for columns
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == num)
            return false;
    }

    //loops for 3x3 matrix

    r = (r / 3) * 3;
    c = (c / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + r][j + c] == num)
                return false;
        }
    }

    return true;
}

void print2D(vector<vector<int>> &board)
{
    for (vector<int> arr : board)
    {
        for (int ele : arr)
            cout << ele << " ";

        cout << endl;
    }
}

int sudoku_01(vector<vector<int>> &board, int vidx)
{
    if (vidx == 81)
    {
        print2D(board);
        return 1;
    }

    int x = vidx / 9;
    int y = vidx % 9;
    int count = 0;

    if (board[x][y] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafePlaceNumber(board, num, x, y))
            {
                board[x][y] = num;
                count += sudoku_01(board, vidx + 1);
                board[x][y] = 0;
            }
        }
    }
    else
    {
        count += sudoku_01(board, vidx + 1);
    }

    return count;
}

int sudoku_02(vector<vector<int>> &board, vector<int> &calls, int vidx)
{
    if (vidx == calls.size())
    {
        print2D(board);
        return 1;
    }

    int x = calls[vidx] / 9;
    int y = calls[vidx] % 9;
    int count = 0;

    if (board[x][y] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafePlaceNumber(board, num, x, y))
            {
                board[x][y] = num;
                count += sudoku_02(board, calls, vidx + 1);
                board[x][y] = 0;
            }
        }
    }
    else
    {
        count += sudoku_02(board, calls, vidx + 1);
    }

    return count;
}

int rows[9] = {0};
int cols[9] = {0};
int matrix[3][3] = {0};

bool sudoku_03(vector<vector<int>> &board, vector<int> &calls, int vidx)
{
    if (vidx == calls.size())
    {
        print2D(board);
        return 1;
    }

    int x = calls[vidx] / 9;
    int y = calls[vidx] % 9;
    // int count = 0;
    bool res = false;

    if (board[x][y] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            int mask = 1 << num;
            if (((rows[x] & mask) == 0) && (cols[y] & mask == 0) && (matrix[x/3][y/3] & mask == 0))
            {
                board[x][y] = num;
                rows[x] ^= mask;
                cols[y] ^= mask;
                matrix[x / 3][y / 3] ^= mask;
                res = res || sudoku_03(board, calls, vidx + 1);
                board[x][y] = 0;
                rows[x] ^= mask;
                cols[y] ^= mask;
                matrix[x / 3][y / 3] ^= mask;
            }
        }
    }

    return res;
}

void sudoku()
{
    vector<vector<int>> boxes = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    //cout << sudoku_01(boxes, 0) << endl;
    vector<int> calls;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (boxes[i][j] == 0)
            {
                int num = i * 9 + j;
                calls.push_back(num);
            }
            else
            {
                int mask = 1 << boxes[i][j];
                if (((rows[i] & mask) == 0) && (cols[j] & mask == 0) && (matrix[i][j] & mask == 0))
                {
                    rows[i] |= mask;
                    cols[j] |= mask;
                    matrix[i / 3][j / 3] = mask;
                }
                else
                    cout << "Invalid Sudoko!!";
            }
        }
    }

    // cout << sudoku_02(boxes, calls, 0) << endl;
    cout << sudoku_03(boxes, calls, 0) << endl;
}
//=====================================================================================================================================

int main(int args, char **argv)
{
    //basic();
    //nqueen();
    //queenbox();
    //subqueen();

    //crypto_basic();

    sudoku();

    return 0;
}