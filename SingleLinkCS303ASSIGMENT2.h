#pragma once
#include <iostream>


template <typename Item_Type> // from lecture
struct Node {
    Item_Type data;
    Node* next;

    Node(const Item_Type& data, Node* next = nullptr)
        : data(data), next(next) {
    }
};

template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor to free memory
    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }

    // Add to front
    void push_front(const Item_Type& item) {
        Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
        head = new_node;
        if (tail == nullptr) {  // If the list was empty
            tail = new_node;
        }
        num_items++;
    }

    // Add to back
    void push_back(const Item_Type& item) {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        if (tail == nullptr) {  // If the list was empty
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        num_items++;
    }

    // Remove from front
    void pop_front() {
        if (head == nullptr) return;
        Node<Item_Type>* temp = head;
        head = head->next;
        if (head == nullptr) {  // If the list is now empty
            tail = nullptr;
        }
        delete temp;
        num_items--;
    }

    // Remove from back
    void pop_back() {
        if (head == nullptr) return;
        if (head == tail) { // Only one node
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<Item_Type>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        num_items--;
    }

    // Get front element
    Item_Type front() const {
        if (head == nullptr) throw std::runtime_error("List is empty");
        return head->data;
    }

    // Get back element
    Item_Type back() const {
        if (tail == nullptr) throw std::runtime_error("List is empty");
        return tail->data;
    }

    // Check if list is empty
    bool empty() const {
        return num_items == 0;
    }

    // Insert at index
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
            return;
        }
        if (index >= num_items) {
            push_back(item);
            return;
        }
        Node<Item_Type>* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        temp->next = new Node<Item_Type>(item, temp->next);
        num_items++;
    }

    // Remove at index
    bool remove(size_t index) {
        if (index >= num_items) return false;
        if (index == 0) {
            pop_front();
            return true;
        }
        Node<Item_Type>* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node<Item_Type>* to_delete = temp->next;
        temp->next = to_delete->next;
        if (to_delete == tail) {
            tail = temp;
        }
        delete to_delete;
        num_items--;
        return true;
    }

    // Find an item in the list
    size_t find(const Item_Type& item) const {
        Node<Item_Type>* temp = head;
        size_t index = 0;
        while (temp) {
            if (temp->data == item) return index;
            temp = temp->next;
            index++;
        }
        return num_items; // Not found
    }

    // Getter for num_items to use for printing
    size_t get_size() const {
        return num_items;
    }

    // Getter for head
    Node<Item_Type>* get_head() const {
        return head;
    }
};

// Template function to print the list
template <typename Item_Type>
void print_list(Single_Linked_List<Item_Type>& list) {
    std::cout << "List: ";
    Node<Item_Type>* current = list.get_head(); // Use the getter for head
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}







