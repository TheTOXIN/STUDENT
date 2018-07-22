object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAB_10'
  ClientHeight = 383
  ClientWidth = 643
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
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 625
    Height = 225
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 239
    Width = 620
    Height = 34
    DataSource = DataSource1
    TabOrder = 1
  end
  object ListBox1: TListBox
    Left = 145
    Top = 279
    Width = 241
    Height = 90
    ItemHeight = 13
    TabOrder = 2
  end
  object Button1: TButton
    Left = 392
    Top = 319
    Width = 121
    Height = 33
    Caption = #1053#1040#1049#1058#1048' '#1055#1040#1056#1059
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 392
    Top = 292
    Width = 121
    Height = 21
    TabOrder = 4
    Text = #1042#1042#1045#1044#1048#1058#1045' '#1060#1040#1052#1048#1051#1048#1070
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 536
    Top = 288
  end
  object ADOTable1: TADOTable
    Active = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\Files\'#1076#1086#1082#1091#1084#1077#1085#1090#1099'\' +
      #1055#1056#1054#1043#1056#1040#1052#1052#1048#1056#1054#1042#1040#1053#1048#1045'\C++\'#1074#1090#1086#1088#1086#1081'_'#1089#1077#1084#1077#1089#1090#1088'\'#1042#1040#1056'_2\LAB_10\BD.mdb;Persist ' +
      'Security Info=False'
    CursorType = ctStatic
    TableName = 'TAB'
    Left = 96
    Top = 288
    object ADOTable1NAME: TWideStringField
      FieldName = 'NAME'
      Size = 255
    end
    object ADOTable1SURNAME: TWideStringField
      FieldName = 'SURNAME'
      Size = 255
    end
    object ADOTable1SEX: TWideStringField
      FieldName = 'SEX'
      Size = 255
    end
    object ADOTable1REG: TIntegerField
      FieldName = 'REG'
    end
    object ADOTable1DATE: TDateTimeField
      FieldName = 'DATE'
    end
    object ADOTable1INFO: TWideStringField
      FieldName = 'INFO'
      Size = 50
    end
    object ADOTable1CALL: TWideStringField
      FieldName = 'CALL'
      Size = 50
    end
  end
end
