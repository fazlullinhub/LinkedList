#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void add(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(T val) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current) {
            if (current->data == val) {
                if (current == head) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }

                if (current == tail) {
                    tail = previous;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    Node<T>* find(T val) {
        Node<T>* current = head;

        while (current) {
            if (current->data == val) {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    void printList() {
        Node<T>* current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);

    std::cout << "Initial list: ";
    list.printList();

    int valueToFind = 2;
    Node<int>* foundNode = list.find(valueToFind);
    if (foundNode) {
        std::cout << "Found value " << foundNode->data << std::endl;
    }
    else {
        std::cout << "Value not found" << std::endl;
    }

    int valueToRemove = 2;
    bool removed = list.remove(valueToRemove);
    if (removed) {
        std::cout << "Value " << valueToRemove << " removed" << std::endl;
    }
    else {
        std::cout << "Value not found for removal" << std::endl;
    }

    std::cout << "List after removal: ";
    list.printList();

    return 0;
}