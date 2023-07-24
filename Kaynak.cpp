/*
**
**                                                   SAKARYA �N�VERS�TE
**
**                                            B�LG�SAYAR VE B�L���M FAK�LTES�
**
**                                             B�LG�SAYAR M�HEND�SL��� B�L�M�
**
**                                            NESNEYE DAYALI PROGRAMLAMA DERS�
**
**                                               2022-2023 G�Z D�NEM� �DEV�
**                                        
**                                             
**                                              �DEV ADI: PROJE/TASARIM
** 
**                                              ��RENC� AD� : SADETT�N KAYA
**
**                                              ��RENC� NUMARASI:G221210006
**
**                                          DERS�N� ALDI�I GRUP:2.��RET�M A GRUBU
**
**
**
**
**
**
**
**
**
**
******************************************************************************************************************************************/


#include<iostream>
#include<fstream> //dosya i�lemleri i�in k�t�phane ekledik
#include<string>
#include<iomanip>
using namespace std;


class Urun //urun classs� a�t�m
{
private:

	

public:

	string urunAdi;
	float urunFiyat;
	float urunStokAdet;
	float kaloriGram;
	string yemekAdi;

	void depoyaKullanciKaydetsin() //depoya kullan�c� kaydediyor
	{
		fstream dosya;
		dosya.open("Depo.txt", ios::out | ios::app);
		if (dosya.is_open())
		{
			cout << "urun adi giriniz...:" << endl;
			cin >> urunAdi;
			cout << "urun stok adeti giriniz...:" << endl;
			cin >> urunStokAdet;
			cout << "urun fiyati giriniz...:" << endl;
			cin >> urunFiyat;
			cout << "urunun kalori gramini giriniz" << endl;
			cin >> kaloriGram;
			dosya << endl << urunAdi << setw(20) << urunStokAdet << setw(20) << kaloriGram << setw(20) << urunFiyat << endl;

		}

		dosya.close();
	}

	void depoyaKaydet(string urunadi, float stokAdet, float fiyt, float kaloriGr) //depoya ben kaydediyorum 
	{

		urunAdi = urunadi;
		urunStokAdet = stokAdet;
		urunFiyat = fiyt;
		kaloriGram = kaloriGr;
		fstream dosya;


		dosya.open("Depo.txt", ios::out | ios::app);
		if (dosya.is_open() == true)
		{
			dosya << urunAdi << endl << urunStokAdet << " " << endl << urunFiyat << " " << endl << kaloriGram << " " << endl << endl;
		}
		dosya.close();
	}

	void urunGuncelle(string degistirAd) //depodaki urunu g�ncellliyor 
	{
		ifstream DosyaOku("Depo.txt"); //bilgi almak icin 
		ofstream DosyaYaz("gecici.txt", ios::out); //gecici dosya a�t�k

		while (DosyaOku >> urunAdi >> urunStokAdet >> urunFiyat >> kaloriGram) //depoyu okuyor
		{


			if (urunAdi == degistirAd) //girilen ad g�ncellenecek ada e�itse bilgileri tekrar istiyo
			{
				cout << "girilecek urun bilgileri: " << endl;
				cout << "urun adi giriniz: " << endl;
				cin >> urunAdi;
				cout << "urun adeti giriniz: " << endl;
				cin >> urunStokAdet;
				cout << "urun fiyat� giriniz: " << endl;
				cin >> urunFiyat;
				cout << "urun kalorisi giriniz: " << endl;
				cin >> kaloriGram;
				DosyaYaz << urunAdi << setw(10) << urunStokAdet << setw(10) << kaloriGram << setw(10) << urunFiyat; //geciciye yaz�yo
			}

			else
			{
				DosyaYaz << urunAdi << setw(10) << urunStokAdet << setw(10) << kaloriGram << setw(10) << urunFiyat; //e�it de�ilse de geciciye yaz�yo
			}
		}
		DosyaYaz.close(); //dosyalar� kapatt�k
		DosyaOku.close();

		remove("Depo.txt");
		rename("gecici.txt", "Depo.txt");
	}

