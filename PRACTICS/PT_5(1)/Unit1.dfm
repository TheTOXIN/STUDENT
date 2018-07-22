object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'PT_5(1)'
  ClientHeight = 283
  ClientWidth = 603
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
    Left = 32
    Top = 8
    Width = 541
    Height = 24
    Caption = #1056#1072#1089#1095#1105#1090' '#1086#1073#1097#1080#1093' '#1079#1072#1090#1088#1072#1090' '#1087#1088#1077#1076#1087#1088#1080#1103#1090#1080#1103' '#1087#1088#1080' '#1074#1099#1087#1091#1089#1082#1077' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 96
    Top = 38
    Width = 393
    Height = 201
    ColCount = 8
    RowCount = 6
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object Button1: TButton
    Left = 213
    Top = 244
    Width = 188
    Height = 33
    Caption = #1056#1040#1057#1057#1063#1048#1058#1040#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
end
