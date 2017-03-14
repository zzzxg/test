#include <map>
#include <string>
#include <stdio.h>
using namespace std;

int lengthOfLongestSubstring(string s);

void test1(){
    string s = "abcabcbb";
    int len = 3;
    if (len == lengthOfLongestSubstring(s))
        printf("test pass!");
    else
        printf("test error!");
}

void test2(){
    string s = "asdfagfdgggfgqwwwerreycxcvujummhgfhfdgh";
    int len = 5;
    int ret =  lengthOfLongestSubstring(s);
    printf("ret = %d ", ret);
    if (len == ret)
        printf("test pass!");
    else
        printf("test error!");}

int main(){

    test1();
    test2();
    return 0;
}

    int lengthOfLongestSubstring(string s) {
        //map 为红黑树（平衡排序二叉树），插入删除操作复杂度为O（logn）
        //由于字母数为有限个，故字母表map中的插入删除操作复杂度为O(1)
        //故此算法复杂度度为O(n)

        int ret = 0;
        map<char, int> m;
        int start = 1;
        for (int i = 1; i <= s.length(); i++)
        {
            char c = s[i - 1];
            if (m[c] >= start)
            {
                start = m[c] + 1;
                m[c] = i;
            }
            else
            {
                m[c] = i;
                ret = max(ret, i - start + 1);
            }
        }
        return ret;
    }