	void urunSil(string silurun) //urun sil fonku
	{
		ifstream DosyaOku("Depo.txt");
		ofstream DosyaYaz("gecici.txt", ios::out);

		while (DosyaOku >> urunAdi >> urunStokAdet >> urunFiyat >> kaloriGram) //depoyu okuyo
		{

			if (urunAdi == silurun) //silincek ad girilen ada e�itse siliyor
			{
				cout << "silinecek urun bilgileri: " << endl;
				cout << "urun adi: " << urunAdi << endl;
				cout << "urun adeti: " << urunStokAdet << endl;
				cout << "urun fiyat�: " << urunFiyat << endl;
				cout << "urun kalorisi: " << kaloriGram << endl;
			}

			else
			{
				DosyaYaz << endl << urunAdi << endl << urunStokAdet << endl << kaloriGram << endl << urunFiyat << endl; //de�ilse geciciye at�yo
			}
		}
		DosyaYaz.close();
		DosyaOku.close();

		remove("Depo.txt"); //depoyu siliyo
		rename("gecici.txt", "Depo.txt"); //de�i�tiriyo isimleri
	}

	void malzemeyeKaydet(string yemekadi, string urunadi, float stokadet)//malzemeye ben kaydediyorum
	{
		yemekAdi = yemekadi;
		urunAdi = urunadi;
		urunStokAdet = stokadet;
		fstream malzemefile;
		malzemefile.open("malzeme.txt", ios::out | ios::app);
		if (malzemefile.is_open())
		{

			malzemefile << setw(20) << yemekAdi << setw(20) << urunAdi << setw(20) << urunStokAdet<<endl; //malzeme dosyas�na at�yo

		}
		malzemefile.close();


	}

	void malzemeyeKullaniciKaydetsin() //malzemeye kulllan�c� kaydediyor yemek ad�yla beraber kaydediyor yemek txt sine ba�lamak i�in
	{

		fstream malzemefile;
		malzemefile.open("malzeme.txt", ios::out | ios::app);
		if (malzemefile.is_open())
		{
			int sayi;
			cout << "yemek adi giriniz" << endl;
			cin >> yemekAdi;
			malzemefile <<setw(20)<< yemekAdi ;
			cout << "kac tane malzeme girceksiniz?" << endl;
			cin >> sayi;
			for (int i = 0; i < sayi; i++)
			{
				cout << i + 1 << ". urunun adini giriniz" << endl;
				cin >> urunAdi;

				malzemefile << setw(20)<<urunAdi ;

			}

			for (int i = 0; i < sayi; i++)
			{
				cout << i + 1 << ". urunun stok adedi giriniz " << endl;
				cin >> urunStokAdet;
				malzemefile << setw(20)<<urunStokAdet;
				
			}
		}
		malzemefile.close();
	}

	void malzemeSil()//malzeme siliyor
	{
		string yemekAdiAra;
		cout << "malzemesi silincek yemek adini giriniz" << endl;
		cin >> yemekAdiAra;
		ifstream dosyaoku("malzeme.txt");
		ofstream dosyayaz("gecici.txt", ios::out);
		while (dosyaoku >> yemekAdi >> urunAdi >> urunStokAdet)
		{
			if (yemekAdi == yemekAdiAra)
			{
				cout << "silindi" << endl;
			}
			else
			{
				dosyayaz << endl << yemekAdi << setw(20) << urunAdi << setw(20) << urunStokAdet;
			}
		}
		dosyayaz.close();
		dosyaoku.close();
		remove("malzeme.txt");
		rename("gecici.txt", "malzeme.txt");
	}
};

class Yemek : public Urun //kal�t�m yapt�m di�er s�n�f�n public �yelerinni kullanmak i�in
{
public:

