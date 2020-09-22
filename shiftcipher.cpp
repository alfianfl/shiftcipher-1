/* 
	Nama 		: Salma Alifia Shafira
	NPM  		: 140810180058
	Kelas		: B
	Praktikum	: Kriptografi - Program Shift Cipher
*/

#include <iostream>
using namespace std;
void enkripsi(){
    string plaintext,ciphertext;
    int k,i;
    char p,text;
    cout << "Masukkan Plaintext : ";
    cin.ignore(); 
	getline (cin, plaintext);
    cout << "Masukkan jumlah pergeseran : "; 
	cin >> k;
    ciphertext = " ";

    for(i = 0; i < plaintext.length(); i++){
        p = plaintext[i];
        if (isalpha(p)) // hanya memproses huruf alfabet saja
        {
           	p = toupper(p); // ubah menjadi huruf kapital
            p = p - 65; // kodekan huruf ke angka 0 s/d 25
            p = (p + k) % 26; // enkripisi, geser sejauh k ke kanan
            p = p + 65;
        } ciphertext = ciphertext + p;
    } cout << "Hasil Ciphertext = " << ciphertext <<endl;
}

void dekripsi(){
    string plaintext,ciphertext;
    int k,i;
    char c,text;
    cout << "Masukkan Cipherteks : ";
    cin.ignore(); 
	getline (cin, ciphertext);
    cout << "Masukkan jumlah pergeseran : "; 
	cin >> k;
    plaintext = " ";

    for (i=0; i<ciphertext.length(); i++)
    {
        c = ciphertext[i];
        if (isalpha(c)) // hanya memproses alpabet
        {
            c = toupper(c); // ubah karakter ke huruf besar
            c = c - 65; // kodekan huruf ke angka 0 sampai 25
            if (c - k < 0) // kasus pembagian bilangan negatif
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65; // kodekan kembali ke huruf semula
            c = tolower(c); // plainteks dinyatakan dengan huruf kecil
        } plaintext = plaintext+ c;
    } cout << "Hasil Plaintext = " << plaintext <<endl;
}

int main()
{
    int x;
    bool stop;
    stop = false;
	cout << "KRIPTOGRAFI - PROGRAM SHIFT CIPHER";
    while (!stop){
    	cout << "\n";
        cout << "Pilih : " <<endl;
        cout << "1. Enkripsi " <<endl;
        cout << "2. Dekripsi " <<endl;
        cout << "Masukkan Pilihan : "; cin >> x;
        switch(x){
            case 1 :
			enkripsi();
			break;
            case 2 :
			dekripsi();
			break;
        }
    } return 0;
}
