//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// string na potrzeby nazwy pilku
AnsiString nazwaPliku = "";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
        // otwarcie nowego dokumentu tekstowego
        if(OpenDialog1->Execute())
        {
                // metoda try catch pozwalaj¹ca na obs³ugê wyj¹tków
                try
                {
                        //wczytanie linijek tekstu na pole Memo
                        Tresc->Lines->LoadFromFile(OpenDialog1->FileName);
                        nazwaPliku = OpenDialog1->FileName;
                }
                catch (...)
                {
                        ShowMessage("B³¹d otwarcia pliku. Upewnij sie, czy pilk istnieje na dysku");
                }

        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
        // zapisywanie pliku tekstowego
        if(SaveDialog1->Execute())
        {
                try
                {
                        Tresc->Lines->SaveToFile(SaveDialog1->FileName);
                        nazwaPliku = SaveDialog1->FileName;
                }
                catch (...)
                {
                        ShowMessage("Zapis zakoñczy³ siê niepowodzeniem");
                }

        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        // zapis pliku
        if(nazwaPliku != "")
        {
                Tresc -> Lines -> SaveToFile(nazwaPliku);
        }  else {
                Form1->Zapiszjako1Click(MainMenu1);
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        // utworzenie nowego pliku
        if(Application -> MessageBox("Czy na pewno utworzyæ nowy pilk?"," PotwierdŸ",MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
        {
                Tresc ->Lines -> Clear();
                nazwaPliku = "";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrescKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{

     if(Shift.Contains(ssCtrl))
     {
        // Kombinacja klawiszy crtl + s
         if((Key == 'S' ) || (Key == 's'))
         {
                Form1 -> Zapisz1Click(MainMenu1);
         }

         // Kombinacja klawiszy crtl + A
         if((Key == 'A' ) || (Key == 'a'))
         {
                Tresc -> SelectAll();

         }

     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
        if(Application -> MessageBox("Czy na pewno zakoñczyæ program?"," PotwierdŸ",MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            Application -> Terminate();
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application -> MessageBox("Czy na pewno zakoñczyæ program?"," PotwierdŸ",MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
            Action = caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WklejCtrlV1Click(TObject *Sender)
{
        Tresc -> PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WytnijCtrlX1Click(TObject *Sender)
{
        Tresc -> CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KopiujCtrlC1Click(TObject *Sender)
{
       Tresc -> CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if(Zawijaniewierszy1 -> Checked == true)
        {
               Zawijaniewierszy1 -> Checked = false;
               Tresc -> WordWrap = false;
               Tresc -> ScrollBars = ssBoth;
        } else {

                Zawijaniewierszy1 -> Checked = true;
                Tresc -> WordWrap = true;
                Tresc -> ScrollBars = ssVertical;

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
        if(FontDialog1 -> Execute())
        {
                //krój
                Tresc -> Font -> Name = FontDialog1 -> Font -> Name;

                //kolor
                Tresc -> Font -> Color = FontDialog1 -> Font -> Color;

                //rozmiar
                Tresc -> Font -> Size = FontDialog1 -> Font -> Size;

                //Styl
                Tresc -> Font -> Style = FontDialog1 -> Font -> Style;

        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
        Form2 -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stronainternetowa1Click(TObject *Sender)
{
        ///yuiyuiyu
        ShellExecute(NULL, "open", "www.google.pl", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

