
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_distinct_chars(const char* s) {
    int count[26] = {0};
    int distinct = 0;
    for (int i = 0; s[i]; i++) {
        if (!count[s[i] - 'a']) {
            count[s[i] - 'a'] = 1;
            distinct++;
        }
    }
    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int da = count_distinct_chars(a);
    int db = count_distinct_chars(b);
    if (da != db) return da - db;
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int la = strlen(a);
    int lb = strlen(b);
    if (la != lb) return la - lb;
    return strcmp(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}