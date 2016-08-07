#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverse_word(string &s, int start, int end)
    {
        while(start < end)
        {
            int tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start ++;
            end --;
        }
    }

    void reverseWords(string &s)
    {
        int word_cnt = 0;
        int i = 0, j = 0;
        int word_start = 0;
        int size = s.size();
        while(true)
        {
            while(i < size && s[i] == ' ')
                i++;
            if(i == size)
                break;
            if(word_cnt)
                s[j++] = ' ';
            word_start = j;
            while(i < size && s[i] != ' ')
            {
                s[j++] = s[i++];
            }
            reverse_word(s, word_start, j-1);
            word_cnt ++;
        }
        s.resize(j);
        reverse_word(s, 0, j - 1);
    }
};