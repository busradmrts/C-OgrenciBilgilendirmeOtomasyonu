#include "stdafx.h"
#include <cmath>
#include <locale.h>
#include <sstream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;
//öðrenci için düðüm oluþturuyorum.
struct ogrenci {
	long int ogrNo;
	char ad[20];
	char soyad[20];
	char bolum[30];
	char sinif[5];
};
//4 Adet Modül Ýçin fonksiyonlar tanýmlandý.
void ogrenciModul();
void ogretimElemaniModul();
void dersModul();
void notGirisModul();

int main()
{
	system("cls");
	setlocale(LC_ALL, "Turkish"); // türkçe karakter desteði
	int secim;
	cout << "Lütfen Bir Modül Seçimi Yapýnýz" << endl << endl << left << setw(25) << "Öðrenci Modülü" << "--> 1" << endl << left << setw(25) << "Ögretim Elemaný Modülü" << "--> 2" << endl << left << setw(25) << "Ders Modülü" << "--> 3" << endl << left << setw(25) << "Not Giriþ Modülü" << "--> 4" << endl << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	//seçim sonucuna göre iþlem yapmak için switch case yapýsý kullanýldý.
	switch (secim)
	{
	case 1:
		ogrenciModul();
		break;
	case 2:
		ogretimElemaniModul();
		break;
	case 3:
		dersModul();
		break;
	case 4:
		notGirisModul();
		break;
	default:
		cout << "Hatalý Giriþ Yaptýnýz Tekrar Seçiniz" << endl << endl;
		goto tekrar;
		break;
	}

	system("pause");
	return 0;
}

//öðrenci modülü baþladýðý yer.
//öðrenci modülünde yapýlacak iþlemler için fonksiyonlar
void ogrenciKayit();
void ogrenciArama();
void ogrenciListele();
void ogrenciDuzenleme();
void bolumeGoreListele();
void sinifaGoreListele();
void noileArama();
void adileArama();


void ogrenciModul() {
	system("cls");
	int secim;
	cout << "Lütfen Yapmak ÝstediÐiniz Ýslemi Seçiniz  " << endl << endl << left << setw(20) << "Ögrenci Eklemek " << "--> 1" << endl << left << setw(20) << "Ögrenci Arama" << "--> 2" << endl << left << setw(20) << "Ögrenci Listeleme" << "--> 3" << endl << left << setw(20) << "Ögrenci Düzenleme" << "--> 4" << endl << left << setw(20) << "Bir Önceki Menü " << "--> 5" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl;
tekrar:
	cout << endl << "Seçim :";
	cin >> secim;
	//switch case ile seçim iþlemi yapýlýyor.
	switch (secim)
	{
	case 0:
		exit(0);
	case 1:
		ogrenciKayit();
		break;
	case 2:
		ogrenciArama();
		break;
	case 3:
		ogrenciListele();
		break;
	case 4:
		ogrenciDuzenleme();
		break;
	case 5:
		main();
	default:
		cout << "Hatali Giriþ Yaptýnýz Tekrar Seçiniz" << endl;
		goto tekrar;
		break;
	}
}

