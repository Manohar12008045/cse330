class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    long long ans = LLONG_MAX;
    
    unordered_map<int, vector<tuple<int, int, int, int>>> centerToPoints;

    for (const vector<int>& A : points)
      for (const vector<int>& B : points) {
        const int center = hash(A, B);
        centerToPoints[center].emplace_back(A[0], A[1], B[0], B[1]);
      }

    
    for (const auto& [_, points] : centerToPoints)
      for (const auto& [ax, ay, bx, by] : points)
        for (const auto& [cx, cy, dx, dy] : points)
         
          if ((cx - ax) * (dx - ax) + (cy - ay) * (dy - ay) == 0) {
            const long long squaredArea =
                dist(ax, ay, cx, cy) * dist(ax, ay, dx, dy);
            if (squaredArea > 0)
              ans = min(ans, squaredArea);
          }

    return ans == LLONG_MAX ? 0 : sqrt(ans);
  }

 private:
  int hash(const vector<int>& p, const vector<int>& q) {
    return ((long long)(p[0] + q[0]) << 16) + (p[1] + q[1]);
  }

  long long dist(int px, int py, int qx, int qy) {
    return (px - qx) * (px - qx) + (py - qy) * (py - qy);
  }
};
