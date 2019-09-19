#pragma once

#include "Typesdef.h"

using namespace System;
using namespace System::Collections;

//using namespace System::Runtime::CompilerServices;
//public ref class Line
//{
//	//public Point Begin;
//	//public Point End;
//};
//
//static ref class SegmentExtensions
//{
//	// TValue должен быть reference type, так что костыль в виде каста к object
//private: static ConditionalWeakTable<Line, Object>^ _depthValues = gcnew ConditionalWeakTable<Line, Object> ();
//
//public: static int GetDepth (this Line line)
//{
//	return (int)_depthValues.GetValue (line, (l) = > 0);
//}
//				public static void SetDepth (this Line line, int depth)
//				{
//					_depthValues.Remove (line);
//					// возможно, затрайкетчить в случае работы из нескольких потоков
//					_depthValues.Add (line, depth);
//				}
//};

namespace TestCpp
{
	ref class CSavePropert
	{
	public: static String^ asFileProp = "Properties.bin";

		Hashtable^ Vals;
		bool bChanged;

	public:
		CSavePropert (String^ asPathExe, DOutMess^ OutMess);
		bool Add (System::String^ asValName, System::Object^ Val);
		void Set (System::String^ asValName, System::Object^ Val);
		Object^ Get (System::String^ asValName);
		void Save ();
	};

}