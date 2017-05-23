//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n=3;// n - непрочитанные сообщения
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)    //Уведомления
{
	TrayIcon1->BalloonTimeout = 3000; // Ставлю на 3 секунды
	TrayIcon1->BalloonTitle = "Вам сообщение";
  	TrayIcon1->BalloonHint ="Кол-во непрочитанных сообщений: "+IntToStr(n);
	TrayIcon1->ShowBalloonHint(); // Вызов
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
   TrayIcon1->Visible = false;
    ShowWindow(Form1->Handle, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = false;
    TrayIcon1->Visible = true;
	ShowWindow(Form1->Handle, SW_HIDE);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  if(Button==mbRight)
TrayIcon1->PopupMenu = PopupMenu1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{

 TrayIcon1->Visible = false;
 Application->Terminate();

}
//---------------------------------------------------------------------------

