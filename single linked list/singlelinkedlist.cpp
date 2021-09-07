#include <iostream>

using namespace std;

struct Mobil {
  string merek, jenis, bahan_bakar;
  int velg, tahun;

  Mobil *next;
};

Mobil *head, *tail, *curr, *newNode, *del, *before;

// membuat single linked list
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

// menambahkan node didepan head kemudian dijadikan head
void MoveHead(string merek, string jenis, string bahan_bakar, int velg, int tahun){
  newNode = new Mobil();
  newNode -> merek = merek;
  newNode -> jenis = jenis;
  newNode -> bahan_bakar = bahan_bakar;
  newNode -> velg = velg;
  newNode -> tahun = tahun;
  newNode -> next = head;
  head = newNode;
}

// menambahkan node baru di tengah
void addMiddle(string merek, string jenis, string bahan_bakar, int velg, int tahun, int posisi) {
  newNode = new Mobil();
  newNode -> merek = merek;
  newNode -> jenis = jenis;
  newNode -> bahan_bakar = bahan_bakar;
  newNode -> velg = velg;
  newNode -> tahun = tahun;

  // tranversing
  curr = head;
  int num = 1;
  while (num < posisi-1) {
    curr = curr -> next;
    num++;
  }
  newNode -> next = curr -> next;
  curr -> next = newNode;
}

void AddTail(string merek, string jenis, string bahan_bakar, int velg, int tahun){
  newNode = new Mobil();
  newNode -> merek = merek;
  newNode -> jenis = jenis;
  newNode -> bahan_bakar = bahan_bakar;
  newNode -> velg = velg;
  newNode -> tahun = tahun;
  newNode -> next = NULL;
  tail -> next = newNode;
  tail = newNode;
}

// remove Head
void RemoveHead(){
  del = head;
  head = head -> next;
  delete del;
}

// remove middle
void RemoveMiddle(int posisi) {
  int num = 1;
  curr = head;
  while (num <= posisi) {
    if (num == posisi - 1) {
      before = curr;
    }
    if (num == posisi) {
      del = curr;
    }
    curr = curr -> next;
    num++;
  }
  before -> next = curr;
  delete del;
}

// remove tail
void RemoveTail() {
  del = tail;
  curr = head;
  while (curr != tail){
    curr = curr -> next;
  }
  tail = curr;
  tail = NULL;
  delete del;
}

// mengubah Head
void ChangeHead(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  head -> merek = merek;
  head -> jenis = jenis;
  head -> bahan_bakar = bahan_bakar;
  head -> velg = velg;
  head -> tahun = tahun;
}

// mengubah tail
void ChangeTail(string merek, string jenis, string bahan_bakar, int velg, int tahun) {
  tail -> merek = merek;
  tail -> jenis = jenis;
  tail -> bahan_bakar = bahan_bakar;
  tail -> velg = velg;
  tail -> tahun = tahun;
}

// mengeprint hasil single linked list
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
  CreateLinkedList("Nissan X Trail", "SUV", "Bensin", 19, 2000);  // mengisi linked list

  PrintSingleLInkedLIst();  // memanggil fungsi print single linked list

  cout << "\n\nSetelah Head Digeser" << endl;

  MoveHead("Honda Odyssey", "MPV", "Bensin", 17, 1994); //menggeser head sebelumnya

  PrintSingleLInkedLIst();

  cout << "\n\nSetelah Tail Ditambahkan" << endl;

  AddTail("Suzuki Vitara", "SUV", "Diesel", 16, 1998);

  PrintSingleLInkedLIst();

  cout << "\n\nSetelah head dihpaus" << endl;

  RemoveHead();

  PrintSingleLInkedLIst();

  cout << "\n\n\n" << endl;

  AddTail("Honda Odyssey", "MPV", "Bensin", 17, 1994);

  cout << "\n\nSetelah ditambah di tengah" << endl;

  addMiddle("Mitsubishi Triton", "Pickup Truck", "Diesel", 16, 2019, 2);

  PrintSingleLInkedLIst();

  cout << "\n\nSetelah node tengah di hapus" << endl;

  RemoveMiddle(3);

  PrintSingleLInkedLIst();
}
