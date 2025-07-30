int main() {
    int Q;
    std::cin >> Q;

    std::set<int> s;

    for (int i = 0; i < Q; ++i) {
        int y, x;
        std::cin >> y >> x;

        if (y == 1) {
            s.insert(x); 
        } else if (y == 2) {
            s.erase(x); 
        } else if (y == 3) {
            if (s.find(x) != s.end()) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        }
    }

    return 0;
}