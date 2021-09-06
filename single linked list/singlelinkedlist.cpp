#include <iostream>

using namespace std;

struct Mobil {
  string merek, jenis, bahan_bakar;
  int velg, tahun;

  Mobil *next;
};

Mobil *head, *tail, *curr;

void CreateLinkedList(string merek, string jenis, string bahan_bakar, int velg, int tahun){
  head = new Mobil();
  head -> merek = merek;
  head -> jenis = jenis;
  head -> bahan_bakar = bahan_bakar;
  head -> velg = velg;
  head -> tahun = tahun;
  head -> next = NULL;
  tail = head;
}

void PrintSingleLInkedLIst() {
  curr = head;
  while (curr != NULL) {
    cout << "Merek Mobil: " << curr -> merek << endl;
    cout << "Jenis Mobil: " << curr -> jenis << endl;
    cout << "Bahan Bakar Mobil: " << curr -> bahan_bakar << endl;
    cout << "Ukruran Velg Mobil: " << curr -> velg << endl;
    cout << "Tahun Terbit Mobil: " << curr -> tahun << endl;

    curr = curr -> next;
  }
}

int main() {
  CreateLinkedList("Nissan X Trail", "SUV", "Bensin", 19, 2000);

  PrintSingleLInkedLIst();
}
