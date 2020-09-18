// Author: Joseph Kuhn

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class node {
    public:
        int value;
        node *next;
        node()
        {
            value = 0;
            next = nullptr;
        }
        ~node() {}
};

class linkedList {
    private:
        node *head;
        int length;
    public:
        linkedList() : head(NULL), length(0){}
        void addToEnd(int item)
        {
            node *create = new node;
            create->value = item;
            length++;
            create->next = NULL;
            if (head == NULL) {
                head = create;
            }
            else {
                node *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = create;
            }
        }
        bool checkEven(int index) {
            node *temp = head;
            node *temp2;
            if (head->next != NULL) {
                temp2 = head->next;
            }
            if (index == 0) {
                if (head->value % 2 == 0) {
                    return true;
                }
            }
            else {
                for (int i = 0; i < index - 1; i++) {
                    temp2 = temp2->next;
                    temp = temp->next;
                }
                if (temp2->value % 2 == 0) {
                    return true;
                }
            }
            return false;
        }
        vector<int> deleteEven() {
            vector<int> v;
            node *temp = head;
            node *temp2;
            if (head->next == NULL) {
                if (head->value % 2 == 0) {
                    v.push_back(head->value);
                    length--;
                    delete head;
                    return v;
                }
                return v;
            }
            temp2 = head->next;
            while (temp2 != NULL) {
                if (head->value % 2 == 0) {
                    v.push_back(head->value);
                    temp = head->next;
                    length--;
                    delete head;
                    head = temp;
                    temp2 = head->next;
                }
                else if (temp2->value % 2 == 0) {
                    v.push_back(temp2->value);
                    temp->next = temp2->next;
                    length--;
                    delete temp2;
                    temp2 = temp->next;
                }
                else {
                    temp2 = temp2->next;
                    temp = temp->next;
                }
            }
            if (head->next == NULL) {
                if (head->value % 2 == 0) {
                    v.push_back(head->value);
                    length--;
                    delete head;
                    return v;
                }
            }
            return v;
        }
        void merge(linkedList listB) {
            node *Atemp = this->head;
            node *Btemp = listB.head;
            if (this->length == 0) {
                this->length += listB.length;
                this->head = listB.head;
                return;
            }
            if (listB.length == 0) {
                return;
            }
            node *Btemp2 = listB.head->next;
            Btemp->next = Atemp;
            this->head = Btemp;
            this->length++;
            if (listB.length == 1) {
                return;
            }
            Btemp = Btemp2;
            while (Btemp2 != NULL) {
                if (Atemp->next == NULL) {
                    Atemp->next = Btemp;
                    Btemp2 = NULL;
                }
                else {
                    Btemp2 = Btemp2->next;
                    Btemp->next = Atemp->next;
                    Atemp->next = Btemp;
                    Atemp = Atemp->next->next;
                    Btemp = Btemp2;
                }
                this->length++;
            }
            return;
        }
        void printList() {
            node *temp = head;
            for (int i = 0; i < length; i++)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
};

int main() {
    int x;
    linkedList listA, listB;
    int num;
    ifstream file;
    file.open("hw5.dat");
    while (file >> num) {
        listA.addToEnd(num); 
    }
    vector<int> v = listA.deleteEven();
    for (int i = 0; i < v.size(); i++) {
        listB.addToEnd(v[i]);
    }
    listA.merge(listB);
    listA.printList();
}
