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
//��renci i�in d���m olu�turuyorum.
struct ogrenci {
	long int ogrNo;
	char ad[20];
	char soyad[20];
	char bolum[30];
	char sinif[5];
};
//4 Adet Mod�l ��in fonksiyonlar tan�mland�.
void ogrenciModul();
void ogretimElemaniModul();
void dersModul();
void notGirisModul();

int main()
{
	system("cls");
	setlocale(LC_ALL, "Turkish"); // t�rk�e karakter deste�i
	int secim;
	cout << "L�tfen Bir Mod�l Se�imi Yap�n�z" << endl << endl << left << setw(25) << "��renci Mod�l�" << "--> 1" << endl << left << setw(25) << "�gretim Eleman� Mod�l�" << "--> 2" << endl << left << setw(25) << "Ders Mod�l�" << "--> 3" << endl << left << setw(25) << "Not Giri� Mod�l�" << "--> 4" << endl << endl;
tekrar:
	cout << "Se�im :";
	cin >> secim;
	//se�im sonucuna g�re i�lem yapmak i�in switch case yap�s� kullan�ld�.
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
		cout << "Hatal� Giri� Yapt�n�z Tekrar Se�iniz" << endl << endl;
		goto tekrar;
		break;
	}

	system("pause");
	return 0;
}

//��renci mod�l� ba�lad��� yer.
//��renci mod�l�nde yap�lacak i�lemler i�in fonksiyonlar
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
	cout << "L�tfen Yapmak �stedi�iniz �slemi Se�iniz  " << endl << endl << left << setw(20) << "�grenci Eklemek " << "--> 1" << endl << left << setw(20) << "�grenci Arama" << "--> 2" << endl << left << setw(20) << "�grenci Listeleme" << "--> 3" << endl << left << setw(20) << "�grenci D�zenleme" << "--> 4" << endl << left << setw(20) << "Bir �nceki Men� " << "--> 5" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl;
tekrar:
	cout << endl << "Se�im :";
	cin >> secim;
	//switch case ile se�im i�lemi yap�l�yor.
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
		cout << "Hatali Giri� Yapt�n�z Tekrar Se�iniz" << endl;
		goto tekrar;
		break;
	}
}

