#include <vector>
#include <algorithm>

int calculateTotalRegion(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);

  
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        left[i] = (heights[i] == heights[i - 1]) ? left[i - 1] + 1 : 1;
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        right[i] = (heights[i] == heights[i + 1]) ? right[i + 1] + 1 : 1;
    }

    int totalRegion = 0;
    for (int i = 0; i < n; ++i) {
        totalRegion += std::max(left[i], right[i]);
    }

    return totalRegion;
}
int main ()
{
    vector<int> v(n,0);
    for(int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
}
