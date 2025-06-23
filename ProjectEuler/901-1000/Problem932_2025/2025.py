class TwentyTwentyFiveNumberFinder:
    def __init__(self, max_digits):
        self.max_digits = max_digits

    def is_2025_number(self, a, b):
        ab = int(f"{a}{b}")  # Concatenate a and b as a string
        return ab == (a + b) ** 2

    def find_sum_up_to(self, target_digits):
        total = 0
        seen = set()

        # Calculate the sum of 2025-numbers for all digit lengths up to target_digits
        for total_digits in range(1, target_digits + 1):
            for b_digits in range(1, total_digits):
                a_digits = total_digits - b_digits
                a_min = 10 ** (a_digits - 1) if a_digits > 1 else 1
                a_max = 10 ** a_digits
                b_min = 10 ** (b_digits - 1) if b_digits > 1 else 1
                b_max = 10 ** b_digits

                for a in range(a_min, a_max):
                    for b in range(b_min, b_max):
                        if self.is_2025_number(a, b):
                            ab = int(f"{a}{b}")  # Concatenate a and b
                            if ab not in seen:
                                seen.add(ab)
                                total += ab
        return total


def main():
    
     # We compute T(4) using the optimized method
    finder = TwentyTwentyFiveNumberFinder(5)
    result = finder.find_sum_up_to(5)
    
    print(f"T(5) = {result}")

    # We compute T(4) using the optimized method
    finder = TwentyTwentyFiveNumberFinder(4)
    result = finder.find_sum_up_to(4)
    
    print(f"T(4) = {result}")  # This should output 5131

if __name__ == "__main__":
    main()
