
const uint64_t MOD = 1ULL << 31;

uint64_t next(uint64_t x, uint64_t P, uint64_t Q) {
    return (x * P + Q) % MOD;
}

int main() {
    uint64_t N, S, P, Q;
    cin >> N >> S >> P >> Q;

    uint64_t power = 1, lam = 1;
    uint64_t tortoise = S;
    uint64_t hare = next(S, P, Q);

    while (tortoise != hare && lam < N) {
        if (power == lam) {
            tortoise = hare;
            power *= 2;
            lam = 0;
        }
        hare = next(hare, P, Q);
        ++lam;
    }

    uint64_t mu = 0;
    tortoise = S;
    hare = S;
    for (uint64_t i = 0; i < lam; ++i)
        hare = next(hare, P, Q);

    while (tortoise != hare && mu < N) {
        tortoise = next(tortoise, P, Q);
        hare = next(hare, P, Q);
        ++mu;
    }

    uint64_t result = (mu + lam) < N ? (mu + lam) : N;
    cout << result << endl;

    return 0;
}
