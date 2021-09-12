#include <iostream>

using namespace std;

struct Mobil {
  string merek, jenis, bahan_bakar;
  int velg, tahun;
  Mobil *prev;
  Mobil *next;
};

// Pointer global
Mobil *head, *tail, *curr, *newNode, *del;

// buat double linked list
void createDoubleLL(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  head = new Mobil();
  head -> merek = merek;
  head -> jenis = jenis;
  head -> bahan_bakar = bahan_bakar;
  head -> velg = velg;
  head -> tahun = tahun;
  head -> prev = NULL;
  head -> next = NULL;
  tail = head;
}

// menambahkan node di depan head
void inFrontHead(string merek, string jenis, string bahan_bakar, int velg, int tahun){
  if (head == NULL) {
    cout << "Double Linked List tidak tersedia" << endl;
  } else {
    newNode = new Mobil();
    newNode -> merek = merek;
    newNode -> jenis = jenis;
    newNode -> bahan_bakar = bahan_bakar;
    newNode -> velg = velg;
    newNode -> tahun = tahun;
    newNode -> prev = NULL;
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
  }
}

// menambahkan node di belakang tail
void behindTail(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  if (head == NULL) {
    cout << "Double Linked List tidak tersedia" << endl;
  } else {
    newNode = new Mobil();
    newNode -> merek = merek;
    newNode -> jenis = jenis;
    newNode -> bahan_bakar = bahan_bakar;
    newNode -> velg = velg;
    newNode -> tahun = tahun;
    newNode -> prev = tail;
    newNode -> next = NULL;
    tail -> next = newNode;
    tail = newNode;
  }
}

// menghapus node yang paling depan / head
void delHead() {
  del = head;
  head = head -> next;
  head -> prev = NULL;
  delete del;
}

// menghapus node paling belakang
void delTail() {
  del = tail;
  tail = tail -> prev;
  tail -> next = NULL;
  delete del;
}


// print double linked list
void printDoubleLL() {
  // cout << "Jumlah data: " << countSinleLL() << endl;
  if (head == NULL) {
    cout << "Double Linked List tidak tersedia" << endl;
  } else {
    curr = head;
    cout << "%%%%%%%%%%%%%%%\n" << endl;
    while (curr != NULL) {
      cout << "Merek Mobil: " << curr -> merek << endl;
      cout << "Jenis Mobil: " << curr -> jenis << endl;
      cout << "Bahan Bakar Mobil: " << curr -> bahan_bakar << endl;
      cout << "Ukruran Velg Mobil: " << curr -> velg << endl;
      cout << "Tahun Terbit Mobil: " << curr -> tahun << "\n" << endl;

      // step
      curr = curr -> next;
    }
  }
}

int main() {
  createDoubleLL("Nissan X Trail", "SUV", "Bensin", 19, 2000);
  printDoubleLL();

  inFrontHead("Honda Odyssey", "MPV", "Bensin", 17, 1994);
  printDoubleLL();

  behindTail("Mitsubishi Outlander", "SUV", "Bensin", 18, 2012);
  printDoubleLL();

  delHead();
  printDoubleLL();

  delTail();
  printDoubleLL();

}
