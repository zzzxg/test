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
        //map Ϊ�������ƽ�������������������ɾ���������Ӷ�ΪO��logn��
        //������ĸ��Ϊ���޸�������ĸ��map�еĲ���ɾ���������Ӷ�ΪO(1)
        //�ʴ��㷨���Ӷȶ�ΪO(n)

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
