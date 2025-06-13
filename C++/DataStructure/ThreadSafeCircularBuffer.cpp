#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <semaphore>

template <typename T>
class CircularBuffer {
public:
    CircularBuffer(size_t capacity)
        : capacity_(capacity), buffer_(std::make_unique<T[]>(capacity)), head_(0), tail_(0), size_(0),
          empty_slots_(capacity), filled_slots_(0) {}

    void push(const T& item) {
        empty_slots_.acquire();
        {
            std::lock_guard<std::mutex> lock(mutex_);
            buffer_[tail_] = item;
            tail_ = (tail_ + 1) % capacity_;
            ++size_;
        }
        filled_slots_.release();
    }

    T pop() {
        filled_slots_.acquire();
        T item;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            item = buffer_[head_];
            head_ = (head_ + 1) % capacity_;
            --size_;
        }
        empty_slots_.release();
        return item;
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return size_;
    }

    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return size_ == 0;
    }

    bool isFull() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return size_ == capacity_;
    }

private:
    size_t capacity_;
    std::unique_ptr<T[]> buffer_;
    size_t head_;
    size_t tail_;
    size_t size_;
    mutable std::mutex mutex_;
    std::counting_semaphore<> empty_slots_;
    std::counting_semaphore<> filled_slots_;
};

int main() {
    CircularBuffer<int> buffer(5);

    // Example usage
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);

    std::cout << "Popped: " << buffer.pop() << std::endl;
    std::cout << "Popped: " << buffer.pop() << std::endl;

    buffer.push(4);
    buffer.push(5);

    while (!buffer.isEmpty()) {
        std::cout << "Popped: " << buffer.pop() << std::endl;
    }

    return 0;
}
