#pragma once
#include "stdafx.h"

class GUIStyle
{
private:
  TextStyle m_textStyle;
  ButtonStyle m_buttonStyle;
  TextfieldStyle m_textfieldStyle;
  DropdownStyle m_dropdownStyle;

public:
  GUIStyle();
  ~GUIStyle();

  virtual void LoadAll();

  TextStyle GetTextStyle();
  ButtonStyle GetButtonStyle();
  TextfieldStyle GetTextfieldStyle();
  DropdownStyle GetDropdownStyle();
};

