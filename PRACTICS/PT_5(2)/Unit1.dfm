object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'PT_5(2)'
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
    Left = 40
    Top = 8
    Width = 515
    Height = 24
    Caption = #1056#1072#1089#1095#1105#1090' '#1080#1079#1076#1077#1088#1078#1077#1082' '#1087#1088#1086#1080#1079#1074#1086#1076#1089#1090#1074#1072' '#1087#1088#1086#1076#1091#1082#1094#1080#1080' '#1087#1088#1077#1076#1087#1088#1080#1103#1090#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 255
    Top = 251
    Width = 27
    Height = 24
    Caption = 'Q :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 104
    Top = 38
    Width = 393
    Height = 201
    ColCount = 8
    RowCount = 7
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object Button1: TButton
    Left = 104
    Top = 245
    Width = 137
    Height = 33
    Caption = #1042#1054#1057#1057#1058#1040#1053#1054#1042#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 288
    Top = 251
    Width = 57
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '10'
  end
  object Button2: TButton
    Left = 360
    Top = 245
    Width = 137
    Height = 33
    Caption = #1054#1041#1053#1059#1051#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
end
