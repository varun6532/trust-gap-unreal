#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetworkHelper.generated.h"

UCLASS()
class VULNERABLE_GAME_API UNetworkHelper : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category="Network")
    static void SendUDPMessage(const FString& Message);
};
