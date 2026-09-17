// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Dead_WrenchCharacter.h"
#include "Dead_WrenchPickUpComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, ADead_WrenchCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEAD_WRENCH_API UDead_WrenchPickUpComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	
	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	UDead_WrenchPickUpComponent();
protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};