object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1050#1040#1051#1045#1053#1044#1040#1056#1068
  ClientHeight = 326
  ClientWidth = 346
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 54
    Height = 25
    Caption = #1043#1054#1044' :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 39
    Width = 82
    Height = 25
    Caption = #1052#1045#1057#1071#1062' :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 96
    Top = 8
    Width = 130
    Height = 21
    TabOrder = 0
    Text = '...'
  end
  object Button1: TButton
    Left = 232
    Top = 8
    Width = 106
    Height = 56
    Caption = #1055#1054#1050#1040#1047#1040#1058#1068
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 96
    Top = 39
    Width = 130
    Height = 21
    TabOrder = 2
    Text = '...'
  end
  object ListBox1: TListBox
    Left = 24
    Top = 88
    Width = 297
    Height = 209
    ItemHeight = 13
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 184
    object N1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N1Click
    end
  end
end
