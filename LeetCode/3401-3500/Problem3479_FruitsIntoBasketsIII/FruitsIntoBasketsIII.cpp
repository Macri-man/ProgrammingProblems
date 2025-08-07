

class Solution {
    int n;
    vector<int> tree;

    void build(const vector<int>& baskets, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = baskets[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(baskets, v*2, tl, tm);
            build(baskets, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, val);
            else
                update(v*2+1, tm+1, tr, pos, val);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int val) {
        if (tree[v] < val) return -1;  
        if (tl == tr) return tl;     
        int tm = (tl + tr) / 2;
        if (tree[v*2] >= val) 
            return query(v*2, tl, tm, val);
        else
            return query(v*2+1, tm+1, tr, val);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = (int)baskets.size();
        tree.resize(4 * n);
        build(baskets, 1, 0, n - 1);

        int unplaced = 0;
        for (int quantity : fruits) {
            int pos = query(1, 0, n - 1, quantity);
            if (pos == -1) {
                unplaced++;
            } else {
                update(1, 0, n - 1, pos, 0); 
            }
        }
        return unplaced;
    }
};
