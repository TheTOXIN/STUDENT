object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 206
  ClientWidth = 393
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
    Top = 182
    Width = 100
    Height = 13
    Caption = #1063#1077#1090#1085#1099#1077' '#1095#1080#1089#1083#1072' :  ....'
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 377
    Height = 21
    TabOrder = 0
    Text = #1042#1074#1077#1076#1080#1090#1077' 10 '#1095#1080#1089#1083#1072' '#1095#1077#1088#1077#1079' '#1087#1088#1086#1073#1077#1083
    OnKeyPress = ComboBox1KeyPress
  end
  object ListBox1: TListBox
    Left = 8
    Top = 35
    Width = 377
    Height = 110
    ItemHeight = 13
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 199
    Top = 151
    Width = 186
    Height = 25
    Caption = #1042#1067#1049#1058#1048
    DoubleBuffered = True
    Kind = bkClose
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 8
    Top = 151
    Width = 185
    Height = 25
    Caption = #1042#1067#1042#1045#1057#1058#1048
    TabOrder = 3
    OnClick = Button1Click
  end
end
