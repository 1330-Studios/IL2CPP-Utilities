using System;
using System.Collections.Generic;
using UnhollowerBaseLib;

namespace _1330Studios.IL2CPPUtilities.Ext {
    public class Il2CppReferenceArrayExt {
        public static Il2CppReferenceArray<T> Add<T>(Il2CppReferenceArray<T> instance, params T[] additions) where T : Il2CppObjectBase {
            Stack<T> stack = new();
            for (var i = 0; i < instance.Length; i++) stack.Push(instance[i]);
            for (var i = 0; i < additions.Length; i++) stack.Push(additions[i]);

            return new(stack.ToArray());
        }

        public static Il2CppReferenceArray<T> Remove<T>(Il2CppReferenceArray<T> instance, params Predicate<T>[] predicates) where T : Il2CppObjectBase {
            Stack<T> stack = new();
            for (var i = 0; i < instance.Length; i++) {
                var qualified = true;
                for (var j = 0; j < predicates.Length; j++)
                        qualified = qualified == false ? false : predicates[j](instance[i]);
                if (qualified)
                    stack.Push(instance[i]);
            }

            return new(stack.ToArray());
        }
    }
}