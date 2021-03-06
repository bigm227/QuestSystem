// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTrigger.h"

// Sets default values
AQuestTrigger::AQuestTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Trigger = CreateDefaultSubobject<UBoxComponent>("Trigger Volume");
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>("BillBoard");

	Trigger->OnComponentBeginOverlap.AddDynamic(this,&AQuestTrigger::BeginOverlap);
}

// Called when the game starts or when spawned
void AQuestTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void AQuestTrigger::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(ACharacter* player = Cast<ACharacter>(OtherActor))
	{
		ReceiveCallback();
	}
}
