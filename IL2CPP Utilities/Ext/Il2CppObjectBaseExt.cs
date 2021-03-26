using System;
using System.Runtime.InteropServices;
using UnhollowerBaseLib;
using UnhollowerRuntimeLib;
using GCHandle = Il2CppSystem.Runtime.InteropServices.GCHandle;

namespace _1330Studios.IL2CPPUtilities.Ext {
    public static class Il2CppObjectBaseExt {
        public static T CloneAs<T>(this T instance) where T : Il2CppObjectBase {
            return Clone(instance).Cast<T>();
        }

        public static Il2CppObjectBase Clone<T>(this T instance) where T : Il2CppObjectBase {
            return new(instance.Pointer);
        }

        public static bool IsGCd<T>(this T instance) where T : Il2CppObjectBase {
            try {
                var ptr = instance.Pointer;
                var a = GCHandle.FromIntPtr(ptr).Target;
                if (a.GetIl2CppType() == Il2CppType.Of<T>())
                    return true;
            } catch (Exception) {}
            return false;
        }
    }
}