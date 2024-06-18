#include<iostream>
#include<cstring>
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

const char* words[33] = {"banana", "apple", "cherry", "kiwi", "lemon", "papaya", "watermelon", "avocados",
"pineapple","strawberries", "grape", "orange", "pomegranate", "mangosteen", "apricot", "coconut", "mango", "fig",
"tangerine", "pear", "nance", "muskmelon", "hazelnut", "dates", "lime", "olive", "peach",
"potato", "peas", "jujube", "tomato", "beans", "broccoli"};

char* answer;
char* pl; // predicted letters

void randword() {
    int ri; // random index
    srand(time(NULL));

    ri=rand() %33;

    answer=new char[strlen(words[ri])+1];
    strcpy(answer,words[ri]);
    pl=new char[strlen(answer)+1];
    memset(pl,'\0',strlen(answer)+1);
}

void display(){
    for(int i=0;i<strlen(answer);++i){
        if(strchr(pl,answer[i])!='\0'){
            cout<<answer[i]<<" ";
        }
		else{
            cout<<"_ ";
        }
    }
    cout<<endl;
}

int scor(int y,int d){

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

	int game;

	cout<<"==================================================="<<endl
		<<"                      WELCOME                      "<<endl<<endl<<endl
		<<"Start (1)                                          "<<endl<<endl<<endl
		<<"Quit  (2)                                          "<<endl<<endl
		<<"==================================================="<<endl;

	cin>>game;

	if(game!=1) return 0;

    int wn=0, cn=0, l; // number of wrong guess, correct guess and letters
    char c; // letter input

    randword();
    l=strlen(answer);

    while(wn<6 && cn<l){

        Hangman(wn+1);

        display();
        bool letterFound=false;

        cout<<"Enter a letter: \t";
        cin>>c;

		if(strchr(pl,c)!='\0'){
            cout<<"You have already guessed this letter. Try it again."<<endl;
            continue;
        }
		strncat(pl,&c,1);

		cout<<"Used Letters: ";
    	for (int i=0;i<strlen(pl)+1;++i) {
        	cout<<pl[i]<<" ";
    	}
    	cout<<endl;

        for(int i=0;i<l;i++){
            if(c==answer[i]){
                cout<<"You have found "<<i+1<<". letter\n";
                ++cn;
                letterFound=true;
            }
        }
        if(!letterFound){
            ++wn;
        }

    }

	Hangman(wn+1);

    if(wn==6){
        cout<<"You lost! Hidden word: "<<answer<<endl;
    }
	else{
        cout<<"Congratulations! You won. Hidden word: "<<answer<<endl<<endl;
    }

	cout<<"Your scor: "<<scor(wn,cn)<<endl<<endl;

    delete[] answer;
    delete[] pl;

	system("pause");

    return 0;
}