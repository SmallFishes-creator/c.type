#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int slow = 1;
    int fast = 1;
    for(fast = 1;fast < numsSize;fast++)
    {
        if(nums[fast - 1] < nums[fast])
        {
            nums[slow] == nums[fast];
            slow++;
        }
    }
    return slow;
}
int main(void)
{
	int nums[] = {1,1,2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d",removeDuplicates(nums,numsSize));
	return 0;
}