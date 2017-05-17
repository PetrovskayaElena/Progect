//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <sstream>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int dec=0;

AnsiString EncodePhoneNumber(AnsiString PhoneNumber, int CountNum)
{
 AnsiString result = "";
 PhoneNumber.Delete(PhoneNumber.AnsiPos("+"),1);
 CountNum = PhoneNumber.Length();
 if((PhoneNumber.Length() % 2) > 0)
   PhoneNumber += "F";
 int i = 1;
 while(i < PhoneNumber.Length())
   {
	result += PhoneNumber[i + 1];
	result += PhoneNumber[i];
	i += 2;
   }
 return result;
}

AnsiString DecodePhoneNumber(AnsiString PhoneNumber, int CountNum)
{
 AnsiString result; CountNum=0;  int i=1;
AnsiString len = PhoneNumber.SubString(7, 2);
   std::string hex;
	hex = len.c_str();
	std::istringstream stream(hex);
	stream >> std::hex >> CountNum;
	PhoneNumber=PhoneNumber.Delete(1,10);
	PhoneNumber=PhoneNumber.Delete(CountNum+4,PhoneNumber.Length());
  while(i<PhoneNumber.Length())
  {
	result=result+PhoneNumber[i+1]+PhoneNumber[i];
	i+=2;
  }
   PhoneNumber=result;
   PhoneNumber=PhoneNumber.Delete(CountNum+1,PhoneNumber.Length());
   return PhoneNumber;

}

String DecodeMessage(String Message,String text)
{
Message=Message.Delete(1,dec+17);
String Str;
String ObStr;
for (int i = 1; i <Message.Length(); i+=4) {
  ObStr=Message.SubString(i,4);
  Str=wchar_t(StrToInt("0x"+ObStr));
text=text+""+Str;
Str="";
ObStr="";
}
return text;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
 Memo1->Text="";
 Memo2->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if((Memo1->Text!="")&&(Edit1->Text!=""))
	{
	String text;
	Memo2->Text="";
	if(Memo1->Text=="")
	text="00";
   else
    {text=Memo1->Text;
	   TBytes pdu;
	pdu = TEncoding::Unicode->GetBytes(text);
   text=Memo2->Text;
   for(int i = 0; i < pdu.Length; i+=2)
		text = text + IntToHex(pdu[i+1], 2) + "" + IntToHex(pdu[i], 2);}
   Memo2->Text="000100"+IntToHex(Edit1->Text.Length(),2)+"91"+EncodePhoneNumber(Edit1->Text,0)+"0008"+IntToHex((Memo1->Text.Length())*2, 2)+text;
   Memo1->Enabled=false;
   Edit1->Enabled=false;
   Button1->Enabled=false;
   Button2->Enabled=true;
   Memo2->Enabled=true;}
   else
   ShowMessage(L"Введите данные!");
 }

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   Memo1->Text="";
   Edit1->Text="";
   Memo1->Enabled=true;
   Memo2->Enabled=false;
   Button1->Enabled=true;
   Button2->Enabled=false;
   Edit1->Enabled=true;
   Memo1->Text=DecodePhoneNumber(Memo2->Text,0)+"  "+DecodeMessage(Memo2->Text,"");


}
//---------------------------------------------------------------------------
