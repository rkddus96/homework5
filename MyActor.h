// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HOMEWORK5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FVector2D start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int evCnt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float totDist;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	float distance(FVector2D first, FVector2D second);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void move();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	int step();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	int createEvent();

};
