
[Problem Link](https://leetcode.com/problems/find-the-duplicate-number/)

- Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.
There is only `one` duplicate number in `nums`, return this `duplicate` number.


>###  Example 1

```
Input: nums = [1,3,4,2,2]
Output: 2
```

>###  Example 2

```
Input: nums = [3,1,3,4,2]
Output: 3
```
>###  Example 3

```
Input: nums = [1,1]
Output: 1
```
>###  Example 4

```
Input: nums = [1,1,2]
Output: 1
```
>### Constraints:

- `2 <= n <= 3 * 104`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in nums appear only once except for precisely one integer which appears two or more times.


>## Solutions

>### Solution 1

```c++
int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])return nums[i];
        }
        return -1;
    }

//TC: O(Nlog(N)) SC: O(1)
```

>### Solution 2

```c++
int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int a[n];
        memset(a, 0, n*sizeof(a[0])); 
        for(int i=0;i<n;i++){
            if(a[nums[i]])return nums[i];
            else a[nums[i]]++;
        }
        return -1;
    }

//TC: O(N) SC: O(N)
```

>### Solution 3

```c++
 int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow=nums[0], fast=nums[0];
        
        do{
            slow=nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
            
        fast=nums[0];
        
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }

//TC: O(N) SC: O(1)
```

>### Solution 4

```c++
int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int j;
        for(int i=0;i<n;i++){
            j=abs(nums[i]);
            j--;
            nums[j]*=-1;
            if(nums[j]>0)return abs(nums[i]);
        }
        return -1;
    }
//TC: O(N) SC: O(1)
```

