//çoksayıda ilişkili dosya kullanımı
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;
int main(int argc, char* argv[])
{ // hasta.txt dosyasında yer alancak alanlar
	int secim, i = 1;
	string Hasta_Adi;
	string Hasta_Soyadi;
	string Tc;
	string Tel;
	int Hasta_Yas;
	char Hasta_cinsiyet;
	//muayene.txt dosyasında yer alacak alanlar
	//string Tc; iki dosya arasındaki ilişkiyi sağlamak için
	string tarih;
	string DK_Adi;
	string Teshis;
	double Ucret;
	char cevap = 'e';
	do
	{
		cout << " Ne yapmak istiyorsunuz ? " << endl;
		cout << " 1) Hasta kayit ekleme " << endl;
		cout << " 2) Randevu kayit " << endl;
		cout << " 3) programdan cikis " << endl;
		cin >> secim;
	} while (secim != 1 && secim != 2 && secim != 3);
	if (secim == 1)
	{
		ofstream DosyaYaz;
		DosyaYaz.open("Hasta.txt", ios::app);
		do
		{
			cout << "\n Hasta TC :"; cin >> Tc;
			cout << "\n Hasta adi :"; cin >> Hasta_Adi;
			cout << "\n Hasta soyadi :"; cin >> Hasta_Soyadi;
			cout << "\n Hasta Yasi :"; cin >> Hasta_Yas;
			cout << "\n telefonu :"; cin >> Tel;
			cout << "\n cinsiyet :"; cin >> Hasta_cinsiyet;
			DosyaYaz << Tc << " " << Hasta_Adi << ' ' << Hasta_Soyadi << ' '
				<< Hasta_Yas << ' ' << Tel << ' '
				<< Hasta_cinsiyet << "\n";
			cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
		} while (!(cevap == 'h'));
		DosyaYaz.close();
		cout << "dosyaya yazim tamamlandi. ";
	}
	if (secim == 2)
	{
		string TC;
		cout << " Hasta TC :"; cin >> TC;
		ifstream DosyaOku("Hasta.txt");
		while (!DosyaOku.eof())
		{
			DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi
				>> Hasta_Yas >> Tel >> Hasta_cinsiyet;
			if (TC == Tc)
			{
				cout << "\n Hasta Bilgileri \n";
				cout << " TC no :" << Tc << endl;
				cout << "adi :" << Hasta_Adi << endl;
				cout << "soy adi :" << Hasta_Soyadi << endl;
				cout << "Yaşi :" << Hasta_Yas << endl;
				cout << "telefonu :" << Tel << endl;
				cout << "cinsiyeti:" << Hasta_cinsiyet << endl;
				cout << " randevu istiyor mu? (e/h)" << endl;
				cin >> cevap;
				if (cevap == 'e')
				{
					DosyaOku.close();
					ofstream DosyaYaz;
					DosyaYaz.open("Muayene.txt", ios::app);
					cout << "\n Randevu Bilgileri \n";
					cout << "\n Tarih :"; cin >> tarih;
					cout << "\n Doktor Adi :"; cin >> DK_Adi;
					cout << "\n Teshis :"; cin >> Teshis;
					cout << "\n Muayene Ucreti :"; cin >> Ucret;
					DosyaYaz << Tc << " " << tarih << ' ' << DK_Adi << ' '
						<< Teshis << ' ' << Ucret << "\n";
					DosyaYaz.close();
					system("PAUSE");
					exit(1);
				}
				else
				{
					exit(1);
				}
			}
		}
	}
	system("PAUSE");
	return EXIT_SUCCESS;

	if (secim == 3)
	{
		string TC;
		cout << " Hasta TC :"; cin >> TC;
		ifstream DosyaOku("Hasta.txt");
		while (!DosyaOku.eof())
		{
			DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi
				>> Hasta_Yas >> Tel >> Hasta_cinsiyet;
			if (TC == Tc)
			{
				cout << "\n Hasta Bilgileri \n";
				cout << " TC no :" << Tc << endl;
				cout << " adi :" << Hasta_Adi << endl;
				cout << " soy adi :" << Hasta_Soyadi << endl;
				cout << " Yaşi :" << Hasta_Yas << endl;
				cout << " telefonu :" << Tel << endl;
				cout << " cinsiyeti:" << Hasta_cinsiyet << endl;
				TC = Tc;
				DosyaOku.close();
				ofstream DosyaYaz;
				DosyaOku.open("Muayene.txt", ios::in);
				cout << " randevu bilgileri \n" << endl;
				cout << setw(11) << " TC " << setw(10) << " Tarih " << setw(12) << " DoktorAdi " << setw(10)
					<< " Teshis " << setw(6) << " Ucret" << endl;
				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> tarih >> DK_Adi >> Teshis >> Ucret;
					if (TC == Tc)
					{
						cout << setw(11) << Tc << setw(10) << tarih << setw(12) << DK_Adi
							<< setw(10)
							<< Teshis << setw(6) << Ucret << endl;
					}
				}
				DosyaYaz.close();
				system("PAUSE");
				exit(1);
			}
		}
	}
}
