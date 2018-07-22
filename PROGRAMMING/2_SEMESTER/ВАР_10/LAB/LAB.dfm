object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_6'
  ClientHeight = 263
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 72
    Top = 8
    Width = 155
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1087#1086#1088#1103#1076#1086#1082' '#1084#1072#1090#1088#1080#1094#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 85
    Top = 234
    Width = 134
    Height = 13
    Caption = #1052#1072#1090#1088#1080#1094#1072' '#1089#1080#1084#1084#1077#1090#1088#1080#1095#1085#1072' - ...'
  end
  object Edit1: TEdit
    Left = 127
    Top = 191
    Width = 42
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'N'
  end
  object Button1: TButton
    Left = 198
    Top = 191
    Width = 91
    Height = 25
    Caption = #1042#1099#1095#1077#1089#1083#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 39
    Width = 281
    Height = 146
    ColCount = 2
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24)
  end
  object Button2: TButton
    Left = 8
    Top = 191
    Width = 91
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
end
