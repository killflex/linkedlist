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
        while (current) {
            cout << "Nama: " << current->data.nama << ", Harga: " << current->data.harga << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {

    string name;
    double price;

    LinkedList makananList;

    cout << "Input nama makanan:";
    cin >> name;

    cout << "\nInput nama harga:";
    cin >> price;

    Makanan makanan1("Nasi Goreng", 10.500);
    Makanan makanan2("Mie Ayam", 8.000);
    Makanan makanan3("Sate Ayam", 12.000);
    Makanan makanan4(name, price);

    makananList.insertAtEnd(makanan1);
    makananList.insertAtEnd(makanan2);
    makananList.insertAtEnd(makanan3);
    makananList.insertAtEnd(makanan4);

    cout << "\nData masuk:" << endl;
    makananList.printList();

    makananList.deleteAtBeginning();
    cout << "\nSetelah menghapus di awal:" << endl;
    makananList.printList();

    makananList.deleteAtEnd();
    cout << "\nSetelah menghapus di akhir:" << endl;
    makananList.printList();

    int count = makananList.countNodes();
    cout << "\nJumlah Makanan: " << count << endl;

    Makanan newMakanan("Bakso", 7.500);
    makananList.updateData(1, newMakanan);
    cout << "\nSetelah mengubah data di tengah:" << endl;
    makananList.printList();

    return 0;
}
