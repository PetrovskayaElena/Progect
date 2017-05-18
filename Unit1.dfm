object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 404
  ClientWidth = 438
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCanResize = FormCanResize
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 185
    Height = 21
    MaxLength = 11
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 62
    Top = 171
    Width = 75
    Height = 25
    Caption = #1042' PDU'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 294
    Top = 171
    Width = 75
    Height = 25
    Caption = #1048#1079' PDU'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 59
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Memo2: TMemo
    Left = 240
    Top = 59
    Width = 185
    Height = 89
    Enabled = False
    Lines.Strings = (
      'Memo2')
    TabOrder = 4
  end
  object Memo3: TMemo
    Left = 135
    Top = 202
    Width = 185
    Height = 194
    TabOrder = 5
  end
end
