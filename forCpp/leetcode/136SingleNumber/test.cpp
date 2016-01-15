#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // while(nums.size()>1)
        // {
        	cout<<nums.size()<<"size"<<endl;
            vector<int>::iterator it;
            for(it=nums.begin()+1;it!=nums.end()&&nums.size()>1;it++)
            {
                if(*nums.begin()==*it)
                {
                	cout<<*nums.begin()<<"numsbegin"<<endl;
                	cout<<*it<<"it"<<endl;
                    it=nums.erase(it);
                    nums.erase(nums.begin());
                    it=nums.begin()+1;
                    cout<<nums.size()<<"size-nei"<<endl;

                }
            }
        // }
        cout<<nums[0]<<"nums[0]"<<endl;
        return nums[0];
    }
};
int main(int argc,char** argv)
{
	Solution* sol=new Solution;
	vector<int> nums;
	// nums.push_back(1);
	// nums.push_back(3);
 //    nums.push_back(1);
 //    nums.push_back(-1);
 //    nums.push_back(3);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(1);
    for(int i=0;i<=1000;i++)
        nums.push_back(i);
    for(int i=0;i<=999;i++)
        nums.push_back(i);
	cout<<sol->singleNumber(nums)<<endl;

	return 0;
}