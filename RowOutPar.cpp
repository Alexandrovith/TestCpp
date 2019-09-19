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

	void CRowOutPar::FillCheckBox (bool bStateChB)
	{
		ChBSelectRow->Checked = bStateChB;
	}
	//___________________________________________________________________________

	System::String^ CRowOutPar::GetTagDataRow (System::String^ asDevName, int& iTagId)
	{//\"Name\":\"RunNumber\",
		System::String^ asTag = String::Format("{3}\"DeviceName\":\"{0}\",\"RequestName\":\"{1}\",\"ParamName\":\"{2}\",\"ParamsOutList\":[{3}{5}\"Value\":\"1\"{4}]{4}", 
																		asDevName, TBRequestName->Text, TBParamName->Text, "{", "}", asRunNumber);
		iTagId = (int)Tag;
		return asTag;
	}
	//___________________________________________________________________________

	System::String^ CRowOutPar::GetTagDataRowChecked (System::String^ asDevName, int& iTagId)
	{
		if (ChBSelectRow->Checked)
			return GetTagDataRow (asDevName, iTagId);
		String^ asRetVoid;
		return asRetVoid;
	}
	//___________________________________________________________________________

	CDataForWr^ CRowOutPar::GetTagWrRowChecked (System::String^ asDevName)
	{
		if (ChBSelectRow->Checked)
		{
			CDataForWr^ DataForWr = gcnew CDataForWr();
			DataForWr->asTag = String::Format ("{3}\"DeviceName\":\"{0}\",\"RequestName\":\"{1}\",\"ParamName\":\"{2}\",\"ParamsOutList\":[{3}\"Name\":\"SuperFlo_Write_Password\",\"Value\":\"123\"{4},{3}{5}\"Value\":\"1\"{4}]{4}",
				asDevName, TBRequestName->Text, TBParamName->Text, "{", "}", asRunNumber);
			DataForWr->asType = TBType->Text;
			DataForWr->asData = TBVal->Text;
			return DataForWr;
		}
		CDataForWr^ asRetVoid;
		return asRetVoid;
	}
}