object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_9'
  ClientHeight = 394
  ClientWidth = 679
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
    Left = 28
    Top = 27
    Width = 28
    Height = 13
    Caption = 'X_min'
  end
  object Label2: TLabel
    Left = 28
    Top = 54
    Width = 32
    Height = 13
    Caption = 'X_max'
  end
  object Label3: TLabel
    Left = 50
    Top = 97
    Width = 6
    Height = 13
    Caption = 'Y'
  end
  object Label4: TLabel
    Left = 50
    Top = 124
    Width = 6
    Height = 13
    Caption = 'Z'
  end
  object Label5: TLabel
    Left = 23
    Top = 174
    Width = 33
    Height = 13
    Caption = 'X_step'
  end
  object Label7: TLabel
    Left = 28
    Top = 240
    Width = 22
    Height = 13
    Caption = 'Step'
  end
  object Edit1: TEdit
    Left = 84
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '...'
  end
  object Edit2: TEdit
    Left = 84
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '...'
  end
  object Edit3: TEdit
    Left = 84
    Top = 94
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '...'
  end
  object Edit4: TEdit
    Left = 84
    Top = 121
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '...'
  end
  object Edit5: TEdit
    Left = 84
    Top = 171
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '...'
  end
  object Edit7: TEdit
    Left = 84
    Top = 237
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '...'
  end
  object Button1: TButton
    Left = 23
    Top = 288
    Width = 182
    Height = 25
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 23
    Top = 328
    Width = 182
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
    TabOrder = 7
    OnClick = Button2Click
  end
  object Chart1: TChart
    Left = 224
    Top = 8
    Width = 447
    Height = 378
    Title.Text.Strings = (
      'TChart')
    View3D = False
    TabOrder = 8
    ColorPaletteIndex = 13
    object Series1: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      Title = 'f(x)'
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end
