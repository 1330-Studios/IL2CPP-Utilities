#pragma once

using namespace System;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace UnhollowerBaseLib;

namespace _1330Studios {
	[ExtensionAttribute]
	static public ref class Il2CppObjectBaseExt abstract sealed {
	public:

		generic<typename T> where T : Il2CppObjectBase
		[ExtensionAttribute]
		static T CloneAs(T instance) {
			Il2CppObjectBase^ obj = gcnew Il2CppObjectBase(instance->Pointer);
			T ret = obj->Cast<T>();
			return ret;
		}
	};
};