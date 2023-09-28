// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ZombieMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));

	RootComponent = ZombieMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombieMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector TargetLocation = FVector(-800.0f, 200.0f, 300.0f);//cambia la ubicacion objetivo segun tus nececidades
	float MovementSpeed = 100; //velocidad de movimiento
	//calcula la direccion y distancia al objetivo
	FVector Direction = (TargetLocation - this->GetActorLocation()).GetSafeNormal();
	float DistanceToTarget = FVector::Dist(TargetLocation, this->GetActorLocation());
	//calcule displazamiento en este frame
	float DeltaMove = MovementSpeed * GetWorld()->DeltaTimeSeconds;


	if (DeltaMove < DistanceToTarget)//aqui es donde se realiza el movimiento
	{
		//si el displazamiento exede la distancia al objeto, mueve directamente al objeto
		this->AddActorWorldOffset(Direction * DeltaMove);// actualiza la pocicion de la nave 
	}
	else
	{
		//mueve el objeto en la direccion calculada
		
		this->AddActorWorldOffset(TargetLocation);
	}

}

