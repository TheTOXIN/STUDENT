object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1051#1040#1041' 6'
  ClientHeight = 171
  ClientWidth = 413
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 138
    Width = 31
    Height = 13
    Caption = #1057#1083#1086#1074#1086
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 391
    Height = 21
    TabOrder = 0
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1089#1083#1086#1074#1072
    OnKeyPress = ComboBox1KeyPress
  end
  object ListBox1: TListBox
    Left = 8
    Top = 35
    Width = 305
    Height = 97
    ItemHeight = 13
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 319
    Top = 60
    Width = 88
    Height = 25
    Caption = #1047#1040#1050#1056#1067#1058#1068
    DoubleBuffered = True
    Kind = bkClose
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 319
    Top = 91
    Width = 88
    Height = 25
    Caption = #1042#1067#1063#1048#1057#1051#1048#1058#1068
    TabOrder = 3
    OnClick = Button1Click
  end
end