//ogrenciBilgileri.txt dosyas�na ��renciye ait bilgileri ekleme
void ogrenciKayit()
{
	system("cls");
	ogrenci ogr;//��renci d���m�nden nesne olu�turma
	int secim;
	ofstream dosya;//dosya ad�nda nesne olu�turma
	dosya.open("ogrenciBilgileri.txt", ios::app);//dosyay� ekleme modunda a�ma
												 //kullan�cadan bilgileri alma
	cout << "��renci Numaras�n� Giriniz :";
	cin >> ogr.ogrNo;
	cout << "��renci Ad�n� Giriniz :";
	cin >> ogr.ad;
	cout << "��renci Soyad�n� Giriniz :";
	cin >> ogr.soyad;
	cout << "��renci B�l�m Giriniz :";
	cin >> ogr.bolum;
	cout << "��renci S�n�f�n� Giriniz :";
	cin >> ogr.sinif;
	//dosyaya yazma
	dosya << ogr.ogrNo << " " << ogr.ad << " " << ogr.soyad << " " << ogr.bolum << " " << ogr.sinif << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0" << endl << endl << "Se�im :";
	cin >> secim;
	if (secim == 1) {
		ogrenciModul();
	}
	else {
		exit(0);
	}
}
//ogrenciBilgileri.txt dosyas�nda arama yapma fonksiyonu
void ogrenciArama()
{
	system("cls");
	int secim;
	cout << "L�tfen Arama T�r�nu Se�iniz" << endl << endl << left << setw(20) << "Numara ile Arama" << "--> 1" << endl << left << setw(20) << "Ad ile Arama" << "--> 2" << endl << left << setw(20) << "Bir �nceki Men� " << "--> 3" << endl << endl;
tekrar:
	cout << "Se�im :";
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
//��renci numaras� ile arama yapma
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

	cout << "Arad���n�z ��renci Numaras�n� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime); //dosyan�n bir sat�r�n� okumak i�in
		istringstream akim(kelime); //kelime yi par�alara ay�rmak i�in
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ogrenciler[a][b] = sozcuk; //par�alanan kelime matrise at�l�yor.
			b++;
		}
		b = 0;
		a++;
	}
	for (int i = 0; i < a; i++) {
		//aranan ��remci numaras� varsa ekrana yaz�l�yor.
		if (no == (ogrenciler[i][0])) {
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(15) << "��renci No" << left << '|' << setw(15) << "��renci Ad�" << left << '|' << setw(15) << "��renci Soyad�" << left << '|' << setw(15) << "B�l�m" << left << '|' << setw(15) << "S�n�f�" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[i][0] << left << "|" << setw(15) << ogrenciler[i][1] << left << "|" << setw(15) << ogrenciler[i][2] << left << "|" << setw(15) << ogrenciler[i][3] << left << "|" << setw(15) << ogrenciler[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Arad���n�z ��renci Kay�tl� De�il Kaydetmek ��in 1' e Bas�n :";
		cin >> giris;
		if (giris == 1)
			ogrenciKayit();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 \nSe�im :";
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

	cout << "Arad���n�z ��renci Ad�n� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rmak
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
			cout << left << '|' << setw(15) << "��renci No" << left << '|' << setw(15) << "��renci Ad�" << left << '|' << setw(15) << "��renci Soyad�" << left << '|' << setw(15) << "B�l�m" << left << '|' << setw(15) << "S�n�f�" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[i][0] << left << "|" << setw(15) << ogrenciler[i][1] << left << "|" << setw(15) << ogrenciler[i][2] << left << "|" << setw(15) << ogrenciler[i][3] << left << "|" << setw(15) << ogrenciler[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Arad���n�z ��renci Kay�tl� De�il Kaydetmek ��in 1' e Bas�n :";
		cin >> giris;
		if (giris == 1)
			ogrenciKayit();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 \nSe�im :";
	cin >> sec;
	if (sec == 0) {
		exit(0);
	}
	else
	{
		ogrenciArama();
	}
}


//kay�tl� ��rencileri listelemeki�in fonksiyonumuz
void ogrenciListele()
{
	system("cls");
	int secim;
	cout << "L�tfen Listeleme T�r�n� Se�iniz" << endl << endl << left << setw(25) << "Bolume Gore Listeleme" << "--> 1" << endl << left << setw(25) << "Sinifa Gore Listeleme" << "--> 2" << endl << left << setw(25) << "�st Men�ye Git" << "--> 3" << endl << endl;
tekrar:
	cout << "Se�im :";
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
		cout << "Hatali Girii Yaptiniz Tekrar Se�iniz" << endl;
		goto tekrar;
		break;
	}
}
//b�l�me g�re ��renci listelemek
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

	cout << "Arad���n�z B�l�m� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara b�lme
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
	cout << left << '|' << setw(15) << "��renci No" << left << '|' << setw(15) << "��renci Ad�" << left << '|' << setw(15) << "��renci Soyad�" << left << '|' << setw(15) << "B�l�m" << left << '|' << setw(15) << "S�n�f�" << endl << endl;
	cout << "_______________________________________________________________________" << endl;
	for (int j = 0; j < a - 1; j++)
	{//istenilen b�l�m ��rencileri yazd�r�l�yor
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
		cout << "Arad���n�z B�l�mde Kay�tl� ��renci Bulunamad�" << endl;
	cout << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 \nSe�im :";
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

	cout << "Arad���n�z S�n�f� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
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
	cout << left << '|' << setw(15) << "��renci No" << left << '|' << setw(15) << "��renci Ad�" << left << '|' << setw(15) << "��renci Soyad�" << left << '|' << setw(15) << "B�l�m" << left << '|' << setw(15) << "S�n�f�" << endl << endl;
	cout << "_______________________________________________________________________" << endl;
	for (int j = 0; j < a - 1; j++)
	{//istenilen s�n�f ��rencileri listeleniyor
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
		cout << "Arad���n�z S�n�fta Kay�tl� ��renci Bulunamad�";
	cout << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 \nSe�im :";
	cin >> giris;
	if (giris == 0) {
		exit(0);
	}
	else
	{
		ogrenciListele();
	}
}
//var olan ��renci bilgilereini d�zenleme fonkisyonu
void ogrenciDuzenleme()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	ogrenci ogr;
	string no, kelime;
	int a = 0, b = 0, var = 0;
	string ogrenciler[1000][5];
	cout << "D�zenlenecek ��rencinin Numaras�n� Giriniz :";
	cin >> no;
	system("cls");
	ifstream dosya;
	dosya.open("ogrenciBilgileri.txt");//��renci bilgileri dosyas� okuma modunda a��l�yor.
	ofstream yDosya;
	yDosya.open("ogrenciBilgileri1.txt", ios::app);//yeni bir dosya ekleme modunda a��l�yor.
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
		//d�zenlenlenecek ��renci hari� di�er t�m ��rencileri yeni dosyaya yaz�yoruz
		if (no != ogrenciler[a][0] && ogrenciler[a][0] != "") {
			yDosya << kelime << endl;
		}
		//d�zenlenecek ��renci bilgilerini ekrana yaz�yoruz.
		else if (no == ogrenciler[a][0]) {
			cout << "D�zenlenecek ��renci Bilgileri " << endl << endl;
			var = 1;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(15) << "��renci No" << left << '|' << setw(15) << "��renci Ad�" << left << '|' << setw(15) << "��renci Soyad�" << left << '|' << setw(15) << "B�l�m" << left << '|' << setw(15) << "S�n�f�" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(15) << ogrenciler[a][0] << left << "|" << setw(15) << ogrenciler[a][1] << left << "|" << setw(15) << ogrenciler[a][2] << left << "|" << setw(15) << ogrenciler[a][3] << left << "|" << setw(15) << ogrenciler[a][4] << endl;
		}
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);
	cout << "_______________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	//d�zenlenecek ��renci bilgilerini tekrar istiyoruz.
	if (var == 1) {
		cout << "��renci Numaras�n� Giriniz :";
		cin >> ogr.ogrNo;
		cout << "��renci Ad�n� Giriniz :";
		cin >> ogr.ad;
		cout << "��renci Soyad�n� Giriniz :";
		cin >> ogr.soyad;
		cout << "��renci B�l�m Giriniz :";
		cin >> ogr.bolum;
		cout << "��renci S�n�f Giriniz :";
		cin >> ogr.sinif;
		//d�zenlenen ��renciyi de yeni dosyaya yaz�yoruz.
		yDosya << ogr.ogrNo << " " << ogr.ad << " " << ogr.soyad << " " << ogr.bolum << " " << ogr.sinif << endl;
		dosya.close();
		yDosya.close();

		
		cout << endl << "D�zenleme Ger�ekle�tirldi." << endl;
	}
	else
		cout << "��renci Bulunamad�" << endl;
	remove("ogrenciBilgileri.txt");//��renci bilgileri dosyas�n� siliyoruz.
	rename("ogrenciBilgileri1.txt", "ogrenciBilgileri.txt");//yeni dosyan�n ad�n� ilk dosyan�n ad�n� veriyoruz.

	int secim;
	cout << endl << "Ana Men�ye D�nmek ��in 1 e Bas�n�z." << endl;
	cin >> secim;
	if (secim == 1)
	{
		main();
	}
	else
		exit(0);
}
//��renci mod�l�n�n bitti�i yer

//�gretim Elemani Mod�l� ba�lad��� yer.
//��retim eleman� bilgileri i�in d���m olu�turuluyor.
struct ogrElemani {
	long int sicilNo;
	char unvan[20];
	char ad[20];
	char soyad[20];
	char bolum[30];
};
//mod�l i�in gerekli fonksiyonlar tan�mlan�yor.
void oElemaniEkle();
void oElemaniAra();
void oElemaniG�ncelle();
void oElemaniListele();

void ogretimElemaniModul() {
	system("cls");
	int secim;
	cout << "L�tfen Yapmak �stedi�iniz ��lemi Se�iniz" << endl << endl << left << setw(25) << "�gretim ELeman� Eklemek" << "--> 1" << endl << left << setw(25) << "��retim Eleman� Arama" << "--> 2" << endl << left << setw(25) << "��retim Eleman� Listeleme" << "--> 3" << endl << left << setw(25) << "��retim Eleman� D�zenleme" << "--> 4 " << endl << left << setw(25) << "Bir �nceki Men�" << "--> 5" << endl << left << setw(25) << "��kmak ��in" << "--> 0" << endl << endl;
tekrar:
	cout << "Se�im :";
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
		oElemaniG�ncelle();
		break;
	case 5:
		main();
	default:
		cout << "Hatali Giri� Yapt�n�z Tekrar Se�iniz" << endl;
		goto tekrar;
		break;
	}
}
//��retim eleman� ekleme fonkisyonu
void oElemaniEkle()
{
	system("cls");
	ogrElemani oE;
	int secim;
	ofstream dosya;
	dosya.open("oElemaniBilgileri.txt", ios::app);//dosya ekleme modunda a��l�yor.
												  //kullan�c�dan bilgiler isteniyor.
	cout << "��retim Eleman� Sicil Numaras�n� Giriniz :";
	cin >> oE.sicilNo;
	cout << "��retim Eleman� Ad�n� Giriniz :";
	cin >> oE.ad;
	cout << "��retim Eleman� Soyad�n� Giriniz :";
	cin >> oE.soyad;
	cout << "��retim Eleman� B�l�m�n� Giriniz :";
	cin >> oE.bolum;
	cout << "��retim Eleman� �nvan�n� Giriniz :";
	cin >> oE.unvan;
	//veriler dosyaya yaz�l�yor
	dosya << oE.sicilNo << " " << oE.unvan << " " << oE.ad << " " << oE.soyad << " " << oE.bolum << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
	cin >> secim;
	if (secim == 1) {
		ogretimElemaniModul();
	}
	else {
		exit(0);
	}
}
//��retim eleman� arama fonksiyonu
void oElemaniAra()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int a = 0, b = 0, yok = 0, giris, sec;
	string oElemanlari[1000][5];
	string kelime, no;
	ifstream dosya;
	dosya.open("oElemaniBilgileri.txt");//dosya okuma modunda a��l�yor.

	cout << "Arad���n�z ��retim Eleman� Sicil Numaras�n� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
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
		//sicilnumaras� girilen ��retim eleman� ekrana yaz�l�yor.
		if (no == (oElemanlari[i][0])) {
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "�nvan" << left << '|' << setw(25) << "��retim Eleman� Ad�" << left << '|' << setw(25) << "Ogretim Eleman� Soyad�" << left << '|' << setw(20) << "��retim Eleman� B�l�m" << endl << endl;
			cout << "___________________________________________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(20) << oElemanlari[i][0] << left << "|" << setw(20) << oElemanlari[i][1] << left << "|" << setw(20) << oElemanlari[i][2] << left << "|" << setw(20) << oElemanlari[i][3] << left << "|" << setw(20) << oElemanlari[i][4] << endl;
			yok = 1;
			goto git;
		}
	}
	//aranan ��retim eleman� yoksa
	if (yok != 1) {
		cout << "Arad���n�z ��retim Eleman� Kay�tl� De�il Kaydetmek ��in 1' e Bas�n :";
		cin >> giris;
		if (giris == 1)
			oElemaniEkle();
	}
