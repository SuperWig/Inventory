#pragma once

#include "CoreMinimal.h"

// without UseEnumValuesAsMaskValuesInEditor values are shifted one
// i.e. RedKey = 2, BlueKey = 4
UENUM(Meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EItems
{
    RedKey = 1,
    BlueKey = 2,
    Dinosaur = 4
};
ENUM_CLASS_FLAGS(EItems)


template<class E>
auto ToUnderlying(E Enum)
{
    static_assert(__is_enum(E), "ToUnderlying is only for enums");
    return static_cast<__underlying_type(E)>(Enum);
}

inline void AddItems(int32& Items, EItems ItemFlags)
{
    Items |= ToUnderlying(ItemFlags);
}

inline void RemoveItems(int32& Items, EItems ItemFlags)
{
    Items &= ~ToUnderlying(ItemFlags);
}

inline bool HasItems(int32 Items, EItems ItemFlags)
{
    return (Items & ToUnderlying(ItemFlags)) != 0;
}

inline bool HasAllItems(int32 Items, EItems ItemFlags)
{
    return (Items & ToUnderlying(ItemFlags)) == ToUnderlying(ItemFlags);
}

// Only really added for debugging
inline void ToggleItems(int32& Items, EItems ItemFlags)
{
    if (HasItems(Items, ItemFlags))
    {
        RemoveItems(Items, ItemFlags);
    }
    else
    {
        AddItems(Items, ItemFlags);
    }
}
