//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
struct kostka
{
  TImage *a;
  bool visible;
};

struct kostka tab[7];

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
tab[0].a=Form1->o;
tab[1].a=Form1->k1;
tab[2].a=Form1->k2;
tab[3].a=Form1->k3;
tab[4].a=Form1->k4;
tab[5].a=Form1->k5;
tab[6].a=Form1->k6;
}
//---------------------------------------------------------------------------

void zmieniacz(int r)
{
int i;
    for(i=1; i<7; i++)
    {
       tab[i].a->Visible=false;
    }
    tab[r].a->Visible=true;
}

//---------------------------------------------------------------------------

void randomizer()
{
int r;
     randomize();
     for(int i=0; i<40;i++)
     {
       r=random(6)+1;
       zmieniacz(r);
       if(i<30){Application->ProcessMessages(); Sleep(20);}
       else if(i>=30 && i<36) {Application->ProcessMessages(); Sleep(150);}
       else if(i==36) {Application->ProcessMessages(); Sleep(250);}
       else if(i==37) {Application->ProcessMessages(); Sleep(250);}
       else if(i==38) {Application->ProcessMessages(); Sleep(250);}
     }

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   tab[0].a->Visible=false;
   randomizer();
}

