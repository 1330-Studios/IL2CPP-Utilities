#pragma once

using namespace System;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace UnhollowerBaseLib;

namespace _1330Studios {
	[ExtensionAttribute]
	public ref class Il2CppObjectBaseExt abstract sealed {
	public:

		generic<typename T> where T : Il2CppObjectBase
		[ExtensionAttribute]
		static T CloneAs(T instance) {
			return Clone(instance)->Cast<T>();
		}

		[ExtensionAttribute]
		static Il2CppObjectBase^ Clone(Il2CppObjectBase^ instance) {
			return gcnew Il2CppObjectBase(instance->Pointer);
		}
	};
};