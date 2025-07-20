class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        string name;
        bool deleted = false;
        TrieNode(string name = "") : name(name) {}
    };

    TrieNode* root = new TrieNode();

    void insert(vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new TrieNode(folder);
            node = node->children[folder];
        }
    }

    unordered_map<string, int> count;
    unordered_map<string, vector<TrieNode*>> nodesBySerial;

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<string> subs;
        for (auto& [childName, childNode] : node->children) {
            subs.push_back("(" + childName + serialize(childNode) + ")");
        }

        sort(subs.begin(), subs.end());

        string serial;
        for (const string& s : subs) serial += s;

        count[serial]++;
        nodesBySerial[serial].push_back(node);

        return serial;
    }

    void markDuplicates() {
        for (auto& [serial, nodes] : nodesBySerial) {
            if (count[serial] > 1) {
                for (TrieNode* node : nodes) {
                    node->deleted = true;
                }
            }
        }
    }

    void collectPaths(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (child->deleted) continue;
            path.push_back(name);
            res.push_back(path);
            collectPaths(child, path, res);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths)
            insert(path);

        serialize(root);
        markDuplicates();

        vector<vector<string>> result;
        vector<string> currPath;
        collectPaths(root, currPath, result);
        return result;
    }
};
