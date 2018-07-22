object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'PT_1'
  ClientHeight = 448
  ClientWidth = 737
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
  object Memo1: TMemo
    Left = 8
    Top = 16
    Width = 218
    Height = 145
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Chart1: TChart
    Left = 232
    Top = 16
    Width = 489
    Height = 424
    LeftWall.Color = -1
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      #1059#1088#1072#1074#1085#1077#1085#1080#1077' '#1088#1077#1075#1088#1077#1089#1089#1080#1080' '#1080' '#1082#1086#1088#1088#1077#1083#1103#1094#1080#1086#1085#1085#1086#1077' '#1087#1086#1083#1077'  ')
    View3D = False
    TabOrder = 1
    PrintMargins = (
      27
      15
      27
      15)
    object Series1: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TBubbleSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Frame.Visible = False
      Marks.Shadow.Color = 8487297
      Marks.Visible = False
      ClickableLine = False
      Pointer.HorizSize = 40
      Pointer.InflateMargins = False
      Pointer.Style = psCircle
      Pointer.VertSize = 40
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      RadiusValues.Name = 'Radius'
      RadiusValues.Order = loNone
    end
  end
  object Button1: TButton
    Left = 8
    Top = 366
    Width = 218
    Height = 33
    Caption = #1042#1067#1063#1048#1057#1051#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 405
    Width = 218
    Height = 35
    Caption = #1048#1053#1060#1054#1056#1052#1040#1062#1048#1071
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 167
    Width = 153
    Height = 193
    ColCount = 2
    FixedCols = 0
    RowCount = 15
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
  end
end
