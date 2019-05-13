#pragma once
#include <iostream>
#include <vector>
#include "Renderer.h"
#include "Transform.h"

class SceneObjectSorter 
{
	public:

	static void SortByDistanceFromCamera(std::vector<Renderer*> arr) 
	{
		float temp1, temp2;

		int size = arr.size();

		Renderer *arr_ar[200];

		for (int loop = 0; loop < arr.size(); loop++) 
		{
			arr_ar[loop] = arr.at(loop);
		}

		for (int loop = 0; loop < arr.size() - 1; loop++) 
		{
			for (int i = 0; i < arr.size() - 1; i++) 
			{
				temp1 = glm::distance(arr_ar[i]->transform->position, glm::vec3(0));
				temp2 = glm::distance(arr_ar[i+1]->transform->position, glm::vec3(0));
				if (temp1 < temp2) 
				{
					Renderer * hold = arr_ar[i];
					arr_ar[i] = arr_ar[i + 1];
					arr_ar[i + 1] = hold;
				}
			}
		}

		arr.clear();

		for (int loop = 0; loop < arr.size(); loop++)
		{
			arr.push_back(arr_ar[loop]);
		}
	}
};