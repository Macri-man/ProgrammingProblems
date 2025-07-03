func kthCharacter(k int) byte {
	word := []byte{'a'}

	for len(word) < k {
		n := len(word)
		nextPart := make([]byte, n)
		for i := 0; i < n; i++ {
			nextPart[i] = (word[i]-'a'+1)%26 + 'a'
		}
		word = append(word, nextPart...)
	}

	return word[k-1]
}
