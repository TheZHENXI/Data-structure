/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */
// int compare(const void* e1,const void* e2)
// {
//     return *(int*)e1 - *(int*)e2;
// }
// //空间复杂度O(1)，时间复杂度O(n+mlogm)
// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//     for(int i = 0;i < nums2Size;i++)
//     {
//         nums1[m+i] = nums2[i];
//     }
//     qsort(nums1,nums1Size,sizeof(nums1[0]),compare);
// }
 void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
 {
    /*--------------------------------------*/
    //1,2,3,0,0,0
    //2,5,6  
    //针对nums1的m为0的情况
    // if(m == 0)
    // {
    //     for(int i = 0;i < n;i++)
    //     {
    //         nums1[i] = nums2[i];
    //     }
    //     return ; 
    // }
    /*--------------------------------------*/
    int p1 = m - 1;
    int p2 = n - 1;
    int cp = nums1Size-1;
    //写法2
    // while(p2 >= 0)
    // {   //p1>=0需放在前，防止nums1的m位0的情况发生：m =0，则p1位-1，则nums1[p1]非法访问
    //     while(p1 >= 0 && (nums1[p1] > nums2[p2]))
    //     {
    //         nums1[cp--] = nums1[p1--];
    //     }
    //     nums1[cp--] = nums2[p2--];  
    // }
    /*--------------------------------------*/
    while(p1 >= 0 && p2 >=0)
    {
        if(nums1[p1] > nums2[p2])
        {
            nums1[cp--] = nums1[p1--];
        }
        else
        {
            nums1[cp--] = nums2[p2--];        
        }
    }
    //跳出上一个while，要么p1 < 0(把nums2剩下的拷贝进去) 要么p2 < 0（直接返回）
    while(p2 >= 0)
    {
        nums1[cp--] = nums2[p2--];
    }
    /*--------------------------------------*/
 }