//ogrenciBilgileri.txt dosyasýna öðrenciye ait bilgileri ekleme
void ogrenciKayit()
{
	system("cls");
	ogrenci ogr;//öðrenci düðümünden nesne oluþturma
	int secim;
	ofstream dosya;//dosya adýnda nesne oluþturma
	dosya.open("ogrenciBilgileri.txt", ios::app);//dosyayý ekleme modunda açma
												 //kullanýcadan bilgileri alma
	cout << "Öðrenci Numarasýný Giriniz :";
	cin >> ogr.ogrNo;
	cout << "Öðrenci Adýný Giriniz :";
	cin >> ogr.ad;
	cout << "Öðrenci Soyadýný Giriniz :";
	cin >> ogr.soyad;
	cout << "Öðrenci Bölüm Giriniz :";
	cin >> ogr.bolum;
	cout << "Öðrenci Sýnýfýný Giriniz :";
	cin >> ogr.sinif;
	//dosyaya yazma
	dosya << ogr.ogrNo << " " << ogr.ad << " " << ogr.soyad << " " << ogr.bolum << " " << ogr.sinif << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0" << endl << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		ogrenciModul();
	}
	else {
		exit(0);
	}
}
//ogrenciBilgileri.txt dosyasýnda arama yapma fonksiyonu
void ogrenciArama()
{
	system("cls");
	int secim;
	cout << "Lütfen Arama Türünu Seçiniz" << endl << endl << left << setw(20) << "Numara ile Arama" << "--> 1" << endl << left << setw(20) << "Ad ile Arama" << "--> 2" << endl << left << setw(20) << "Bir Önceki Menü " << "--> 3" << endl << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	switch (secim)
	{
	case 1:
		noileArama();
		break;
	case 2:
		adileArama();
		break;
	case 3:
		ogrenciModul();
	default:
		cout << "Hatali Giris Yaptiniz Tekrar Seciniz" << endl;
		goto tekrar;
		break;
	}

}
//öðrenci numarasý ile arama yapma
void noileArama()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, yok = 0, giris, sec;
	string ogrenciler[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");

	cout << "Aradýðýnýz Öðrenci Numarasýný Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime); //dosyanýn bir satýrýný okumak için
		istringstream akim(kelime); //kelime yi parçalara ayýrmak için
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk; //parçalanan kelime matrise atýlýyor.
			b++;
		}
		b = 0;
		a++;
	}
	for (int i = 0; i < a; i++) {
		//aranan öðremci numarasý varsa ekrana yazýlýyor.
		if (no == (ogrenciler[i][0])) {
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(15) << "Öðrenci No" << left << '|' << setw(15) << "Öðrenci Adý" << left << '|' << setw(15) << "Öðrenci Soyadý" << left << '|' << setw(15) << "Bölüm" << left << '|' << setw(15) << "Sýnýfý" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[i][0] << left << "|" << setw(15) << ogrenciler[i][1] << left << "|" << setw(15) << ogrenciler[i][2] << left << "|" << setw(15) << ogrenciler[i][3] << left << "|" << setw(15) << ogrenciler[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Aradýðýnýz Öðrenci Kayýtlý Deðil Kaydetmek Ýçin 1' e Basýn :";
		cin >> giris;
		if (giris == 1)
			ogrenciKayit();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> sec;
	if (sec == 0) {
		exit(0);
	}
	else
	{
		ogrenciArama();
	}
}

void adileArama()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, yok = 0, giris, sec;
	string ogrenciler[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");

	cout << "Aradýðýnýz Öðrenci Adýný Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrmak
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk;//matrise atamam
			b++;
		}
		b = 0;
		a++;
	}
	for (int i = 0; i < a; i++) {
		if (no == (ogrenciler[i][1])) {
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(15) << "Öðrenci No" << left << '|' << setw(15) << "Öðrenci Adý" << left << '|' << setw(15) << "Öðrenci Soyadý" << left << '|' << setw(15) << "Bölüm" << left << '|' << setw(15) << "Sýnýfý" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[i][0] << left << "|" << setw(15) << ogrenciler[i][1] << left << "|" << setw(15) << ogrenciler[i][2] << left << "|" << setw(15) << ogrenciler[i][3] << left << "|" << setw(15) << ogrenciler[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Aradýðýnýz Öðrenci Kayýtlý Deðil Kaydetmek Ýçin 1' e Basýn :";
		cin >> giris;
		if (giris == 1)
			ogrenciKayit();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> sec;
	if (sec == 0) {
		exit(0);
	}
	else
	{
		ogrenciArama();
	}
}


//kayýtlý öðrencileri listelemekiçin fonksiyonumuz
void ogrenciListele()
{
	system("cls");
	int secim;
	cout << "Lütfen Listeleme Türünü Seçiniz" << endl << endl << left << setw(25) << "Bolume Gore Listeleme" << "--> 1" << endl << left << setw(25) << "Sinifa Gore Listeleme" << "--> 2" << endl << left << setw(25) << "Üst Menüye Git" << "--> 3" << endl << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	switch (secim)
	{
	case 1:
		bolumeGoreListele();
		break;
	case 2:
		sinifaGoreListele();
		break;
	case 3:
		ogrenciModul();
		break;
	default:
		cout << "Hatali Girii Yaptiniz Tekrar Seçiniz" << endl;
		goto tekrar;
		break;
	}
}
//bölüme göre öðrenci listelemek
void bolumeGoreListele()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0;
	int giris, count = 0;
	string ogrenciler[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");

	cout << "Aradýðýnýz Bölümü Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara bölme
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk;//matrise atamam
			b++;
		}
		b = 0;
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(15) << "Öðrenci No" << left << '|' << setw(15) << "Öðrenci Adý" << left << '|' << setw(15) << "Öðrenci Soyadý" << left << '|' << setw(15) << "Bölüm" << left << '|' << setw(15) << "Sýnýfý" << endl << endl;
	cout << "_______________________________________________________________________" << endl;
	for (int j = 0; j < a - 1; j++)
	{//istenilen bölüm öðrencileri yazdýrýlýyor
		if (no == ogrenciler[j][3])
		{
			if (j % 2 != 0) {
				SetConsoleTextAttribute(renkVer, 3);
				cout << left << "|" << setw(15) << ogrenciler[j][0] << left << "|" << setw(15) << ogrenciler[j][1] << left << "|" << setw(15) << ogrenciler[j][2] << left << "|" << setw(15) << ogrenciler[j][3] << left << "|" << setw(15) << ogrenciler[j][4] << endl;
			}
			else {
				SetConsoleTextAttribute(renkVer, 5);
				cout << left << "|" << setw(15) << ogrenciler[j][0] << left << "|" << setw(15) << ogrenciler[j][1] << left << "|" << setw(15) << ogrenciler[j][2] << left << "|" << setw(15) << ogrenciler[j][3] << left << "|" << setw(15) << ogrenciler[j][4] << endl;
			}
			count++;
		}
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0)
		cout << "Aradýðýnýz Bölümde Kayýtlý Öðrenci Bulunamadý" << endl;
	cout << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> giris;
	if (giris == 0) {
		exit(0);
	}
	else
	{
		ogrenciListele();
	}

}

void sinifaGoreListele()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, giris, count = 0;
	string ogrenciler[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");

	cout << "Aradýðýnýz Sýnýfý Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(15) << "Öðrenci No" << left << '|' << setw(15) << "Öðrenci Adý" << left << '|' << setw(15) << "Öðrenci Soyadý" << left << '|' << setw(15) << "Bölüm" << left << '|' << setw(15) << "Sýnýfý" << endl << endl;
	cout << "_______________________________________________________________________" << endl;
	for (int j = 0; j < a - 1; j++)
	{//istenilen sýnýf öðrencileri listeleniyor
		if (no == ogrenciler[j][4])
		{
			if (j % 2 == 0)
				SetConsoleTextAttribute(renkVer, 3);
			else
				SetConsoleTextAttribute(renkVer, 5);
			cout << left << "|" << setw(15) << ogrenciler[j][0] << left << "|" << setw(15) << ogrenciler[j][1] << left << "|" << setw(15) << ogrenciler[j][2] << left << "|" << setw(15) << ogrenciler[j][3] << left << "|" << setw(15) << ogrenciler[j][4] << endl;
			count++;
		}
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0)
		cout << "Aradýðýnýz Sýnýfta Kayýtlý Öðrenci Bulunamadý";
	cout << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> giris;
	if (giris == 0) {
		exit(0);
	}
	else
	{
		ogrenciListele();
	}
}
//var olan öðrenci bilgilereini düzenleme fonkisyonu
void ogrenciDuzenleme()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	ogrenci ogr;
	string no, kelime;
	int a = 0, b = 0, var = 0;
	string ogrenciler[1000][5];
	cout << "Düzenlenecek Öðrencinin Numarasýný Giriniz :";
	cin >> no;
	system("cls");
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");//öðrenci bilgileri dosyasý okuma modunda açýlýyor.
	ofstream yDosya;
	yDosya.open("ogrenciBilgileri1.txt", ios::app);//yeni bir dosya ekleme modunda açýlýyor.
	while (!dosya.eof())
	{
		getline(dosya, kelime);
		istringstream akim(kelime);
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk;
			b++;
		}
		b = 0;
		//düzenlenlenecek öðrenci hariç diðer tüm öðrencileri yeni dosyaya yazýyoruz
		if (no != ogrenciler[a][0] && ogrenciler[a][0] != "") {
			yDosya << kelime << endl;
		}
		//düzenlenecek öðrenci bilgilerini ekrana yazýyoruz.
		else if (no == ogrenciler[a][0]) {
			cout << "Düzenlenecek Öðrenci Bilgileri " << endl << endl;
			var = 1;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(15) << "Öðrenci No" << left << '|' << setw(15) << "Öðrenci Adý" << left << '|' << setw(15) << "Öðrenci Soyadý" << left << '|' << setw(15) << "Bölüm" << left << '|' << setw(15) << "Sýnýfý" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[a][0] << left << "|" << setw(15) << ogrenciler[a][1] << left << "|" << setw(15) << ogrenciler[a][2] << left << "|" << setw(15) << ogrenciler[a][3] << left << "|" << setw(15) << ogrenciler[a][4] << endl;
		}
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	//düzenlenecek öðrenci bilgilerini tekrar istiyoruz.
	if (var == 1) {
		cout << "Öðrenci Numarasýný Giriniz :";
		cin >> ogr.ogrNo;
		cout << "Öðrenci Adýný Giriniz :";
		cin >> ogr.ad;
		cout << "Öðrenci Soyadýný Giriniz :";
		cin >> ogr.soyad;
		cout << "Öðrenci Bölüm Giriniz :";
		cin >> ogr.bolum;
		cout << "Öðrenci Sýnýf Giriniz :";
		cin >> ogr.sinif;
		//düzenlenen öðrenciyi de yeni dosyaya yazýyoruz.
		yDosya << ogr.ogrNo << " " << ogr.ad << " " << ogr.soyad << " " << ogr.bolum << " " << ogr.sinif << endl;
		dosya.close();
		yDosya.close();

		
		cout << endl << "Düzenleme Gerçekleþtirldi." << endl;
	}
	else
		cout << "Öðrenci Bulunamadý" << endl;
	remove("ogrenciBilgileri.txt");//öðrenci bilgileri dosyasýný siliyoruz.
	rename("ogrenciBilgileri1.txt", "ogrenciBilgileri.txt");//yeni dosyanýn adýný ilk dosyanýn adýný veriyoruz.

	int secim;
	cout << endl << "Ana Menüye Dönmek Ýçin 1 e Basýnýz." << endl;
	cin >> secim;
	if (secim == 1)
	{
		main();
	}
	else
		exit(0);
}
//öðrenci modülünün bittiði yer

//Ögretim Elemani Modülü baþladýðý yer.
//öðretim elemaný bilgileri için düðüm oluþturuluyor.
struct ogrElemani {
	long int sicilNo;
	char unvan[20];
	char ad[20];
	char soyad[20];
	char bolum[30];
};
//modül için gerekli fonksiyonlar tanýmlanýyor.
void oElemaniEkle();
void oElemaniAra();
void oElemaniGüncelle();
void oElemaniListele();

void ogretimElemaniModul() {
	system("cls");
	int secim;
	cout << "Lütfen Yapmak Ýstediðiniz Ýþlemi Seçiniz" << endl << endl << left << setw(25) << "Ögretim ELemaný Eklemek" << "--> 1" << endl << left << setw(25) << "Öðretim Elemaný Arama" << "--> 2" << endl << left << setw(25) << "Öðretim Elemaný Listeleme" << "--> 3" << endl << left << setw(25) << "Öðretim Elemaný Düzenleme" << "--> 4 " << endl << left << setw(25) << "Bir Önceki Menü" << "--> 5" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0" << endl << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	switch (secim)
	{
	case 0:
		exit(0);
	case 1:
		oElemaniEkle();
		break;
	case 2:
		oElemaniAra();
		break;
	case 3:
		oElemaniListele();
		break;
	case 4:
		oElemaniGüncelle();
		break;
	case 5:
		main();
	default:
		cout << "Hatali Giriþ Yaptýnýz Tekrar Seçiniz" << endl;
		goto tekrar;
		break;
	}
}
//öðretim elemaný ekleme fonkisyonu
void oElemaniEkle()
{
	system("cls");
	ogrElemani oE;
	int secim;
	ofstream dosya;
	dosya.open("oElemaniBilgileri.txt", ios::app);//dosya ekleme modunda açýlýyor.
												  //kullanýcýdan bilgiler isteniyor.
	cout << "Öðretim Elemaný Sicil Numarasýný Giriniz :";
	cin >> oE.sicilNo;
	cout << "Öðretim Elemaný Adýný Giriniz :";
	cin >> oE.ad;
	cout << "Öðretim Elemaný Soyadýný Giriniz :";
	cin >> oE.soyad;
	cout << "Öðretim Elemaný Bölümünü Giriniz :";
	cin >> oE.bolum;
	cout << "Öðretim Elemaný Ünvanýný Giriniz :";
	cin >> oE.unvan;
	//veriler dosyaya yazýlýyor
	dosya << oE.sicilNo << " " << oE.unvan << " " << oE.ad << " " << oE.soyad << " " << oE.bolum << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		ogretimElemaniModul();
	}
	else {
		exit(0);
	}
}
//öðretim elemaný arama fonksiyonu
void oElemaniAra()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, yok = 0, giris, sec;
	string oElemanlari[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("oElemaniBilgileri.txt");//dosya okuma modunda açýlýyor.

	cout << "Aradýðýnýz Öðretim Elemaný Sicil Numarasýný Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			oElemanlari[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	for (int i = 0; i < a; i++) {
		//sicilnumarasý girilen öðretim elemaný ekrana yazýlýyor.
		if (no == (oElemanlari[i][0])) {
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "Ünvan" << left << '|' << setw(25) << "Öðretim Elemaný Adý" << left << '|' << setw(25) << "Ogretim Elemaný Soyadý" << left << '|' << setw(20) << "Öðretim Elemaný Bölüm" << endl << endl;
			cout << "___________________________________________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(20) << oElemanlari[i][0] << left << "|" << setw(20) << oElemanlari[i][1] << left << "|" << setw(20) << oElemanlari[i][2] << left << "|" << setw(20) << oElemanlari[i][3] << left << "|" << setw(20) << oElemanlari[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	//aranan öðretim elemaný yoksa
	if (yok != 1) {
		cout << "Aradýðýnýz Öðretim Elemaný Kayýtlý Deðil Kaydetmek Ýçin 1' e Basýn :";
		cin >> giris;
		if (giris == 1)
			oElemaniEkle();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "___________________________________________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1 " << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> sec;
	if (sec == 1) {
		ogretimElemaniModul();
	}
	else
	{
		exit(0);
	}
}
//öðretim elemaný bilgileri güncelleme
void oElemaniGüncelle()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	ogrElemani oE;
	string no, kelime;
	int a = 0, b = 0, var = 0;
	string oElemanlari[1000][5];
	cout << "Düzenlenecek Öðretim Elemanýnýn Sicil Numarasýný Giriniz :";
	cin >> no;
	ifstream dosya;
	dosya.open("oElemaniBilgileri.txt");//dosya okuma modunda açýlýyor
	ofstream yDosya;
	yDosya.open("oElemaniBilgileri1.txt", ios::app);//yeni bir doþya oluþturuyoruz ekleme modunda

	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			oElemanlari[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		//güncelenecek hoca hariç tüm veriler yeni dosyaya yazýlýyor.
		if (no != oElemanlari[a][0] && oElemanlari[a][0] != "") {
			yDosya << kelime << endl;
		}
		//düzenlenecek hoca bilgileri ekrana yazýlýyor.
		else if (no == oElemanlari[a][0]) {
			cout << "Düzenlenecek Öðretim Elemaný Bilgileri " << endl << endl;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "Ünvan" << left << '|' << setw(25) << "Öðretim Elemaný Adý" << left << '|' << setw(25) << "Ogretim Elemaný Soyadý" << left << '|' << setw(20) << "Öðretim Elemaný Bölüm" << endl << endl;
			cout << "___________________________________________________________________________________________________" << endl;
			var = 1;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(20) << oElemanlari[a][0] << left << "|" << setw(20) << oElemanlari[a][1] << left << "|" << setw(20) << oElemanlari[a][2] << left << "|" << setw(20) << oElemanlari[a][3] << left << "|" << setw(20) << oElemanlari[a][4] << endl;
		}
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "___________________________________________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	//düzenlenecek hocanýn verileri yeniden giriliyor.
	if (var == 1) {
		cout << "Öðretim Elemaný Sicil Numarasýný Giriniz :";
		cin >> oE.sicilNo;
		cout << "Öðretim Elemanýn Adýný Giriniz :";
		cin >> oE.ad;
		cout << "Öðretim Elemanýn Soyadýný Giriniz :";
		cin >> oE.soyad;
		cout << "Öðretim Elemanýn Bölümünü Giriniz :";
		cin >> oE.bolum;
		cout << "Öðretim Elemanýn Ünvanýný Giriniz :";
		cin >> oE.unvan;
		//yeni bilgiler yeni dosyaya ekleniyor.
		yDosya << oE.sicilNo << " " << oE.unvan << " " << oE.ad << " " << oE.soyad << " " << oE.bolum << " " << endl;
		dosya.close();
		yDosya.close();

		cout << endl << "Düzenleme Gerçekleþtirldi." << endl;
	}
	else
		cout << "Öðretim Elemaný Bulunamadý" << endl;
	remove("oElemaniBilgileri.txt");//eski dosya siliniyor.
	rename("oElemaniBilgileri1.txt", "oElemaniBilgileri.txt");//yeni dosyaya eski dosyanýn adý veriliyor.
	int secim;
	cout << endl << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 " << endl << "Seçim :";
	cin >> secim;
	if (secim == 1)
	{
		ogretimElemaniModul();
	}
	else
		exit(0);
}
void oElemaniListele()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, count = 0;
	int giris;
	string oElemani[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("oElemaniBilgileri.txt");

	cout << "Aradýðýnýz Bölümü Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//string parçalama
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			oElemani[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "Ünvan" << left << '|' << setw(25) << "Öðretim Elemaný Adý" << left << '|' << setw(25) << "Ogretim Elemaný Soyadý" << left << '|' << setw(20) << "Öðretim Elemaný Bölüm" << endl << endl;
	cout << "___________________________________________________________________________________________________" << endl;
	for (int j = 0; j < a; j++)
	{
		//öðretim elemani listeliyoruz.
		if (no == oElemani[j][4])
		{
			if (j % 2 == 0)
				SetConsoleTextAttribute(renkVer, 3);
			else
				SetConsoleTextAttribute(renkVer, 5);
			cout << left << "|" << setw(8) << oElemani[j][0] << left << "|" << setw(15) << oElemani[j][1] << left << "|" << setw(25) << oElemani[j][2] << left << "|" << setw(25) << oElemani[j][3] << left << "|" << setw(20) << oElemani[j][4] << endl;
			count++;
		}
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "___________________________________________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0)
		cout << "Aradýðýnýz Bölümde Kayýtlý Öðretim Elemaný Bulunamadý" << endl;
	cout << endl << endl << left << setw(25) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(25) << "Çýkmak Ýçin" << "--> 0 " << endl << "Seçim :";
	cin >> giris;
	if (giris == 1) {
		ogretimElemaniModul();
	}
	else
	{
		exit(0);
	}
}
//Öðretim Elemaný Modülü Bittiði yer

//Ders Modülün Baþladýðý Yer
//ders için düðüm oluþturuluyor.
struct ders {
	long int dersNo;
	long int dersKredisi;
	char oElemani[20];
	char dersAd[20];
};
//ders iþlemleri için fonksiyonlar tanýmlanýyor.
void dersEkle();
void dersGuncelle();
void dersListele();
void dersAra();

void dersModul() {
	system("cls");
	int secim;
	cout << "Lütfen Yapmak Ýstediðiniz Ýþlemi Seçiniz" << endl << endl << left << setw(15) << "Ders Eklemek" << "--> 1" << endl << left << setw(15) << "Ders Arama" << "--> 2" << endl << left << setw(15) << "Ders Listeleme" << "--> 3" << endl << left << setw(15) << "Ders Düzenleme" << "--> 4 " << endl << left << setw(15) << "Üst Menü" << "--> 5" << endl << left << setw(15) << "Çýkmak Ýçin" << "--> 0" << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	switch (secim)
	{
	case 0:
		exit(0);
	case 1:
		dersEkle();
		break;
	case 2:
		dersAra();
		break;
	case 3:
		dersListele();
		break;
	case 4:
		dersGuncelle();
		break;
	case 5:
		main();
	default:
		cout << "Hatali Giriþ Yaptiniz Tekrar Seciniz" << endl;
		goto tekrar;
		break;
	}
}
//ders ekleme fonksiyonu
void dersEkle()
{
	system("cls");
	ders d;
	int secim;
	ofstream dosya;
	dosya.open("ders.txt", ios::app);//ders eklemek için dosya açýlýyor.
									 //ders bilgileri kullanýcýdan alýnýyor.
	cout << "Ders Numarasýný Giriniz :";
	cin >> d.dersNo;
	cout << "Dersin Adýný Giriniz :";
	cin >> d.dersAd;
	cout << "Dersin Hocasýnýn Sicil Numarasýný Giriniz Giriniz :";
	cin >> d.oElemani;
	cout << "Dersin Kredisini Giriniz :";
	cin >> d.dersKredisi;
	//ders bilgileri dosyaya yazýlýyor.
	dosya << d.dersNo << " " << d.dersAd << " " << d.oElemani << " " << d.dersKredisi << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		dersModul();
	}
	else {
		exit(0);
	}
}
//ders bilgileri güncelleme fonksiyonu.
void dersGuncelle()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	ders d;
	string ad, kelime;
	int a = 0, b = 0, var = 0;
	string ders[1000][5];
	cout << "Düzenlenecek Dersin Adýný Giriniz :";
	cin >> ad;
	ifstream dosya;
	dosya.open("ders.txt");//dosya okuma modunda açýlýyor
	ofstream yDosya;
	yDosya.open("ders1.txt", ios::app);//yeni dosya ekleme modunda açýlýyor.

	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		//diðer dersler yeni dosyaya yazýlýyor.
		if (ad != ders[a][1] && ders[a][0] != "") {
			yDosya << kelime << endl;
		}
		//düzenlenecek ders bilgileri ekrana yazýlýyor.
		else if (ad == ders[a][1]) {
			cout << "Düzenlenecek Ders Bilgileri " << endl << endl;
			var = 1;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Adý" << left << '|' << setw(27) << "Dersin Hocasýnýn Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(8) << ders[a][0] << left << "|" << setw(20) << ders[a][1] << left << "|" << setw(27) << ders[a][2] << left << "|" << setw(2) << ders[a][3] << endl << endl;
			SetConsoleTextAttribute(renkVer, 2);
			cout << "_______________________________________________________________________" << endl;

		}
		a++;
	}
	SetConsoleTextAttribute(renkVer, 7);
	//düzenlenecek dersin bigileri isteniyor
	if (var == 1) {
		cout << "Dersin Numarasýný Giriniz :";
		cin >> d.dersNo;
		cout << "Dersin Adýný Giriniz :";
		cin >> d.dersAd;
		cout << "Dersin Hocasýnýn Sicil Numarasýný Giriniz :";
		cin >> d.oElemani;
		cout << "Dersin Kredisini Giriniz :";
		cin >> d.dersKredisi;
		yDosya << d.dersNo << " " << d.dersAd << " " << d.oElemani << " " << d.dersKredisi << endl;
		dosya.close();
		yDosya.close();

		cout << endl << "Düzenleme Gerçekleþtirldi." << endl;
	}
	else
		cout << "Ders Bulunamadý" << endl;
	remove("ders.txt");
	rename("ders1.txt", "ders.txt");
	int secim;
	cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1)
	{
		dersModul();
	}
	else if (secim == 0)
		exit(0);
}
//derslerilistelemek için fonksiyonumuz
void dersListele()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int a = 0, b = 0, count = 0;
	int giris;
	string ders[1000][5];
	string kelime;
	ifstream dosya;
	dosya.open("ders.txt");//dosya okuma modunda açýlýyor.
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//paröalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);//yazý rengi verme
	cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Adý" << left << '|' << setw(10) << "Dersin Hocasýnýn Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);//yazý rengi verme
	for (int j = 0; j < a - 1; j++)
	{
		if (j % 2 == 0)
			SetConsoleTextAttribute(renkVer, 3);//yazý rengi verme
		else
			SetConsoleTextAttribute(renkVer, 5);//yazý rengi verme
		cout << left << '|' << setw(8) << ders[j][0] << left << '|' << setw(20) << ders[j][1] << left << '|' << setw(25) << ders[j][2] << left << '|' << setw(2) << ders[j][3] << endl;
		count++;
	}
	SetConsoleTextAttribute(renkVer, 2);//yazý rengi verme
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);//yazý rengi verme
	if (count == 0)
		cout << " Kayýtlý Ders Bulunamadý" << endl;
	cout << endl << "Bir Önceki Menüye Dönmek Ýçin --> 1 " << endl << "Çýkmak Ýçin --> 0 \nGiriniz :";
	cin >> giris;
	if (giris == 0) {
		exit(0);
	}
	else
	{
		dersModul();
	}
}
void dersAra()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int a = 0, b = 0, yok = 0, giris, sec;
	string ders[1000][5];
	string kelime, ad;
	ifstream dosya;
	dosya.open("ders.txt");//dosya okuma modunda açýlýyor

	cout << "Aradýðýnýz Dersin Adýný Giriniz :";
	cin >> ad;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	for (int i = 0; i < a - 1; i++) {
		if (ad == ders[i][1]) {
			yok = 1;
			SetConsoleTextAttribute(renkVer, 2);//yazýya renk verme
			cout << left << '|' << setw(10) << "Ders No" << left << '|' << setw(25) << "Ders Adý" << left << '|' << setw(30) << "Dersin Hocasýnýn Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
			cout << "_________________________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);//yazýya renk verme
			cout << left << '|' << setw(10) << ders[i][0] << left << '|' << setw(25) << ders[i][1] << left << '|' << setw(30) << ders[i][2] << left << '|' << setw(2) << ders[i][3] << " " << endl;
			SetConsoleTextAttribute(renkVer, 2);//yazýya renk verme
			cout << "_________________________________________________________________________________" << endl;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Aradýðýnýz Ders Kayýtlý Deðil Kaydetmek Ýçin 1' e Basýn :";
		cin >> giris;
		if (giris == 1)
			dersEkle();
	}
git:
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(15) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(15) << "Çýkmak Ýçin" << "--> 0 \nSeçim :";
	cin >> sec;
	if (sec == 0) {
		exit(0);
	}
	else
	{
		dersModul();
	}
}
//Ders Modülünü Bittiði Yer

