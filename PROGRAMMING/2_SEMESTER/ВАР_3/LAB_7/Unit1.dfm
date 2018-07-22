object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 178
  ClientWidth = 644
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
    Left = 111
    Top = 143
    Width = 125
    Height = 13
    Caption = #1057#1072#1084#1072#1103' '#1076#1083#1080#1085#1085#1072#1103' '#1075#1088#1091#1087#1087#1072' - '
  end
  object Label2: TLabel
    Left = 416
    Top = 143
    Width = 48
    Height = 13
    Caption = #1044#1083#1080#1085#1085#1072' - '
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 628
    Height = 21
    TabOrder = 0
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1075#1088#1091#1087#1087#1091' '#1095#1080#1089#1077#1083' 0 '#1080' 1'
    OnKeyPress = ComboBox1KeyPress
  end
  object ListBox1: TListBox
    Left = 8
    Top = 35
    Width = 628
    Height = 97
    ItemHeight = 13
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 531
    Top = 138
    Width = 105
    Height = 25
    Caption = #1042#1099#1081#1090#1080
    DoubleBuffered = True
    Kind = bkClose
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 8
    Top = 138
    Width = 97
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 3
    OnClick = Button1Click
  end
end
