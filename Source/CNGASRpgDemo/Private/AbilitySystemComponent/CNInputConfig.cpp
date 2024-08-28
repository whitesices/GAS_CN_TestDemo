// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/CNInputConfig.h"

const UInputAction* UCNInputConfig::FindAbilityActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
    //通过遍历查询相应的Tag
    for (const FCNInputAction& Action : AbilityInputActions)
    {
        //判断InputAction是否有效 ，同时判断与需要的InpuTag是否一样
        if (Action.InputAction && Action.InputTag == InputTag)
        {
            return Action.InputAction;
        }
    }

    if (bLogNotFound)
    {
        //打印相应Log日志
        UE_LOG( LogTemp , Error , TEXT("找不到AbilityInputAction从指定的标签[%s],在InputConfig[%s]"),*InputTag.ToString() , *GetNameSafe(this)   );
    }




    return nullptr;
}
