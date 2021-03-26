using System;
using System.Diagnostics;
using UnhollowerBaseLib;
using UnhollowerRuntimeLib;

namespace _1330Studios.IL2CPPUtilities.Utilities {
    public class Arrays {
        public static Il2CppArrayBase<T> NewArray<T>(ulong size = 0) {
            if (size < 0)
                throw new ArgumentOutOfRangeException(nameof(size), "Array size can't be negative!");

            var ptr = Il2CppClassPointerStore<T>.NativeClassPtr;
            if (ptr.Equals(Il2CppSystem.IntPtr.Zero))
                throw new NullReferenceException("New array type requires an Il2Cpp reference type! The given type doesn't meet that criteria!");

            var arrptr = IL2CPP.il2cpp_array_new(ptr, size);
            if (arrptr.Equals(Il2CppSystem.IntPtr.Zero))
                throw new NullReferenceException("Created array's pointer is IntPtr.Zero");

            Debug.WriteLine($"Array created with the size of {size+1} elements allowed.");

            var obj = new Il2CppObjectBase(arrptr);
            return obj.Cast<Il2CppArrayBase<T>>();
        }

        public static Il2CppArrayBase<T> NewArray<T>(ulong size, T[] @base) {
            var array = NewArray<T>(size);
            for (var i = 0; i < @base.Length; i++)
                if (@base.Length <= array.Length)
                    array[i] = @base[i];
            return array;
        }
    }
}