class CountSquares {
   public:
    unordered_map<int, vector<int>> um;
    map<pair<int, int>,int> freq;
    CountSquares() {}

    void add(vector<int> point) {
        um[point[0]].push_back(point[1]);
        freq[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int cnt = 0;
        int x1 = point[0], y1 = point[1];
        for (auto& y2 : um[x1]) {
            if(y2 == y1) continue;
            int d = abs(y2 - y1);
            cnt += freq[{x1 + d, y1}] * freq[{x1 + d, y2}];
            cnt += freq[{x1 - d, y1}] * freq[{x1 - d, y2}];
        }
        return cnt;
    }
};
