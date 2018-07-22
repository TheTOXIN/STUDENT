object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_7'
  ClientHeight = 169
  ClientWidth = 467
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
    Left = 95
    Top = 143
    Width = 16
    Height = 13
    Caption = '....'
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 449
    Height = 21
    TabOrder = 0
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1075#1088#1091#1087#1087#1091' '#1080#1079' 0 '#1080' 1'
    OnKeyPress = ComboBox1KeyPress
  end
  object ListBox1: TListBox
    Left = 8
    Top = 35
    Width = 449
    Height = 97
    ItemHeight = 13
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 369
    Top = 136
    Width = 88
    Height = 25
    Caption = #1047#1040#1050#1056#1067#1058#1068
    DoubleBuffered = True
    Kind = bkClose
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 9
    Top = 138
    Width = 80
    Height = 25
    Caption = #1053#1040#1049#1058#1048
    TabOrder = 3
    OnClick = Button1Click
  end
end
