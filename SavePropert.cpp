#include "SavePropert.h"

using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;


namespace TestCpp
{
	CSavePropert::CSavePropert (String^ asPathExe, DOutMess^ OutMess)
	{
		try
		{
			asFileProp = asPathExe + "\\" + asFileProp;
			FileStream^ FS = gcnew FileStream (asFileProp, FileMode::Open);
			BinaryFormatter^ BF = gcnew BinaryFormatter ();
			Vals = (System::Collections::Hashtable^)BF->Deserialize (FS);
		}
		catch (Exception^ exc)
		{
			OutMess (String::Format ("Чтение файла [{0}]\t{1}",
				asFileProp, exc->Message/*, Environment::NewLine, exc->StackTrace*/));			
		}
		if (Vals == nullptr)
			Vals = gcnew Hashtable ();
	}
	//___________________________________________________________________________

	void CSavePropert::Set (System::String^ asValName, System::Object^ Val)
	{
		Vals[asValName] = Val;
		bChanged = true;
	}
	//___________________________________________________________________________

	bool CSavePropert::Add (System::String^ asValName, System::Object^ Val)
	{
		if (Vals->ContainsKey (asValName) == false)
		{
			Vals->Add (asValName, Val);
			bChanged = true;
			return true;
		}
		return false;
	}
	//___________________________________________________________________________

	Object^ CSavePropert::Get (System::String^ asValName)
	{
		if (Vals->ContainsKey (asValName))
		{
			return Vals[asValName];
			bChanged = true;
		}
		return nullptr;
	}
	//___________________________________________________________________________

	void CSavePropert::Save ()
	{
		if (bChanged)
		{
			bChanged = false;
			FileStream^ FS = gcnew FileStream (asFileProp, FileMode::OpenOrCreate);
			BinaryFormatter^ BF = gcnew BinaryFormatter ();
			BF->Serialize (FS, Vals);
		}
	}
}