git:
	SetConsoleTextAttribute(renkVer, 2);
	cout << "___________________________________________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1 " << endl << left << setw(25) << "��kmak ��in" << "--> 0 \nSe�im :";
	cin >> sec;
	if (sec == 1) {
		ogretimElemaniModul();
	}
	else
	{
		exit(0);
	}
}
//��retim eleman� bilgileri g�ncelleme
void oElemaniG�ncelle()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);

	ogrElemani oE;
	string no, kelime;
	int a = 0, b = 0, var = 0;
	string oElemanlari[1000][5];
	cout << "D�zenlenecek ��retim Eleman�n�n Sicil Numaras�n� Giriniz :";
	cin >> no;
	ifstream dosya;
	dosya.open("oElemaniBilgileri.txt");//dosya okuma modunda a��l�yor
	ofstream yDosya;
	yDosya.open("oElemaniBilgileri1.txt", ios::app);//yeni bir do�ya olu�turuyoruz ekleme modunda

	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rrma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			oElemanlari[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		//g�ncelenecek hoca hari� t�m veriler yeni dosyaya yaz�l�yor.
		if (no != oElemanlari[a][0] && oElemanlari[a][0] != "") {
			yDosya << kelime << endl;
		}
		//d�zenlenecek hoca bilgileri ekrana yaz�l�yor.
		else if (no == oElemanlari[a][0]) {
			cout << "D�zenlenecek ��retim Eleman� Bilgileri " << endl << endl;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "�nvan" << left << '|' << setw(25) << "��retim Eleman� Ad�" << left << '|' << setw(25) << "Ogretim Eleman� Soyad�" << left << '|' << setw(20) << "��retim Eleman� B�l�m" << endl << endl;
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
	//d�zenlenecek hocan�n verileri yeniden giriliyor.
	if (var == 1) {
		cout << "��retim Eleman� Sicil Numaras�n� Giriniz :";
		cin >> oE.sicilNo;
		cout << "��retim Eleman�n Ad�n� Giriniz :";
		cin >> oE.ad;
		cout << "��retim Eleman�n Soyad�n� Giriniz :";
		cin >> oE.soyad;
		cout << "��retim Eleman�n B�l�m�n� Giriniz :";
		cin >> oE.bolum;
		cout << "��retim Eleman�n �nvan�n� Giriniz :";
		cin >> oE.unvan;
		//yeni bilgiler yeni dosyaya ekleniyor.
		yDosya << oE.sicilNo << " " << oE.unvan << " " << oE.ad << " " << oE.soyad << " " << oE.bolum << " " << endl;
		dosya.close();
		yDosya.close();

		cout << endl << "D�zenleme Ger�ekle�tirldi." << endl;
	}
	else
		cout << "��retim Eleman� Bulunamad�" << endl;
	remove("oElemaniBilgileri.txt");//eski dosya siliniyor.
	rename("oElemaniBilgileri1.txt", "oElemaniBilgileri.txt");//yeni dosyaya eski dosyan�n ad� veriliyor.
	int secim;
	cout << endl << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 " << endl << "Se�im :";
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

	cout << "Arad���n�z B�l�m� Giriniz :";
	cin >> no;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//string par�alama
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
	cout << left << '|' << setw(8) << "Sicil No" << left << '|' << setw(15) << "�nvan" << left << '|' << setw(25) << "��retim Eleman� Ad�" << left << '|' << setw(25) << "Ogretim Eleman� Soyad�" << left << '|' << setw(20) << "��retim Eleman� B�l�m" << endl << endl;
	cout << "___________________________________________________________________________________________________" << endl;
	for (int j = 0; j < a; j++)
	{
		//��retim elemani listeliyoruz.
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
		cout << "Arad���n�z B�l�mde Kay�tl� ��retim Eleman� Bulunamad�" << endl;
	cout << endl << endl << left << setw(25) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(25) << "��kmak ��in" << "--> 0 " << endl << "Se�im :";
	cin >> giris;
	if (giris == 1) {
		ogretimElemaniModul();
	}
	else
	{
		exit(0);
	}
}
//��retim Eleman� Mod�l� Bitti�i yer

//Ders Mod�l�n Ba�lad��� Yer
//ders i�in d���m olu�turuluyor.
struct ders {
	long int dersNo;
	long int dersKredisi;
	char oElemani[20];
	char dersAd[20];
};
//ders i�lemleri i�in fonksiyonlar tan�mlan�yor.
void dersEkle();
void dersGuncelle();
void dersListele();
void dersAra();

void dersModul() {
	system("cls");
	int secim;
	cout << "L�tfen Yapmak �stedi�iniz ��lemi Se�iniz" << endl << endl << left << setw(15) << "Ders Eklemek" << "--> 1" << endl << left << setw(15) << "Ders Arama" << "--> 2" << endl << left << setw(15) << "Ders Listeleme" << "--> 3" << endl << left << setw(15) << "Ders D�zenleme" << "--> 4 " << endl << left << setw(15) << "�st Men�" << "--> 5" << endl << left << setw(15) << "��kmak ��in" << "--> 0" << endl;
tekrar:
	cout << "Se�im :";
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
		cout << "Hatali Giri� Yaptiniz Tekrar Seciniz" << endl;
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
	dosya.open("ders.txt", ios::app);//ders eklemek i�in dosya a��l�yor.
									 //ders bilgileri kullan�c�dan al�n�yor.
	cout << "Ders Numaras�n� Giriniz :";
	cin >> d.dersNo;
	cout << "Dersin Ad�n� Giriniz :";
	cin >> d.dersAd;
	cout << "Dersin Hocas�n�n Sicil Numaras�n� Giriniz Giriniz :";
	cin >> d.oElemani;
	cout << "Dersin Kredisini Giriniz :";
	cin >> d.dersKredisi;
	//ders bilgileri dosyaya yaz�l�yor.
	dosya << d.dersNo << " " << d.dersAd << " " << d.oElemani << " " << d.dersKredisi << endl;
	dosya.close();
	cout << endl << "Veri Eklendi." << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
	cin >> secim;
	if (secim == 1) {
		dersModul();
	}
	else {
		exit(0);
	}
}
//ders bilgileri g�ncelleme fonksiyonu.
void dersGuncelle()
{
	HANDLE renkVer;
	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	ders d;
	string ad, kelime;
	int a = 0, b = 0, var = 0;
	string ders[1000][5];
	cout << "D�zenlenecek Dersin Ad�n� Giriniz :";
	cin >> ad;
	ifstream dosya;
	dosya.open("ders.txt");//dosya okuma modunda a��l�yor
	ofstream yDosya;
	yDosya.open("ders1.txt", ios::app);//yeni dosya ekleme modunda a��l�yor.

	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		//di�er dersler yeni dosyaya yaz�l�yor.
		if (ad != ders[a][1] && ders[a][0] != "") {
			yDosya << kelime << endl;
		}
		//d�zenlenecek ders bilgileri ekrana yaz�l�yor.
		else if (ad == ders[a][1]) {
			cout << "D�zenlenecek Ders Bilgileri " << endl << endl;
			var = 1;
			SetConsoleTextAttribute(renkVer, 2);
			cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Ad�" << left << '|' << setw(27) << "Dersin Hocas�n�n Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
			cout << "_______________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);
			cout << left << "|" << setw(8) << ders[a][0] << left << "|" << setw(20) << ders[a][1] << left << "|" << setw(27) << ders[a][2] << left << "|" << setw(2) << ders[a][3] << endl << endl;
			SetConsoleTextAttribute(renkVer, 2);
			cout << "_______________________________________________________________________" << endl;

		}
		a++;
	}
	SetConsoleTextAttribute(renkVer, 7);
	//d�zenlenecek dersin bigileri isteniyor
	if (var == 1) {
		cout << "Dersin Numaras�n� Giriniz :";
		cin >> d.dersNo;
		cout << "Dersin Ad�n� Giriniz :";
		cin >> d.dersAd;
		cout << "Dersin Hocas�n�n Sicil Numaras�n� Giriniz :";
		cin >> d.oElemani;
		cout << "Dersin Kredisini Giriniz :";
		cin >> d.dersKredisi;
		yDosya << d.dersNo << " " << d.dersAd << " " << d.oElemani << " " << d.dersKredisi << endl;
		dosya.close();
		yDosya.close();

		cout << endl << "D�zenleme Ger�ekle�tirldi." << endl;
	}
	else
		cout << "Ders Bulunamad�" << endl;
	remove("ders.txt");
	rename("ders1.txt", "ders.txt");
	int secim;
	cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
	cin >> secim;
	if (secim == 1)
	{
		dersModul();
	}
	else if (secim == 0)
		exit(0);
}
//derslerilistelemek i�in fonksiyonumuz
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
	dosya.open("ders.txt");//dosya okuma modunda a��l�yor.
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
		for (int i = 0; akim; ++i) {
			string sozcuk;
			akim >> sozcuk;
			ders[a][b] = sozcuk;//matrise atama
			b++;
		}
		b = 0;
		a++;
	}
	SetConsoleTextAttribute(renkVer, 2);//yaz� rengi verme
	cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Ad�" << left << '|' << setw(10) << "Dersin Hocas�n�n Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);//yaz� rengi verme
	for (int j = 0; j < a - 1; j++)
	{
		if (j % 2 == 0)
			SetConsoleTextAttribute(renkVer, 3);//yaz� rengi verme
		else
			SetConsoleTextAttribute(renkVer, 5);//yaz� rengi verme
		cout << left << '|' << setw(8) << ders[j][0] << left << '|' << setw(20) << ders[j][1] << left << '|' << setw(25) << ders[j][2] << left << '|' << setw(2) << ders[j][3] << endl;
		count++;
	}
	SetConsoleTextAttribute(renkVer, 2);//yaz� rengi verme
	cout << "_____________________________________________________________________" << endl;
	SetConsoleTextAttribute(renkVer, 7);//yaz� rengi verme
	if (count == 0)
		cout << " Kay�tl� Ders Bulunamad�" << endl;
	cout << endl << "Bir �nceki Men�ye D�nmek ��in --> 1 " << endl << "��kmak ��in --> 0 \nGiriniz :";
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
	dosya.open("ders.txt");//dosya okuma modunda a��l�yor

	cout << "Arad���n�z Dersin Ad�n� Giriniz :";
	cin >> ad;
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
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
			SetConsoleTextAttribute(renkVer, 2);//yaz�ya renk verme
			cout << left << '|' << setw(10) << "Ders No" << left << '|' << setw(25) << "Ders Ad�" << left << '|' << setw(30) << "Dersin Hocas�n�n Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
			cout << "_________________________________________________________________________________" << endl;
			SetConsoleTextAttribute(renkVer, 3);//yaz�ya renk verme
			cout << left << '|' << setw(10) << ders[i][0] << left << '|' << setw(25) << ders[i][1] << left << '|' << setw(30) << ders[i][2] << left << '|' << setw(2) << ders[i][3] << " " << endl;
			SetConsoleTextAttribute(renkVer, 2);//yaz�ya renk verme
			cout << "_________________________________________________________________________________" << endl;
			goto git;
		}
	}
	SetConsoleTextAttribute(renkVer, 7);
	if (yok != 1) {
		cout << "Arad���n�z Ders Kay�tl� De�il Kaydetmek ��in 1' e Bas�n :";
		cin >> giris;
		if (giris == 1)
			dersEkle();
	}
