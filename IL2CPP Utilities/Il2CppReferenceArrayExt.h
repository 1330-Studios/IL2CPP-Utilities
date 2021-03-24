#pragma once

using namespace System;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace UnhollowerBaseLib;

namespace _1330Studios {
	[ExtensionAttribute]
	static public ref class Il2CppReferenceArrayExt abstract sealed {
	public:

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static Il2CppReferenceArray<T>^ Add(Il2CppReferenceArray<T>^ instance, ...array<T>^ additions) {
			List<T>^ list = gcnew List<T>();
			for (int i = 0; i < instance->Length; i++)
				list->Add(instance[i]);
			for (int i = 0; i < additions->Length; i++)
				list->Add(instance[i]);
			return gcnew Il2CppReferenceArray<T>(list->ToArray());
		}

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static Il2CppReferenceArray<T>^ Remove(Il2CppReferenceArray<T>^ instance, System::Predicate<T>^ predicate) {
			List<T>^ list = gcnew List<T>();
			for (int i = 0; i < instance->Length; i++)
				if (!predicate(instance[i]))
					list->Add(instance[i]);

			return gcnew Il2CppReferenceArray<T>(list->ToArray());
		}

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static Il2CppReferenceArray<T>^ Select(Il2CppReferenceArray<T>^ instance, System::Predicate<T>^ predicate) {
			List<T>^ list = gcnew List<T>();
			for (int i = 0; i < instance->Length; i++)
				if (predicate(instance[i]))
					list->Add(instance[i]);

			return gcnew Il2CppReferenceArray<T>(list->ToArray());
		}

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static void Do(Il2CppReferenceArray<T>^ instance, Action<T>^ action) {
			for (int i = 0; i < instance->Length; i++)
				action(instance[i]);
		}

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static void DoIf(Il2CppReferenceArray<T>^ instance, System::Predicate<T>^ predicate, Action<T>^ action) {
			for (int i = 0; i < instance->Length; i++)
				if (predicate(instance[i]))
					action(instance[i]);
		}

		generic<typename T> where T : Il2CppObjectBase
			[ExtensionAttribute]
		static Il2CppReferenceArray<T>^ Reverse(Il2CppReferenceArray<T>^ instance) {
			List<T>^ list = gcnew List<T>();
			for (int i = instance->Length - 1; i >= 0; i--)
				list->Add(instance[i]);

			return gcnew Il2CppReferenceArray<T>(list->ToArray());
		}
	};
}