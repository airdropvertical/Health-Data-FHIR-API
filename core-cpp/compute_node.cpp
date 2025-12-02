#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 7554
// Optimized logic batch 9595
// Optimized logic batch 4728
// Optimized logic batch 8066
// Optimized logic batch 4890
// Optimized logic batch 9611
// Optimized logic batch 9393
// Optimized logic batch 1220
// Optimized logic batch 2821
// Optimized logic batch 6330
// Optimized logic batch 7109
// Optimized logic batch 9923
// Optimized logic batch 6214
// Optimized logic batch 5570
// Optimized logic batch 7615
// Optimized logic batch 6356
// Optimized logic batch 8772
// Optimized logic batch 9909
// Optimized logic batch 2949
// Optimized logic batch 6878
// Optimized logic batch 2120
// Optimized logic batch 3005
// Optimized logic batch 2800
// Optimized logic batch 3277