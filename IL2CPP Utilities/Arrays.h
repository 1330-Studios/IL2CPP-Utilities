#pragma once

using namespace UnhollowerBaseLib;

namespace _1330Studios {
	public ref class Arrays	{
	public:
		generic<typename T> where T : System::Object
		static Il2CppArrayBase<T>^ NewArray(long long size) {
			if (size < 0)
				throw std::exception("Array size can't be negative!");
			System::IntPtr ptr = Il2CppClassPointerStore<T>::NativeClassPtr;
			if (ptr.Equals(System::IntPtr::Zero))
				throw std::exception("New array requires an Il2Cpp reference type. The given type isn't.");
			System::IntPtr arrPtr = IL2CPP::il2cpp_array_new(ptr, size);
			if (arrPtr.Equals(System::IntPtr::Zero))
				throw std::exception("Created array's pointer is 0. This will not function correctly!");
			std::cout << "Array created with the size of " << size << std::endl;
			Il2CppObjectBase^ obj = gcnew Il2CppObjectBase(arrPtr);
			try	{
				Il2CppArrayBase<T>^ array = obj->Cast<Il2CppArrayBase<T>^>();
				return array;
			} catch (const std::exception& e) {
				std::cout << "Error thrown when turning Il2CppObjectBase^ into Il2CppArrayBase<T>^!" << std::endl;
				throw e;
			}
			return nullptr;
		}
	};
}