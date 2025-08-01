struct document get_document(char* text) {
    struct document doc;
    doc.data = malloc(MAX_PARAGRAPHS * sizeof(struct paragraph));
    doc.paragraph_count = 0;

    char* paragraph_start = text;
    while (paragraph_start && *paragraph_start) {
        // Find next newline or end
        char* paragraph_end = strchr(paragraph_start, '\n');
        int paragraph_len = paragraph_end ? (paragraph_end - paragraph_start) : strlen(paragraph_start);

        char* paragraph_copy = malloc(paragraph_len + 1);
        strncpy(paragraph_copy, paragraph_start, paragraph_len);
        paragraph_copy[paragraph_len] = '\0';

        struct paragraph para;
        para.data = malloc(100 * sizeof(struct sentence));
        para.sentence_count = 0;

        char* sentence_start = paragraph_copy;
        while (sentence_start && *sentence_start) {
            char* sentence_end = strchr(sentence_start, '.');
            if (!sentence_end) sentence_end = sentence_start + strlen(sentence_start);
            int sentence_len = sentence_end - sentence_start;

            if (sentence_len > 0) {
                char* sentence_copy = malloc(sentence_len + 1);
                strncpy(sentence_copy, sentence_start, sentence_len);
                sentence_copy[sentence_len] = '\0';

                struct sentence sen;
                sen.data = malloc(100 * sizeof(struct word));
                sen.word_count = 0;

                char* word_token = strtok(sentence_copy, " ");
                while (word_token != NULL) {
                    sen.data[sen.word_count].data = malloc(strlen(word_token) + 1);
                    strcpy(sen.data[sen.word_count].data, word_token);
                    sen.word_count++;
                    word_token = strtok(NULL, " ");
                }

                para.data[para.sentence_count++] = sen;

                free(sentence_copy);
            }

            sentence_start = *sentence_end == '.' ? sentence_end + 1 : NULL;
        }

        doc.data[doc.paragraph_count++] = para;

        free(paragraph_copy);

        paragraph_start = paragraph_end ? paragraph_end + 1 : NULL;
    }

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}