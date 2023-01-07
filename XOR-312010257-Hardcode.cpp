#include <iostream>
#include <string>

using namespace std;
string text="Saya harus lulus tepat waktu dan menjadi sarjana";
string encrypt(string plaintext, int key) {
  string ciphertext = "";

  // Enkripsi setiap karakter dari plaintext
  for (int i = 0; i < plaintext.length(); i++) {
    char c = plaintext[i];

    // Jika karakter merupakan huruf kecil
    if (c >= 'a' && c <= 'z') {
      c = c + key;
      if (c > 'z') {
        c = c - 'z' + 'a' - 1;
      }
    }
    // Jika karakter merupakan huruf besar
    else if (c >= 'A' && c <= 'Z') {
      c = c + key;
      if (c > 'Z') {
        c = c - 'Z' + 'A' - 1;
      }
    }
    ciphertext += c;
  }

  return ciphertext;
}

string decrypt(string ciphertext, int key) {
  string plaintext = "";

  // Dekripsi setiap karakter dari ciphertext
  for (int i = 0; i < ciphertext.length(); i++) {
    char c = ciphertext[i];

    // Jika karakter merupakan huruf kecil
    if (c >= 'a' && c <= 'z') {
      c = c - key;
      if (c < 'a') {
        c = c + 'z' - 'a' + 1;
      }
    }
    // Jika karakter merupakan huruf besar
    else if (c >= 'A' && c <= 'Z') {
      c = c - key;
      if (c < 'A') {
        c = c + 'Z' - 'A' + 1;
      }
    }
    plaintext += c;
  }

  return plaintext;
}

int main() {
  int key;


  cout << "Masukkan kunci enkripsi (angka 1-25): ";
  cin >> key;

  string ciphertext = encrypt(text, key);
  cout << "Chipertext: " << ciphertext << endl;

  string decrypted = decrypt(ciphertext, key);
  cout << "Teks asli: " << decrypted << endl;

  return 0;
}