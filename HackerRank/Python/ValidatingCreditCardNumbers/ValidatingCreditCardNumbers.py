import re

def is_valid(card):
    if not re.fullmatch(r'(?:\d{16}|\d{4}-\d{4}-\d{4}-\d{4})', card):
        return False

    digits = card.replace('-', '')

    if digits[0] not in '456':
        return False

    if re.search(r'(\d)\1{3,}', digits):
        return False

    return True

n = int(input())
for _ in range(n):
    card = input().strip()
    print('Valid' if is_valid(card) else 'Invalid')