//Not Giriþ Modülünü Baþladýðý Yer
//not bilgileri için düðüm oluþturuluyor.
struct not{
	string ogrNum;
	string dersAdi;
	int vize;
	int final;
	double ortalama;
	string durum;
	string dersNum;
};
//iþlemler için fonksiyonlar
void ogrDersEkle();
void ogrNotEkle();
void ogrDersListele();
void ogrKarne();

void notGirisModul()
{
	system("cls");
	int secim;
	cout << "Lütfen Yapmak Ýstediðiniz Ýþlemi Seçiniz" << endl << endl << left << setw(22) << "Öðrenciye Ders Ekleme" << "--> 1" << endl << left << setw(22) << "Öðrenciye Not Ekleme" << "--> 2" << endl << left << setw(22) << "Öðrenci Ders Listele" << "--> 3" << endl << left << setw(22) << "Öðrenci Karnesi" << "--> 4 " << endl << left << setw(22) << "Bir Önceki Menü" << "--> 5" << endl << left << setw(22) << "Çýkmak Ýçin" << "--> 0" << endl;
tekrar:
	cout << "Seçim :";
	cin >> secim;
	switch (secim)
	{
	case 0:
		exit(0);
	case 1:
		ogrDersEkle();
		break;
	case 2:
		ogrNotEkle();
		break;
	case 3:
		ogrDersListele();
		break;
	case 4:
		ogrKarne();
		break;
	case 5:
		main();
	default:
		cout << "Hatali Giriþ Yaptýnýz Tekrar Seçiniz" << endl;
		goto tekrar;
		break;
	}
}
//ders ekleme fonksiyonu
void ogrDersEkle() {
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, count = 0, yok;
	int secim;
	string ders[1000][4];
	not n;
	string kelime, dersNo, ogrNo;
	ifstream dosya;
	dosya.open("ders.txt");
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosya satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	//eklenebilecek dersler listeleniyor.
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Adý" << left << '|' << setw(10) << "Dersin Hocasýnýn Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	for (int j = 0; j < a - 1; j++)
	{
		if (j % 2 == 0)
			SetConsoleTextAttribute(renkVer, 3);
		else
			SetConsoleTextAttribute(renkVer, 5);
		cout << left << '|' << setw(8) << ders[j][0] << left << '|' << setw(20) << ders[j][1] << left << '|' << setw(25) << ders[j][2] << left << '|' << setw(2) << ders[j][3] << " " << endl;
		count++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0)
		cout << " Kayýtlý Ders Bulunamadý" << endl;
	yok = a - 1;
	if (count != 0) {
		cout << endl << "Öðrenciye Ekleyebileceðiniz Dersler Yukarýda Listelenmiþtir." << endl;
		cout << "Öðrencinin Numarasýný Giriniz :";
		cin >> ogrNo;
	git:
		cout << "Ekleyeceðiniz Dersin Numarasýný Giriniz :";
		cin >> dersNo;
		for (int i = 0; i < a - 1; i++) //dizinin eleman larýnda boþ olana gelene kadar okumak için a-1 diyoruz.
		{
			//ders varsa öðrenciye ekleme iþlemi yapýyoruz.
			if (dersNo == ders[i][0]) {
				n.ogrNum = ogrNo;
				n.dersNum = ders[i][0];
				n.dersAdi = ders[i][1];
				ofstream dosya;
				dosya.open("ogrDers.txt", ios::app);
				dosya << n.ogrNum << " " << n.dersNum << " " << n.dersAdi << endl;
				dosya.close();
				cout << endl << "Veri Eklendi." << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
				cin >> secim;
				if (secim == 1) {
					notGirisModul();
				}
				else {
					exit(0);
				}
			}
			else {
				yok++;
			}
		}
		if (yok != a - 1) {
			cout << "Geçerli Ders Kodu Giriniz" << endl;
			goto git;
		}

	}
	cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		notGirisModul();
	}
	else {
		exit(0);
	}
}
void ogrNotEkle() {
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, count = 0, yok;
	string giris;
	int secim;
	string dersler[1000][3];
	string ogrDersler[1000][3];
	not n; //not düðümünden nesne oluþturdum.
	string kelime, dersNo, ogrNo;
	ifstream dosya;
	dosya.open("ogrDers.txt");
	while (!dosya.eof())
	{
		getline(dosya, kelime);
		istringstream akim(kelime);
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			dersler[a][b] = sozcuk;
			b++;
		}
		b = 0;
		a++;
	}
	cout << "Not Ekleyeceðiniz Öðrenci Numarasýný Giriniz :";
	cin >> ogrNo;
	system("cls");
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(16) << "Öðrenci Numarasý" << left << '|' << setw(20) << "Dersin Numarasý" << left << '|' << setw(10) << "Dersin Adý" << endl << endl;
	cout << "___________________________________________________________" << endl;
	for (int j = 0; j < a - 1; j++)
	{
		if (ogrNo == dersler[j][0]) {
			ogrDersler[j][0] = dersler[j][0];
			ogrDersler[j][1] = dersler[j][1];
			ogrDersler[j][2] = dersler[j][2];
			if (j % 2 == 0)
				SetConsoleTextAttribute(renkVer, 3);
			else
				SetConsoleTextAttribute(renkVer, 5);
			cout << left << '|' << setw(16) << dersler[j][0] << left << '|' << setw(20) << dersler[j][1] << left << '|' << setw(25) << dersler[j][2] << endl;
			count++;
		}
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "___________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0) {
		cout << "Öðrenci Numarasýna Ait Ders Bulunamadý." << endl;
		cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
		cin >> secim;
		if (secim == 1) {
			notGirisModul();
		}
		else {
			exit(0);
		}
	}
	yok = a - 1;
	if (count != 0) {
		cout << endl << "Öðrenciye Ekleyebileceðiniz Dersler Yukarýda Listelenmiþtir." << endl;
	git:
		cout << "Ekleyeceðiniz Dersin Numarasýný Giriniz :";
		cin >> dersNo;
		for (int i = 0; i < a - 1; i++) //dizinin eleman larýnda boþ olana gelene kadar okumak için a-1 diyoruz.
		{
			if (dersNo == ogrDersler[i][1]) {
				n.ogrNum = ogrNo;
				n.dersAdi = ogrDersler[i][2];
				cout << "Vize Notunu Giriniz :";
				cin >> n.vize;
				cout << "Final Notunu Giriniz :";
				cin >> n.final;
				n.ortalama = ((n.vize * 40) / 100) + ((n.final * 60) / 100);
				if (n.ortalama >= 45 && n.final >= 45) {
					n.durum = "Gecti";
				}
				else {
					n.durum = "Kaldi";
				}
				ofstream notDosya;
				notDosya.open("ogrDersNotlari.txt", ios::app);
				notDosya << n.ogrNum << " " << n.dersAdi << " " << n.vize << " " << n.final << " " << n.ortalama << " " << n.durum << endl;
				notDosya.close();
				cout << endl << "Veri Eklendi." << endl;
				cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
				cin >> secim;
				if (secim == 1) {
					notGirisModul();
				}
				else {
					exit(0);
				}
			}
			else {
				yok++;
			}
		}
		if (yok != a - 1) {
			cout << "Geçerli Ders Kodu Giriniz" << endl;
			goto git;
		}
	}
	cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		notGirisModul();
	}
	else {
		exit(0);
	}
}
void ogrDersListele() {
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, count = 0, yok, deger;
	string giris;
	int secim, varmi = 0;
	string dersler[1000][3];
	string ogrDersler[1000][3];
	not n; //not düðümünden nesne oluþturdum.
	string kelime, dersNo, ogrNo;
	ifstream dosya;
	dosya.open("ogrDers.txt");//dosya okuma modunda açýlýyor
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan satýr okuma
		istringstream akim(kelime);//parçalara ayýrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			dersler[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
tekrar:
	cout << "Derslerini Listeleyeceðiniz Öðrencinin Numarasýný Giriniz :";
	cin >> ogrNo;
	system("cls");
	//ogrenci bilgilerine ulaþýlýyor.
	int k = 0, l = 0, sec;
	string ogrenciler[1000][5];
	string kelimeO, no;
	ifstream dosyaO;
	dosyaO.open("ogrenciBilgileri.txt");
	while (!dosyaO.eof())
	{
		getline(dosyaO, kelimeO);
		istringstream akim(kelimeO);
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[k][l] = sozcuk;
			l++;
		}
		l = 0;
		k++;
	}
	for (int x = 0; x <k; x++)
	{
		if (ogrNo == ogrenciler[x][0]) {
			deger = x;
			varmi = 1;
			goto git;
		}
	}
	if (varmi != 1)
		goto tekrar;
	//
