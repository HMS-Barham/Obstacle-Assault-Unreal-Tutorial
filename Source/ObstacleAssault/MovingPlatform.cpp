// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	if (ShouldPlatformReturn())
	{
		FVector NormalizedDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + NormalizedDirection * PlatformMaxDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() >= PlatformMaxDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("You Spin Me Right Round"));
}


