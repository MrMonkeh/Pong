// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PaddleAI.generated.h"

UCLASS()
class PONG_API APaddleAI : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddleAI();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Ball property to follow
	UPROPERTY(EditAnywhere)
		AActor* Ball;

	// Speed
	UPROPERTY(EditAnywhere)
		float speed;

	// Movement functions
	UFUNCTION()
		void MoveUp(float Value);
	UFUNCTION()
		void MoveRight(float Value);
	
};
