// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB02GameMode.h"
#include "PVZ_USFX_LAB02Pawn.h"
#include "Zombie.h"
#include "Plant.h"

APVZ_USFX_LAB02GameMode::APVZ_USFX_LAB02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB02Pawn::StaticClass();
}

void APVZ_USFX_LAB02GameMode::BeginPlay()
{
	Super::BeginPlay();


	//ZOmbi----------------------------------
	FVector SpawnLocation1 = FVector(400.0f, 200.0f, 300.0f);
	//AZombie* NewZombieActor1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(SpawnLocation1), FRotator::ZeroRotator);

	FVector MinSpawnLocation = FVector(-1000.0f, -1000.0f, 0.0f);
	FVector MaxSpawnLocation = FVector(1000.0f, 1000.0f, 0.0f);

	float RandomX = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.Y);
	float RandomY = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.Y);
	float Z = 180.0f;//haltura en z

	//lugar donde quiereras crear la instancia del objeto de planta //o donde parece el zombie
	FVector SpawnLocation = FVector(RandomX, RandomY, Z);//coordenadas 
	AZombie* NewZombieActor1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(SpawnLocation1), FRotator::ZeroRotator);



	//planta-------------------------

	APlant* NuevaPlant = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), FVector(-800, 200, 200), FRotator::ZeroRotator);


}
