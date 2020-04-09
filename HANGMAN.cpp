#include <bits/stdc++.h>
using namespace std;
char IMG[71][13];
vector <string> words;
string answer,s;
int a,b,cnt;
void loaddata(){
    ifstream fin1("HANGMANIMG.inp",ios::in);
    for(int i=1;i<71;i++)
        for(int j=1;j<13;j++)
            fin1 >> IMG[i][j];
    fin1.close();
    ifstream fin2("HANGMANWORDS.inp",ios::in);
    fin2 >> a;
    for(int i=0;i<a;i++){
        fin2 >> s;
        words.push_back(s);
    }
    fin2.close();
}
void pickwords(){
    srand(time(NULL));
    b=rand();
    b=b%a;
    answer=words[b];
}
void PRINTING(){
    for(int i=cnt*7+1;i<cnt*7+8;i++){
        for(int j=1;j<13;j++)
            cout << (IMG[i][j]!='.' ? IMG[i][j] : ' ');
        cout << endl;
    }
}
void PLAY(){
    int match;
    char guess;
    string progress="";
    for(int i=0;i<answer.length();i++)
        progress=progress+'-';
    while(cnt<=7){
    match=0;
    PRINTING();
    cout << progress << endl;
    if(cnt==7){
        cout << "You Lose" << endl;
        cout << "The Answer was " << answer << endl;
        exit(0);
    }
    cout << "GUESS A WORD." << endl;
    cin >> guess;
    for(int i=0;i<answer.length();i++)
        if(answer[i]==guess){
            progress[i]=guess;
            match++;
        }
    if(match==0){
        cout << "There was no " << guess << "." << endl;
        cnt++;
    }
    else
        cout << "There was " << match << ' ' << guess << '.' << endl;
    }
}
int main(){
    loaddata();
    std::cin;
    pickwords();
    PLAY();
}
