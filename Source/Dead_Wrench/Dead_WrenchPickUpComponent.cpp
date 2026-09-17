// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dead_WrenchPickUpComponent.h"

UDead_WrenchPickUpComponent::UDead_WrenchPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UDead_WrenchPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UDead_WrenchPickUpComponent::OnSphereBeginOverlap);
}

void UDead_WrenchPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ADead_WrenchCharacter* Character = Cast<ADead_WrenchCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
