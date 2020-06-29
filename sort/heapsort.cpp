#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>nums{3,2,1,5,6,4};
	int temp = 0;
	for (int j = nums.size() - 1; j >= 1; j--)
	{
		for (int i = (j - 1) / 2; i >= 0; i--)
		{
			if (nums[i]>nums[2 * i + 1])
			{
				temp = nums[i];
				nums[i] = nums[2 * i + 1];
				nums[2 * i + 1] = temp;
			}
			if ((2*i+2<=j)&&(nums[i]>nums[2 * i + 2]))//这里需要注意，一定有左节点，但不一定有右节点，因此要先判断是否存在
			{
				temp = nums[i];
				nums[i] = nums[2 * i + 2];
				nums[2 * i + 2] = temp;
			}

		}
		temp = nums[0];
		nums[0] = nums[j];
		nums[j] = temp;
		
	}
	for(int i=0;i<nums.size();i++)
	cout << nums[i];
	system("pause");
	return 0;
}
