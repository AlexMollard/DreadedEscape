// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_PickUpComponent.h"

UTP_PickUpComponent::UTP_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTP_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTP_PickUpComponent::OnSphereBeginOverlap);
}

void UTP_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ADreadedEscapeCharacter* Character = Cast<ADreadedEscapeCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Output to the log that the character picked up the object
		UE_LOG(LogTemp, Warning, TEXT("Character %s picked up the object"), *Character->GetName());
		
		// Get the actor that owns this component
		AActor* Owner = GetOwner();

		// Destroy the actor that owns this component
		Owner->Destroy();

		// Output to the log that the object was destroyed
		UE_LOG(LogTemp, Warning, TEXT("Object %s was destroyed"), *GetName());
	}
}
