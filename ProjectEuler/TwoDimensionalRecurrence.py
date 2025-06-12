MOD = 1123581313

class FibonacciSumCalculator:
    def __init__(self, k):
        self.k = k
        self.fib = self._generate_fibonacci(k)

    def _generate_fibonacci(self, n):
        fib = [0, 1]
        for _ in range(2, n + 1):
            fib.append(fib[-1] + fib[-2])
        return fib

    def _mod_pow(self, base, exp):
        result = 1
        base = base % MOD
        while exp > 0:
            if exp % 2:
                result = (result * base) % MOD
            base = (base * base) % MOD
            exp //= 2
        return result

    def _compute_power_sum(self, base):
        total = 0
        for f in self.fib[2:]:  # skipping f_0 and f_1
            total = (total + self._mod_pow(base, f)) % MOD
        return total

    def compute_s(self):
        # Compute S(k) using the sum of A(f_i, f_j)
        total = 0
        for i in range(2, self.k + 1):
            for j in range(2, self.k + 1):
                total = (total + self._compute_power_sum(self.fib[i])) % MOD
        return total

def main():
    calculator = FibonacciSumCalculator(10)
    result = calculator.compute_s()
    print(f"S(10) = {result}")

    calculator = FibonacciSumCalculator(50)
    result = calculator.compute_s()
    print(f"S(50) = {result}")

    calculator = FibonacciSumCalculator(5)
    result = calculator.compute_s()
    print(f"S(5) = {result}")

if __name__ == "__main__":
    main()