	void yemekGuncelle(string g�ncelleYemek)//yemek g�ncelleme fonksiyonu
	{
		ifstream DosyaOku("yemek.txt"); //bilgi almak icin 
		ofstream DosyaYaz("gecici.txt", ios::out); //gecici dosya a�t�k
		while (DosyaOku >> yemekAdi >> urunFiyat) //yemek dosyas�n� okuyor
		{
			if (yemekAdi == g�ncelleYemek)
			{
				cout << "girilecek yemek bilgileri" << endl;
				cout << "yemek adi...:" << endl;
				cin >> yemekAdi;
				cout << "yemek fiyati...:" << endl;
				cin >> yemekFiyati;
				DosyaYaz << setw(20)<<yemekAdi << setw(20) << yemekFiyati << endl;
			}
			else
			{
				DosyaYaz << setw(20)<<yemekAdi << setw(20) << yemekFiyati << endl;
			}
		}


		ifstream dosyaokuu("malzeme.txt");
		ofstream dosyayayazzz("temp.txt");

		while (dosyaokuu >> yemekAdi >> urunAdi >> urunStokAdet)
		{
			if (yemekAdi == g�ncelleYemek)
			{
				cout << "girdiginiz yemek adini tekrar giriniz" << endl;
				cin >> yemekAdi;
				dosyayayazzz << setw(20)<< endl<<yemekAdi;
				int sayi;
				cout << "guncellediginiz yemegin malzeme sayisini giriniz" << endl;
				cin >> sayi;
				for (int i = 0; i < sayi; i++)
				{
					cout << i + 1 << ". urunun adini giriniz" << endl;
					cin >> urunAdi;
					
					dosyayayazzz << setw(20) << urunAdi;
				}

				for (int i = 0; i < sayi; i++)
				{
					cout << i + 1 << ".urunun fiyatini giriniz" << endl; cin >> urunFiyat;
					dosyayayazzz << setw(20)<< urunFiyat;
				}
			}

			else
			{
				dosyayayazzz << setw(20) << yemekAdi << setw(20)<< urunAdi<<setw(10) << urunStokAdet<<endl;
			}

		}
		dosyayayazzz.close();
		dosyaokuu.close();

		DosyaYaz.close();
		DosyaOku.close();

		remove("yemek.txt");
		rename("gecici.txt", "yemek.txt");


		remove("malzeme.txt");
		rename("temp.txt", "malzeme.txt");//isimleri de�i�tirdik
	}

	void yemekSil()//yemek siliyor ayn� zamanda malzeme dosyas�ndan o yemekle ilgili urunleri de siliyor
	{
		string yemekAdiAra;
		cout << "silmek istediginiz yemegi giriniz" << endl;
		cin >> yemekAdiAra;
		ifstream dosyaoku("yemek.txt");//bilgi almak i�in.
		ofstream dosyayaz("gecici.txt", ios::out);//gecici txt a�t�k

		while (dosyaoku >> yemekAdi >> yemekFiyati)//dosyay� okuyor d�ng�de
		{
			if (yemekAdiAra == yemekAdi)//girilen yemek ad� yemek ad�na e�iitse siliyor
			{
				cout << "silindi";
			}

			else
			{
				dosyayaz << endl << yemekAdi << setw(20) << yemekFiyati << endl;//e�it de�ilse gecici txt ye yaz�yor 
			}
		}

		ifstream dosyaokuu("malzeme.txt"); //malzemeye ba�lamak i�in malzeme txt yi de a�t�k
		ofstream dosyayayazzz("temp.txt"); //gecici txt a�t�k

		while (dosyaokuu >> yemekAdi >> urunAdi >> urunStokAdet)//malzeme dosyasini okuyor
		{
			if (yemekAdiAra != yemekAdi)
			{
				dosyayayazzz << left << setw(20) << yemekAdi << setw(20) << urunAdi << setw(20) << urunStokAdet << endl;
			}
		}
		dosyayayazzz.close();
		dosyaokuu.close();

		dosyayaz.close();
		dosyaoku.close();
		remove("yemek.txt");
		rename("gecici.txt", "yemek.txt");

		remove("malzeme.txt");
		rename("temp.txt", "malzeme.txt");
	}

	void yemekKaydet(string yemekname, float yemkparasi) //kendim girmek i�in yemek kaydet fonku yazd�m
	{
		yemekFiyati = yemkparasi;
		yemekAdi = yemekname;
		fstream Ydosya;
		Ydosya.open("yemek.txt", ios::out | ios::app | ios::in);
		if (Ydosya.is_open())
		{
			Ydosya <<setw(20) << yemekAdi <<setw(20) << yemekFiyati << endl;
		}
		Ydosya.close();
	}

	void yemekKullaniciEklesin()
	{
		fstream ydosyasi;

		ydosyasi.open("yemek.txt", ios::out | ios::app);//dosyayi a�t�k yemek txt ad�nda

		if (ydosyasi.is_open())//e�er dosya a��ksa alttaki i�lemleri yap diyor
		{
			cout << "yemek adi giriniz...:" << endl;
			cin >> yemekAdi; ydosyasi <<setw(20)<< yemekAdi;
			cout << "yemek fiyati giriniz...:" << endl;
			cin >> yemekFiyati; ydosyasi << setw(20)<<yemekFiyati;
		}
		ydosyasi.close();//dosyayi kapatt�k
	}

private:

