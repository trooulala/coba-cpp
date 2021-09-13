#include <iostream>

using namespace std;

struct Mobil {
  string merek, jenis, bahan_bakar;
  int velg, tahun;
  Mobil *next;
};

// pointer global
Mobil *head, *tail, *curr, *newNode, *del;

void createcSingle(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  head = new Mobil();
  head -> merek = merek;
  head -> jenis = jenis;
  head -> bahan_bakar = bahan_bakar;
  head -> velg = velg;
  head -> tahun = tahun;
  tail = head;
  tail -> next = head;
}

// menambahkan node di depan head
void addInFront(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  newNode = new Mobil();
  newNode -> merek = merek;
  newNode -> jenis = jenis;
  newNode -> bahan_bakar = bahan_bakar;
  newNode -> velg = velg;
  newNode -> tahun = tahun;
  newNode -> next = head;
  tail -> next = newNode;
  head = newNode;
}

// menampilkan node
void printcSingle() {
  cout << "\n\tDaftar Mobil" << endl;
  curr = head;
  while (curr -> next != head) {
    cout << "Merek Mobil: " << curr -> merek << endl;
    cout << "Jenis Mobil: " << curr -> jenis << endl;
    cout << "Bahan Bakar Mobil: " << curr -> bahan_bakar << endl;
    cout << "Ukruran Velg Mobil: " << curr -> velg << endl;
    cout << "Tahun Terbit Mobil: " << curr -> tahun << endl;
    cout << "--------------------------" << endl;
    // step
    curr = curr -> next;
  }
  cout << "Merek Mobil: " << curr -> merek << endl;
  cout << "Jenis Mobil: " << curr -> jenis << endl;
  cout << "Bahan Bakar Mobil: " << curr -> bahan_bakar << endl;
  cout << "Ukruran Velg Mobil: " << curr -> velg << endl;
  cout << "Tahun Terbit Mobil: " << curr -> tahun << endl;
  cout << "--------------------------" << endl;
}


int main() {
  createcSingle("BMW 4 Series Coupe", "Coupe", "Bensin", 19, 2018);
  printcSingle();

  addInFront("Suzuki Vitara", "SUV", "Diesel", 16, 1997);
  printcSingle();
}
