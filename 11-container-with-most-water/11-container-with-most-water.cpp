class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int n = height.size();
        queue<pair<int, int>> left, right;

        pair<int, int> prev = {INT_MIN, INT_MIN};

        for (int i = 0; i < n; i++)
        {

            if (height[i] > prev.first)
            {
                left.push({height[i], i});
                prev = left.front();
            }
        }

        prev.first = prev.second = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {

            if (height[i] > prev.first)
            {
                right.push({height[i], i});
                prev = right.front();
            }
        }

        int ans = 0;

        int h = min(left.front().first, right.front().first);

        while (left.size() > 0 and right.size() > 0)
        {

            while (left.size() > 0 and left.front().first < h)
                left.pop();

            while (right.size() > 0 and right.front().first < h)
                right.pop();

            if (left.size() == 0 or right.size() == 0)
                return ans;

            h = min(left.front().first, right.front().first);

            int cur = h * (right.front().second - left.front().second);

            ans = max(ans, cur);

            h++;
        }

        return ans;
    }
};
