#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int size=nums.size();
        for(int i=0;i+j<size;i++)
        {
            cout<<"start"<<i<<endl;
            if(nums[i]==0)
            {
                // int m = nums[size-j];
                // nums[size-j]=nums[i];
                // nums[i]=m;
                // for(int c=0 ,d=size-1;nums[d]==0;d--,c++)
                // {
                //     j=c;

                // }
                
                for(int d=size-j-1;nums[d]==0;d--)
                {
                    j++;
                }
                cout<<"i:"<<i<<endl;
                cout<<"j:"<<j<<endl;
                if(i+j>=size)
                break;
                cout<<"run swap()"<<endl;
                swap(nums[i],nums[size-j-1]);

                cout<<"huanguo"<<i<<":    ";

                for (int i = 0; i < size; ++i)
                {
                    cout<<nums[i]<<"\t";
                }
                cout<<endl;
            }
        }
    }
    
    void swap(int &a,int &b)
    {
        int m=a;
        a=b;
        b=m;
    }
};


int main(int argc, char const *argv[])
{
    int array[]={0,1,0,3,12};
    int count=sizeof(array)/sizeof(int);
    vector<int> vec1(array,array+count);
        cout<<"执行前          ";

    for (int i = 0; i < count; ++i)
    {
        cout<<vec1[i]<<"\t";
    }
    cout<<endl;
    Solution* solut1 = new Solution();
    solut1->moveZeroes(vec1);

    cout<<"执行后         ";
    for (int i = 0; i < count; ++i)
    {
        cout<<vec1[i]<<"\t";
    }
    cout<<endl;
    return 0;
}