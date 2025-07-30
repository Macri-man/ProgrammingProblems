int main() {
    int Q;
    cin >> Q;
    map<string, int> m;

    for (int i = 0; i < Q; ++i) {
        int type;
        string name;
        cin >> type >> name;

        if (type == 1) {
            int marks;
            cin >> marks;
            m[name] += marks;
        } else if (type == 2) {
            m.erase(name);
        } else if (type == 3) {
            cout << m[name] << endl; 
        }
    }

    return 0;
}