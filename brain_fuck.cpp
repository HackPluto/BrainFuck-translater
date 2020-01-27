#include<bits/stdc++.h>
using namespace std;

char data[3000]; //max memory 3000 bytes
char *d;          //operating byte
const char *p;   //command pointer
map<int, int >bracket;  //bracket's map
int bra_num=0;      //bracket number

void point_add() {
    d++;
}

void point_decr() {
    d--;
}

void num_add() {
    (*d)++;
}

void num_decr() {
    (*d)--;
}

void puts() {
    cout << *d;
}

void gets() {
    cin >> *d;
}

void bra_open() {
    int num=bra_num;
    if (*d == '\0') {
        p += (bracket[num]-num);
        bra_num += (bracket[num]-num);
    }
}

void bra_close(int fir) {
    p -= (bracket[fir]-fir);
    bra_num -= (bracket[fir]-fir);
}

int main() {
    d = data;
    char buff[1000];
    cin>>buff;
    p=buff;
    while (*p) {
        switch (*p) {
            case '>':
                point_add();
                break;
            case '<':
                point_decr();
                break;
            case '+':
                num_add();
                break;
            case '-':
                num_decr();
                break;
            case '.':
                puts();
                break;
            case ',':
                gets();
                break;
            case '[':
                bracket[bra_num]=0;
                bra_open();
                break;
            case ']':
                map<int,int>::iterator it = bracket.begin();
                int fir;
                for (it; it!=bracket.end(); it++) {
                    if (it->second==0) {
                        bracket[it->first]=bra_num;
                        fir = it->first;
                        break;
                    }
                }
                bra_close(fir);
                break;
        }
        p++;
        bra_num++;
    }
};
