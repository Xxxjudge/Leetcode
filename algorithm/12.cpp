class Solution {
public:
	string intToRoman(int num) {
		vector<string> roman{ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		vector<int> nums{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string ans = "";
		while (num) {
			for (int i = 0; i<13; i++)
				if (num >= nums[i]) {
					num -= nums[i];
					ans += roman[i];
					break;
				}
		}
		return ans;
	}
};