#include <stdio.h>
#include <stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return *(int*)e1 -*(int*)e2;
}
int minimumDifference2(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int min = 100000;
    for(int i = 0;i <= numsSize - k;i++)
    {
        int tmp = nums[i + k - 1] - nums[i];
        if(min > tmp)
            min = tmp;
    }
    return min;
}
//二进制枚举（超时）
int minimumDifference1(int* nums, int numsSize, int k) {
    int total = 1;
    for(int i = 0;i < numsSize;i++)
    {
        total *= 2;
    }
    int min_sub = 100000;
    for(int i = 0;i < total;i++)
    {
        int count = 0;
        int tmp1 = i;
        while(tmp1 != 0)
        {
            if(tmp1 & 1 == 1)
            {
                count++;
            }
            tmp1 = tmp1 >> 1;
        }
        if(count == k)
        {
            int max = nums[0];
            int min = nums[0];
            int tmp2 = i;
            for(int j = 0;tmp2 != 0;j++)
            {
                if(tmp2 & 1 == 1)
                {
                    if(max <= nums[j])
                        max = nums[j];
                    if(min >= nums[j])
                        min = nums[j];
                }
                tmp2 = tmp2 >> 1;
            }
            if(min_sub >= max - min)
                min_sub = max - min;
        }
    }
    return min_sub;
}
int main(void)
{
    int nums[] = {9,4,1,7};
    int sz = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    printf("%d\n",minimumDifference2(nums,sz,k));
}