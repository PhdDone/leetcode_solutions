/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/
class Solution {
public:
  vector<int> getRow(int rowIndex) {
  
    vector<int> res(rowIndex+1,1);
    if(rowIndex == 0)return res;
    for(int i = 1; i <= rowIndex; i++)
      {
	int tmp = res[0];
	for(int j = 1; j <= i-1; j++)
	  {
	    int kk = res[j];
	    res[j] = tmp+res[j];
	    tmp = kk;
	  }
      }
    return res;
  }
};
