#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool canPlaceVertical(string word, int r, int c)
{
    if (r == 0 && word.length() != board.size())
    {
        if (board[r + word.length()][c] != '+')
            return false;
    }
    else if ((r + word.length()) >= board.size() && word.length() != board.size())
    {
        if (board[r - 1][c] != '+')
            return false;
    }
    else
    {
        if (board[r - 1][c] != '+' || board[r + word.length()][c] != '+')
            return false;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (!(board[r + i][c] == '-' || word[i] == board[r + i][c]))
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeWordVertical(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r + i][c] == '-')
        {
            board[r + i][c] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplaceWordVertical(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i])
        {
            board[r + i][c] = '-';
        }
    }
}

bool canPlaceHorizontal(string word, int r, int c)
{
    if (c == 0 && word.length() != board[0].size())
    {
        if (board[r][c + word.length()] != '+')
            return false;
    }
    else if ((c + word.length()) == board[0].size() && word.length() != board[0].size())
    {
        if (board[r][c - 1] != '+')
            return false;
    }
    else
    {
        if (board[r][c - 1] != '+' || board[r][c + word.length()] != '+')
            return false;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (!(board[r][c + i] == '-' || word[i] == board[r][c + i]))
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeWordHorizontal(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r][c + i] == '-')
        {
            board[r][c + i] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplaceWordHorizontal(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i])
        {
            board[r][c + i] = '-';
        }
    }
}

int crossWordUtil(vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (vector<char> ar : board)
        {
            for (char ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        return 1;
    }

    string word = words[idx];
    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (canPlaceHorizontal(word, i, j))
            {
                vector<bool> pos = placeWordHorizontal(word, i, j);
                count += crossWordUtil(words, idx + 1);
                unplaceWordHorizontal(i, j, pos);
            }

            if (canPlaceVertical(word, i, j))
            {
                vector<bool> pos = placeWordVertical(word, i, j);
                count += crossWordUtil(words, idx + 1);
                unplaceWordVertical(i, j, pos);
            }
        }
    }
    return count;
}

void crossWord()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossWordUtil(words, 0) << endl;
}

int main(int args, char **argv)
{
    crossWord();

    return 0;
}