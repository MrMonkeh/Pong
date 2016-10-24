// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "CameraDirector.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		// Cut instantly to camera one.
		OurPlayerController->SetViewTarget(MainCamera);
	}
	
}

// Called every frame
void ACameraDirector::Tick( float DeltaTime )
{
	
	Super::Tick( DeltaTime );

}

