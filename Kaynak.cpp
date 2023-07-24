/*
**
**                                                   SAKARYA ÜNÝVERSÝTE
**
**                                            BÝLGÝSAYAR VE BÝLÝÞÝM FAKÜLTESÝ
**
**                                             BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**
**                                            NESNEYE DAYALI PROGRAMLAMA DERSÝ
**
**                                               2022-2023 GÜZ DÖNEMÝ ÖDEVÝ
**                                        
**                                             
**                                              ÖDEV ADI: PROJE/TASARIM
** 
**                                              ÖÐRENCÝ ADÝ : SADETTÝN KAYA
**
**                                              ÖÐRENCÝ NUMARASI:G221210006
**
**                                          DERSÝNÝ ALDIÐI GRUP:2.ÖÐRETÝM A GRUBU
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
#include<fstream> //dosya iþlemleri için kütüphane ekledik
#include<string>
#include<iomanip>
using namespace std;


class Urun //urun classsý açtým
{
private:

	

public:

	string urunAdi;
	float urunFiyat;
	float urunStokAdet;
	float kaloriGram;
	string yemekAdi;

	void depoyaKullanciKaydetsin() //depoya kullanýcý kaydediyor
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

	void urunGuncelle(string degistirAd) //depodaki urunu güncellliyor 
	{
		ifstream DosyaOku("Depo.txt"); //bilgi almak icin 
		ofstream DosyaYaz("gecici.txt", ios::out); //gecici dosya açtýk

		while (DosyaOku >> urunAdi >> urunStokAdet >> urunFiyat >> kaloriGram) //depoyu okuyor
		{


			if (urunAdi == degistirAd) //girilen ad güncellenecek ada eþitse bilgileri tekrar istiyo
			{
				cout << "girilecek urun bilgileri: " << endl;
				cout << "urun adi giriniz: " << endl;
				cin >> urunAdi;
				cout << "urun adeti giriniz: " << endl;
				cin >> urunStokAdet;
				cout << "urun fiyatý giriniz: " << endl;
				cin >> urunFiyat;
				cout << "urun kalorisi giriniz: " << endl;
				cin >> kaloriGram;
				DosyaYaz << urunAdi << setw(10) << urunStokAdet << setw(10) << kaloriGram << setw(10) << urunFiyat; //geciciye yazýyo
			}

			else
			{
				DosyaYaz << urunAdi << setw(10) << urunStokAdet << setw(10) << kaloriGram << setw(10) << urunFiyat; //eþit deðilse de geciciye yazýyo
			}
		}
		DosyaYaz.close(); //dosyalarý kapattýk
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

			if (urunAdi == silurun) //silincek ad girilen ada eþitse siliyor
			{
				cout << "silinecek urun bilgileri: " << endl;
				cout << "urun adi: " << urunAdi << endl;
				cout << "urun adeti: " << urunStokAdet << endl;
				cout << "urun fiyatý: " << urunFiyat << endl;
				cout << "urun kalorisi: " << kaloriGram << endl;
			}

			else
			{
				DosyaYaz << endl << urunAdi << endl << urunStokAdet << endl << kaloriGram << endl << urunFiyat << endl; //deðilse geciciye atýyo
			}
		}
		DosyaYaz.close();
		DosyaOku.close();

		remove("Depo.txt"); //depoyu siliyo
		rename("gecici.txt", "Depo.txt"); //deðiþtiriyo isimleri
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

			malzemefile << setw(20) << yemekAdi << setw(20) << urunAdi << setw(20) << urunStokAdet<<endl; //malzeme dosyasýna atýyo

		}
		malzemefile.close();


	}

	void malzemeyeKullaniciKaydetsin() //malzemeye kulllanýcý kaydediyor yemek adýyla beraber kaydediyor yemek txt sine baðlamak için
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

class Yemek : public Urun //kalýtým yaptým diðer sýnýfýn public üyelerinni kullanmak için
{
public:

	void yemekGuncelle(string güncelleYemek)//yemek güncelleme fonksiyonu
	{
		ifstream DosyaOku("yemek.txt"); //bilgi almak icin 
		ofstream DosyaYaz("gecici.txt", ios::out); //gecici dosya açtýk
		while (DosyaOku >> yemekAdi >> urunFiyat) //yemek dosyasýný okuyor
		{
			if (yemekAdi == güncelleYemek)
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
			if (yemekAdi == güncelleYemek)
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
		rename("temp.txt", "malzeme.txt");//isimleri deðiþtirdik
	}

	void yemekSil()//yemek siliyor ayný zamanda malzeme dosyasýndan o yemekle ilgili urunleri de siliyor
	{
		string yemekAdiAra;
		cout << "silmek istediginiz yemegi giriniz" << endl;
		cin >> yemekAdiAra;
		ifstream dosyaoku("yemek.txt");//bilgi almak için.
		ofstream dosyayaz("gecici.txt", ios::out);//gecici txt açtýk

		while (dosyaoku >> yemekAdi >> yemekFiyati)//dosyayý okuyor döngüde
		{
			if (yemekAdiAra == yemekAdi)//girilen yemek adý yemek adýna eþiitse siliyor
			{
				cout << "silindi";
			}

			else
			{
				dosyayaz << endl << yemekAdi << setw(20) << yemekFiyati << endl;//eþit deðilse gecici txt ye yazýyor 
			}
		}

		ifstream dosyaokuu("malzeme.txt"); //malzemeye baðlamak için malzeme txt yi de açtýk
		ofstream dosyayayazzz("temp.txt"); //gecici txt açtýk

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

	void yemekKaydet(string yemekname, float yemkparasi) //kendim girmek için yemek kaydet fonku yazdým
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

		ydosyasi.open("yemek.txt", ios::out | ios::app);//dosyayi açtýk yemek txt adýnda

		if (ydosyasi.is_open())//eðer dosya açýksa alttaki iþlemleri yap diyor
		{
			cout << "yemek adi giriniz...:" << endl;
			cin >> yemekAdi; ydosyasi <<setw(20)<< yemekAdi;
			cout << "yemek fiyati giriniz...:" << endl;
			cin >> yemekFiyati; ydosyasi << setw(20)<<yemekFiyati;
		}
		ydosyasi.close();//dosyayi kapattýk
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

	yemegimiz.yemekKaydet("karniyarik", 5);//yemek txt sinde bir þeyler olmasý lazým silmek güncellemek için o yuzden bu iþlemin yapýlabildiiðini göstercek kadar
	yemegimiz.yemekKaydet("dolma", 44);     //az þeyler ekledim 
	yemegimiz.yemekKaydet("menemen", 55);

	do //menü
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



		Urun urunumuz;//urun classýndan urunumuz diye nesne oluþturdum
		fstream dosya("Depo.txt", ios::out);//dosyayi temizliyo böyle
		dosya.close();
		fstream malzemefile("malzeme.txt", ios::out);
		malzemefile.close();
		int secenek;
		cin >> secenek;
		string adgir;
		urunumuz.depoyaKaydet("fasulye", 20, 20, 5);
		urunumuz.depoyaKaydet("pýrasa", 20, 20, 5);  //depo boþ durmasýn diye kendim kaydettim urun 
		urunumuz.depoyaKaydet("sogan", 20, 20, 5);   // cunku kullanýcý direkt silme iþlemine basmak isteyebilirdi boþ durmamasý lazým deponun
		urunumuz.malzemeyeKaydet("patlicanyemegi", "patlican", 5);  //depoya kaydetme sebebimle ayný sebepten ötürü buna da kaydettim kendim biraz
		urunumuz.malzemeyeKaydet("pirasayemegi", "pirasa", 5);
		urunumuz.malzemeyeKaydet("karniyarik", "kiyma", 8);
		switch (secenek)
		{
		case 1:

			urunumuz.depoyaKullanciKaydetsin();//depoya kullanýcý kaydediyor
			break;

		case 2:

			cout << "guncellenecek urunun adini gir" << endl;
			cin >> adgir;
			urunumuz.urunGuncelle(adgir);//depodaki urunu güncelliyor
			break;

		case 3:

			cout << "silinecek urunun adini giriniz" << endl;
			cin >> adgir;
			urunumuz.urunSil(adgir); //depodaki urunu siliyor
			break;

		case 4:
			urunumuz.malzemeyeKullaniciKaydetsin(); //malzeme txtsine malzeme kaydediyor kullanýcý
			break;

		case 5:
			urunumuz.malzemeSil(); //malzeme siliyor
			break;
		case 6:
			yemegimiz.yemekKullaniciEklesin(); //yemek ekliyo kullanýcý
			break;
		case 7:
			yemegimiz.yemekSil(); //yemek siliyo
			break;
		case 8:
			cout << "guncellemek istediginiz yemek adini giriniz" << endl;
			cin >> adgir;
			yemegimiz.yemekGuncelle(adgir); //yemek güncelliyo
			break;

		default:
			cout << "lutfen gercerli aralikta sayi giriniz";
			break;
		}

		cout << endl;
		cout << "islemi tekrar yapmak ister misiniz (e/h)" << endl;  //dongü icin kullanýcýya evet hayir sorusunu sordum
		cin >> eh;

	}

	while (eh != 'h');

	system("pause");





}