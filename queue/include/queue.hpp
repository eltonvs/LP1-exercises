#ifndef _queue_hpp_
#define _queue_hpp_

template <typename Data>
class Queue {
 public:
    Queue(const int _SIZE);
    bool enqueue(const Data);
    bool dequeue(Data &);
    bool front(Data &) const;

 private:
    Data *m_list = nullptr;
    int m_SIZE = 0;
    int m_f = -1;
    int m_b = -1;
};

#endif