#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//abaabaabacacaabaabcc
//abaabc
void get_next(const char* pattern,int* next)
{
    int len = strlen(pattern);
    int i = 1;
    int j = 0;
    while(i < len)
    {
        if(pattern[i] == pattern[j])
        {
            j++;
            next[i] = j;
            i++;
        }
        else
        {
            if(j != 0)
            {
                j = next[j - 1]; 
            }
            else
            {
                next[i] = 0;
                i++;
            }
        }
    }
}
int KMP(const char* text,const char* pattern)
{
    assert(text && pattern);
    int t_sz = strlen(text);
    int p_sz = strlen(pattern); 
    int* next = (int*)calloc(p_sz,sizeof(int));
    get_next(pattern,next);
    int i = 0;
    int j = 0;
    while(i < t_sz)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = next[j - 1];
            }
            else
            {
                i++;
            }
        }
        if(j == p_sz)
        {
            free(next);
            return i - j;
        }
    }
    free(next);
    return -1;
}
int main(void)
{
    char* text = "abaabaabacacaabaabcc";
    char* pattern = "abaabc";
    int p = KMP(text,pattern);
    printf("匹配的位置为：%d\n",p);
    return 0;
}