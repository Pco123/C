#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
/*
912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。
示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
提示：
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
链接：https://leetcode-cn.com/problems/sort-an-array/
*/

/*
//方法一：快速排序
void Swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int GetMinIndex(int* array, const int left, const int right)
{
    int mid= (left + right) >> 1;
    if (array[left] < array[mid])
    {
        if (array[mid] < array[right])
        {
            return mid;
        }
        else if(array[left]>array[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (array[mid] > array[right])
        {
            return mid;
        }
        else if (array[left] < array[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int partition(int*array,int left,int right)
{
    int mid=GetMinIndex(array,left,right);
    Swap(&array[mid],&array[left]);
    int keyi=left;
    while(left<right)
    {
        while(left<right&&array[right]>=array[keyi])
        {
            right--;
        }
        while(left<right&&array[left]<=array[keyi])
        {
            left++;
        }
        Swap(&array[left],&array[right]);
    }
     Swap(&array[left],&array[keyi]);
     return left;
}

void QucikSort(int *array,int begin,int end)
{
    if(begin>=end)
    {
        return;
    }
    int key=partition(array,begin,end);
    QucikSort(array,begin,key-1);
    QucikSort(array,key+1,end);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int *array=(int *)malloc(sizeof(int)*numsSize);
    QucikSort(nums,0,numsSize-1);
    memcpy(array,nums,sizeof(int)*numsSize);
    *returnSize=numsSize;
    return nums;
}


//方法二：希尔排序
void shellSort(int*array,int size)
{
    int gap=size;
    while(gap>1)
    {
        gap=gap/3+1;
        for(int i=0;i<size-gap;i++)
        {
            int end=i;
            int temp=array[end+gap];
            while(end>=0)
            {
                if(array[end]>temp)
                {
                    array[end+gap]= array[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            array[end+gap]=temp;
        }

    }

}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize=numsSize;
    int *array=(int*)malloc(sizeof(int)*numsSize);
    shellSort(nums,numsSize);
    memcpy(array,nums,sizeof(int)*numsSize);
    return array;
}

//方法三：堆排序

void swap(int *x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void adjustBigHead(int*array,int parent,const int size)
{
    int child=parent*2+1;       //左孩子
    while(child<size)
    {
        if(child+1<size&&array[child]<array[child+1])
        {
            child++;
        }

        if(array[child]>array[parent])
        {
            swap(&array[child],&array[parent]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }

    }
}

void HeapSort(int*array,const int size)
{
    for(int i=(size-1)/2;i>=0;i--)
    {
        adjustBigHead(array,i,size);
    }

    int end=size-1;
    while(end>0)
    {
        swap(&array[end],&array[0]);
        adjustBigHead(array,0,end);
        --end;
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize=numsSize;
    int *array=(int*)malloc(sizeof(int)*numsSize);
    HeapSort(nums,numsSize);
    memcpy(array,nums,sizeof(int)*numsSize);
    return array;
}

//方法四：归并排序
void MergeSort(int* array, int left, int right, int* tempArr)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) >> 1;
    //[left,min]  [mid+1,right]
    MergeSort(array, left, mid, tempArr);
    MergeSort(array, mid+1, right, tempArr);

    int begin1 = left;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = right;
    int i = left;

    //两段有序子区间归并给tempArr，并拷贝回给array
    //只要有一个数组内的元素空了，就跳出循环
    //出来后把另外一个还未空的数组的元素放进tempArr中
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (array[begin1] < array[begin2])
        {
            tempArr[i++] = array[begin1++];
        }
        else
        {
            tempArr[i++] = array[begin2++];
        }
    }

    while (begin1 <= end1)
    {
        tempArr[i++] = array[begin1++];
    }

    while (begin2 <= end2)
    {
        tempArr[i++] = array[begin2++];
    }

    //拷贝给array数组
    for (int j = left; j <= right; j++)
    {
        array[j] = tempArr[j];
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize=numsSize;
    int *array=(int*)malloc(sizeof(int)*numsSize);
    MergeSort(nums,0,numsSize-1,array);
    free (array);
    return nums;
}
*/