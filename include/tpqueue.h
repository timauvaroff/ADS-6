// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T* arr;
    int begin;
    int end;
    int count;
    int step_back(int index) const
    {
        int res = --index;
        if (res < 0)
            res += size + 1;
        return res;
    }
    int step_forward(int index) const
    {
        int res = ++index;
        if (res > size)
            res -= size + 1;
        return res;
    }
public:
    TPQueue() : begin(0), end(0), count(0)
    {
        arr = new T[size + 1];
    }
    ~TPQueue()
    {
        delete[] arr;
    }
    void push(const T& item)
    {
        assert(count < size);
        int current = end;
        while (current != begin && item.prior > arr[step_back(current)].prior)
        {
            arr[current] = arr[step_back(current)];
            current = step_back(current);
        }
        arr[current] = item;
        end = step_forward(end);
        count++;
    }
    T pop()
    {
        assert(count > 0);
        T item = arr[begin];
        begin = step_forward(begin);
        count--;
        return item;
    }

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
