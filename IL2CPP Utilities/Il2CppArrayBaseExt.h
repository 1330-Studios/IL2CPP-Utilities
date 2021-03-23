#pragma once
#include <type_traits>

using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace UnhollowerBaseLib;

namespace _1330Studios {
	[ExtensionAttribute]
	static public ref class Il2CppArrayBaseExt abstract sealed {
	public:
		generic<typename il2cppobj> where il2cppobj : Il2CppObjectBase

		[ExtensionAttribute]
		static Il2CppReferenceArray<il2cppobj>^ Add(Il2CppReferenceArray<il2cppobj>^ instance, ...array<il2cppobj>^ additions) {
			List<il2cppobj>^ list = gcnew List<il2cppobj>();
			for (int i = 0; i < instance->Length; i++)
				list->Add(instance[i]);
			for (int i = 0; i < additions->Length; i++)
				list->Add(instance[i]);
			return gcnew Il2CppReferenceArray<il2cppobj>(list->ToArray());
		}
	};
}