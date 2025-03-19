// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Juranek_GAM415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UDecalComponent;

UCLASS(config=Game)
class AJuranek_GAM415Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;


public:
	AJuranek_GAM415Projectile();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
		USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
		UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

