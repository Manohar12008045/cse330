class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> u;
        for (auto &p: points)
            u[p[0]].push_back(p[1]);
        for (auto &[x,line]: u)
            sort(line.begin(), line.end());
        int ret = INT_MAX;
        for (auto l1 = u.begin(); l1 != u.end(); ++l1) {
            auto &[y1,line1] = *l1;
            for (auto l2 = l1; ++l2 != u.end(); ) {
                auto &[y2,line2] = *l2;
                auto h = abs(y1 - y2);
                auto i = line1.begin();
                auto iend = line1.end();
                auto j = line2.begin();
                auto jend = line2.end();
                auto prev = INT_MIN;
                auto minw = INT_MAX;
                while(i != iend && j != jend) {
                    if (*i < *j) {
                        ++i;
                        continue;
                    }
                    if (*i > *j) {
                        ++j;
                        continue;
                    }
                    if (prev != INT_MIN)
                        minw = min(minw, *i - prev);
                    prev = *i;
                    ++i;
                    ++j;
                }
                if (minw != INT_MAX)
                    ret = min(ret, h*minw);
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
