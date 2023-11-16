#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;

void crypt(int r, string &text);
void decrypt();

//FUNCTIONS
int GenerateKey()
{
    int i;
    
    srand(time(NULL));
    i = rand()%10+1;
    return i;
}

string ChangeCharCrypt(string text, int r)
{
    string new_char;

    for(int x=0; x<text.size(); x++)
        new_char += text[x]+r;

    return new_char;
}

string ChangeCharDecrypt(string text, int r)
{
    string old_char;

    for(int y=0; y<text.size(); y++)
        old_char += text[y]-r;

    return old_char;
}

int main()
{
    int choice, ran;
    string text;

    cout<<"[1] crypt file"<<endl;
    cout<<"[2] decrypt file"<<endl;
    cout<<"[0] exit program"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            ran = GenerateKey();
            crypt(ran, text);
        break;

        case 2:
            decrypt();
        break;
    }
    return 0;
}

//VOID
void crypt(int r, string &text)
{
    ifstream FILE_READ("TESTO.txt");       //READ FILE
    ofstream FILE_KEY("KEY.txt");          //OUTPUT FILE WITH KEY
    ofstream FILE_CRYPT("CRYPT.txt");      //OUTPUT FILE CRYPT

    while(getline(FILE_READ, text))
        FILE_CRYPT << ChangeCharCrypt(text, r);

    FILE_KEY << r;

    //CLOSE FILES
    FILE_READ.close();
    FILE_KEY.close();
    FILE_CRYPT.close();

    cout<<"File generate with success.";
}

void decrypt()
{
    int r;
    string text;

    ifstream FILE_READ1("CRYPT.TXT");       //READ FILE
    ifstream FILE_KEY("KEY.txt");           //READ KEY FILE
    ofstream FILE_DECRYPT("DECRYPT.txt");   //OUTPUT FILE DECRYPT

    FILE_KEY >> r;

    while(getline(FILE_READ1, text))
        FILE_DECRYPT << ChangeCharDecrypt(text, r);

    //CLOSE FILES
    FILE_READ1.close();
    FILE_KEY.close();
    FILE_DECRYPT.close();

    cout<<"File generate with success.";
}
