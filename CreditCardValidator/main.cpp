#include "Main.h"
#include <sstream>
using namespace std;

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(0, clickedButton)
wxEND_EVENT_TABLE()

class CreditCard {
private:
    int cardLen;
    long long cardNum;
    int* cardArray;

public:
    string cardStr;

    CreditCard(string str) {
        cardStr = str;

        stringstream num(str);
        num >> cardNum;

        cardLen = setCardLen();
        cardArray = (int*)malloc(cardLen * sizeof(int));
        setCardArray();
    }

    int setCardLen() {
        int i = 0;
        long long tempCardNum = cardNum;
        while ((tempCardNum / 10) != 0) {
            tempCardNum /= 10;
            i += 1;
        }

        i += 1;
        return i;
    }

    int getCardLen() {
        return cardLen;
    }

    void setCardArray() {
        long long tempCardNum = cardNum;
        for (int i = cardLen - 1; i >= 0; i--) {
            cardArray[i] = tempCardNum % 10;
            tempCardNum /= 10;
        }
    }

    void getCardArray() {
        for (int i = 0; i < cardLen; i++) {
            std::cout << cardArray[i] << "\n";
        }
    }

    bool luhnsAlgorithm() {
        int sum = 0;

        for (int i = 0; i < cardLen; i++) {
            if (i % 2 == 0 || i == 0) {
                int doubleNum = (cardArray[i] * 2);
                sum += (doubleNum / 10) + (doubleNum - ((doubleNum / 10) * 10));

            }
            else {
                sum += cardArray[i];
            }
        }
        return (sum % 10 == 0);
    }

};



Main::Main() : wxFrame(nullptr, wxID_ANY, "Credit Card Validator",wxPoint(30, 30), wxSize(500, 200))
{

	cardNumTextBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 40), wxSize(300, 30));
	submitButton = new wxButton(this, 0, "Submit", wxPoint(320, 40), wxSize(150, 30));
};

Main::~Main() 
{
};

void Main::clickedButton(wxCommandEvent &event) {
	string cardStr = (string) cardNumTextBox->GetValue();
	bool isValid = true;

	for (int i = 0; i < cardStr.length(); i++) {
		if (!isdigit(cardStr[i])) {
			isValid = false;
		}
	}

	if (cardStr.length() < 13 || cardStr.length() > 19) {
		isValid = false;
	}

	CreditCard card = CreditCard(cardStr);

	if (isValid && card.luhnsAlgorithm()) {
		isValidText = new wxStaticText(this, wxID_ANY, "This number is valid", wxPoint(10, 80), wxSize(300, 30));
	}
	else {
		isValidText = new wxStaticText(this, wxID_ANY, "This number or input is invalid", wxPoint(10, 80), wxSize(300, 30));
	}
	
	isValidText = new wxStaticText(this, wxID_ANY, "", wxPoint(10, 80), wxSize(300, 30));
	

}

