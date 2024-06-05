#include<iostream>
#include<cstring>
#include<locale.h>
#include<ctime>
#include<cstdlib>

using namespace std;


void Hangman(int s) {
    switch(s) {
        	
	case 1:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"==========\n";
    	break;
    	
		case 2:
		
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"==========\n";
		break;
		
		case 3:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<" |   |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"==========\n";
		break;
		
		case 4:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<" |\\  |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"==========\n";
    	break;
		
		case 5:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<"/|\\  |\n"
    	<<"     |\n"
    	<<"     |\n"
    	<<"==========\n";
    	break;
		
		case 6:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<"/|\\  |\n"
    	<<"/    |\n"
    	<<"     |\n"
    	<<"==========\n";
    	break;
		
		case 7:
	
	cout<<" +---+\n"
    	<<" |   |\n"
    	<<" O   |\n"
    	<<"/|\\  |\n"
    	<<"/ \\  |\n"
    	<<"     |\n"
    	<<"==========\n";
    	break;		
	
    }
}

const char* kelimegrup[33] = {"banana", "dut", "nar", "elma", "roka", "kivi", "ayva", "turp", 
"erik","incir", "armut", "kiraz", "kavun", "vi�ne", "�ilek", "havu�", "mango", "limon",
"biber", "marul", "kabak", "karpuz", "kay�s�", "pancar", "ananas", "zeytin", "lahana",
"patates", "bezelye", "avokado", "domates", "fasulye", "brokoli"};

char* cevap;
char* teh; // tahmin edilen harfler

void randkelime() {
    int soru;
    srand(time(NULL));

    soru=rand() %33;

    cevap=new char[strlen(kelimegrup[soru])+1];
    strcpy(cevap,kelimegrup[soru]);
    teh=new char[strlen(cevap)+1];
    memset(teh,'\0',strlen(cevap)+1);
}

void gosterge(){
	setlocale(LC_ALL, "Turkish");
    for(int i=0;i<strlen(cevap);++i){
        if(strchr(teh,cevap[i])!='\0'){
            cout<<cevap[i]<<" ";
        }
		else{
            cout<<"_ ";
        }
    }
    cout<<endl;
}

puanhesapla(int y,int d){
		
	switch(y){
		
		case 0:
			y=15;
			break;
		case 1:
			y=10;
			break;
		case 2:
			y=8;
			break;
		case 3:
			y=6;
			break;
		case 4:
			y=4;
			break;
		case 5:
			y=2;
			break;
		case 6:
			y=0;
			break;
	}
	switch(d){
		
		case 0:
			d=0;
			break;
		case 1:
			d=2;
			break;
		case 2:
			d=4;
			break;
		case 3:
			d=6;
			break;
		case 4:
			d=8;
			break;
		case 5:
			d=10;
			break;
		case 6:
			d=12;
			break;
		case 7:
			d=14;
			break;
	}
	
	return d+y;
	
}

int main(){
    setlocale(LC_ALL, "Turkish");

	int oyun;

	cout<<"==================================================="<<endl
		<<"                      WELCOME                      "<<endl<<endl<<endl
		<<"Yeni Oyun (1)                                      "<<endl<<endl<<endl
		<<"Katagori: Meyve-Sebze                              "<<endl<<endl<<endl
		<<"��k�� (2)                                          "<<endl<<endl<<endl
		<<"==================================================="<<endl;

		cin>>oyun;
		
		if(oyun!=1) return 0;

    int ys=0, ds=0, h; // yanl�� say�s�, do�ru say�s�, harf say�s�
    char c; // girilen harf

    randkelime();
    h=strlen(cevap);

    while(ys<6 && ds<h){
    	
        Hangman(ys+1);
        
        gosterge();
        bool harfBulundu=false;
        
        cout<<"Bir harf giriniz: \t";
        cin>>c;

		if(strchr(teh,c)!='\0'){
            cout<<"Bu harfi zaten tahmin ettiniz. Tekrar deneyin."<<endl;
            continue;
        }
		strncat(teh,&c,1);

		cout<<"Kullan�lan Harfler: ";
    	for (int i=0;i<strlen(teh)+1;++i) {
        	cout<<teh[i]<<" ";
    	}
    	cout<<endl;

        for(int i=0;i<h;i++){
            if(c==cevap[i]){
                cout<<i+1<<". harfi buldunuz\n";
                ++ds;
                harfBulundu=true;
            }
        }
        if(!harfBulundu){
            ++ys;
        }

    }
    
	Hangman(ys+1);
	
    if(ys==6){
        cout<<"Kaybettiniz! Do�ru kelime: "<<cevap<<endl;
    }
	else{
        cout<<"Tebrikler! Kazand�n�z. Do�ru kelime: "<<cevap<<endl<<endl;
    }
	
	cout<<"Bu oyunki puan�n�z: "<<puanhesapla(ys,ds)<<endl<<endl;
	
    delete[] cevap;
    delete[] teh;

	system("pause");
	
    return 0;
}
