object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_6 '
  ClientHeight = 186
  ClientWidth = 495
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
    Width = 169
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1084#1072#1090#1088#1080#1094#1091' A '#1080' '#1088#1072#1079#1084#1077#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 183
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
    Left = 231
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
    Left = 385
    Top = 8
    Width = 96
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100' B'
    TabOrder = 2
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 385
    Top = 39
    Width = 96
    Height = 130
    ColCount = 1
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 3
    ColWidths = (
      64)
    RowHeights = (
      24
      24)
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 39
    Width = 371
    Height = 130
    ColCount = 2
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24)
  end
  object Button2: TButton
    Left = 288
    Top = 8
    Width = 91
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' A'
    TabOrder = 5
    OnClick = Button2Click
  end
end
