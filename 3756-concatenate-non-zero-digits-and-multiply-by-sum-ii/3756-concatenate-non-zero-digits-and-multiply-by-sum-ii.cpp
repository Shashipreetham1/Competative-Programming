#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        long long sum;
        int cnt;

        Node(long long v = 0, long long s = 0, int c = 0) {
            val = v;
            sum = s;
            cnt = c;
        }
    };

    vector<Node> seg;
    vector<long long> pow10;

    Node merge(const Node &L, const Node &R) {
        Node res;
        res.cnt = L.cnt + R.cnt;
        res.sum = L.sum + R.sum;
        res.val = (L.val * pow10[R.cnt] + R.val) % MOD;
        return res;
    }

    void build(int idx, int l, int r, const string &s) {
        if (l == r) {
            if (s[l] != '0') {
                int d = s[l] - '0';
                seg[idx] = Node(d, d, 1);
            } else {
                seg[idx] = Node();
            }
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, s);
        build(2 * idx + 2, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return Node();

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx + 1, l, mid, ql, qr);
        Node right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        seg.assign(4 * n, Node());

        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        build(0, 0, n - 1, s);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(0, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};