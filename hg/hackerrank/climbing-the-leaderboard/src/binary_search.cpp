vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    /*
     * Write your code here.
     */
    vector<int> rank;
    vector<int> ans;
    scores.push_back(0);
    rank.reserve(scores.size());
    rank.push_back(1);
    int cr = 1;
    for (size_t i=1; i < scores.size(); i++) {
        auto& prev = scores[i-1];
        auto& curr = scores[i];
        if (prev != curr) {
            cr++;
        }
        rank.push_back(cr);
    }
    
    for (size_t i=0; i < alice.size(); i++) {
        int alice_score = alice[i];
        int l = 0;
        int r = scores.size();
        cout << alice_score << '\n';
        while (l < r) {
            // cout << '(' << l << ' ' << r << ')' << endl;
            int m = (l+r)/2;
            if (alice_score > scores[m]) {
                r = m;
            } else if (alice_score < scores[m]) {
                l = m+1;
            } else {
                l = m;
                break;
            }
        }
        ans.push_back(rank[l]);
        // cout << scores[l] << ' ';
    }
    return ans;

}