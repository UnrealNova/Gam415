// Copyright Epic Games, Inc. All Rights Reserved.

#include "Juranek_GAM415Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"

AJuranek_GAM415Projectile::AJuranek_GAM415Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AJuranek_GAM415Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));

	// Set as root component
	RootComponent = CollisionComp;

	ballMesh->SetupAttachment(CollisionComp);

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}


void AJuranek_GAM415Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

	
	}

	if (baseMat)
	{
		float ranNumX = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumY = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumZ = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float frameNum = UKismetMathLibrary::RandomFloatInRange(0.f, 3.f);

		FVector4 randColor = FVector4(ranNumX, ranNumY, ranNumZ, 1.f);

		UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), baseMat, FVector(40.f, 40.f, 40.f), Hit.Location, Hit.Normal.Rotation(), 10.f);
		UMaterialInstanceDynamic* MatInstance = Decal->CreateDynamicMaterialInstance();

		MatInstance->SetVectorParameterValue("Color", randColor);
		MatInstance->SetScalarParameterValue("Frame", frameNum);
	}
	
}