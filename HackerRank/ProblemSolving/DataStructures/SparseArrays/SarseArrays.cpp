vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> freq;

    for (const string& s : stringList) {
        freq[s]++;
    }

    vector<int> results;
    results.reserve(queries.size());

    for (const string& q : queries) {
        results.push_back(freq[q]);
    }

    return results;
}
