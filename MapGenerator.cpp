// MapGenerator.cpp

#include "MapGenerator.h"

void AMapGenerator::BeginPlay()
{
    Super::BeginPlay();

    GenerateMap();
}

void AMapGenerator::GenerateMap()
{
    if (UseRandomSeed)
    {
        Seed = FDateTime::Now().ToUnixTimestamp();
    }

    FRandomStream randomStream(Seed);

    Map.Empty();

    for (int x = 0; x < Width; x++)
    {
        Map.Add(TArray<int32>());

        for (int y = 0; y < Height; y++)
        {
            if (x == 0 || x == Width - 1 || y == 0 || y == Height - 1)
            {
                Map[x].Add(1);
            }
            else
            {
                Map[x].Add(randomStream.RandRange(0, 99) < InitialWallChance ? 1 : 0);
            }
        }
    }

    for (int i = 0; i < SmoothingIterations; i++)
    {
        for (int x = 0; x < Width; x++)
        {
            for (int y = 0; y < Height; y++)
            {
                int32 neighbourWallCount = 0;

                for (int nx = x - 1; nx <= x + 1; nx++)
                {
                    for (int ny = y - 1; ny <= y + 1; ny++)
                    {
                        if (nx >= 0 && nx < Width && ny >= 0 && ny < Height)
                        {
                            neighbourWallCount += Map[nx][ny];
                        }
                        else
                        {
                            neighbourWallCount++;
                        }
                    }
                }

                if (neighbourWallCount > WallThreshold)
                {
                    Map[x][y] = 1;
                }
                else if (neighbourWallCount < WallThreshold)
                {
                    Map[x][y] = 0;
                }
            }
        }
   
