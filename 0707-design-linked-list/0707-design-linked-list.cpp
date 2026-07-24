class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class MyLinkedList {
private:
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {

        if (index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    void addAtHead(int val) {

        Node* n = new Node(val);

        n->next = head;

        if (head != NULL) {
            head->prev = n;
        }

        head = n;
        size++;
    }

    void addAtTail(int val) {

        Node* n = new Node(val);

        if (head == NULL) {
            head = n;
            size++;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = n;
        n->prev = temp;

        size++;
    }

    void addAtIndex(int index, int val) {

        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* n = new Node(val);

        n->next = temp->next;
        n->prev = temp;

        temp->next->prev = n;
        temp->next = n;

        size++;
    }

    void deleteAtIndex(int index) {

        if (index < 0 || index >= size)
            return;

        if (index == 0) {

            Node* temp = head;
            head = head->next;

            if (head != NULL)
                head->prev = NULL;

            delete temp;
            size--;

            return;
        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */