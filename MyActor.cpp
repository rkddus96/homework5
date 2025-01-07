// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor() : start(0.0f, 0.0f), evCnt(0), totDist(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float ret = sqrt(pow((second.X - first.X), 2) + pow((second.Y - first.Y), 2));


	return ret;
}

void AMyActor::move()
{
	for (int i = 0; i < 10; i++)
	{
		createEvent();
		FVector2D prev = start;
		start.X += step();
		start.Y += step();
		float dist = distance(prev, start);
		totDist += dist;
		UE_LOG(LogTemp, Log, TEXT(" %d move  X : %f  Y : %f | dist : %f"), i+1, start.X, start.Y, dist);
	}

	UE_LOG(LogTemp, Log, TEXT("total dist : %f, eventCount : %d"), totDist, evCnt);
}

int AMyActor::step()
{
	int32 RandomValue = FMath::RandRange(-1, 1);
	return RandomValue;
}

int AMyActor::createEvent()
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= 50)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		evCnt++;
	}
	return 0;
}

