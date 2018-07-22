object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'FORM'
  ClientHeight = 161
  ClientWidth = 362
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
    Width = 81
    Height = 13
    Caption = #1042#1040#1064#1045' '#1057#1051#1054#1042#1054' - '
  end
  object Label2: TLabel
    Left = 263
    Top = 30
    Width = 98
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' k '#1087#1086#1079#1080#1094#1080#1102
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 249
    Height = 21
    TabOrder = 0
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1089#1083#1086#1074#1072
    OnKeyPress = ComboBox1KeyPress
  end
  object ListBox1: TListBox
    Left = 8
    Top = 35
    Width = 249
    Height = 97
    ItemHeight = 13
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 263
    Top = 107
    Width = 88
    Height = 25
    Caption = #1047#1040#1050#1056#1067#1058#1068
    DoubleBuffered = True
    Kind = bkClose
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 263
    Top = 76
    Width = 88
    Height = 25
    Caption = #1053#1040#1049#1058#1048' '#1057#1051#1054#1042#1054
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 263
    Top = 49
    Width = 91
    Height = 21
    TabOrder = 4
    Text = 'k'
  end
end
