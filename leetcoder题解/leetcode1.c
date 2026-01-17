#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize - 1;
    while(left < right)
    {
        if(nums[left] == val)
        {
            while(nums[right] == val)
            {
                right--;
            }
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            right--;
        }
        left++;
    }
    int count = 0;
    for(count = 0;nums[count] != val;count++)
    {
        ;
    }
    return count;
}
int main(void)
{
	int nums[] = {3,2,2,3};
	int val = 3;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d",removeElement(nums,numsSize,val));
	return 0;
}