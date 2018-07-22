object Form1: TForm1
  Left = 364
  Top = 177
  BorderStyle = bsDialog
  Caption = 'TicTacToe'
  ClientHeight = 336
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 300
    Width = 81
    Height = 25
    Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 104
    Top = 300
    Width = 89
    Height = 25
    Caption = #1042#1082#1083'/'#1074#1099#1082#1083' '#1073#1086#1090#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 208
    Top = 300
    Width = 84
    Height = 25
    Caption = #1057#1087#1088#1072#1074#1082#1072
    TabOrder = 2
    OnClick = Button3Click
  end
  object MainMenu1: TMainMenu
    Left = 136
    Top = 144
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1048#1075#1088#1072
      Default = True
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N2Click
    end
  end
end
