#include <stdio.h>
#include <stdlib.h>

//qsort函数排序
int cmp(const void* e1,const void* e2)
{
    return (*(int*)e1) - (*(int*)e2);
}
int minPairSum2(int* nums, int numsSize) {
    //排序
    qsort(nums,numsSize,sizeof(int),cmp);
    //双指针求和
    int left = 0;
    int right = numsSize - 1;
    int max = nums[left] + nums[right];
    while(left < right)
    {
        if(max < nums[left] + nums[right])
            max = nums[left] + nums[right];
        left++;
        right--;
    }
    return max;
}
//冒泡排序（超时）
int minPairSum1(int* nums, int numsSize) {
    //排序
    for(int j = numsSize - 1;j >= 1;j--)
    {
        for(int i = 0;i < j;i++)
        {
            if(nums[i] > nums[i + 1])
            {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
        }
    }
    //双指针求和
    int left = 0;
    int right = numsSize - 1;
    int max = nums[left] + nums[right];
    while(left < right)
    {
        if(max < nums[left] + nums[right])
            max = nums[left] + nums[right];
        left++;
        right--;
    }
    return max;
}
int main(void)
{
	int nums[] = {3,5,2,3};
	int sz = sizeof(nums) / sizeof(nums[0]);
	printf("%d",minPairSum2(nums,sz));
	return 0;
}