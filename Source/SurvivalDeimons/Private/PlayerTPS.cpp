// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTPS.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerTPS::APlayerTPS()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerTPS::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerTPS::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void APlayerTPS::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// Called every frame
void APlayerTPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerTPS::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerTPS::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerTPS::MoveRight);
	PlayerInputComponent->BindAxis("LookUpDown", this, &APlayerTPS::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRightLeft", this, &APlayerTPS::AddControllerYawInput);
}