git:
	SetConsoleTextAttribute(renkVer, 7);
	cout << endl << left << setw(15) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(15) << "��kmak ��in" << "--> 0 \nSe�im :";
	cin >> sec;
	if (sec == 0) {
		exit(0);
	}
	else
	{
		dersModul();
	}
}
//Ders Mod�l�n� Bitti�i Yer

//Not Giri� Mod�l�n� Ba�lad��� Yer
//not bilgileri i�in d���m olu�turuluyor.
struct not{
	string ogrNum;
	string dersAdi;
	int vize;
	int final;
	double ortalama;
	string durum;
	string dersNum;
};
//i�lemler i�in fonksiyonlar
void ogrDersEkle();
void ogrNotEkle();
void ogrDersListele();
void ogrKarne();

void notGirisModul()
{
	system("cls");
	int secim;
	cout << "L�tfen Yapmak �stedi�iniz ��lemi Se�iniz" << endl << endl << left << setw(22) << "��renciye Ders Ekleme" << "--> 1" << endl << left << setw(22) << "��renciye Not Ekleme" << "--> 2" << endl << left << setw(22) << "��renci Ders Listele" << "--> 3" << endl << left << setw(22) << "��renci Karnesi" << "--> 4 " << endl << left << setw(22) << "Bir �nceki Men�" << "--> 5" << endl << left << setw(22) << "��kmak ��in" << "--> 0" << endl;
tekrar:
	cout << "Se�im :";
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
		cout << "Hatali Giri� Yapt�n�z Tekrar Se�iniz" << endl;
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
		getline(dosya, kelime);//dosya sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
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
	cout << left << '|' << setw(8) << "Ders No" << left << '|' << setw(20) << "Ders Ad�" << left << '|' << setw(10) << "Dersin Hocas�n�n Sicil No" << left << '|' << setw(2) << "Ders Kredisi" << endl << endl;
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
		cout << " Kay�tl� Ders Bulunamad�" << endl;
	yok = a - 1;
	if (count != 0) {
		cout << endl << "��renciye Ekleyebilece�iniz Dersler Yukar�da Listelenmi�tir." << endl;
		cout << "��rencinin Numaras�n� Giriniz :";
		cin >> ogrNo;
	git:
		cout << "Ekleyece�iniz Dersin Numaras�n� Giriniz :";
		cin >> dersNo;
		for (int i = 0; i < a - 1; i++) //dizinin eleman lar�nda bo� olana gelene kadar okumak i�in a-1 diyoruz.
		{
			//ders varsa ��renciye ekleme i�lemi yap�yoruz.
			if (dersNo == ders[i][0]) {
				n.ogrNum = ogrNo;
				n.dersNum = ders[i][0];
				n.dersAdi = ders[i][1];
				ofstream dosya;
				dosya.open("ogrDers.txt", ios::app);
				dosya << n.ogrNum << " " << n.dersNum << " " << n.dersAdi << endl;
				dosya.close();
				cout << endl << "Veri Eklendi." << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
			cout << "Ge�erli Ders Kodu Giriniz" << endl;
			goto git;
		}

	}
	cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
	not n; //not d���m�nden nesne olu�turdum.
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
	cout << "Not Ekleyece�iniz ��renci Numaras�n� Giriniz :";
	cin >> ogrNo;
	system("cls");
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(16) << "��renci Numaras�" << left << '|' << setw(20) << "Dersin Numaras�" << left << '|' << setw(10) << "Dersin Ad�" << endl << endl;
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
		cout << "��renci Numaras�na Ait Ders Bulunamad�." << endl;
		cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
		cout << endl << "��renciye Ekleyebilece�iniz Dersler Yukar�da Listelenmi�tir." << endl;
	git:
		cout << "Ekleyece�iniz Dersin Numaras�n� Giriniz :";
		cin >> dersNo;
		for (int i = 0; i < a - 1; i++) //dizinin eleman lar�nda bo� olana gelene kadar okumak i�in a-1 diyoruz.
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
				cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
			cout << "Ge�erli Ders Kodu Giriniz" << endl;
			goto git;
		}
	}
	cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
	not n; //not d���m�nden nesne olu�turdum.
	string kelime, dersNo, ogrNo;
	ifstream dosya;
	dosya.open("ogrDers.txt");//dosya okuma modunda a��l�yor
	while (!dosya.eof())
	{
		getline(dosya, kelime);//dosyadan sat�r okuma
		istringstream akim(kelime);//par�alara ay�rma
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
	cout << "Derslerini Listeleyece�iniz ��rencinin Numaras�n� Giriniz :";
	cin >> ogrNo;
	system("cls");
	//ogrenci bilgilerine ula��l�yor.
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
	cout << "Ogrencinin Numaras� :" << ogrNo << endl << "Ogrencinin Ad� Soyad� :" << ogrenciler[deger][1] << " " << ogrenciler[deger][2] << endl << "Ogrencinin S�n�f� :" << ogrenciler[deger][4] << endl << "Ogrencinin B�l�m� :" << ogrenciler[deger][3] << endl << endl;
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(20) << "Dersin Numaras�" << left << '|' << setw(10) << "Dersin Ad�" << endl << endl;
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
		cout << "��renci Numaras�na Ait Ders Bulunamad�." << endl;
		cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
		cin >> secim;
		if (secim == 1) {
			notGirisModul();
		}
		else {
			exit(0);
		}
	}
	cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
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
	}//��renci bilgilerine ula��l�yor.
	int deg = a;
