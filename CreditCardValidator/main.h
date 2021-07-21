#include "wx/wx.h"
#include "resource.h"


class Main : public wxFrame {
public:
	Main();
	~Main();

public:
	wxTextCtrl* cardNumTextBox = nullptr;
	wxButton* submitButton = nullptr;
	wxStaticText* isValidText = nullptr;

	void clickedButton(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();

};