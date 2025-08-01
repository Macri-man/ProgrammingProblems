char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char** split_string(const char* str, const char* delim, int* count) {
    char* copy = strdup(str);
    int capacity = 10;
    char** result = malloc(capacity * sizeof(char*));
    int size = 0;

    char* token = strtok(copy, delim);
    while (token) {
        if (size >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(char*));
        }
        result[size++] = strdup(token);
        token = strtok(NULL, delim);
    }

    *count = size;
    free(copy);
    return result;
}

char**** get_document(char* text) {
    int para_count;
    char** paragraphs = split_string(text, "\n", &para_count);

    char**** document = malloc(para_count * sizeof(char***));

    for (int i = 0; i < para_count; i++) {
        int sent_count;
        char** sentences = split_string(paragraphs[i], ".", &sent_count);
        document[i] = malloc(sent_count * sizeof(char**));

        for (int j = 0; j < sent_count; j++) {
            int word_count;
            char** words = split_string(sentences[j], " ", &word_count);
            document[i][j] = malloc(word_count * sizeof(char*));

            for (int k = 0; k < word_count; k++) {
                document[i][j][k] = words[k];  // already strdup'd
            }

            free(words);
        }

        free(sentences);
        free(paragraphs[i]);
    }

    free(paragraphs);
    return document;
}
