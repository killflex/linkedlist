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
    Node* prev;
    Node(Makanan makanan) : data(makanan), next(nullptr), prev(nullptr) {}
};

// Definisi Double Linked List
class DoubleLinkedList {
public:
    Node* head;
    Node* tail;

    // Konstruktor
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    // Fungsi untuk menambahkan node di akhir
    void insertAtEnd(Makanan makanan) {
        Node* newNode = new Node(makanan);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Fungsi untuk menghapus node di awal
    void deleteAtBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
        }
    }

    // Fungsi untuk menghapus node di akhir
    void deleteAtEnd() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            delete temp;
        }
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
    // void printList() {
    //     Node* current = head;
    //     while (current) {
    //         std::cout << "Nama: " << current->data.nama << ", Harga: " << current->data.harga << " -> ";
    //         current = current->next;
    //     }
    //     std::cout << "nullptr" << std::endl;
    // }
};

int main() {

    string name;
    double price;

    DoubleLinkedList makananList;

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

    // DoubleLinkedList makananList;

    // Makanan makanan1("Nasi Goreng", 10.5);
    // Makanan makanan2("Mie Ayam", 8.0);
    // Makanan makanan3("Sate Ayam", 12.0);

    // makananList.insertAtEnd(makanan1);
    // makananList.insertAtEnd(makanan2);
    // makananList.insertAtEnd(makanan3);

    // std::cout << "Daftar Makanan:" << std::endl;
    // makananList.printList();

    // makananList.deleteAtBeginning();
    // std::cout << "Setelah menghapus di awal:" << std::endl;
    // makananList.printList();

    // makananList.deleteAtEnd();
    // std::cout << "Setelah menghapus di akhir:" << std.endl;
    // makananList.printList();

    // int count = makananList.countNodes();
    // std::cout << "Jumlah Makanan: " << count << std::endl;

    // Makanan newMakanan("Bakso", 7.5);
    // makananList.updateData(1, newMakanan);
    // std::cout << "Setelah mengubah data di tengah:" << std::endl;
    // makananList.printList();

    // return 0;
}
