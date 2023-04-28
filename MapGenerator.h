// MapGenerator.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

UCLASS()
class MYPROJECT_API AMapGenerator : public AActor
{
    GENERATED_BODY()

public:
    // The dimensions of the map to generate
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 Width = 100;

    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 Height = 100;

    // The random seed to use for generation
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 Seed = 0;

    // Whether to use a random seed instead of the specified seed
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    bool UseRandomSeed = true;

    // The chance for a cell to be a wall at the start of generation (in percent)
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 InitialWallChance = 45;

    // The number of times to smooth the map after the initial generation
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 SmoothingIterations = 5;

    // The minimum number of neighbouring walls for a cell to become a wall
    UPROPERTY(EditAnywhere, Category = "Map Generation")
    int32 WallThreshold = 4;

    // The map data
    TArray<TArray<int32>> Map;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Generates the map
    void GenerateMap();
};
