#!/bin/python3

import re
import sys
from collections import defaultdict

def most_frequent_trigram(text):
    trigram_count = defaultdict(int)
    trigram_first_occurrence = {}
    index = 0

    # Split by period to get sentences
    sentences = text.strip().split('.')
    
    for sentence in sentences:
        # Normalize to lowercase and trim
        sentence = sentence.strip().lower()
        if not sentence:
            continue

        # Get words (alphabets only)
        words = re.findall(r'\b[a-z]+\b', sentence)
        
        # Form trigrams
        for i in range(len(words) - 2):
            trigram = ' '.join(words[i:i+3])
            trigram_count[trigram] += 1
            if trigram not in trigram_first_occurrence:
                trigram_first_occurrence[trigram] = index
            index += 1

    # Find the trigram with the highest frequency and earliest occurrence
    most_common = max(trigram_count.items(), key=lambda x: (x[1], -trigram_first_occurrence[x[0]]))
    return most_common[0]

if __name__ == '__main__':
    s = input()
    result = most_frequent_trigram(s)
    print(result)
