#include "RowOutPar.h"


namespace TestCpp
{
	void CRowOutPar::FillControlByName (System::String^ asContrtolName, System::String^ asTextToWr)
	{
		for each (auto item in Controls)
		{
			System::Windows::Forms::TextBox^ TB = dynamic_cast<System::Windows::Forms::TextBox^> (item);
			if (TB != nullptr && TB->Name->Equals (asContrtolName))
			{
				TB->Text = asTextToWr;
				break;
			}
		}
	}
	//___________________________________________________________________________

	System::String^ CRowOutPar::GetTagDataRow (String^ asDevName)
	{
		//String^ asd = String::Format ("\"{\"DeviceName\":\"{0}\",", asDevName);// , TBRequestName->Text, TBParamName->Text);
		String^ asTag = String::Format("\"{3}\"DeviceName\":\"{0}\",\"RequestName\":\"{1}\",\"ParamName\":\"{2}\",\"ParamsOutList\":[{3}\"Name\":\"RunNumber\",\"Value\":\"1\"{4}]{4}\"", 
																		asDevName, TBRequestName->Text, TBParamName->Text, "{", "}");
		return asTag;
	}
}