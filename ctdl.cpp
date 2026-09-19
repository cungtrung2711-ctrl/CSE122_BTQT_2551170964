#include <iostream>
using namespace std;

typedef int T;

struct Queue {
    T* array;
    int front, back, size, capacity;
};

// Khai báo nguyên m?u hàm
void queueInit(Queue& q, int capacity);
bool queueIsFull(Queue& q);
bool queueIsEmpty(Queue& q);
void enQueue(Queue& q, T e);
void deQueue(Queue& q);
void printQueue(Queue& q);
void queueDestroy(Queue& q);

int main() {
    Queue q;
    int cap, choice, val;

    cout << "Nhap dung luong (capacity) cua hang doi: ";
    cin >> cap;
    queueInit(q, cap);

    while (true) {
        cout << "\n--- MENU HANG DOI ---" << endl;
        cout << "1. enQueue | 2. deQueue | 3. Xem trang thai | 4. Thoat" << endl;
        cout << "Chon: "; cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri: "; cin >> val;
                enQueue(q, val);
                printQueue(q); 
                break;
            case 2:
                deQueue(q);
                printQueue(q);
                break;
            case 3:
                printQueue(q);
                break;
            default:
                cout << "Lua chon sai!" << endl;
        }
    }

    queueDestroy(q);
    return 0;
}

void queueInit(Queue& q, int capacity) {
    q.capacity = capacity;
    q.array = new T[q.capacity];
    q.front = 0; q.back = -1; q.size = 0;
}

bool queueIsFull(Queue& q) { return q.size == q.capacity; }
bool queueIsEmpty(Queue& q) { return q.size == 0; }

void enQueue(Queue& q, T e) {
    if (queueIsFull(q)) { cout << "-> Loi: Hang doi da day!\n"; return; }
    q.back = (q.back + 1) % q.capacity;
    q.array[q.back] = e;
    q.size++;
    cout << "-> Da them " << e << " vao hang doi.\n";
}

void deQueue(Queue& q) {
    if (queueIsEmpty(q)) { cout << "-> Loi: Hang doi rong!\n"; return; }
    cout << "-> Da lay phan tu " << q.array[q.front] << " ra.\n";
    q.front = (q.front + 1) % q.capacity;
    q.size--;
}

void printQueue(Queue& q) {
    cout << "\n[TRANG THAI] front: " << q.front 
         << " | back: " << q.back 
         << " | size: " << q.size 
         << " | capacity: " << q.capacity << endl;
    
    cout << "Du lieu trong hang doi (theo thu tu FIFO): ";
    for (int i = 0; i < q.size; i++) 
        cout << q.array[(q.front + i) % q.capacity] << " ";
}

void queueDestroy(Queue& q) { delete[] q.array; }
