object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'getPicture'
  ClientHeight = 307
  ClientWidth = 362
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 320
    Top = 8
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object N4: TMenuItem
        Caption = #1053#1086#1084#1077#1088#1072
        OnClick = N4Click
      end
    end
    object N3: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N3Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1050#1072#1088#1090#1080#1085#1082#1080'|*.bmp'
    Left = 256
    Top = 8
  end
end
