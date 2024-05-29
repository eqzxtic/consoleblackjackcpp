#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int sumPlayer,sizePlayer,sumDealer,sizeDealer;
int bani,gata,pariu;
char ans,hit;
bool cL,cW,stop=0;

int v[13]; // AS DOI TREI PATRU CINCI SASE SAPTE OPT NOUA ZECE REGE DAMA JUVETE

void addCard(int player)
{
    int x;
    bool nuCarti=false;
    for(int i=0; i<1; i++)
    {
        x = rand() % (13 + 1 - 2) + 2;
        if(v[x]<4)
        {
            if(player==1 && sizePlayer<5)
            {
                if(x==11)
                {
                    if(x+sumPlayer>21)
                    {
                        sumPlayer+=1;
                        v[x]++;
                    }
                    else
                    {
                        sumPlayer+=11;
                        v[x]++;
                    }
                }
                if(x!=11)
                {
                    sumPlayer+=x;
                    v[x]++;
                }
                sizePlayer++;
            }
            if(player==2 && sizeDealer<5 && sumDealer<17)
            {
                if(x==11)
                {
                    if(x+sumDealer>21)
                    {
                        sumDealer+=1;
                        v[x]++;
                    }
                    else
                    {
                        sumDealer+=11;
                        v[x]++;
                    }
                }
                if(x!=11)
                {
                    sumDealer+=x;
                    v[x]++;
                }
                sizeDealer++;
            }
        }
        else
        {
            nuCarti=true;
        }
        while(v[x]>4)
        {
            for(int j=0; j<1; j++)
            {
                x = rand() % (13 + 1 - 2) + 2;
            }
        }
        if(nuCarti==true)
        {
            if(player==1 && sizePlayer<5)
            {
                if(x==11)
                {
                    if(x+sumPlayer>21)
                    {
                        sumPlayer+=1;
                        v[x]++;
                    }
                    else
                    {
                        sumPlayer+=11;
                        v[x]++;
                    }
                }
                if(x!=11)
                {
                    sumPlayer+=x;
                    v[x]++;
                }
                sizePlayer++;
            }
            if(player==2 && sizeDealer<5 && sumDealer<17)
            {
                if(x==11)
                {
                    if(x+sumDealer>21)
                    {
                        sumDealer+=1;
                        v[x]++;
                    }
                    else
                    {
                        sumDealer+=11;
                        v[x]++;
                    }
                }
                if(x!=11)
                {
                    sumDealer+=x;
                    v[x]++;
                }
                sizeDealer++;
            }

        }
    }
}

void reset()
{
    hit=0;
    sizePlayer=0;
    sumPlayer=0;
    sizeDealer=0;
    sumDealer=0;
    for(int i=1;i<=13;i++)
    {
        v[i]=0;
    }
}

bool checkLose()
{
    if(hit=='s' && sumDealer>sumPlayer && sumDealer<21) return 1;
    if(sumPlayer>21) return 1;
    else if(sumDealer==21) return 1;
    else return 0;
}
bool checkWin()
{
    if(sumPlayer==21) return 1;
    if(sumDealer>21) return 1;
    else if(sumDealer>=17 && sumPlayer>sumDealer && sumPlayer<21) return 1;
    else return 0;
}

int main()
{
    bani=500;
    srand(time(0));
    cout << "Incepem jocul? (Y/N)\n";
    cin >> ans;
    tolower(ans);
    if(ans=='y')
    {
        cout << "Cat vrei sa pariezi? (Balanta : " << bani << " )\n";
        cin >> pariu;
        bani-=pariu;
        while(stop==0)
        {
            reset();
            gata=-1;
            addCard(1);
            addCard(1);
            addCard(2);
            addCard(2);
            while(gata==-1)
            {
                tolower(hit);
                if(hit=='s')
                {
                    while(sumDealer<17)
                    {
                        addCard(2);
                    }
                }
                if(hit=='h')
                {
                    addCard(1);
                }
                cout << "Dealerul are " << sumDealer << " din " << sizeDealer << "\n";
                cout << "Tu ai " << sumPlayer << " din " << sizePlayer << "\n";
                cW=checkWin();
                cL=checkLose();
                if(cW==1)
                {
                    gata=1;
                    bani+=(2*pariu);
                }
                if(cL==1)
                {
                    gata=0;
                }
                if(cW==0 && cL==0)
                {
                    cout << "Hit sau Stand (H/S)\n";
                    cin >> hit;
                }
            }
            if(gata==1)
            {
                cout << "\n\n\nAi castigat! Doresti sa continui?(Y/N)\n";
                cin >> ans;
                tolower(ans);
                if(ans=='n')
                {
                    stop=1;
                    return 0;
                }
                cout << "\n\n\n";
                cout << "Cat vrei sa pariezi? (Balanta : " << bani << " )\n";
                cin >> pariu;
                bani-=pariu;
            }
            if(gata==0)
            {
                cout << "\n\n\nAi pierdut! Doresti sa continui?(Y/N)\n";
                cin >> ans;
                tolower(ans);
                if(ans=='n')
                {
                    stop=1;
                    return 0;
                }
                cout << "\n\n\n";
                cout << "Cat vrei sa pariezi? (Balanta : " << bani << " )\n";
                cin >> pariu;
                bani-=pariu;
            }
        }
    }
    if(ans=='n')
    {
        return 0;
    }
}
