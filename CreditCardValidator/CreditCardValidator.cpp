	#include "CreditCardValidator.h"
    #include <sstream>
    using namespace std;

	wxIMPLEMENT_APP(CreditCardValidator);

CreditCardValidator::CreditCardValidator() {

}

CreditCardValidator::~CreditCardValidator() {

}

bool CreditCardValidator::OnInit() {
	frame = new Main();
	frame->Show();

	return true;
}