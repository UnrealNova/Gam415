// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshFromStatic.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
AMeshFromStatic::AMeshFromStatic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	procMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Proc Mesh");
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");

	RootComponent = procMesh;
	baseMesh->SetupAttachment(procMesh);

}

// Called when the game starts or when spawned
void AMeshFromStatic::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMeshFromStatic::PostActorCreated()
{
	Super::PostActorCreated();
	GetMeshData();

}

void AMeshFromStatic::PostLoad()
{
	Super::PostLoad();
	GetMeshData();
}

void AMeshFromStatic::GetMeshData()
{
	UStaticMesh* mesh = baseMesh->GetStaticMesh();
	if (mesh)
	{
		UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(mesh, 0, 0, Vertices, Triangles, Normals, UV0, Tangents);
		procMesh->UpdateMeshSection(0, Vertices, Normals, UV0, UpVertexColors, Tangents);
		CreateMesh();
	}
}

void AMeshFromStatic::CreateMesh()
{
	if (baseMesh)
	{
		procMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, UpVertexColors, Tangents, true);
	}
}

// Called every frame
void AMeshFromStatic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