	string yemekAdi;
	float yemekFiyati;

};


int main()
{

	char eh;
	Yemek yemegimiz;
	fstream ydosyasi("yemek.txt", ios::out);//dosyayi temizliyo
	ydosyasi.close();

	yemegimiz.yemekKaydet("karniyarik", 5);//yemek txt sinde bir �eyler olmas� laz�m silmek g�ncellemek i�in o yuzden bu i�lemin yap�labildii�ini g�stercek kadar
	yemegimiz.yemekKaydet("dolma", 44);     //az �eyler ekledim 
	yemegimiz.yemekKaydet("menemen", 55);

	do //men�
	{
		cout << "*********menu********" << endl << endl;
		cout << "depoya urun kaydetmek icin 1 e basiniz" << endl;
		cout << "depodaki urunu guncellemek icin 2 ye basiniz" << endl;
		cout << "depodaki urunu silmek icin 3 e basiniz " << endl;
		cout << "malzeme dosyasina malzeme kaydetmek icin 4 e basiniz" << endl;
		cout << "malzeme dosyasindan malzeme silmek icin 5 e basiniz" << endl;
		cout << "yemek dosyasina yemek eklemek icin 6 ya basiniz" << endl;
		cout << "yemek silmek icin 7 ye basiniz" << endl;
		cout << "yemek dosyasini guncellemek icin 8 e basiniz" << endl;



		Urun urunumuz;//urun class�ndan urunumuz diye nesne olu�turdum
		fstream dosya("Depo.txt", ios::out);//dosyayi temizliyo b�yle
		dosya.close();
		fstream malzemefile("malzeme.txt", ios::out);
		malzemefile.close();
		int secenek;
		cin >> secenek;
		string adgir;
		urunumuz.depoyaKaydet("fasulye", 20, 20, 5);
		urunumuz.depoyaKaydet("p�rasa", 20, 20, 5);  //depo bo� durmas�n diye kendim kaydettim urun 
		urunumuz.depoyaKaydet("sogan", 20, 20, 5);   // cunku kullan�c� direkt silme i�lemine basmak isteyebilirdi bo� durmamas� laz�m deponun
		urunumuz.malzemeyeKaydet("patlicanyemegi", "patlican", 5);  //depoya kaydetme sebebimle ayn� sebepten �t�r� buna da kaydettim kendim biraz
		urunumuz.malzemeyeKaydet("pirasayemegi", "pirasa", 5);
		urunumuz.malzemeyeKaydet("karniyarik", "kiyma", 8);
		switch (secenek)
		{
		case 1:

			urunumuz.depoyaKullanciKaydetsin();//depoya kullan�c� kaydediyor
			break;

		case 2:

			cout << "guncellenecek urunun adini gir" << endl;
			cin >> adgir;
			urunumuz.urunGuncelle(adgir);//depodaki urunu g�ncelliyor
			break;

		case 3:

			cout << "silinecek urunun adini giriniz" << endl;
			cin >> adgir;
			urunumuz.urunSil(adgir); //depodaki urunu siliyor
			break;

		case 4:
			urunumuz.malzemeyeKullaniciKaydetsin(); //malzeme txtsine malzeme kaydediyor kullan�c�
			break;

		case 5:
			urunumuz.malzemeSil(); //malzeme siliyor
			break;
		case 6:
			yemegimiz.yemekKullaniciEklesin(); //yemek ekliyo kullan�c�
			break;
		case 7:
			yemegimiz.yemekSil(); //yemek siliyo
			break;
		case 8:
			cout << "guncellemek istediginiz yemek adini giriniz" << endl;
			cin >> adgir;
			yemegimiz.yemekGuncelle(adgir); //yemek g�ncelliyo
			break;

		default:
			cout << "lutfen gercerli aralikta sayi giriniz";
			break;
		}

		cout << endl;
		cout << "islemi tekrar yapmak ister misiniz (e/h)" << endl;  //dong� icin kullan�c�ya evet hayir sorusunu sordum
		cin >> eh;

	}

	while (eh != 'h');

	system("pause");





}