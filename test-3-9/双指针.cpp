
//1.Ë«Ö¸Õë 
//https://leetcode.cn/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int cur=0,des=-1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[cur]==0) cur++;
        //     else {
        //         swap(nums[des+1],nums[cur]);
        //         des++,cur++;
        //     }
        // }

        for (int cur = 0, des = -1; cur < nums.size(); cur++)
        {
            if (nums[cur])
            {
                swap(nums[++des], nums[cur]);
                //swap(nums[des+1],nums[cur])
                //des++;
            }
        }
    }
};
2.Ë«Ö¸Õë
https ://leetcode.cn/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1, size = arr.size();
        while (dest < size)
        {
            if (arr[cur]) dest++;
            else dest += 2;
            if (dest >= size - 1)  break;
            cur++;
        }
        if (dest == size)
        {
            arr[size - 1] = 0;
            dest -= 2, cur--;
        }
        while (cur >= 0)
        {
            if (arr[cur]) arr[dest] = arr[cur];
            else {
                arr[dest--] = 0;
                arr[dest] = 0;
            }
            cur--, dest--;
        }
    }
};