object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB'
  ClientHeight = 215
  ClientWidth = 415
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
    Left = 80
    Top = 176
    Width = 100
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1084#1072#1090#1088#1080#1094#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 96
    Top = 16
    Width = 73
    Height = 17
    Caption = #1052#1040#1058#1056#1048#1062#1040' '#1040
  end
  object Label3: TLabel
    Left = 327
    Top = 13
    Width = 90
    Height = 25
    Caption = #1052#1040#1058#1056#1048#1062#1040' '#1042
  end
  object Edit1: TEdit
    Left = 207
    Top = 176
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
    Left = 255
    Top = 176
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
    Left = 311
    Top = 176
    Width = 96
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100' B'
    TabOrder = 2
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 311
    Top = 39
    Width = 96
    Height = 131
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
    Width = 289
    Height = 131
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
    Left = 206
    Top = 8
    Width = 91
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' A'
    TabOrder = 5
    OnClick = Button2Click
  end
end
