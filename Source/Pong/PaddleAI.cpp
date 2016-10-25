// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "PaddleAI.h"


// Sets default values
APaddleAI::APaddleAI()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	speed = 10;
}

// Called when the game starts or when spawned
void APaddleAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddleAI::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//static float move = 0;
	//move += DeltaTime;
	FVector ballLocation = Ball->GetActorLocation();
	FVector current = GetActorLocation();
	//if (move >= 5)
	//{
	float move = speed*DeltaTime;
	
		if (current.Y < ballLocation.Y - 10)
			MoveRight(move);
		else if (current.Y > ballLocation.Y + 10)
			MoveRight(-1*move);
		if (current.Z < ballLocation.Z - 10)
			MoveUp(move);
		else if (current.Z > ballLocation.Z + 10)
			MoveUp(-1*move);
		//move = 0;
	//}
	
}

// Called to bind functionality to input
void APaddleAI::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void APaddleAI::MoveUp(float Value)
{
	FVector current = GetActorLocation();
	if (floor(current.Z) + 1 > 500)
	{
		current.Z = 498;
		SetActorLocation(current);
	}
	else if (floor(current.Z) - 1 < -500)
	{
		current.Z = -498;
		SetActorLocation(current);
	}
	else
	{
		FVector Direction(0, 0, 1);
		AddMovementInput(Direction, Value);
	}


}

void APaddleAI::MoveRight(float Value)
{
	FVector current = GetActorLocation();
	if (floor(current.Y) + 1 > 500)
	{
		current.Y = 498;
		SetActorLocation(current);
	}
	else if (floor(current.Y) - 1 < -500)
	{
		current.Y = -498;
		SetActorLocation(current);
	}
	else
	{
		FVector Direction = FVector::CrossProduct(FVector::UpVector, FVector::ForwardVector);
		AddMovementInput(Direction, Value);
	}
}

