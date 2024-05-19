#include <iostream>

using namespace std;

// Node class
int main() {
    // Coba deklarasi pointer menggunakan nullptr
class Node {
public:
    int data;
    Node* next;
    Node* ptr = nullptr;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Menambahkan node di awal linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Menghapus node dengan nilai tertentu
    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = nullptr;

        // Mencari node yang akan dihapus
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == nullptr)
            return;

        // Menghapus node
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }

    // Mencari node dengan nilai tertentu
    bool search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Memperbarui nilai node dengan nilai baru
    void update(int oldData, int newData) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == oldData) {
                temp->data = newData;
                return;
            }
            temp = temp->next;
        }
        cout << "Data not found." << endl;
    }

    // Membalik linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Menampilkan linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Penyisipan
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    cout << "Linked list setelah penyisipan: ";
    list.display();

    // Penghapusan
    list.deleteNode(2);
    cout << "Linked list setelah penghapusan: ";
    list.display();

    // Penelusuran Pencarian
    int searchKey = 3;
    cout << "Apakah " << searchKey << " ditemukan? ";
    if (list.search(searchKey))
        cout << "Ya" << endl;
    else
        cout << "Tidak" << endl;

    // Pembaruan
    list.update(3, 4);
    cout << "Linked list setelah pembaruan: ";
    list.display();

    // Pembalikan
    list.reverse();
    cout << "Linked list setelah pembalikan: ";
    list.display();

    return 0;
}

 81 changes: 81 additions & 0 deletions81  
queuee.cpp
-0,0 +1,81
#include <iostream>//Rafi Daniswara Putra Widiatnoko //202332146
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

 32 changes: 32 additions & 0 deletions32  
selectionsort.cpp
@@ -0,0 +1,32 @@
#include <iostream>
using namespace std;

void selectionsort (int arr[], int n)
{
	int i , j , mi n_ i dx;
	for (i = 0; i < n - 1; i++){
		mi n _ i dx = i ;
		for (j = i + 1; j < n; j++){
			if (arr[j] < arr [mi n_ i dx])
				mi n_i dx= j;
		}
		if (min_idx != i)
			swap (arr [mi n_i dx], arr[i]);
	}
}
void cetak (int arr[], int size)
{
	int i; 
	for (i = 0; i < size; i++){
		cout << arr [i] << " ";
		cout << endl;
	}
}
int main ()
{
	int arr [] = { 64, 25, 12, 22, 11 };
	int n = sizeof (arr) / sizeof (arr[0]);
	selection sort (arr, n)
	cetak (arr, n)
	return 0;
}