git:
	SetConsoleTextAttribute(renkVer, 6);
	cout << "Ogrencinin Numarasý :" << ogrNo << endl << "Ogrencinin Adý Soyadý :" << ogrenciler[deger][1] << " " << ogrenciler[deger][2] << endl << "Ogrencinin Sýnýfý :" << ogrenciler[deger][4] << endl << "Ogrencinin Bölümü :" << ogrenciler[deger][3] << endl << endl;
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(20) << "Dersin Numarasý" << left << '|' << setw(10) << "Dersin Adý" << endl << endl;
	cout << "__________________________________________" << endl;
	for (int j = 0; j < k - 1; j++)
	{
		if (ogrNo == dersler[j][0]) {
			ogrDersler[j][0] = dersler[j][0];
			ogrDersler[j][1] = dersler[j][1];
			ogrDersler[j][2] = dersler[j][2];
			if (j % 2 == 0)
				SetConsoleTextAttribute(renkVer, 3);
			else
				SetConsoleTextAttribute(renkVer, 5);
			cout << left << '|' << setw(20) << dersler[j][1] << left << '|' << setw(25) << dersler[j][2] << endl;
			count++;
		}
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "__________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0) {
		cout << "Öðrenci Numarasýna Ait Ders Bulunamadý." << endl;
		cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
		cin >> secim;
		if (secim == 1) {
			notGirisModul();
		}
		else {
			exit(0);
		}
	}
	cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		notGirisModul();
	}
	else {
		exit(0);
	}
}
void ogrKarne() {
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, count = 0, yok, deger;
	string giris;
	int secim, varmi = 0;
	string ogrdersler[1000][6];
	string kelime, dersNo, ogrNo;
	ifstream dosya;
	dosya.open("ogrDersNotlari.txt");
	while (!dosya.eof())
	{
		getline(dosya, kelime);
		istringstream akim(kelime);
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrdersler[a][b] = sozcuk;
			b++;
		}
		b = 0;
		a++;
	}//öðrenci bilgilerine ulaþýlýyor.
	int deg = a;
