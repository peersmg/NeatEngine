#pragma once
#include "stdafx.h"

class GUIStyle
{
private:
  TextStyle m_textStyle;
  ButtonStyle m_buttonStyle;
  TextboxStyle m_textboxStyle;

public:
  GUIStyle();
  ~GUIStyle();

  virtual void LoadAll();

  TextStyle GetTextStyle();
  ButtonStyle GetButtonStyle();
  TextboxStyle GetTextboxStyle();
};

