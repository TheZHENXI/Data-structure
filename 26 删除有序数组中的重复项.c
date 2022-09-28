#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    //0,0,1,1,1,2,2,3,3,4
    int left = 0; 
    int right = 0;
    nums[left] = nums[0]; 
    left++;
    while(right < numsSize-1)
    {
        right++;
        if(nums[right] > nums[left-1])
        {
            nums[left++] = nums[right];
        }
    }

    return left;

}
int main()
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums, 10);
    return 0;
}