#include <iostream>//Rafi Daniswara P.W (202332146)
#define MAX 100 // Maksimum ukuran queue

class Queue {
private:
    int front, rear, size;
    int* queue;

public:
    Queue(int s = MAX) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue is full!" << std::endl;
            return;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % size;
            queue[rear] = value;
            std::cout << "Inserted " << value << std::endl;
        }
    }

    void dequeue() {
        if (front == -1) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Deleted " << queue[front] << std::endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Queue elements are: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            std::cout << queue[i] << " ";
        }
        std::cout << queue[rear] << std::endl;
    }
};

int main() {
    Queue q(5); // Membuat queue dengan ukuran maksimum 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}

