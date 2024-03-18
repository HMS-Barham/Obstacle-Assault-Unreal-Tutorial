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

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CubeLocation.Y = CubeLocation.Y + 2;

	SetActorLocation(CubeLocation);

	//Move the plattform forward
		//Add a variable to the appropriate vector

	//Check to see if platform has gone too far
		//If statement to see if platform has moved more than a set variable.

	//Reverse Platform
		//Subtract variable from vector

}

