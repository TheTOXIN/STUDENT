object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB'
  ClientHeight = 206
  ClientWidth = 285
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
    Left = 8
    Top = 8
    Width = 157
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1084#1072#1090#1088#1080#1094#1091' '#1080' '#1088#1072#1079#1084#1077#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 216
    Top = 176
    Width = 57
    Height = 22
    Caption = 'count'
  end
  object Edit1: TEdit
    Left = 187
    Top = 8
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
  object Edit2: TEdit
    Left = 235
    Top = 8
    Width = 42
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = 'M'
  end
  object Button1: TButton
    Left = 105
    Top = 173
    Width = 96
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 39
    Width = 265
    Height = 130
    ColCount = 2
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24)
  end
  object Button2: TButton
    Left = 8
    Top = 173
    Width = 91
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
end
