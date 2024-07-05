#pragma once
#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

namespace HFlyWeight
{
#define WIDTH 5
#define HEIGHT 5
#define GRASS_TEXTURE text
#define HILL_TEXTURE text
#define RIVER_TEXTURE text
	class Texture {};
	Texture text;

	class Terrain
	{
	public:
		Terrain(int movementCost, bool isWater, Texture texture) :
			movementCost_(movementCost), isWater_(isWater), texture_(texture)
		{
		}

		int GetMovementCost() { return movementCost_; }
		bool IsWater() { return isWater_; }
		const Texture& GetTexture() { return texture_; }

	private:
		int movementCost_;
		bool isWater_;
		Texture texture_;
	};

	class World
	{
	public:
		World() : GrassTerrain(1, false, GRASS_TEXTURE),
			HillTerrain(3, false, HILL_TEXTURE),
			RiverTerrain(2, true, RIVER_TEXTURE)
		{
		}

		void GenerateTerrain();
		const Terrain& GetTile(int x, int y) const;

	private:
		Terrain* tiles[WIDTH][HEIGHT];

		Terrain GrassTerrain;
		Terrain HillTerrain;
		Terrain RiverTerrain;
	};

	void World::GenerateTerrain()
	{
		//땅에 풀을 채운다.
		for (int x = 0; x < WIDTH; ++x)
		{
			for (int y = 0; y < HEIGHT; ++y)
			{
				//언덕 놓기
				if (Random(10) == 0)
				{
					tiles[x][y] = &HillTerrain;
				}
				else
				{
					tiles[x][y] = &GrassTerrain;
				}
			}
		}

		//강을 하나 놓는다.
		int x = Random(WIDTH);
		for (int y = 0; y < HEIGHT; ++y)
		{
			tiles[x][y] = &RiverTerrain;
		}
	}

	const Terrain& World::GetTile(int x, int y) const
	{
		return *tiles[x][y];
	}

	int Random(int Value)
	{

	}
}

#endif // __FLYWEIGHT_H__
