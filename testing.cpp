#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// Definisi struktur Makanan
struct Makanan {
    string nama;
    double harga;
    Makanan(string n, double h) : nama(n), harga(h) {}
};

// Definisi Node
struct Node {
    Makanan data;
    Node* next;
    Node(Makanan makanan) : data(makanan), next(nullptr) {}
};

// Definisi Linked List
class LinkedList {
public:
    Node* head;

    // Konstruktor
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan node di akhir
    void insertAtEnd(Makanan makanan) {
        Node* newNode = new Node(makanan);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Fungsi untuk menghapus node di awal
    void deleteAtBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Fungsi untuk menghapus node terakhir
    void deleteAtEnd() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // Fungsi untuk menghitung jumlah data/node
    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk mengubah data di tengah
    void updateData(int position, Makanan newMakanan) {
        Node* current = head;
        int count = 0;
        while (current) {
            if (count == position) {
                current->data = newMakanan;
                return;
            }
            count++;
            current = current->next;
        }
    }

    // Fungsi untuk mencetak isi linked list
    void printList() {
        Node* current = head;
        int i = 1;

        while (current) {
            cout << "\n" << i << ". Nama: " << current->data.nama << ", Harga: " << current->data.harga << "K -> " ;
            current = current->next;
            i++;
        }
        cout << "nullptr" << endl;
    }
};

int main() {

    string name;
    double price;

    LinkedList makananList;

    cout << "------Insert data di akhir!------" << endl;
    cout << "Input nama makanan:" << endl;
    std:: getline(std::cin, name);

    cout << "\nInput harga makanan:" << endl;
    cin >> price;

    Makanan makanan1("Rujak Cingur", 12.000);
    Makanan makanan2("Nasi Campur", 14.000);
    Makanan makanan3("Nasi Pecel", 10.000);
    Makanan makanan4(name, price);

    makananList.insertAtEnd(makanan1);
    makananList.insertAtEnd(makanan2);
    makananList.insertAtEnd(makanan3);
    makananList.insertAtEnd(makanan4);

    cout << "\nData masuk:";
    makananList.printList();

    makananList.deleteAtBeginning();
    cout << "\nSetelah menghapus di awal:";
    makananList.printList();

    makananList.deleteAtEnd();
    cout << "\nSetelah menghapus di akhir:";
    makananList.printList();

    int count = makananList.countNodes();
    cout << "\nJumlah Data Makanan: " << count << endl;

    Makanan newMakanan("Bakso", 5.000);
    makananList.updateData(1, newMakanan);
    cout << "\nSetelah mengubah data di tengah:";
    makananList.printList();

    return 0;
}
