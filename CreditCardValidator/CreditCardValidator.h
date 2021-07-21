#pragma once

#include "resource.h"
#include "wx/wx.h"
#include "main.h"

class CreditCardValidator : public wxApp
{
public:
	CreditCardValidator();
	~CreditCardValidator();

private:
	Main* frame = nullptr;

public:
	virtual bool OnInit();


};
