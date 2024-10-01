#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){
    //Inisialisasi
    srand(static_cast<unsigned int>(time(0))); //seed untuk angka acak
    int target = rand() % 100+1; //angka acak antara 1 dan 100
    int tebak, attempt = 0, maxAttempts = 10;
    bool isWin = false;

    //array untuk nyimpan tebakan pemain
    int tebakanSebelumnya[10]={0};

    cout <<"Selamat datang di permainan Tebak Angka! \n";
    cout <<"Tebak angka antara 1 hingga 100. Anda memiliki maksimal 10 percobaan.\n";

    while (attempt < maxAttempts){
        cout << "Percobaan ke-" << (attempt + 1) << " Masukkan tebakan Anda: ";
        cin >> tebak;

        // jika angka tidak di rentang 1-100, lanjutkan tanpa menghitung perocbaan itu
        if (tebak < 1 || tebak > 100){
            cout << "Tebakan harus antara 1 dan 100!, Coba lagi.\n";
            continue;
        }
    
        //cek apakah angka pernah ditebak sebelumnya
        bool sudahDitebak = false;
        for (int i =0; i < attempt; i++){
            if (tebakanSebelumnya[i]==tebak){
                sudahDitebak = true;
                break;
            }
        }

        if(sudahDitebak){
            cout << "Anda sudah menebak angka ini sebelumnya! Coba angka lain.\n";
            continue; 
        }

        //simpan tebakan ke array
        tebakanSebelumnya[attempt] = tebak;

        //increament jumlah percobaan
        attempt++;

        //selection untuk mengecek apakah tebakan benar
        if(tebak == target){
            cout << "Selamat! Anda menebak angka yang benar dalam " << attempt << " percobaan.\n";
            isWin = true;
            break;
        } else if (tebak < target){
            cout << "Angka terlalu kecil. Coba lagi.\n";
        } else {
            cout << "Angka terlalu besar. Coba lagi.\n";
        }

        //repetisi dengan break untuk berhenti jika percobaan max tercapai
        if(attempt>=maxAttempts){
            cout << "Anda telah mencapai jumlah percobaan maksimum.\n";
            break;
        }

        //menampilkan semua tebakan sebelumnya setelah percobaan ke-5
        if(attempt==5){
            cout << "Tebakan sebelumnya : ";
            for (int i = 0; i < attempt; i++){
                cout << tebakanSebelumnya[i] << "";
            }
            cout <<"\n";
        }
    }
    //output final (menang atau kalah)
    if (!isWin){
        cout << "Anda gagal menebak angka. Angka yang benar adalah: " << target <<"\n";
    }
    return 0;
}
