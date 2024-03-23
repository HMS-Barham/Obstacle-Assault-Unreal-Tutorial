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

	//Move the plattform forward
		//Add a variable to the appropriate vector
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += PlatformVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	//Check to see if platform has gone too far
		//If statement to see if platform has moved more than a set variable.
	float PlatformDistanceTravelled = FVector::Dist(StartLocation, CurrentLocation);
	//Reverse Platform
		//Subtract variable from vector
	if(PlatformDistanceTravelled >= PlatformMaxDistance)
	{
		FVector NormalizedDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + NormalizedDirection * PlatformMaxDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	

}