tekrar:
	cout << "Karnesini Görmek Ýstediðiniz Öðrenci Numarasýný Giriniz :";
	cin >> ogrNo;
	system("cls");
	int k = 0, l = 0, sec;
	string ogrenciler[1000][5];
	string kelimeO, no;
	ifstream dosyaO;
	dosyaO.open("ogrenciBilgileri.txt");
	while (!dosyaO.eof())
	{
		getline(dosyaO, kelimeO);
		istringstream akim(kelimeO);
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[k][l] = sozcuk;
			l++;
		}
		l = 0;
		k++;
	}
	for (int x = 0; x <a; x++)
	{
		if (ogrNo == ogrenciler[x][0]) {
			deger = x;
			varmi = 1;
			goto git;
		}
	}
	if (varmi != 0)
		goto tekrar;
	//
git:
	SetConsoleTextAttribute(renkVer, 6);
	cout << "Ogrencinin Numarasý :" << ogrNo << endl << "Ogrencinin Adý Soyadý :" << ogrenciler[deger][1] << " " << ogrenciler[deger][2] << endl << "Ogrencinin Sýnýfý :" << ogrenciler[deger][4] << endl << "Ogrencinin Bölümü :" << ogrenciler[deger][3] << endl << endl;
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(20) << "Dersin Adý" << left << '|' << setw(10) << "Vize" << left << '|' << setw(10) << "Final" << left << '|' << setw(10) << "Ortalama" << left << '|' << setw(10) << "Durum" << endl << endl;
	cout << "____________________________________________________________" << endl;
	for (int j = 0; j < deg; j++)
	{
		if (ogrNo == ogrdersler[j][0]) {
			if (j % 2 == 0)
				SetConsoleTextAttribute(renkVer, 3);
			else
				SetConsoleTextAttribute(renkVer, 5);
			cout << left << '|' << setw(20) << ogrdersler[j][1] << left << '|' << setw(10) << ogrdersler[j][2] << left << '|' << setw(10) << ogrdersler[j][3] << left << '|' << setw(10) << ogrdersler[j][4] << left << '|' << setw(10) << ogrdersler[j][5] << endl;
			count++;
		}
	}SetConsoleTextAttribute(renkVer, 2);
	cout << "____________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	if (count == 0) {
		cout << "Öðrenci Numarasýna Ait Ders Bulunamadý." << endl;
		cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
		cin >> secim;
		if (secim == 1) {
			notGirisModul();
		}
		else {
			exit(0);
		}
	}
	cout << endl << left << setw(20) << "Üst Menüye Dönmek Ýçin" << "--> 1" << endl << left << setw(20) << "Çýkmak Ýçin" << "--> 0" << endl << "Seçim :";
	cin >> secim;
	if (secim == 1) {
		notGirisModul();
	}
	else {
		exit(0);
	}
}