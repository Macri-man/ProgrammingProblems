#include <mutex>
#include <functional>
#include <array>

class DiningPhilosophers {
private:
    std::array<std::mutex, 5> forks;

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        std::unique_lock<std::mutex> firstFork(forks[std::min(left, right)]);
        std::unique_lock<std::mutex> secondFork(forks[std::max(left, right)]);

        if (left < right) {
            pickLeftFork();
            pickRightFork();
        } else {
            pickRightFork();
            pickLeftFork();
        }

        eat();

        putLeftFork();
        putRightFork();
    }
};