tekrar:
	cout << "Karnesini G�rmek �stedi�iniz ��renci Numaras�n� Giriniz :";
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
	cout << "Ogrencinin Numaras� :" << ogrNo << endl << "Ogrencinin Ad� Soyad� :" << ogrenciler[deger][1] << " " << ogrenciler[deger][2] << endl << "Ogrencinin S�n�f� :" << ogrenciler[deger][4] << endl << "Ogrencinin B�l�m� :" << ogrenciler[deger][3] << endl << endl;
	SetConsoleTextAttribute(renkVer, 2);
	cout << left << '|' << setw(20) << "Dersin Ad�" << left << '|' << setw(10) << "Vize" << left << '|' << setw(10) << "Final" << left << '|' << setw(10) << "Ortalama" << left << '|' << setw(10) << "Durum" << endl << endl;
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
		cout << "��renci Numaras�na Ait Ders Bulunamad�." << endl;
		cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
		cin >> secim;
		if (secim == 1) {
			notGirisModul();
		}
		else {
			exit(0);
		}
	}
	cout << endl << left << setw(20) << "�st Men�ye D�nmek ��in" << "--> 1" << endl << left << setw(20) << "��kmak ��in" << "--> 0" << endl << "Se�im :";
	cin >> secim;
	if (secim == 1) {
		notGirisModul();
	}
	else {
		exit(0);
	}
}