int str_compare(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    if (s1[i] == '\0') return -1; 
    return 1; 
}

void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char **s, int from, int to) {
    while (from < to) {
        swap(&s[from], &s[to]);
        from++;
        to--;
    }
}

int next_permutation(int n, char **s) {
    if (n <= 1) return 0;

    int i = n - 2;
    while (i >= 0 && str_compare(s[i], s[i + 1]) >= 0) {
        i--;
    }

    if (i < 0) {
        return 0;
    }

    int j = n - 1;
    while (j > i && str_compare(s[j], s[i]) <= 0) {
        j--;
    }

    swap(&s[i], &s[j]);

    reverse(s, i + 1, n - 1);

    return 1;
}
