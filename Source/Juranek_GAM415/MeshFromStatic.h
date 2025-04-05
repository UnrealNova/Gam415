// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MeshFromStatic.generated.h"

UCLASS()
class JURANEK_GAM415_API AMeshFromStatic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshFromStatic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostActorCreated() override;

	virtual void PostLoad() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere)
	TArray<int> Triangles;

	UPROPERTY(EditAnywhere)
	TArray<FVector2D> UV0;

	UPROPERTY()
	TArray<FVector> Normals;

	UPROPERTY()
	TArray<FLinearColor> VertexColors;

	TArray<FColor> UpVertexColors;

	TArray<FProcMeshTangent> Tangents;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* baseMesh;

private:
	UProceduralMeshComponent* procMesh;
	void GetMeshData();
	void CreateMesh();

};
