	#include "CreditCardValidator.h"
    #include <sstream>
    using namespace std;

	wxIMPLEMENT_APP(CreditCardValidator);

CreditCardValidator::CreditCardValidator() {

}

CreditCardValidator::~CreditCardValidator() {

}

bool CreditCardValidator::OnInit() {
	m_frame1 = new Main();
	m_frame1->Show();

	return true;
}