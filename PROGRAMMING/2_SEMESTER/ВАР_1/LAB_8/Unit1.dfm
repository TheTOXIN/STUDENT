object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_8'
  ClientHeight = 344
  ClientWidth = 510
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'NEW'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 170
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OPEN'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'SAVE'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 432
    Top = 8
    Width = 66
    Height = 25
    Caption = 'DEL'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 354
    Top = 8
    Width = 72
    Height = 25
    Caption = 'ADD'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 278
    Top = 8
    Width = 70
    Height = 25
    Caption = 'SEARCH'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button6Click
  end
  object StringGrid1: TStringGrid
    Left = 9
    Top = 48
    Width = 489
    Height = 257
    ColCount = 10
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 6
    ColWidths = (
      64
      64
      64
      64
      64
      64
      64
      64
      64
      64)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object MainMenu1: TMainMenu
    Left = 232
    Top = 312
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N6: TMenuItem
        Caption = #1053#1086#1074#1099#1081
      end
      object N4: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
      end
      object N5: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      end
      object N7: TMenuItem
        Caption = #1042#1099#1081#1090#1077
      end
    end
    object N2: TMenuItem
      Caption = #1047#1072#1087#1080#1089#1100
    end
    object N3: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'dat'
    Filter = 'F|*.dat'
    Left = 168
    Top = 312
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.dat'
    Filter = 'F|*.dat'
    Left = 320
    Top = 312
  end
end
